# $OpenBSD: Makefile,v 1.4 2021/11/02 00:02:33 sthen Exp $

COMMENT =	python client for consul

MODPY_EGG_VERSION =	1.1.0

DISTNAME =	python-consul-${MODPY_EGG_VERSION}
PKGNAME =	py-consul-${MODPY_EGG_VERSION}
REVISION =	1

CATEGORIES =	sysutils

HOMEPAGE =	https://python-consul.readthedocs.io

# MIT
PERMIT_PACKAGE =	Yes

MODULES =	lang/python
FLAVOR =	python3
FLAVORS =	python3

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes

RUN_DEPENDS =	www/py-requests${MODPY_FLAVOR} \
		devel/py-six${MODPY_FLAVOR}

# requires pytest-twisted
NO_TEST =	Yes

.include <bsd.port.mk>
