# $OpenBSD: Makefile,v 1.18 2021/07/22 23:24:37 jca Exp $

COMMENT =		ZRTP library

DISTNAME =		libzrtp-0.20180617
CATEGORIES =		telephony security
REVISION =		1

# AGPLv3
PERMIT_PACKAGE =	Yes

GH_ACCOUNT =		juha-h
GH_PROJECT =		libzrtp
GH_COMMIT =		9069e4c1828c18d31c2b424f6eaf870cf3b8453f

CONFIGURE_STYLE =	autoreconf
CONFIGURE_ARGS =	--disable-docs
AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.9
AUTORECONF =		./bootstrap.sh

.include <bsd.port.arch.mk>
.if ${PROPERTIES:Mclang}
MAKE_FLAGS += GCCMAGIC2=-lcompiler_rt
.endif

.include <bsd.port.mk>
