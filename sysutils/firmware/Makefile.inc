# $OpenBSD: Makefile.inc,v 1.8 2022/01/14 14:20:21 espie Exp $

COMMENT ?=	firmware binary images for ${FW_DRIVER}(4) driver

DISTNAME ?=	${FW_DRIVER}-${FW_VER}
DIST_SUBDIR =	firmware
PKGNAME ?=	${FW_DRIVER}-firmware-${FW_VER}

CATEGORIES +=	sysutils/firmware

PERMIT_PACKAGE ?=   proprietary
PERMIT_DISTFILES ?= proprietary

.if !defined(GH_ACCOUNT)
MASTER_SITES ?=	http://firmware.openbsd.org/firmware-dist/
.endif

PKG_ARCH ?=	*
PREFIX ?=	/etc
NO_BUILD ?=	Yes
NO_TEST ?=	Yes

# XXX fw_update doesn't know what to do with @ts
PKG_ARGS += 	-DNO_TS_IN_PLIST
.if ${PERMIT_PACKAGE:L:Myes}
#
# This is a special-purpose directory. Packages produced from this should
# not be included in package directories on normal mirrors, but only on
# firmware.openbsd.org mirrors and installed by fw_update.
#
# PERMIT_* should be set so that packages produced during bulk builds do
# not get included in the main package directories.
#
ERRORS += "Fatal: packages for fw_update should not have PERMIT_*=Yes"
.endif
