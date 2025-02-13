# $OpenBSD: Makefile,v 1.74 2022/01/17 13:09:21 tobhe Exp $

COMMENT=		vector graphics library

DISTNAME=		cairo-1.17.4
REVISION=		1

CATEGORIES=		graphics
DPB_PROPERTIES=		parallel
EXTRACT_SUFX=		.tar.xz

SHARED_LIBS += cairo                     13.1 # 2.11704.0
SHARED_LIBS += cairo-gobject             2.1 # 2.11704.0
SHARED_LIBS += cairo-script-interpreter  2.1 # 2.11704.0

HOMEPAGE=		http://cairographics.org/

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# LGPLv2.1 / MPL 1.1
PERMIT_PACKAGE=	Yes

WANTLIB += X11 Xext Xrender c fontconfig freetype glib-2.0 gobject-2.0
WANTLIB += lzo2 m pixman-1 png pthread xcb xcb-render xcb-shm
WANTLIB += z

MASTER_SITES=		https://cairographics.org/releases/ \
			https://cairographics.org/snapshots/

MODULES=		devel/meson

USE_GMAKE=		Yes

LIB_DEPENDS=		archivers/lzo2 \
			devel/glib2 \
			graphics/png

CONFIGURE_ARGS=		-Dspectre=disabled \
			-Dtests=disabled

# needed for arch with ld.bfd 
CONFIGURE_ENV=		LDFLAGS="-L/usr/X11R6/lib"

# needed for firefox
CONFIGURE_ARGS +=	-Dtee=enabled

# XXX fatal error: 'lzo/lzo2a.h' file not found
CFLAGS +=		-I${LOCALBASE}/include

pre-configure:
	${SUBST_CMD} ${WRKSRC}/src/meson.build

# XXX
post-install:
	chmod +x ${PREFIX}/bin/cairo-trace

.include <bsd.port.mk>
