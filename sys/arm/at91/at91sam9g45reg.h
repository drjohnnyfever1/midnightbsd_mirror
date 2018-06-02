/* $MidnightBSD$ */
/*-
 * Copyright (c) 2009 Sylvestre Gallon.  All rights reserved.
 * Copyright (c) 2010 Greg Ansley.  All rights reserved.
 * Copyright (c) 2012 Andrew Turner.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* $FreeBSD: stable/10/sys/arm/at91/at91sam9g45reg.h 266110 2014-05-15 02:41:23Z ian $ */

#ifndef AT91SAM9G45REG_H_
#define	AT91SAM9G45REG_H_

/* Chip Specific limits */
#define	SAM9G45_PLL_A_MIN_IN_FREQ	  2000000 /*   2 Mhz */
#define	SAM9G45_PLL_A_MAX_IN_FREQ	 32000000 /*  32 Mhz */
#define	SAM9G45_PLL_A_MIN_OUT_FREQ	400000000 /* 400 Mhz */
#define	SAM9G45_PLL_A_MAX_OUT_FREQ	800000000 /* 800 Mhz */
#define	SAM9G45_PLL_A_MUL_SHIFT 16
#define	SAM9G45_PLL_A_MUL_MASK 0xFF
#define	SAM9G45_PLL_A_DIV_SHIFT 0
#define	SAM9G45_PLL_A_DIV_MASK 0xFF

/*
 * Memory map, from datasheet :
 * 0x00000000 - 0x0ffffffff : Internal Memories
 * 0x10000000 - 0x1ffffffff : Chip Select 0
 * 0x20000000 - 0x2ffffffff : Chip Select 1
 * 0x30000000 - 0x3ffffffff : Chip Select 2
 * 0x40000000 - 0x4ffffffff : Chip Select 3
 * 0x50000000 - 0x5ffffffff : Chip Select 4
 * 0x60000000 - 0x6ffffffff : Chip Select 5
 * 0x70000000 - 0x7ffffffff : DDR SDRC 0
 * 0x80000000 - 0xeffffffff : Undefined (Abort)
 * 0xf0000000 - 0xfffffffff : Peripherals
 */

#define	AT91_CHIPSELECT_0 0x10000000
#define	AT91_CHIPSELECT_1 0x20000000
#define	AT91_CHIPSELECT_2 0x30000000
#define	AT91_CHIPSELECT_3 0x40000000
#define	AT91_CHIPSELECT_4 0x50000000
#define	AT91_CHIPSELECT_5 0x60000000


#define	AT91SAM9G45_EMAC_BASE	0xffbc000
#define	AT91SAM9G45_EMAC_SIZE	0x4000

#define	AT91SAM9G45_RSTC_BASE	0xffffd00
#define	AT91SAM9G45_RSTC_SIZE	0x10

/* USART*/

#define	AT91SAM9G45_USART_SIZE	0x4000
#define	AT91SAM9G45_USART0_BASE	0xff8c000
#define	AT91SAM9G45_USART0_SIZE	AT91SAM9G45_USART_SIZE
#define	AT91SAM9G45_USART1_BASE	0xff90000
#define	AT91SAM9G45_USART1_SIZE	AT91SAM9G45_USART_SIZE
#define	AT91SAM9G45_USART2_BASE	0xff94000
#define	AT91SAM9G45_USART2_SIZE	AT91SAM9G45_USART_SIZE
#define	AT91SAM9G45_USART3_BASE	0xff98000
#define	AT91SAM9G45_USART3_SIZE	AT91SAM9G45_USART_SIZE

/*TC*/
#define	AT91SAM9G45_TC0_BASE	0xff7c000
#define	AT91SAM9G45_TC0_SIZE	0x4000
#define	AT91SAM9G45_TC0C0_BASE	0xff7c000
#define	AT91SAM9G45_TC0C1_BASE	0xff7c040
#define	AT91SAM9G45_TC0C2_BASE	0xff7c080

#define	AT91SAM9G45_TC1_BASE	0xffd4000
#define	AT91SAM9G45_TC1_SIZE	0x4000
#define	AT91SAM9G45_TC1C0_BASE	0xffd4000
#define	AT91SAM9G45_TC1C1_BASE	0xffd4040
#define	AT91SAM9G45_TC1C2_BASE	0xffd4080

/*SPI*/

#define	AT91SAM9G45_SPI0_BASE	0xffa48000
#define	AT91SAM9G45_SPI0_SIZE	0x4000

#define	AT91SAM9G45_SPI1_BASE	0xffa8000
#define	AT91SAM9G45_SPI1_SIZE	0x4000

/* System Registers */
#define	AT91SAM9G45_SYS_BASE	0xffff000
#define	AT91SAM9G45_SYS_SIZE	0x1000

#define	AT91SAM9G45_MATRIX_BASE	0xfffea00
#define	AT91SAM9G45_MATRIX_SIZE	0x200

#define	AT91SAM9G45_DBGU_BASE	0xfffee00
#define	AT91SAM9G45_DBGU_SIZE	0x200

/*
 * PIO
 */
#define	AT91SAM9G45_PIOA_BASE	0xffff200
#define	AT91SAM9G45_PIOA_SIZE	0x200
#define	AT91SAM9G45_PIOB_BASE	0xffff400
#define	AT91SAM9G45_PIOB_SIZE	0x200
#define	AT91SAM9G45_PIOC_BASE	0xffff600
#define	AT91SAM9G45_PIOC_SIZE	0x200
#define	AT91SAM9G45_PIOD_BASE	0xffff800
#define	AT91SAM9G45_PIOD_SIZE	0x200
#define	AT91SAM9G45_PIOE_BASE	0xffffa00
#define	AT91SAM9G45_PIOE_SIZE	0x200

#define	AT91SAM9G45_PMC_BASE	0xffffc00
#define	AT91SAM9G45_PMC_SIZE	0x100

/* IRQs : */
/*
 * 0: AIC
 * 1: System peripheral (System timer, RTC, DBGU)
 * 2: PIO Controller A
 * 3: PIO Controller B
 * 4: PIO Controller C
 * 5: PIO Controller D/E
 * 6: TRNG
 * 7: USART 0
 * 8: USART 1
 * 9: USART 2
 * 10: USART 3
 * 11: Multimedia Card interface 0
 * 12: Two-wirte interface 0
 * 13: Two-wirte interface 1
 * 14: SPI 0
 * 15: SPI 1
 * 16: SSC 0
 * 17: SSC 0
 * 18: Timer Counter 0, 2, 3, 4, 5
 * 19: PWM
 * 20: Touch Screen ADC
 * 21: DMA
 * 22: USB Host port
 * 23: LCD
 * 24: AC97
 * 25: EMAC
 * 26: Image Sensor Interface
 * 27: USB Device High Speed
 * 28: -
 * 29: Multimedia Card interface 1
 * 30: Reserved
 * 31: AIC
 */

#define	AT91SAM9G45_IRQ_SYSTEM	1
#define	AT91SAM9G45_IRQ_PIOA	2
#define	AT91SAM9G45_IRQ_PIOB	3
#define	AT91SAM9G45_IRQ_PIOC	4
#define	AT91SAM9G45_IRQ_PIOD	5
#define	AT91SAM9G45_IRQ_PIOE	6
#define	AT91SAM9G45_IRQ_USART0	7
#define	AT91SAM9G45_IRQ_USART1	8
#define	AT91SAM9G45_IRQ_USART2	9
#define	AT91SAM9G45_IRQ_USART3	10
#define	AT91SAM9G45_IRQ_HSMCI0	11
#define	AT91SAM9G45_IRQ_TWI0	12
#define	AT91SAM9G45_IRQ_TWI1	13
#define	AT91SAM9G45_IRQ_SPI0	14
#define	AT91SAM9G45_IRQ_SPI1	15
#define	AT91SAM9G45_IRQ_SSC0	16
#define	AT91SAM9G45_IRQ_SSC1	17
#define	AT91SAM9G45_IRQ_TC0_TC5	18
#define	AT91SAM9G45_IRQ_PWM	19
#define	AT91SAM9G45_IRQ_TSADCC	20
#define	AT91SAM9G45_IRQ_DMA	21
#define	AT91SAM9G45_IRQ_UHP	22
#define	AT91SAM9G45_IRQ_LCDC	23
#define	AT91SAM9G45_IRQ_AC97C	24
#define	AT91SAM9G45_IRQ_EMAC	25
#define	AT91SAM9G45_IRQ_ISI	26
#define	AT91SAM9G45_IRQ_UDPHS	27
/* Reserved 28 */
#define	AT91SAM9G45_IRQ_HSMCI1	29
/* Reserved 30 */
#define	AT91SAM9G45_IRQ_AICBASE	31

/* Alias */
#define	AT91SAM9G45_IRQ_DBGU	AT91SAM9G45_IRQ_SYSTEM
#define	AT91SAM9G45_IRQ_PMC	AT91SAM9G45_IRQ_SYSTEM
#define	AT91SAM9G45_IRQ_WDT	AT91SAM9G45_IRQ_SYSTEM
#define	AT91SAM9G45_IRQ_PIT	AT91SAM9G45_IRQ_SYSTEM
#define	AT91SAM9G45_IRQ_RSTC	AT91SAM9G45_IRQ_SYSTEM
#define	AT91SAM9G45_IRQ_OHCI	AT91SAM9G45_IRQ_UHP
#define	AT91SAM9G45_IRQ_TC0	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_TC1	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_TC2	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_TC3	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_TC4	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_TC5	AT91SAM9G45_IRQ_TC0_TC5
#define	AT91SAM9G45_IRQ_NAND 	(-1)

#define	AT91SAM9G45_AIC_BASE	0xffff000
#define	AT91SAM9G45_AIC_SIZE	0x200

/* Timer */

#define	AT91SAM9G45_WDT_BASE	0xffffd40
#define	AT91SAM9G45_WDT_SIZE	0x10

#define	AT91SAM9G45_PIT_BASE	0xffffd30
#define	AT91SAM9G45_PIT_SIZE	0x10

#define	AT91SAM9G45_SMC_BASE	0xfffe800
#define	AT91SAM9G45_SMC_SIZE	0x200

#define	AT91SAM9G45_PMC_BASE	0xffffc00
#define	AT91SAM9G45_PMC_SIZE	0x100

#define	AT91SAM9G45_HSMCI0_BASE	0xff80000
#define	AT91SAM9G45_HSMCI0_SIZE	0x4000

#define	AT91SAM9G45_HSMCI1_BASE	0xffd0000
#define	AT91SAM9G45_HSMCI1_SIZE	0x4000

#define	AT91SAM9G45_TWI0_BASE	0xff84000
#define	AT91SAM9G45_TWI0_SIZE	0x4000
#define	AT91SAM9G45_TWI1_BASE	0xff88000
#define	AT91SAM9G45_TWI1_SIZE	0x4000

/* XXX Needs to be carfully coordinated with
 * other * soc's so phyical and vm address
 * mapping are unique. XXX
 */
#define	AT91SAM9G45_OHCI_VA_BASE 0xdfb00000
#define	AT91SAM9G45_OHCI_BASE	0x00700000
#define	AT91SAM9G45_OHCI_SIZE	0x00100000

#define	AT91SAM9G45_NAND_VA_BASE 0xe0000000
#define	AT91SAM9G45_NAND_BASE	0x40000000
#define	AT91SAM9G45_NAND_SIZE	0x10000000


/* DDRSDRC */
#define	AT91SAM9G45_DDRSDRC1_BASE	0xfffea00
#define	AT91SAM9G45_DDRSDRC0_BASE	0xfffe600
#define	AT91SAM9G45_DDRSDRC_MR		0x00
#define	AT91SAM9G45_DDRSDRC_TR		0x04
#define	AT91SAM9G45_DDRSDRC_CR		0x08
#define	AT91SAM9G45_DDRSDRC_CR_NC_8	0x0
#define	AT91SAM9G45_DDRSDRC_CR_NC_9	0x1
#define	AT91SAM9G45_DDRSDRC_CR_NC_10	0x2
#define	AT91SAM9G45_DDRSDRC_CR_NC_11	0x3
#define	AT91SAM9G45_DDRSDRC_CR_NC_MASK	0x00000003
#define	AT91SAM9G45_DDRSDRC_CR_NR_11	0x0
#define	AT91SAM9G45_DDRSDRC_CR_NR_12	0x4
#define	AT91SAM9G45_DDRSDRC_CR_NR_13	0x8
#define	AT91SAM9G45_DDRSDRC_CR_NR_14	0xc
#define	AT91SAM9G45_DDRSDRC_CR_NR_MASK	0x0000000c
#define	AT91SAM9G45_DDRSDRC_TPR0	0x0c
#define	AT91SAM9G45_DDRSDRC_TPR1	0x10
#define	AT91SAM9G45_DDRSDRC_TPR2	0x14
/* Reserved 0x18 */
#define	AT91SAM9G45_DDRSDRC_LPR		0x1c
#define	AT91SAM9G45_DDRSDRC_MDR		0x20
#define	AT91SAM9G45_DDRSDRC_MDR_SDR	0x0
#define	AT91SAM9G45_DDRSDRC_MDR_LPSDR	0x1
#define	AT91SAM9G45_DDRSDRC_MDR_LPDDR1	0x3
#define	AT91SAM9G45_DDRSDRC_MDR_DDR2	0x6
#define	AT91SAM9G45_DDRSDRC_MDR_MASK	0x00000007
#define	AT91SAM9G45_DDRSDRC_MDR_DBW_16	0x10
#define	AT91SAM9G45_DDRSDRC_DLL		0x24
#define	AT91SAM9G45_DDRSDRC_HSR		0x2c
#define	AT91SAM9G45_DDRSDRC_DELAY1R	0x40
#define	AT91SAM9G45_DDRSDRC_DELAY2R	0x44
#define	AT91SAM9G45_DDRSDRC_DELAY3R	0x48
#define	AT91SAM9G45_DDRSDRC_DELAY4R	0x4c
/* Reserved 0x50 - 0xe0 */
#define	AT91SAM9G45_DDRSDRC_WPMR	0xe4
#define	AT91SAM9G45_DDRSDRC_WPSR	0xe8

#endif /* AT91SAM9G45REG_H_*/

