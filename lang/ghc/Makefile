# $OpenBSD: Makefile,v 1.190 2021/11/09 04:48:50 gnezdo Exp $

# Not yet ported to other architectures
ONLY_FOR_ARCHS =	i386 amd64

COMMENT =		compiler for the functional language Haskell

# Note: please never ever set DPB_PROPERTIES=parallel (or some other
# magic that enables parallel builds) for this port! Not even if it
# appears to work. (search the upstream bug tracker for terms like
# "non-deterministic", "unresolved symbol", "signature mismatch" etc. to
# find the appropriate bug tickets)

# ghc hardcodes ${WRKDIR}/bin/gcc when the package is compiled with ccache
NO_CCACHE =		Yes

GHC_VERSION =		8.10.6
DISTNAME =		ghc-${GHC_VERSION}
CATEGORIES =		lang devel
HOMEPAGE =		https://www.haskell.org/ghc/

REVISION =		1

# Version of the precompiled binaries
BIN_VER =		8.10.3.20210429

# lang/python needed for regression tests.
MODULES =		lang/python

MODPY_BUILDDEP =	No
MODPY_RUNDEP =		No

# BSD w/o advertising clause.
# Distfile is bundled with other stuff like libffi, mingw
# binaries, with BSD, GPLv2 and Perl artistic license.
PERMIT_PACKAGE =		Yes

WANTLIB += c curses ffi gmp iconv m pthread util

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

BUILD_DEPENDS =		archivers/bzip2 \
			archivers/gtar \
			textproc/py-sphinx${MODPY_FLAVOR}>=4.0.2
RUN_DEPENDS =

# GHC build uses -Wl,-z,wxneeded on OpenBSD.
# XXX: wxneeded is a hack. Fix rts/Linker.c, mmapForLinker() and
#      loadObj_() instead.
USE_WXNEEDED =		special

MASTER_SITES =		${HOMEPAGE}dist/${GHC_VERSION}/ \
			${HOMEPAGE}dist/stable/dist/
MASTER_SITES0 =		https://openbsd.dead-parrot.de/distfiles/

DIST_SUBDIR =		ghc

BINDISTFILE =		${BINDISTFILE-${MACHINE_ARCH}}

DISTFILES =		ghc-${GHC_VERSION}-src.tar.xz \
			ghc-${GHC_VERSION}-testsuite.tar.xz \
			${BINDISTFILE}

.for m in amd64 i386
BINDISTFILE-$m =	ghc-${BIN_VER}-$m-unknown-openbsd.tar.xz:0 \
			ghc-${BIN_VER}-shlibs-$m.tar.gz:0
SUPDISTFILES +=		${BINDISTFILE-$m}
.endfor

# Substvars for all libraries, assuming that ghc-boot, ghc-boot-th,
# ghc-heap and ghci will always have the same version number as ghc.
GHC_ITEMS = \
        CABAL			3.2.1.0          \
        ARRAY			0.5.4.0    	 \
        BASE			4.14.3.0   	 \
        BINARY			0.8.8.0 	 \
        BYTESTRING		0.10.12.0	 \
        CONTAINERS		0.6.5.1		 \
        DEEPSEQ			1.4.4.0		 \
        DIRECTORY		1.3.6.0		 \
        EXCEPTIONS		0.10.4		 \
        FILEPATH		1.4.2.1		 \
        GHC			8.10.6		 \
        GHC_COMPACT		0.1.0.0		 \
        GHC_PRIM		0.6.1		 \
        HASKELINE		0.8.2		 \
        HPC			0.6.1.0		 \
        INTEGER_GMP		1.0.3.0		 \
        MTL			2.2.2		 \
        PARSEC			3.1.14.0	 \
        PRETTY			1.1.3.6		 \
        PROCESS			1.6.13.2	 \
        STM			2.5.0.1		 \
	TEMPLATE-HASKELL	2.16.0.0	 \
	TERMINFO		0.4.1.4		 \
	TEXT			1.2.4.1		 \
	TIME			1.9.3		 \
	TRANSFORMERS		0.5.6.2		 \
	UNIX			2.7.2.2		 \
	XHTML			3000.2.2.1

.for _i _v in ${GHC_ITEMS}
${_i}_VER =	${_v}
SUBST_VARS +=	${_i}_VER
.endfor

USE_GMAKE =		Yes
USE_GROFF =		Yes

AUTOCONF_VERSION =	2.71
CONFIGURE_STYLE =	gnu autoconf no-autoheader
CONFIGURE_ARGS +=	--with-ffi-includes=${LOCALBASE}/include \
			--with-ffi-libraries=${LOCALBASE}/lib \
			--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib \
			--with-iconv-includes=${LOCALBASE}/include \
			--with-iconv-libraries=${LOCALBASE}/lib \
			--with-system-libffi \
			CC="${CC}"

# Don't autodetect ld.lld. It fails at some point during the build
# with /usr/bin/ld.lld: error: cannot preempt symbol: memcpy
CONFIGURE_ARGS +=	--disable-ld-override

CONFIGURE_ENV += SPHINXBUILD=${LOCALBASE}/bin/sphinx-build${MODPY_BIN_SUFFIX}

# Do not pick up gpatch
CONFIGURE_ENV +=	ac_cv_path_PatchCmd=/usr/bin/patch

# Since ghc-7.10, ghc does not run without HOME defined and pointing to
# a writable directory, which would cause configure to fail (because it
# still builds ghc-pwd). Set HOME to let a 7.10-bootstrapper work.
CONFIGURE_ENV +=	HOME=${PORTHOME}

MAKE_FLAGS +=		StripLibraries=YES \
			INSTALL_BIN_OPTS=-s \
			HSCOLOUR_SRCS=NO \
			BUILD_SPHINX_PDF=NO

# For mktexpk (via dvips when building the PostScript documentation):
PORTHOME =		${WRKDIR}

TEST_DEPENDS =	print/ghostscript/gnu ${MODPY_RUN_DEPENDS}

post-extract:
	cd ${WRKSRC}/libraries/unix && \
	mkdir -p System/OpenBSD && \
	install -m 644 ${FILESDIR}/Process.hsc System/OpenBSD

BOOTSTRAP_SHLIBS =	${WRKDIR}/ghc-${BIN_VER}-shlibs-${MACHINE_ARCH}

# Disables haddock as it runs out of memory on i386.
.if ${MACHINE_ARCH:Mi386}
HADDOCK_DOCS =	NO
PKG_ARGS =	-Dno_i386=0
.else
HADDOCK_DOCS =	YES
PKG_ARGS =	-Dno_i386=1
.endif

post-patch:
	cd ${WRKDIR}/ghc-${BIN_VER} && \
	LD_LIBRARY_PATH=${BOOTSTRAP_SHLIBS} \
	CONFIGURE_ENV=${CONFIGURE_ENV} \
	./configure --prefix=${WRKDIR}/bootstrap CC="${CC}" && \
	LD_LIBRARY_PATH=${BOOTSTRAP_SHLIBS} \
	${MAKE_PROGRAM} install
	rm -rf ${WRKDIR}/ghc-${BIN_VER}
# - Create some wrapper scripts setting LD_LIBRARY_PATH
	cd ${WRKDIR}/bin && \
	for f in $$(ls ../bootstrap/bin); do \
		${INSTALL_SCRIPT} /dev/null $$f && \
		exec > $$f && \
		echo '#!/bin/sh' && \
		echo 'LD_LIBRARY_PATH=${BOOTSTRAP_SHLIBS} \' && \
		printf 'exec ${WRKDIR}/bootstrap/bin/%s "$$@"\n' "$$f"; \
	done
	cp ${WRKSRC}/mk/build.mk{.sample,}
	echo libraries/base_CONFIGURE_OPTS+=--configure-option=--with-libcharset=no >> ${WRKSRC}/mk/build.mk
	echo HADDOCK_DOCS=${HADDOCK_DOCS} >> ${WRKSRC}/mk/build.mk

do-test:
	ulimit -c 0 -n 1024 && \
	cd ${WRKSRC}/testsuite/tests && \
	exec ${SETENV} ${MAKE_ENV} LC_CTYPE=en_US.UTF-8 \
		${MAKE_PROGRAM} ${MAKE_FLAGS} \
		PYTHON="${MODPY_BIN}"



# It doesn't matter whether this is the actual date of the bootstrapper
# build. It's just used to get different distfiles whenever new
# bootstrappers have to be built.
BOOTSTRAP_DATE =	20210429

# Create a bootstrapper. This compiles a stripped-down version of
# ghc and creates a `bindist', i.e. a tarball with binaries that
# can be used for bootstrapping.
bootstrap: patch
	@if [ ! -x ${LOCALBASE}/bin/autoconf-2.69 ]; then \
		echo Please install autoconf-2.69.; \
		false; \
	fi
	@if [ ! -x ${LOCALBASE}/bin/automake-1.4 ]; then \
		echo Please install automake-1.4.; \
		false; \
	fi

	$(_PBUILD) $(MAKE) _bootstrap_prepare

	env CONFIGURE_ENV=RELEASE=NO ${MAKE} configure

	${MAKE} build ALL_TARGET="all binary-dist" \
		AUTOCONF_VERSION=2.69 AUTOMAKE_VERSION=1.4

	$(_PBUILD) $(MAKE) _bootstrap_finish

_bootstrap_prepare:
	echo HSCOLOUR_SRCS=NO > ${WRKSRC}/mk/build.mk
	echo GhcLibHcOpts=-O -fasm >> ${WRKSRC}/mk/build.mk
	echo GhcStage1HcOpts=-O -fasm >> ${WRKSRC}/mk/build.mk
	echo GhcStage2HcOpts=-O -fasm >> ${WRKSRC}/mk/build.mk
	echo SplitObjs=NO >> ${WRKSRC}/mk/build.mk
	echo GhcLibWays=v >> ${WRKSRC}/mk/build.mk
	echo GhcRTSWays=thr >> ${WRKSRC}/mk/build.mk
	echo GhcWithInterpreter=NO >> ${WRKSRC}/mk/build.mk
	echo GhcThreaded=YES >> ${WRKSRC}/mk/build.mk
	echo INTEGER_LIBRARY=integer-simple >> ${WRKSRC}/mk/build.mk
	echo SRC_CC_OPTS+=-g -O0 >> ${WRKSRC}/mk/build.mk
	echo HADDOCK_DOCS=NO >> ${WRKSRC}/mk/build.mk
	echo BUILD_SPHINX_HTML=NO >> ${WRKSRC}/mk/build.mk
	echo BUILD_SPHINX_PDF=NO >> ${WRKSRC}/mk/build.mk
	echo GhcWithSMP=NO >> ${WRKSRC}/mk/build.mk
	echo LD_OPTS=-optl-static -optl-s >> ${WRKSRC}/mk/build.mk
	echo DYNAMIC_GHC_PROGRAMS=No >> ${WRKSRC}/mk/build.mk

	echo ${BOOTSTRAP_DATE} > ${WRKSRC}/VERSION_DATE

_bootstrap_finish:
	mkdir -p ${WRKBUILD}/ghc-${GHC_VERSION}.${BOOTSTRAP_DATE}-shlibs-$$(arch -s)
	ldd ${WRKBUILD}/ghc/stage2/build/tmp/ghc-stage2 | \
	awk '$$NF ~ /^\/usr\/(local\/)?lib\// { print $$NF }' | \
	xargs -J % cp -p % ${WRKBUILD}/ghc-${GHC_VERSION}.${BOOTSTRAP_DATE}-shlibs-$$(arch -s)
	cd ${WRKBUILD} && \
	pax -wzf ghc-${GHC_VERSION}.${BOOTSTRAP_DATE}-shlibs-$$(arch -s){.tar.gz,}

.include <bsd.port.mk>
