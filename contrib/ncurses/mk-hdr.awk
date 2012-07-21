# $Id: mk-hdr.awk,v 1.1.1.1 2012-07-21 14:51:28 laffer1 Exp $
##############################################################################
# Copyright (c) 2007 Free Software Foundation, Inc.                          #
#                                                                            #
# Permission is hereby granted, free of charge, to any person obtaining a    #
# copy of this software and associated documentation files (the "Software"), #
# to deal in the Software without restriction, including without limitation  #
# the rights to use, copy, modify, merge, publish, distribute, distribute    #
# with modifications, sublicense, and/or sell copies of the Software, and to #
# permit persons to whom the Software is furnished to do so, subject to the  #
# following conditions:                                                      #
#                                                                            #
# The above copyright notice and this permission notice shall be included in #
# all copies or substantial portions of the Software.                        #
#                                                                            #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    #
# THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    #
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        #
# DEALINGS IN THE SOFTWARE.                                                  #
#                                                                            #
# Except as contained in this notice, the name(s) of the above copyright     #
# holders shall not be used in advertising or otherwise to promote the sale, #
# use or other dealings in this Software without prior written               #
# authorization.                                                             #
##############################################################################
#
# Author: Thomas E. Dickey	2007
#
# Generate install/uninstall rules for header files
# Variables:
#	subset	  ("none", "base", "base+ext_funcs" or "termlib", etc.)
#	compat	  ("yes" or "no", flag to add link to curses.h
#
function basename(path) {
	sub(/^.*\//,"",path)
	return path;
}
BEGIN	{
		found = 0
		using = 1
		count = 0
	}
	/^@/ {
		using = 0
		if (subset == "none") {
			using = 1
		} else if (index(subset,$2) > 0) {
			using = 1
		} else {
			using = 0
		}
	}
	/^[@#]/ {
		next
	}
	{
		if (using && NF != 0) {
			if (found == 0) {
				print  ""
				print  "# generated by mk-hdr.awk"
				printf "#  subset:     %s\n", subset 
				printf "#  compat:     %s\n", compat 
				print  ""
				found = 1
			}
			data[count] = $1
			count = count + 1
		}
	}
END	{
		if ( count > 0 )
		{
			print "${DESTDIR}${includedir} :"
			print "	sh ${srcdir}/../mkdirs.sh $@"
			print ""
			print "install \\"
			print "install.libs \\"
			print "install.includes :: ${AUTO_SRC} ${DESTDIR}${includedir} \\"

			for (i = 0; i < count - 1; ++i) {
				printf "		%s \\\n", data[i]
			}
			printf "		%s\n", data[count - 1]

			for (i = 0; i < count; ++i) {
				printf "	@ (cd ${DESTDIR}${includedir} && rm -f %s) ; ../headers.sh ${INSTALL_DATA} ${DESTDIR}${includedir} ${srcdir} %s\n", basename(data[i]), data[i]
				if (data[i] == "curses.h" && compat == "yes") {
					printf "	@ (cd ${DESTDIR}${includedir} && rm -f ncurses.h && ${LN_S} %s ncurses.h)\n", data[i]
				}
			}
			print ""
			print "uninstall \\"
			print "uninstall.libs \\"
			print "uninstall.includes ::"

			for (i = 0; i < count; ++i) {
				printf "	-@ (cd ${DESTDIR}${includedir} && rm -f %s)\n", basename(data[i])
				if (data[i] == "curses.h" && compat == "yes") {
					printf "	-@ (cd ${DESTDIR}${includedir} && rm -f ncurses.h)\n"
				}
			}
		}
	}
# vile:ts=4 sw=4
