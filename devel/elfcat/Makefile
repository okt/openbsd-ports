# $OpenBSD: Makefile,v 1.1.1.1 2021/11/02 16:36:59 fcambus Exp $

COMMENT =	ELF visualizer, generating HTML files from ELF binaries

GH_ACCOUNT =	ruslashev
GH_PROJECT =	elfcat
GH_TAGNAME =	0.1.8

CATEGORIES =	devel

# zlib
PERMIT_PACKAGE =	Yes

WANTLIB += c c++abi m pthread

MODULES =		devel/cargo

CONFIGURE_STYLE =	cargo

.include <bsd.port.mk>
