# $OpenBSD: Makefile,v 1.18 2021/11/02 00:01:53 sthen Exp $

COMMENT =		simple RPC framework based on GObject system

GH_PROJECT =		libsearpc
# upstream keep on sliding tags to pull in new commits
# this commit is from the "v3.2-latest" tag
GH_COMMIT =		50ff08b03c7cec8e10b35ba438633b9fe08a8d90
DISTNAME =		libsearpc-3.2.0pl20200809
REVISION =		0

SHARED_LIBS +=		searpc		0.0 # 1.2

# LGPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ffi glib-2.0 gobject-2.0 iconv intl jansson pcre pthread

MODULES =		lang/python

LIB_DEPENDS =		devel/glib2 \
			devel/jansson

SEPARATE_BUILD =	Yes
CONFIGURE_STYLE =	autoreconf
CONFIGURE_ARGS +=	--with-python3

MODPY_ADJ_FILES =	lib/searpc-codegen.py pysearpc/pygencode.py

.include <bsd.port.mk>
