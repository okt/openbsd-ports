# $OpenBSD: Makefile,v 1.33 2021/10/25 12:33:19 sthen Exp $

COMMENT=	PHP support for rar archives

DISTNAME=	rar-4.2.0
CATEGORIES=	archivers
REVISION=	1

# PHP
PERMIT_PACKAGE=	Yes

WANTLIB=	c m ${COMPILER_LIBCXX}

COMPILER =		base-clang ports-gcc base-gcc

MODULES=	lang/php/pecl
CONFIGURE_STYLE= gnu

.include <bsd.port.mk>
