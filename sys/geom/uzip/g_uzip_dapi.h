/* $MidnightBSD$ */
/*-
 * Copyright (c) 2006-2016 Maxim Sobolev <sobomax@FreeBSD.org>
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: stable/10/sys/geom/uzip/g_uzip_dapi.h 303167 2016-07-21 23:49:26Z sobomax $
 */

struct g_uzip_dapi;

DEFINE_RAW_METHOD(g_uzip_dapi_decompress, int, struct g_uzip_dapi *,
    const char *, void *, size_t, void *);
DEFINE_RAW_METHOD(g_uzip_dapi_free, void, struct g_uzip_dapi *);
DEFINE_RAW_METHOD(g_uzip_dapi_rewind, int, struct g_uzip_dapi *, const char *);

struct g_uzip_dapi {
	g_uzip_dapi_decompress_t decompress;
	g_uzip_dapi_free_t free;
	g_uzip_dapi_rewind_t rewind;
	void *pvt;
	int max_blen;
};
