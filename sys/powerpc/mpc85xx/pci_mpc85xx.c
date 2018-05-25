/* $MidnightBSD$ */
/*-
 * Copyright 2006-2007 by Juniper Networks.
 * Copyright 2008 Semihalf.
 * Copyright 2010 The FreeBSD Foundation
 * All rights reserved.
 *
 * Portions of this software were developed by Semihalf
 * under sponsorship from the FreeBSD Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * From: FreeBSD: src/sys/powerpc/mpc85xx/pci_ocp.c,v 1.9 2010/03/23 23:46:28 marcel
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: stable/10/sys/powerpc/mpc85xx/pci_mpc85xx.c 266160 2014-05-15 17:30:16Z ian $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/ktr.h>
#include <sys/sockio.h>
#include <sys/mbuf.h>
#include <sys/malloc.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/socket.h>
#include <sys/queue.h>
#include <sys/bus.h>
#include <sys/lock.h>
#include <sys/mutex.h>
#include <sys/rman.h>
#include <sys/endian.h>

#include <vm/vm.h>
#include <vm/pmap.h>

#include <dev/ofw/ofw_pci.h>
#include <dev/ofw/ofw_bus.h>
#include <dev/ofw/ofw_bus_subr.h>
#include <dev/pci/pcivar.h>
#include <dev/pci/pcireg.h>
#include <dev/pci/pcib_private.h>

#include <powerpc/ofw/ofw_pci.h>

#include "ofw_bus_if.h"
#include "pcib_if.h"

#include <machine/resource.h>
#include <machine/bus.h>
#include <machine/intr_machdep.h>

#include <powerpc/mpc85xx/mpc85xx.h>

#define	REG_CFG_ADDR	0x0000
#define	CONFIG_ACCESS_ENABLE	0x80000000

#define	REG_CFG_DATA	0x0004
#define	REG_INT_ACK	0x0008

#define	REG_POTAR(n)	(0x0c00 + 0x20 * (n))
#define	REG_POTEAR(n)	(0x0c04 + 0x20 * (n))
#define	REG_POWBAR(n)	(0x0c08 + 0x20 * (n))
#define	REG_POWAR(n)	(0x0c10 + 0x20 * (n))

#define	REG_PITAR(n)	(0x0e00 - 0x20 * (n))
#define	REG_PIWBAR(n)	(0x0e08 - 0x20 * (n))
#define	REG_PIWBEAR(n)	(0x0e0c - 0x20 * (n))
#define	REG_PIWAR(n)	(0x0e10 - 0x20 * (n))

#define	REG_PEX_MES_DR	0x0020
#define	REG_PEX_MES_IER	0x0028
#define	REG_PEX_ERR_DR	0x0e00
#define	REG_PEX_ERR_EN	0x0e08

#define PCIR_LTSSM	0x404
#define LTSSM_STAT_L0	0x16

#define	DEVFN(b, s, f)	((b << 16) | (s << 8) | f)

struct fsl_pcib_softc {
	struct ofw_pci_softc pci_sc;
	device_t	sc_dev;

	int		sc_iomem_target;
	bus_addr_t	sc_iomem_alloc, sc_iomem_start, sc_iomem_end;
	int		sc_ioport_target;
	bus_addr_t	sc_ioport_alloc, sc_ioport_start, sc_ioport_end;

	struct resource *sc_res;
	bus_space_handle_t sc_bsh;
	bus_space_tag_t	sc_bst;
	int		sc_rid;

	int		sc_busnr;
	int		sc_pcie;
	uint8_t		sc_pcie_capreg;		/* PCI-E Capability Reg Set */

	/* Devices that need special attention. */
	int		sc_devfn_tundra;
	int		sc_devfn_via_ide;
};

/* Local forward declerations. */
static uint32_t fsl_pcib_cfgread(struct fsl_pcib_softc *, u_int, u_int, u_int,
    u_int, int);
static void fsl_pcib_cfgwrite(struct fsl_pcib_softc *, u_int, u_int, u_int,
    u_int, uint32_t, int);
static int fsl_pcib_decode_win(phandle_t, struct fsl_pcib_softc *);
static void fsl_pcib_err_init(device_t);
static void fsl_pcib_inbound(struct fsl_pcib_softc *, int, int, u_long,
    u_long, u_long);
static int fsl_pcib_init(struct fsl_pcib_softc *, int, int);
static void fsl_pcib_outbound(struct fsl_pcib_softc *, int, int, u_long,
    u_long, u_long);

/* Forward declerations. */
static int fsl_pcib_attach(device_t);
static int fsl_pcib_detach(device_t);
static int fsl_pcib_probe(device_t);

static int fsl_pcib_maxslots(device_t);
static uint32_t fsl_pcib_read_config(device_t, u_int, u_int, u_int, u_int, int);
static void fsl_pcib_write_config(device_t, u_int, u_int, u_int, u_int,
    uint32_t, int);

/* Configuration r/w mutex. */
struct mtx pcicfg_mtx;
static int mtx_initialized = 0;

/*
 * Bus interface definitions.
 */
static device_method_t fsl_pcib_methods[] = {
	/* Device interface */
	DEVMETHOD(device_probe,		fsl_pcib_probe),
	DEVMETHOD(device_attach,	fsl_pcib_attach),
	DEVMETHOD(device_detach,	fsl_pcib_detach),

	/* pcib interface */
	DEVMETHOD(pcib_maxslots,	fsl_pcib_maxslots),
	DEVMETHOD(pcib_read_config,	fsl_pcib_read_config),
	DEVMETHOD(pcib_write_config,	fsl_pcib_write_config),

	DEVMETHOD_END
};

static devclass_t fsl_pcib_devclass;

DEFINE_CLASS_1(pcib, fsl_pcib_driver, fsl_pcib_methods,
    sizeof(struct fsl_pcib_softc), ofw_pci_driver);
DRIVER_MODULE(pcib, ofwbus, fsl_pcib_driver, fsl_pcib_devclass, 0, 0);

static int
fsl_pcib_probe(device_t dev)
{

	if (ofw_bus_get_type(dev) == NULL ||
	    strcmp(ofw_bus_get_type(dev), "pci") != 0)
		return (ENXIO);

	if (!(ofw_bus_is_compatible(dev, "fsl,mpc8540-pci") ||
	    ofw_bus_is_compatible(dev, "fsl,mpc8548-pcie")))
		return (ENXIO);

	device_set_desc(dev, "Freescale Integrated PCI/PCI-E Controller");
	return (BUS_PROBE_DEFAULT);
}

static int
fsl_pcib_attach(device_t dev)
{
	struct fsl_pcib_softc *sc;
	phandle_t node;
	uint32_t cfgreg;
	int maxslot, error;
	uint8_t ltssm, capptr;

	sc = device_get_softc(dev);
	sc->sc_dev = dev;

	sc->sc_rid = 0;
	sc->sc_res = bus_alloc_resource_any(dev, SYS_RES_MEMORY, &sc->sc_rid,
	    RF_ACTIVE);
	if (sc->sc_res == NULL) {
		device_printf(dev, "could not map I/O memory\n");
		return (ENXIO);
	}
	sc->sc_bst = rman_get_bustag(sc->sc_res);
	sc->sc_bsh = rman_get_bushandle(sc->sc_res);
	sc->sc_busnr = 0;

	if (!mtx_initialized) {
		mtx_init(&pcicfg_mtx, "pcicfg", NULL, MTX_SPIN);
		mtx_initialized = 1;
	}

	cfgreg = fsl_pcib_cfgread(sc, 0, 0, 0, PCIR_VENDOR, 2);
	if (cfgreg != 0x1057 && cfgreg != 0x1957)
		goto err;

	capptr = fsl_pcib_cfgread(sc, 0, 0, 0, PCIR_CAP_PTR, 1);
	while (capptr != 0) {
		cfgreg = fsl_pcib_cfgread(sc, 0, 0, 0, capptr, 2);
		switch (cfgreg & 0xff) {
		case PCIY_PCIX:
			break;
		case PCIY_EXPRESS:
			sc->sc_pcie = 1;
			sc->sc_pcie_capreg = capptr;
			break;
		}
		capptr = (cfgreg >> 8) & 0xff;
	}

	node = ofw_bus_get_node(dev);

	/*
	 * Initialize generic OF PCI interface (ranges, etc.)
	 */

	error = ofw_pci_init(dev);
	if (error)
		return (error);

	/*
	 * Configure decode windows for PCI(E) access.
	 */
	if (fsl_pcib_decode_win(node, sc) != 0)
		goto err;

	cfgreg = fsl_pcib_cfgread(sc, 0, 0, 0, PCIR_COMMAND, 2);
	cfgreg |= PCIM_CMD_SERRESPEN | PCIM_CMD_BUSMASTEREN | PCIM_CMD_MEMEN |
	    PCIM_CMD_PORTEN;
	fsl_pcib_cfgwrite(sc, 0, 0, 0, PCIR_COMMAND, cfgreg, 2);

	sc->sc_devfn_tundra = -1;
	sc->sc_devfn_via_ide = -1;


	/*
	 * Scan bus using firmware configured, 0 based bus numbering.
	 */
	sc->sc_busnr = 0;
	maxslot = (sc->sc_pcie) ? 0 : PCI_SLOTMAX;
	fsl_pcib_init(sc, sc->sc_busnr, maxslot);

	if (sc->sc_pcie) {
		ltssm = fsl_pcib_cfgread(sc, 0, 0, 0, PCIR_LTSSM, 1);
		if (ltssm < LTSSM_STAT_L0) {
			if (bootverbose)
				printf("PCI %d: no PCIE link, skipping\n",
				    device_get_unit(dev));
			return (0);
		}
	}

	fsl_pcib_err_init(dev);

	return (ofw_pci_attach(dev));

err:
	return (ENXIO);
}

static uint32_t
fsl_pcib_cfgread(struct fsl_pcib_softc *sc, u_int bus, u_int slot, u_int func,
    u_int reg, int bytes)
{
	uint32_t addr, data;

	if (bus == sc->sc_busnr - 1)
		bus = 0;

	addr = CONFIG_ACCESS_ENABLE;
	addr |= (bus & 0xff) << 16;
	addr |= (slot & 0x1f) << 11;
	addr |= (func & 0x7) << 8;
	addr |= reg & 0xfc;
	if (sc->sc_pcie)
		addr |= (reg & 0xf00) << 16;

	mtx_lock_spin(&pcicfg_mtx);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_CFG_ADDR, addr);

	switch (bytes) {
	case 1:
		data = bus_space_read_1(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA + (reg & 3));
		break;
	case 2:
		data = le16toh(bus_space_read_2(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA + (reg & 2)));
		break;
	case 4:
		data = le32toh(bus_space_read_4(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA));
		break;
	default:
		data = ~0;
		break;
	}
	mtx_unlock_spin(&pcicfg_mtx);
	return (data);
}

static void
fsl_pcib_cfgwrite(struct fsl_pcib_softc *sc, u_int bus, u_int slot, u_int func,
    u_int reg, uint32_t data, int bytes)
{
	uint32_t addr;

	if (bus == sc->sc_busnr - 1)
		bus = 0;

	addr = CONFIG_ACCESS_ENABLE;
	addr |= (bus & 0xff) << 16;
	addr |= (slot & 0x1f) << 11;
	addr |= (func & 0x7) << 8;
	addr |= reg & 0xfc;
	if (sc->sc_pcie)
		addr |= (reg & 0xf00) << 16;

	mtx_lock_spin(&pcicfg_mtx);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_CFG_ADDR, addr);

	switch (bytes) {
	case 1:
		bus_space_write_1(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA + (reg & 3), data);
		break;
	case 2:
		bus_space_write_2(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA + (reg & 2), htole16(data));
		break;
	case 4:
		bus_space_write_4(sc->sc_bst, sc->sc_bsh,
		    REG_CFG_DATA, htole32(data));
		break;
	}
	mtx_unlock_spin(&pcicfg_mtx);
}

#if 0
static void
dump(struct fsl_pcib_softc *sc)
{
	unsigned int i;

#define RD(o)	bus_space_read_4(sc->sc_bst, sc->sc_bsh, o)
	for (i = 0; i < 5; i++) {
		printf("POTAR%u  =0x%08x\n", i, RD(REG_POTAR(i)));
		printf("POTEAR%u =0x%08x\n", i, RD(REG_POTEAR(i)));
		printf("POWBAR%u =0x%08x\n", i, RD(REG_POWBAR(i)));
		printf("POWAR%u  =0x%08x\n", i, RD(REG_POWAR(i)));
	}
	printf("\n");
	for (i = 1; i < 4; i++) {
		printf("PITAR%u  =0x%08x\n", i, RD(REG_PITAR(i)));
		printf("PIWBAR%u =0x%08x\n", i, RD(REG_PIWBAR(i)));
		printf("PIWBEAR%u=0x%08x\n", i, RD(REG_PIWBEAR(i)));
		printf("PIWAR%u  =0x%08x\n", i, RD(REG_PIWAR(i)));
	}
	printf("\n");
#undef RD

	for (i = 0; i < 0x48; i += 4) {
		printf("cfg%02x=0x%08x\n", i, fsl_pcib_cfgread(sc, 0, 0, 0,
		    i, 4));
	}
}
#endif

static int
fsl_pcib_maxslots(device_t dev)
{
	struct fsl_pcib_softc *sc = device_get_softc(dev);

	return ((sc->sc_pcie) ? 0 : PCI_SLOTMAX);
}

static uint32_t
fsl_pcib_read_config(device_t dev, u_int bus, u_int slot, u_int func,
    u_int reg, int bytes)
{
	struct fsl_pcib_softc *sc = device_get_softc(dev);
	u_int devfn;

	if (bus == sc->sc_busnr && !sc->sc_pcie && slot < 10)
		return (~0);
	devfn = DEVFN(bus, slot, func);
	if (devfn == sc->sc_devfn_tundra)
		return (~0);
	if (devfn == sc->sc_devfn_via_ide && reg == PCIR_INTPIN)
		return (1);
	return (fsl_pcib_cfgread(sc, bus, slot, func, reg, bytes));
}

static void
fsl_pcib_write_config(device_t dev, u_int bus, u_int slot, u_int func,
    u_int reg, uint32_t val, int bytes)
{
	struct fsl_pcib_softc *sc = device_get_softc(dev);

	if (bus == sc->sc_busnr && !sc->sc_pcie && slot < 10)
		return;
	fsl_pcib_cfgwrite(sc, bus, slot, func, reg, val, bytes);
}

static void
fsl_pcib_init_via(struct fsl_pcib_softc *sc, uint16_t device, int bus,
    int slot, int fn)
{

	if (device == 0x0686) {
		fsl_pcib_write_config(sc->sc_dev, bus, slot, fn, 0x52, 0x34, 1);
		fsl_pcib_write_config(sc->sc_dev, bus, slot, fn, 0x77, 0x00, 1);
		fsl_pcib_write_config(sc->sc_dev, bus, slot, fn, 0x83, 0x98, 1);
		fsl_pcib_write_config(sc->sc_dev, bus, slot, fn, 0x85, 0x03, 1);
	} else if (device == 0x0571) {
		sc->sc_devfn_via_ide = DEVFN(bus, slot, fn);
		fsl_pcib_write_config(sc->sc_dev, bus, slot, fn, 0x40, 0x0b, 1);
	}
}

static int
fsl_pcib_init_bar(struct fsl_pcib_softc *sc, int bus, int slot, int func,
    int barno)
{
	bus_addr_t *allocp;
	uint32_t addr, mask, size;
	int reg, width;

	reg = PCIR_BAR(barno);

	if (DEVFN(bus, slot, func) == sc->sc_devfn_via_ide) {
		switch (barno) {
		case 0:	addr = 0x1f0; break;
		case 1: addr = 0x3f4; break;
		case 2: addr = 0x170; break;
		case 3: addr = 0x374; break;
		case 4: addr = 0xcc0; break;
		default: return (1);
		}
		fsl_pcib_write_config(sc->sc_dev, bus, slot, func, reg, addr, 4);
		return (1);
	}

	fsl_pcib_write_config(sc->sc_dev, bus, slot, func, reg, ~0, 4);
	size = fsl_pcib_read_config(sc->sc_dev, bus, slot, func, reg, 4);
	if (size == 0)
		return (1);
	width = ((size & 7) == 4) ? 2 : 1;

	if (size & 1) {		/* I/O port */
		allocp = &sc->sc_ioport_alloc;
		size &= ~3;
		if ((size & 0xffff0000) == 0)
			size |= 0xffff0000;
	} else {		/* memory */
		allocp = &sc->sc_iomem_alloc;
		size &= ~15;
	}
	mask = ~size;
	size = mask + 1;
	/* Sanity check (must be a power of 2). */
	if (size & mask)
		return (width);

	addr = (*allocp + mask) & ~mask;
	*allocp = addr + size;

	if (bootverbose)
		printf("PCI %u:%u:%u:%u: reg %x: size=%08x: addr=%08x\n",
		    device_get_unit(sc->sc_dev), bus, slot, func, reg,
		    size, addr);

	fsl_pcib_write_config(sc->sc_dev, bus, slot, func, reg, addr, 4);
	if (width == 2)
		fsl_pcib_write_config(sc->sc_dev, bus, slot, func, reg + 4,
		    0, 4);
	return (width);
}

static int
fsl_pcib_init(struct fsl_pcib_softc *sc, int bus, int maxslot)
{
	int secbus;
	int old_pribus, old_secbus, old_subbus;
	int new_pribus, new_secbus, new_subbus;
	int slot, func, maxfunc;
	int bar, maxbar;
	uint16_t vendor, device;
	uint8_t command, hdrtype, class, subclass;

	secbus = bus;
	for (slot = 0; slot <= maxslot; slot++) {
		maxfunc = 0;
		for (func = 0; func <= maxfunc; func++) {
			hdrtype = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_HDRTYPE, 1);

			if ((hdrtype & PCIM_HDRTYPE) > PCI_MAXHDRTYPE)
				continue;

			if (func == 0 && (hdrtype & PCIM_MFDEV))
				maxfunc = PCI_FUNCMAX;

			vendor = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_VENDOR, 2);
			device = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_DEVICE, 2);

			if (vendor == 0x1957 && device == 0x3fff) {
				sc->sc_devfn_tundra = DEVFN(bus, slot, func);
				continue;
			}

			command = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_COMMAND, 1);
			command &= ~(PCIM_CMD_MEMEN | PCIM_CMD_PORTEN);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_COMMAND, command, 1);

			if (vendor == 0x1106)
				fsl_pcib_init_via(sc, device, bus, slot, func);

			/* Program the base address registers. */
			maxbar = (hdrtype & PCIM_HDRTYPE) ? 1 : 6;
			bar = 0;
			while (bar < maxbar)
				bar += fsl_pcib_init_bar(sc, bus, slot, func,
				    bar);

			/* Put a placeholder interrupt value */
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_INTLINE, PCI_INVALID_IRQ, 1);

			command |= PCIM_CMD_MEMEN | PCIM_CMD_PORTEN;
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_COMMAND, command, 1);

			/*
			 * Handle PCI-PCI bridges
			 */
			class = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_CLASS, 1);
			subclass = fsl_pcib_read_config(sc->sc_dev, bus, slot,
			    func, PCIR_SUBCLASS, 1);

			/* Allow only proper PCI-PCI briges */
			if (class != PCIC_BRIDGE)
				continue;
			if (subclass != PCIS_BRIDGE_PCI)
				continue;

			secbus++;

			/* Program I/O decoder. */
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_IOBASEL_1, sc->sc_ioport_start >> 8, 1);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_IOLIMITL_1, sc->sc_ioport_end >> 8, 1);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_IOBASEH_1, sc->sc_ioport_start >> 16, 2);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_IOLIMITH_1, sc->sc_ioport_end >> 16, 2);

			/* Program (non-prefetchable) memory decoder. */
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_MEMBASE_1, sc->sc_iomem_start >> 16, 2);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_MEMLIMIT_1, sc->sc_iomem_end >> 16, 2);

			/* Program prefetchable memory decoder. */
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_PMBASEL_1, 0x0010, 2);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_PMLIMITL_1, 0x000f, 2);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_PMBASEH_1, 0x00000000, 4);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_PMLIMITH_1, 0x00000000, 4);

			/* Read currect bus register configuration */
			old_pribus = fsl_pcib_read_config(sc->sc_dev, bus,
			    slot, func, PCIR_PRIBUS_1, 1);
			old_secbus = fsl_pcib_read_config(sc->sc_dev, bus,
			    slot, func, PCIR_SECBUS_1, 1);
			old_subbus = fsl_pcib_read_config(sc->sc_dev, bus,
			    slot, func, PCIR_SUBBUS_1, 1);

			if (bootverbose)
				printf("PCI: reading firmware bus numbers for "
				    "secbus = %d (bus/sec/sub) = (%d/%d/%d)\n",
				    secbus, old_pribus, old_secbus, old_subbus);

			new_pribus = bus;
			new_secbus = secbus;

			secbus = fsl_pcib_init(sc, secbus,
			    (subclass == PCIS_BRIDGE_PCI) ? PCI_SLOTMAX : 0);

			new_subbus = secbus;

			if (bootverbose)
				printf("PCI: translate firmware bus numbers "
				    "for secbus %d (%d/%d/%d) -> (%d/%d/%d)\n",
				    secbus, old_pribus, old_secbus, old_subbus,
				    new_pribus, new_secbus, new_subbus);

			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_PRIBUS_1, new_pribus, 1);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_SECBUS_1, new_secbus, 1);
			fsl_pcib_write_config(sc->sc_dev, bus, slot, func,
			    PCIR_SUBBUS_1, new_subbus, 1);
		}
	}

	return (secbus);
}

static void
fsl_pcib_inbound(struct fsl_pcib_softc *sc, int wnd, int tgt, u_long start,
    u_long size, u_long pci_start)
{
	uint32_t attr, bar, tar;

	KASSERT(wnd > 0, ("%s: inbound window 0 is invalid", __func__));

	switch (tgt) {
	/* XXX OCP85XX_TGTIF_RAM2, OCP85XX_TGTIF_RAM_INTL should be handled */
	case OCP85XX_TGTIF_RAM1:
		attr = 0xa0f55000 | (ffsl(size) - 2);
		break;
	default:
		attr = 0;
		break;
	}
	tar = start >> 12;
	bar = pci_start >> 12;

	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PITAR(wnd), tar);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PIWBEAR(wnd), 0);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PIWBAR(wnd), bar);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PIWAR(wnd), attr);
}

static void
fsl_pcib_outbound(struct fsl_pcib_softc *sc, int wnd, int res, u_long start,
    u_long size, u_long pci_start)
{
	uint32_t attr, bar, tar;

	switch (res) {
	case SYS_RES_MEMORY:
		attr = 0x80044000 | (ffsl(size) - 2);
		break;
	case SYS_RES_IOPORT:
		attr = 0x80088000 | (ffsl(size) - 2);
		break;
	default:
		attr = 0x0004401f;
		break;
	}
	bar = start >> 12;
	tar = pci_start >> 12;

	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_POTAR(wnd), tar);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_POTEAR(wnd), 0);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_POWBAR(wnd), bar);
	bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_POWAR(wnd), attr);
}


static void
fsl_pcib_err_init(device_t dev)
{
	struct fsl_pcib_softc *sc;
	uint16_t sec_stat, dsr;
	uint32_t dcr, err_en;

	sc = device_get_softc(dev);

	sec_stat = fsl_pcib_cfgread(sc, 0, 0, 0, PCIR_SECSTAT_1, 2);
	if (sec_stat)
		fsl_pcib_cfgwrite(sc, 0, 0, 0, PCIR_SECSTAT_1, 0xffff, 2);
	if (sc->sc_pcie) {
		/* Clear error bits */
		bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PEX_MES_IER,
		    0xffffffff);
		bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PEX_MES_DR,
		    0xffffffff);
		bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PEX_ERR_DR,
		    0xffffffff);

		dsr = fsl_pcib_cfgread(sc, 0, 0, 0,
		    sc->sc_pcie_capreg + PCIER_DEVICE_STA, 2);
		if (dsr)
			fsl_pcib_cfgwrite(sc, 0, 0, 0,
			    sc->sc_pcie_capreg + PCIER_DEVICE_STA,
			    0xffff, 2);

		/* Enable all errors reporting */
		err_en = 0x00bfff00;
		bus_space_write_4(sc->sc_bst, sc->sc_bsh, REG_PEX_ERR_EN,
		    err_en);

		/* Enable error reporting: URR, FER, NFER */
		dcr = fsl_pcib_cfgread(sc, 0, 0, 0,
		    sc->sc_pcie_capreg + PCIER_DEVICE_CTL, 4);
		dcr |= PCIEM_CTL_URR_ENABLE | PCIEM_CTL_FER_ENABLE |
		    PCIEM_CTL_NFER_ENABLE;
		fsl_pcib_cfgwrite(sc, 0, 0, 0,
		    sc->sc_pcie_capreg + PCIER_DEVICE_CTL, dcr, 4);
	}
}

static int
fsl_pcib_detach(device_t dev)
{

	if (mtx_initialized) {
		mtx_destroy(&pcicfg_mtx);
		mtx_initialized = 0;
	}
	return (bus_generic_detach(dev));
}

static int
fsl_pcib_decode_win(phandle_t node, struct fsl_pcib_softc *sc)
{
	device_t dev;
	int error, i, trgt;

	dev = sc->sc_dev;

	fsl_pcib_outbound(sc, 0, -1, 0, 0, 0);

	/*
	 * Configure LAW decode windows.
	 */
	error = law_pci_target(sc->sc_res, &sc->sc_iomem_target,
	    &sc->sc_ioport_target);
	if (error != 0) {
		device_printf(dev, "could not retrieve PCI LAW target info\n");
		return (error);
	}

	for (i = 0; i < sc->pci_sc.sc_nrange; i++) {
		switch (sc->pci_sc.sc_range[i].pci_hi &
		    OFW_PCI_PHYS_HI_SPACEMASK) {
		case OFW_PCI_PHYS_HI_SPACE_CONFIG:
			continue;
		case OFW_PCI_PHYS_HI_SPACE_IO:
			trgt = sc->sc_ioport_target;
			fsl_pcib_outbound(sc, 2, SYS_RES_IOPORT,
			    sc->pci_sc.sc_range[i].host,
			    sc->pci_sc.sc_range[i].size,
			    sc->pci_sc.sc_range[i].pci);
			sc->sc_ioport_start = sc->pci_sc.sc_range[i].host;
			sc->sc_ioport_end = sc->pci_sc.sc_range[i].host +
			    sc->pci_sc.sc_range[i].size;
			sc->sc_ioport_alloc = 0x1000 + sc->pci_sc.sc_range[i].pci;
			break;
		case OFW_PCI_PHYS_HI_SPACE_MEM32:
		case OFW_PCI_PHYS_HI_SPACE_MEM64:
			trgt = sc->sc_iomem_target;
			fsl_pcib_outbound(sc, 1, SYS_RES_MEMORY,
			    sc->pci_sc.sc_range[i].host,
			    sc->pci_sc.sc_range[i].size,
			    sc->pci_sc.sc_range[i].pci);
			sc->sc_iomem_start = sc->pci_sc.sc_range[i].host;
			sc->sc_iomem_end = sc->pci_sc.sc_range[i].host +
			    sc->pci_sc.sc_range[i].size;
			sc->sc_iomem_alloc = sc->pci_sc.sc_range[i].pci;
			break;
		default:
			panic("Unknown range type %#x\n",
			    sc->pci_sc.sc_range[i].pci_hi &
			    OFW_PCI_PHYS_HI_SPACEMASK);
		}
		error = law_enable(trgt, sc->pci_sc.sc_range[i].host,
		    sc->pci_sc.sc_range[i].size);
		if (error != 0) {
			device_printf(dev, "could not program LAW for range "
			    "%d\n", i);
			return (error);
		}
	}

	/*
	 * Set outbout and inbound windows.
	 */
	fsl_pcib_outbound(sc, 3, -1, 0, 0, 0);
	fsl_pcib_outbound(sc, 4, -1, 0, 0, 0);

	fsl_pcib_inbound(sc, 1, -1, 0, 0, 0);
	fsl_pcib_inbound(sc, 2, -1, 0, 0, 0);
	fsl_pcib_inbound(sc, 3, OCP85XX_TGTIF_RAM1, 0,
	    2U * 1024U * 1024U * 1024U, 0);

	return (0);
}

