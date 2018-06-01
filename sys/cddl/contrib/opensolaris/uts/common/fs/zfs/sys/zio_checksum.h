/* $MidnightBSD$ */
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.
 * Copyright (c) 2014, 2015 by Delphix. All rights reserved.
 * Copyright Saso Kiselkov 2013, All rights reserved.
 */

#ifndef _SYS_ZIO_CHECKSUM_H
#define	_SYS_ZIO_CHECKSUM_H

#include <sys/zio.h>
#include <zfeature_common.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Signature for checksum functions.
 */
typedef void zio_checksum_t(const void *data, uint64_t size,
    const void *ctx_template, zio_cksum_t *zcp);
typedef void *zio_checksum_tmpl_init_t(const zio_cksum_salt_t *salt);
typedef void zio_checksum_tmpl_free_t(void *ctx_template);

typedef enum zio_checksum_flags {
	/* Strong enough for metadata? */
	ZCHECKSUM_FLAG_METADATA = (1 << 1),
	/* ZIO embedded checksum */
	ZCHECKSUM_FLAG_EMBEDDED = (1 << 2),
	/* Strong enough for dedup (without verification)? */
	ZCHECKSUM_FLAG_DEDUP = (1 << 3),
	/* Uses salt value */
	ZCHECKSUM_FLAG_SALTED = (1 << 4),
	/* Strong enough for nopwrite? */
	ZCHECKSUM_FLAG_NOPWRITE = (1 << 5)
} zio_checksum_flags_t;

/*
 * Information about each checksum function.
 */
typedef struct zio_checksum_info {
	/* checksum function for each byteorder */
	zio_checksum_t			*ci_func[2];
	zio_checksum_tmpl_init_t	*ci_tmpl_init;
	zio_checksum_tmpl_free_t	*ci_tmpl_free;
	zio_checksum_flags_t		ci_flags;
	char				*ci_name;	/* descriptive name */
} zio_checksum_info_t;

typedef struct zio_bad_cksum {
	zio_cksum_t		zbc_expected;
	zio_cksum_t		zbc_actual;
	const char		*zbc_checksum_name;
	uint8_t			zbc_byteswapped;
	uint8_t			zbc_injected;
	uint8_t			zbc_has_cksum;	/* expected/actual valid */
} zio_bad_cksum_t;

extern zio_checksum_info_t zio_checksum_table[ZIO_CHECKSUM_FUNCTIONS];

/*
 * Checksum routines.
 */
extern zio_checksum_t zio_checksum_SHA256;
#ifdef illumos
extern zio_checksum_t zio_checksum_SHA512_native;
extern zio_checksum_t zio_checksum_SHA512_byteswap;

/* Skein */
extern zio_checksum_t zio_checksum_skein_native;
extern zio_checksum_t zio_checksum_skein_byteswap;
extern zio_checksum_tmpl_init_t zio_checksum_skein_tmpl_init;
extern zio_checksum_tmpl_free_t zio_checksum_skein_tmpl_free;

/* Edon-R */
extern zio_checksum_t zio_checksum_edonr_native;
extern zio_checksum_t zio_checksum_edonr_byteswap;
extern zio_checksum_tmpl_init_t zio_checksum_edonr_tmpl_init;
extern zio_checksum_tmpl_free_t zio_checksum_edonr_tmpl_free;
#endif

extern int zio_checksum_equal(spa_t *, blkptr_t *, enum zio_checksum,
    void *, uint64_t, uint64_t, zio_bad_cksum_t *);
extern void zio_checksum_compute(zio_t *zio, enum zio_checksum checksum,
    void *data, uint64_t size);
extern int zio_checksum_error_impl(spa_t *, blkptr_t *, enum zio_checksum,
    void *, uint64_t, uint64_t, zio_bad_cksum_t *);
extern int zio_checksum_error(zio_t *zio, zio_bad_cksum_t *out);
extern enum zio_checksum spa_dedup_checksum(spa_t *spa);
extern void zio_checksum_templates_free(spa_t *spa);
extern spa_feature_t zio_checksum_to_feature(enum zio_checksum cksum);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_ZIO_CHECKSUM_H */
