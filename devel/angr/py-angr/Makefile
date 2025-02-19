# $OpenBSD: Makefile,v 1.19 2021/11/02 00:00:22 sthen Exp $

COMMENT =	multi-architecture binary analysis toolkit

ANGR_PYTHON_MODULE =	angr
REVISION =		2

HOMEPAGE =	https://angr.io/

WANTLIB =	${COMPILER_LIBCXX} m

# C++11
COMPILER =	base-clang ports-gcc

BUILD_DEPENDS =	devel/angr/py-pyvex>=${MODPY_EGG_VERSION} \
		devel/py-bitstring${MODPY_FLAVOR} \
		devel/py-cffi${MODPY_FLAVOR} \
		devel/py-future${MODPY_FLAVOR}

# AngrServer could use (unported) rpyc
RUN_DEPENDS =	devel/angr/py-ailment>=${MODPY_EGG_VERSION} \
		devel/angr/py-archinfo>=${MODPY_EGG_VERSION} \
		devel/angr/py-claripy>=${MODPY_EGG_VERSION} \
		devel/angr/py-cle>=${MODPY_EGG_VERSION} \
		devel/angr/py-pyvex>=${MODPY_EGG_VERSION} \
		devel/capstone/python${MODPY_FLAVOR} \
		devel/py-bitstring${MODPY_FLAVOR} \
		devel/py-cachetools${MODPY_FLAVOR} \
		devel/py-cffi${MODPY_FLAVOR} \
		devel/py-cooldict${MODPY_FLAVOR} \
		devel/py-cparser${MODPY_FLAVOR} \
		devel/py-future${MODPY_FLAVOR} \
		devel/py-mulpyplexer${MODPY_FLAVOR} \
		devel/py-progressbar${MODPY_FLAVOR} \
		devel/py-protobuf${MODPY_FLAVOR}>=3.9.1 \
		devel/py-sortedcontainers${MODPY_FLAVOR} \
		math/py-networkx${MODPY_FLAVOR} \
		net/py-dpkt${MODPY_FLAVOR} \
		sysutils/py-psutil${MODPY_FLAVOR}

# XXX this is a bit of a mess. angr_native.so actually links against
# /usr/local/lib/pythonXXX/site-packages/unicorn/lib/libunicorn.so
# (which isn't in a place where a linked library would normally be
# found). SONAME in libunicorn.so is "libunicorn.so.1" so the
# lib-depends-check message is a bit unexpected. BDEP+RDEP is the
# simplest way to make it work. LIB_DEPENDS doesn't work because
# it is stripped unless there's a matching WANTLIB and that can't
# be done with an unversioned .so.
BUILD_DEPENDS += devel/py-unicorn${MODPY_FLAVOR}>=1.0.2rc2
RUN_DEPENDS +=	devel/py-unicorn${MODPY_FLAVOR}>=1.0.2rc2

USE_GMAKE =	Yes

MAKE_ENV =	CXX=${CXX} CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include/angr-vex/"

DOCDIR =	${PREFIX}/share/doc/py-${ANGR_PYTHON_MODULE}

pre-configure:
	${SUBST_CMD} ${WRKSRC}/native/Makefile

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCDIR}/

.include <bsd.port.mk>
