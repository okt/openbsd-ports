# $OpenBSD: Makefile,v 1.20 2022/02/02 08:08:41 landry Exp $

COMMENT =	mesh data abstration library

GH_ACCOUNT=	lutraconsulting
GH_PROJECT =	MDAL
GH_TAGNAME =	release-0.9.3

PKGNAME =	${GH_PROJECT:L}-${GH_TAGNAME:S/release-//}

SHARED_LIBS =	mdal 6.2

CATEGORIES =	geo devel textproc

HOMEPAGE =	http://www.mdal.xyz/

MAINTAINER =	Landry Breuil <landry@openbsd.org>

# BSD
PERMIT_PACKAGE =	Yes

MODULES =	devel/cmake

# uses std=gnu++11
COMPILER =	base-clang ports-gcc

# needs a version of netcdf with nc_inq_varids
LIB_DEPENDS =	math/netcdf>=4 \
		geo/gdal

BUILD_DEPENDS =	devel/gtest

CONFIGURE_ARGS=	-DCMAKE_CXX_FLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

WANTLIB += ${COMPILER_LIBCXX} c gdal hdf5 m netcdf sqlite3 xml2 z

post-extract:
	rm ${WRKSRC}/cmake/FindSQLite3.cmake

.include <bsd.port.mk>
