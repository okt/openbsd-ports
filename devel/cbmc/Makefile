#$OpenBSD: Makefile,v 1.13 2021/11/30 10:10:06 sthen Exp $

COMMENT =	Bounded Model Checker for C and C++ programs

GH_ACCOUNT =	diffblue
GH_PROJECT =	cbmc
GH_TAGNAME =	cbmc-5.5
PKGNAME =	${GH_TAGNAME}
REVISION =	4

CATEGORIES =	devel

HOMEPAGE =	http://www.cprover.org/cbmc/

MAINTAINER =	Mages Simon <mages.simon@googlemail.com>

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB += c m ${COMPILER_LIBCXX}

DISTFILES =	${GH_DISTFILE} \
		minisat2_2.2.1.orig.tar.gz:0
MASTER_SITES0 =	${MASTER_SITE_DEBIAN:=main/m/minisat2/}

COMPILER =	base-clang ports-clang

BUILD_DEPENDS =	devel/bison

USE_GMAKE =	Yes

MAKE_FLAGS =	CFLAGS="-Wall ${CFLAGS}" \
		CXXFLAGS="-Wall ${CXXFLAGS}" \
		LINKFLAGS="${LDFLAGS}"

WRKSRC =	${WRKDIST}/src

post-extract:
	mv ${WRKDIR}/minisat2-2.2.1 ${WRKDIST}/minisat-2.2.1
	cd ${WRKDIST}/minisat-2.2.1; \
	patch -z .bak -p1 < ../scripts/minisat-2.2.1-patch

do-install:
.for i in goto-analyzer goto-cc goto-diff goto-instrument cbmc
	${INSTALL_PROGRAM} ${WRKBUILD}/${i}/${i} ${PREFIX}/bin/
.endfor
	${INSTALL_MAN} ${WRKDIST}/doc/man/cbmc.1 ${PREFIX}/man/man1/
	cd ${WRKDIST}/doc/ && find . -type d -exec ${INSTALL_DATA_DIR} \
		${PREFIX}/share/doc/cbmc/{} \;
	cd ${WRKDIST}/doc/ && find . -type f -exec ${INSTALL_DATA} \
		${WRKDIST}/doc/{} ${PREFIX}/share/doc/cbmc/{} \;
	rm ${PREFIX}/share/doc/cbmc/man/cbmc.1
	rmdir ${PREFIX}/share/doc/cbmc/man/

.include <bsd.port.mk>
