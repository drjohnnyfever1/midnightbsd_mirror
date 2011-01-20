/*
 * Copyright (c) 2007-2009 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SUDO_USAGE_H
#define _SUDO_USAGE_H

void usage __P((int)) __attribute__((__noreturn__));

/*
 * Usage strings for sudo.  These are here because we
 * need to be able to substitute values from configure.
 */
#define SUDO_USAGE1 " -h | -K | -k | -L | -V"
#define SUDO_USAGE2 " -v [-AknS] [-g groupname|#gid] [-p prompt] [-u user name|#uid]"
#define SUDO_USAGE3 " -l[l] [-AknS] [-g groupname|#gid] [-p prompt] [-U user name] [-u user name|#uid] [-g groupname|#gid] [command]"
#define SUDO_USAGE4 " [-AbEHknPS] [-C fd] [-c class|-] [-g groupname|#gid] [-p prompt] [-u user name|#uid] [-g groupname|#gid] [VAR=value] [-i|-s] [<command>]"
#define SUDO_USAGE5 " -e [-AknS] [-C fd] [-c class|-] [-g groupname|#gid] [-p prompt] [-u user name|#uid] file ..."

/*
 * Configure script arguments used to build sudo.
 */
#define CONFIGURE_ARGS "--with-all-insults --build=i386-midnightbsd-freebsd7.0"

#endif /* _SUDO_USAGE_H */
