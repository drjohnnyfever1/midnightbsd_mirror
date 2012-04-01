/* $MidnightBSD: src/sys/cddl/contrib/opensolaris/uts/common/fs/zfs/sys/refcount.h,v 1.2 2008/12/03 00:24:32 laffer1 Exp $ */
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
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_REFCOUNT_H
#define	_SYS_REFCOUNT_H

#pragma ident	"%Z%%M%	%I%	%E% SMI"

#include_next <sys/refcount.h>
#include <sys/list.h>
#include <sys/zfs_context.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * If the reference is held only by the calling function and not any
 * particular object, use FTAG (which is a string) for the holder_tag.
 * Otherwise, use the object that holds the reference.
 */
#define	FTAG ((char *)__func__)

#if defined(DEBUG) || !defined(_KERNEL)
typedef struct reference {
	list_node_t ref_link;
	void *ref_holder;
	uint64_t ref_number;
	uint8_t *ref_removed;
} reference_t;

typedef struct refcount {
	kmutex_t rc_mtx;
	list_t rc_list;
	list_t rc_removed;
	int64_t rc_count;
	int64_t rc_removed_count;
} refcount_t;

/* Note: refcount_t should be initialized to zero before use. */

void refcount_create(refcount_t *rc);
void refcount_destroy(refcount_t *rc);
void refcount_destroy_many(refcount_t *rc, uint64_t number);
int refcount_is_zero(refcount_t *rc);
int64_t refcount_count(refcount_t *rc);
int64_t refcount_add(refcount_t *rc, void *holder_tag);
int64_t refcount_remove(refcount_t *rc, void *holder_tag);
int64_t refcount_add_many(refcount_t *rc, uint64_t number, void *holder_tag);
int64_t refcount_remove_many(refcount_t *rc, uint64_t number, void *holder_tag);

void refcount_sysinit(void);
void refcount_fini(void);

#else /* DEBUG */

typedef struct refcount {
	uint64_t rc_count;
} refcount_t;

#define	refcount_create(rc) ((rc)->rc_count = 0)
#define	refcount_destroy(rc) ((rc)->rc_count = 0)
#define	refcount_destroy_many(rc, number) ((rc)->rc_count = 0)
#define	refcount_is_zero(rc) ((rc)->rc_count == 0)
#define	refcount_count(rc) ((rc)->rc_count)
#define	refcount_add(rc, holder) atomic_add_64_nv(&(rc)->rc_count, 1)
#define	refcount_remove(rc, holder) atomic_add_64_nv(&(rc)->rc_count, -1)
#define	refcount_add_many(rc, number, holder) \
	atomic_add_64_nv(&(rc)->rc_count, number)
#define	refcount_remove_many(rc, number, holder) \
	atomic_add_64_nv(&(rc)->rc_count, -number)

#define	refcount_sysinit()
#define	refcount_fini()

#endif /* DEBUG */

#ifdef	__cplusplus
}
#endif

#endif /* _SYS_REFCOUNT_H */
