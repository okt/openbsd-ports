# $OpenBSD: Makefile,v 1.14 2021/04/24 05:03:22 rsadowski Exp $

COMMENT =	central daemon of KDE workspaces
DISTNAME =	kded-${VERSION}

WANTLIB += ${COMPILER_LIBCXX} KF5ConfigCore KF5CoreAddons KF5Crash
WANTLIB += KF5DBusAddons KF5Service Qt5Core Qt5DBus Qt5Gui Qt5Widgets
WANTLIB += c m

BUILD_DEPENDS =	devel/kf5/kdoctools>=${MODKF5_VERSION}

RUN_DEPENDS =	devel/kf5/kdoctools>=${MODKF5_VERSION} \
		devel/desktop-file-utils

LIB_DEPENDS =	devel/kf5/kconfig>=${MODKF5_VERSION} \
		devel/kf5/kcoreaddons>=${MODKF5_VERSION} \
		devel/kf5/kcrash>=${MODKF5_VERSION} \
		devel/kf5/kdbusaddons>=${MODKF5_VERSION} \
		devel/kf5/kservice>=${MODKF5_VERSION}

.include <bsd.port.mk>
