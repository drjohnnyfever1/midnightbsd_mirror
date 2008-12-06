/* $MidnightBSD: src/usr.bin/batt/batt.c,v 1.2 2008/12/06 15:03:28 laffer1 Exp $ */
/*- 
 * Copyright (c) 2008 Lucas Holt
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

#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdio.h>
#include <unistd.h>

static void	usage();

int 
main(int argc, char *argv[])
{
	int life, time, units;
	size_t len;
	int ch, lflag, tflag, uflag;

	lflag = tflag = uflag = 0;
	while ((ch = getopt(argc, argv, "ltu")) != -1) {
		switch (ch) {
			case 'l':
				lflag = 1;
				break;
			case 't':
				tflag = 1;
				break;
			case 'u':
				uflag = 1;
				break;
			case '?': /* FALLTHROUGH */
			default:
				usage();
				/* NOTREACHED */
		}
	}
	argc -= optind;
	argv += optind;

	/* if no flags are set, use the most likely */
	if (lflag == tflag == uflag == 0)
		lflag = tflag = 1;

	if (lflag) {
		len = sizeof(life);
		if (sysctlbyname("hw.acpi.battery.life", &life, &len, NULL, 0) < 0)
			err(1, "ACPI not loaded or no battery found.");
		printf("%d%% capacity\n", life);
	}

	if (tflag) {
		len = sizeof(time);
		if (sysctlbyname("hw.acpi.battery.time", &time, &len, NULL, 0) < 0)
			err(1, "ACPI not loaded or no battery found.");
		if (time < 1)
			printf("Battery charging or drained.\n");
		else if (time == 1)
			printf("1 minute remaining\n");
		else
			printf("%d minutes remaining\n", time);
	}

	if (uflag) {
		len = sizeof(units);
        	if (sysctlbyname("hw.acpi.battery.units", &units, &len, NULL, 0) < 0)
                	err(1, "ACPI not loaded or no battery found.");
		if (units == 1)
			printf("1 battery\n");
        	else
			printf("%d batteries\n", units);
	}

	return (0);
}

static void
usage()
{

	fprintf(stderr, "usage: batt [-ltf]\n");
	exit(1);
}
