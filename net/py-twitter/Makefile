# $OpenBSD: Makefile,v 1.17 2021/11/02 00:01:42 sthen Exp $

COMMENT=		twitter python module

MODPY_EGG_VERSION=	1.18.0
DISTNAME=		twitter-${MODPY_EGG_VERSION}
PKGNAME=		py-twitter-${MODPY_EGG_VERSION}
REVISION=		1

CATEGORIES=		net www

HOMEPAGE=		https://mike.verdone.ca/twitter/
MAINTAINER=		Daniel Winters <daniel@tydirium.org>

# MIT
PERMIT_PACKAGE=	Yes

MODPY_PI=		Yes

MODULES=		lang/python

MODPY_SETUPTOOLS=	Yes
FLAVORS=		python3
FLAVOR=			python3

RUN_DEPENDS=		net/py-irclib${MODPY_FLAVOR}
BUILD_DEPENDS=		${RUN_DEPENDS}
TEST_DEPENDS=		devel/py-nose${MODPY_FLAVOR}

.include <bsd.port.mk>
