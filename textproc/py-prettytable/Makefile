# $OpenBSD: Makefile,v 1.18 2021/11/02 00:02:39 sthen Exp $

COMMENT =	Python library for pretty-printing tabular data

MODPY_EGG_VERSION =	0.7.2
DISTNAME =		prettytable-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
CATEGORIES =		textproc devel
REVISION =		6

MAINTAINER =	Edd Barrett <edd@openbsd.org>

MASTER_SITES =	${MASTER_SITE_GOOGLECODE:=prettytable/}
HOMEPAGE =	https://code.google.com/p/prettytable/

FLAVOR =	python3
FLAVORS =	python3

# 3 clause BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes

post-install:
	chmod -R a+r ${PREFIX}/lib/python${MODPY_VERSION}/site-packages/prettytable-${MODPY_EGG_VERSION}-py${MODPY_VERSION}.egg-info/

.include <bsd.port.mk>
