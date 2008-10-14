# $FreeBSD: src/share/mk/bsd.compat.mk,v 1.20 2005/03/02 11:53:21 trhodes Exp $
# $MidnightBSD: src/share/mk/bsd.compat.mk,v 1.2 2006/05/22 06:03:21 laffer1 Exp $

.if !defined(BURN_BRIDGES)
.for oldnew in \
	NOATM:NO_ATM \
	NOCLEANDIR:NO_CLEANDIR \
	NOCRYPT:NO_CRYPT \
	NODOCCOMPRESS:NO_DOCCOMPRESS \
	NOEXTRADEPEND:NO_EXTRADEPEND \
	NOFORTH:NO_FORTH \
	NOFSCHG:NO_FSCHG \
	NOGAMES:NO_GAMES \
	NOHTML:NO_HTML \
	NOINET6:NO_INET6 \
	NOINFO:NO_INFO \
	NOINFOCOMPRESS:NO_INFOCOMPRESS \
	NOINSTALLLIB:NO_INSTALLLIB \
	NOLIBPTHREAD:NO_LIBPTHREAD \
	NOLIBTHR:NO_LIBTHR \
	NOLINT:NO_LINT \
	NOMAN:NO_MAN \
	NOMANCOMPRESS:NO_MANCOMPRESS \
	NOMLINKS:NO_MLINKS \
	NOOBJ:NO_OBJ \
	NOPAM:NO_PAM \
	NOPIC:NO_PIC \
	NOPROFILE:NO_PROFILE \
	NO_RCMNDS:NO_RCMDS \
	NOSHARE:NO_SHARE \
	NOSHARED:NO_SHARED \
	NOTAGS:NO_TAGS
.for old in ${oldnew:C/:.*//}
.for new in ${oldnew:C/.*://}
.if defined(${old}) && !defined(${new})
.warning ${old} is deprecated in favour of ${new}
${new}=	${${old}}
.endif
.endfor
.endfor
.endfor
.endif
