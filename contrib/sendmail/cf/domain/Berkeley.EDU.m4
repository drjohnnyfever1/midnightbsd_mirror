divert(-1)
#
# Copyright (c) 1998, 1999 Sendmail, Inc. and its suppliers.
#	All rights reserved.
# Copyright (c) 1983 Eric P. Allman.  All rights reserved.
# Copyright (c) 1988, 1993
#	The Regents of the University of California.  All rights reserved.
#
# By using this file, you agree to the terms and conditions set
# forth in the LICENSE file which can be found at the top level of
# the sendmail distribution.
#
#
divert(0)
VERSIONID(`$Id: Berkeley.EDU.m4,v 1.1.1.1 2006-02-25 02:26:19 laffer1 Exp $')
DOMAIN(berkeley-only)dnl
define(`BITNET_RELAY', `bitnet-relay.Berkeley.EDU')dnl
define(`UUCP_RELAY', `uucp-relay.Berkeley.EDU')dnl
define(`confFORWARD_PATH', `$z/.forward.$w:$z/.forward')dnl
define(`confCW_FILE', `-o /etc/sendmail.cw')dnl
define(`confDONT_INIT_GROUPS', True)dnl
FEATURE(redirect)dnl
FEATURE(use_cw_file)dnl
FEATURE(stickyhost)dnl
