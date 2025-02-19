# $OpenBSD: Makefile,v 1.16 2021/08/29 08:17:23 jasper Exp $

COMMENT=		automated hinting process based on FreeType's autohinter #'

DISTNAME =		ttfautohint-1.8.4
SHARED_LIBS +=  ttfautohint               0.0 # 1.0
CATEGORIES =		graphics

HOMEPAGE =		https://www.freetype.org/ttfautohint/#download

# FreeType License or GPLv2
PERMIT_PACKAGE =	Yes

MASTER_SITES =		${MASTER_SITE_SAVANNAH:=/freetype/}

COMPILER =		base-clang ports-gcc

WANTLIB += c freetype glib-2.0 graphite2 harfbuzz iconv intl m pthread
WANTLIB += pcre z ${COMPILER_LIBCXX}

LIB_DEPENDS =		devel/harfbuzz

USE_GMAKE =		Yes
CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--without-doc \
			--without-qt

# gnulib problem: autoconf tests run with -std=gnu99, which hides the
# max_align_t definition (like it should), but then some of the code gets
# compiled with -std=gnu++11, which exposes the definition.
#
# https://lists.gnu.org/archive/html/bug-gnulib/2016-04/msg00003.html

CONFIGURE_ENV =		ac_cv_type_max_align_t=yes

.include <bsd.port.mk>
