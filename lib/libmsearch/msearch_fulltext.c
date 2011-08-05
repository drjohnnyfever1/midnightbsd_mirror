/*-
 * Copyright (c) 2011 Lucas Holt
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
 */

#include <sys/cdefs.h>
__MBSDID("$MidnightBSD: src/lib/libmsearch/msearch_fulltext.c,v 1.2 2011/08/05 02:23:40 laffer1 Exp $");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <magic.h>

#include "msearch_private.h"

#define MAX_INDEX_SIZE 1048576

msearch_fulltext *
msearch_fulltext_open(const char *filename) {
        msearch_fulltext *idx;

        if ((idx = calloc(1, sizeof(msearch_fulltext))) == NULL) {
                return NULL;
        }
        idx->index_file = strdup(filename);

        if (sqlite3_open(filename, &(idx->db)) != SQLITE_OK) {
                sqlite3_close(idx->db);
                return NULL;
        }

        return idx;
}

int
msearch_fulltext_close(msearch_fulltext *idx) {
        if (idx == NULL)
                return -1;
        sqlite3_close(idx->db);
        free(idx->index_file);
        free(idx);

        return 0;
}

int
msearch_fulltext_create(msearch_fulltext *idx) {
        msearch_db_do(idx->db, "CREATE VIRTUAL TABLE data using fts4 (path, textdata, tokenize=porter)");
        return 0;
}

int
msearch_fulltext_index(msearch_fulltext *idx, msearch_index *iidx) {
	sqlite3_stmt *stmt;
	int ret;
	char *pathname;

	ret = msearch_db_prepare(iidx->db, &stmt, "SELECT path FROM files");

	if (ret == 0) {
		while (1) {
			ret = sqlite3_step(stmt);
			if (ret == SQLITE_ROW) {
				pathname = strdup(sqlite3_column_text(stmt, 0));
				msearch_fulltext_index_file(idx, pathname);				
				free(pathname);		
			} else if (ret == SQLITE_DONE)
				break;
		}
	}
	sqlite3_finalize(stmt);

	return 0;
}

int
msearch_fulltext_index_file(msearch_fulltext *idx, const char *path) {
	sqlite3_stmt *stmt;
	size_t len;
	char *filedata;
	FILE *fp;
	struct stat st;
	magic_t magic;
	char *mimetype;

	if (path == NULL)
		return 1;

	if (stat(path, &st) != 0)
		return 1;

	if (st.st_size > MAX_INDEX_SIZE)
		return 2;

	magic = magic_open(MAGIC_MIME);
	magic_load(magic, NULL);
	mimetype = magic_file(magic, path);
	magic_close(magic);
#ifdef DEBUG
	if (mimetype != NULL)
		fprintf(stderr, "magic mime type is %s %s\n", path, mimetype);
	else
		fprintf(stderr, "null mimetype for %s\n", path);
#endif
	if (strcmp("text/plain", mimetype) != 0)
		return 0;

	fp = fopen(path, "r");
	if (fp == NULL) {
		return 1;
	}

	filedata = malloc(st.st_size * sizeof(char));
	if (filedata == NULL) {
		fclose(fp);
		return 1;
	}
	len = fread(filedata, st.st_size, 1, fp);
	if (ferror(fp) != 0 || len == 0) {
		free(filedata);
		fclose(fp);
		return 1;
	}
	filedata[st.st_size -1] = '\0'; 
	fclose(fp);

	fprintf(stderr, "file data: %d `%s`\n", strlen(filedata), filedata);
	if (filedata != NULL && *filedata != '\0') {
		if (sqlite3_prepare_v2(idx->db, "INSERT INTO data VALUES(?,?)", -1, &stmt, 0) != SQLITE_OK)
                                return 4;

		sqlite3_bind_text(stmt, 1, path, strlen(path), SQLITE_TRANSIENT);
		sqlite3_bind_text(stmt, 2, filedata, st.st_size, SQLITE_TRANSIENT);
		if (sqlite3_step(stmt) != SQLITE_DONE) {
                        sqlite3_finalize(stmt);
                        return 4;
                }
                sqlite3_finalize(stmt);
	}

	free(filedata);
	return 0;
}
