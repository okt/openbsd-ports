# $OpenBSD: Makefile,v 1.15 2021/11/02 00:00:51 sthen Exp $

COMMENT =		converting Jupyter notebooks

MODPY_EGG_VERSION =	5.6.1
DISTNAME =		nbconvert-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		0

CATEGORIES =		devel

HOMEPAGE =		https://jupyter.org/

# BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes
MODPY_PYTEST_ARGS =	nbconvert

FLAVORS =		python3
FLAVOR =		python3

RUN_DEPENDS =		devel/py-entrypoints${MODPY_FLAVOR}>=0.2.2 \
			devel/py-jupyter_core${MODPY_FLAVOR} \
			devel/py-nbformat${MODPY_FLAVOR}>=4.4 \
			devel/py-testpath${MODPY_FLAVOR} \
			devel/py-traitlets${MODPY_FLAVOR}>=4.2 \
			textproc/py-defusedxml${MODPY_FLAVOR} \
			textproc/py-mistune${MODPY_FLAVOR}>=0.8.1 \
			textproc/py-pandocfilters${MODPY_FLAVOR}>=1.4.1 \
			textproc/py-pygments${MODPY_FLAVOR} \
			www/py-bleach${MODPY_FLAVOR} \
			www/py-jinja2${MODPY_FLAVOR}>2.4
TEST_DEPENDS =		${BASE_PKGPATH}=${MODPY_EGG_VERSION} \
			devel/py-ipykernel${MODPY_FLAVOR} \
			devel/py-jupyter_client${MODPY_FLAVOR}>=5.3.1 \
			devel/py-nose${MODPY_FLAVOR} \
			devel/py-pebble${MODPY_FLAVOR} \
			www/py-tornado${MODPY_FLAVOR}>=4.0

PORTHOME =		${WRKDIR}

.include <bsd.port.mk>
