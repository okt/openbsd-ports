# $OpenBSD: Makefile,v 1.8 2021/11/02 00:00:26 sthen Exp $

COMMENT =	decorator for caching properties in classes

MODPY_EGG_VERSION = 1.5.1
DISTNAME =	cached-property-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}
REVISION =	4

CATEGORIES =	devel

MAINTAINER =	Sebastien Marie <semarie@online.fr>

# BSD
PERMIT_PACKAGE=	Yes

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

FLAVORS =	python3
FLAVOR =	python3

TEST_DEPENDS +=		devel/py-freezegun${MODPY_FLAVOR} \
			devel/py-dateutil${MODPY_FLAVOR}

.include <bsd.port.mk>
