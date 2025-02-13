# $OpenBSD: Makefile,v 1.87 2022/01/13 08:07:52 ajacoutot Exp $

COMMENT=		GNOME music playing application

GNOME_PROJECT=		gnome-music
GNOME_VERSION=		41.0
REVISION=		2

# GPLv2+
PERMIT_PACKAGE=		Yes

WANTLIB += gio-2.0 glib-2.0 gobject-2.0

MODULES=		devel/dconf \
			devel/meson \
			lang/python \
			x11/gnome

MODGNOME_TOOLS +=	desktop-file-utils gobject-introspection yelp
MODGNOME_TOOLS +=	gtk-update-icon-cache

MODGNOME_LDFLAGS=	-L${X11BASE}/lib

LIB_DEPENDS=		devel/glib2

BUILD_DEPENDS=		devel/py-gobject3${MODPY_FLAVOR} \
			x11/gnome/grilo-plugins \
			x11/gnome/libdazzle \
			x11/gnome/libmediaart \
			x11/gnome/online-accounts \
			x11/gnome/tracker3 \
			x11/libhandy

RUN_DEPENDS=		devel/py-gobject3${MODPY_FLAVOR} \
			www/py-requests${MODPY_FLAVOR} \
			x11/gnome/grilo-plugins \
			x11/gnome/libdazzle \
			x11/gnome/libmediaart \
			x11/gnome/online-accounts \
			x11/gnome/tracker3 \
			x11/libhandy

# sndio(7) support
RUN_DEPENDS +=		multimedia/gstreamer1/plugins-base

DEBUG_PACKAGES=		${BUILD_PACKAGES}

.include <bsd.port.mk>
