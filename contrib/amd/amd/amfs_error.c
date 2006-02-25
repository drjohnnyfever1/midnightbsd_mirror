/*
 * Copyright (c) 1997-2004 Erez Zadok
 * Copyright (c) 1989 Jan-Simon Pendry
 * Copyright (c) 1989 Imperial College of Science, Technology & Medicine
 * Copyright (c) 1989 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Jan-Simon Pendry at Imperial College, London.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      %W% (Berkeley) %G%
 *
 * $Id: amfs_error.c,v 1.1.1.2 2006-02-25 02:32:00 laffer1 Exp $
 *
 */

/*
 * Error file system.
 * This is used as a last resort catchall if
 * nothing else worked.  EFS just returns lots
 * of error codes, except for unmount which
 * always works of course.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */
#include <am_defs.h>
#include <amd.h>

static char *amfs_error_match(am_opts *fo);
static int amfs_error_fmount(mntfs *mf);
static int amfs_error_fumount(mntfs *mf);
static void amfs_error_umounted(am_node *mp);


/*
 * Ops structure
 */
am_ops amfs_error_ops =
{
  "error",
  amfs_error_match,
  0,				/* amfs_error_init */
  amfs_auto_fmount,
  amfs_error_fmount,
  amfs_auto_fumount,
  amfs_error_fumount,
  amfs_error_lookuppn,
  amfs_error_readdir,
  0,				/* amfs_error_readlink */
  0,				/* amfs_error_mounted */
  amfs_error_umounted,
  find_amfs_auto_srvr,
  FS_DISCARD
};



/*
 * EFS file system always matches
 */
static char *
amfs_error_match(am_opts *fo)
{
  return strdup("(error-hook)");
}


static int
amfs_error_fmount(mntfs *mf)
{
  return ENOENT;
}


static int
amfs_error_fumount(mntfs *mf)
{
  /*
   * Always succeed
   */
  return 0;
}


/*
 * EFS interface to RPC lookup() routine.
 * Should never get here in the automounter.
 * If we do then just give an error.
 */
am_node *
amfs_error_lookuppn(am_node *mp, char *fname, int *error_return, int op)
{
  *error_return = ESTALE;
  return 0;
}


/*
 * EFS interface to RPC readdir() routine.
 * Should never get here in the automounter.
 * If we do then just give an error.
 */
int
amfs_error_readdir(am_node *mp, nfscookie cookie, nfsdirlist *dp, nfsentry *ep, int count)
{
  return ESTALE;
}


/*
 * umounted() callback for EFS.
 *
 * This prevents core-dumps on callbacks to error file-systems from
 * nfsx_fumount.
 */
static void
amfs_error_umounted(am_node *mp)
{
  /* nothing to do */
}
