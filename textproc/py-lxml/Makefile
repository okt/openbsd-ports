# $OpenBSD: Makefile,v 1.40 2021/11/14 12:05:58 sthen Exp $

BROKEN-hppa=	OOM on src/lxml/lxml.etree.c

COMMENT=	Python binding for the libxml2 and libxslt libraries

MODPY_EGG_VERSION=	4.6.4
DISTNAME=	lxml-${MODPY_EGG_VERSION}
PKGNAME=	py-lxml-${MODPY_EGG_VERSION}

CATEGORIES=	textproc devel

HOMEPAGE=	https://lxml.de/

# BSD
PERMIT_PACKAGE=	Yes

WANTLIB=	${MODPY_WANTLIB} exslt m pthread xml2 xslt z

MODULES=	lang/python

LIB_DEPENDS=	textproc/libxslt
TEST_DEPENDS=	textproc/py-cssselect${MODPY_FLAVOR}

MODPY_PI=	Yes
MODPY_SETUPTOOLS=Yes
MODPY_PYTEST=	Yes

FLAVORS=	python3
FLAVOR?=

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${MODPY_PY_PREFIX}lxml
	@cp -r ${WRKSRC}/doc/* ${PREFIX}/share/doc/${MODPY_PY_PREFIX}lxml/

pre-test:
	cd ${WRKSRC} && cp lib.openbsd-*/lxml/*.so src/lxml

.include <bsd.port.mk>
