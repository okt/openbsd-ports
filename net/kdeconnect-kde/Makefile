# $OpenBSD: Makefile,v 1.7 2021/11/30 17:19:22 rsadowski Exp $

COMMENT =	KDE app that allows your devices to communicate

DISTNAME =	kdeconnect-kde-${MODKDE_VERSION}

SHARED_LIBS +=	kdeconnectcore		2.0 # 1.4
SHARED_LIBS +=	kdeconnectinterfaces	2.0 # 1.4
SHARED_LIBS +=	kdeconnectpluginkcm	0.0 # 1.4

CATEGORIES =	net

HOMEPAGE =	https://kdeconnect.kde.org

MAINTAINER =	Ingo Feinerer <feinerer@logic.at>

# GPLv2+
PERMIT_PACKAGE = Yes

WANTLIB += ${COMPILER_LIBCXX} ICE KF5Auth KF5AuthCore KF5Bookmarks
WANTLIB += KF5Codecs KF5Completion KF5ConfigCore KF5ConfigGui
WANTLIB += KF5ConfigWidgets KF5CoreAddons KF5DBusAddons KF5I18n
WANTLIB += KF5IconThemes KF5ItemViews KF5JobWidgets KF5KCMUtils
WANTLIB += KF5KIOCore KF5KIOFileWidgets KF5KIOGui KF5KIONTLM KF5KIOWidgets
WANTLIB += KF5Notifications KF5People KF5Service KF5Solid KF5WaylandClient
WANTLIB += KF5WidgetsAddons KF5WindowSystem KF5XmlGui Qt5Concurrent
WANTLIB += Qt5Core Qt5DBus Qt5Gui Qt5Network Qt5Qml Qt5QmlModels
WANTLIB += Qt5Quick Qt5QuickControls2 Qt5WaylandClient Qt5Widgets
WANTLIB += Qt5X11Extras Qt5Xml SM X11 Xext Xtst c fakekey m qca-qt5
WANTLIB += wayland-client

MASTER_SITES =	${MASTER_SITE_KDE:=stable/release-service/${MODKDE_VERSION}/src/}

MODULES =	x11/kde-applications \
		devel/kf5 \
		lang/python

BUILD_DEPENDS =	devel/gettext,-tools \
		devel/kf5/qqc2-desktop-style \
		devel/kf5/kirigami2

RUN_DEPENDS =	devel/desktop-file-utils \
		devel/kf5/breeze-icons \
		devel/kf5/kirigami2 \
		devel/kf5/qqc2-desktop-style \
		sysutils/sshfs-fuse \
		sysutils/sshpass \
		x11/gtk+3,-guic

LIB_DEPENDS =	devel/kf5/kauth \
		devel/kf5/kbookmarks \
		devel/kf5/kcmutils \
		devel/kf5/kcodecs \
		devel/kf5/kcompletion \
		devel/kf5/kconfig \
		devel/kf5/kconfigwidgets \
		devel/kf5/kcoreaddons \
		devel/kf5/kdbusaddons \
		devel/kf5/ki18n \
		devel/kf5/kiconthemes \
		devel/kf5/kio \
		devel/kf5/kitemviews \
		devel/kf5/kjobwidgets \
		devel/kf5/knotifications \
		devel/kf5/kpeople \
		devel/kf5/kpeople \
		devel/kf5/kservice \
		devel/kf5/kwayland \
		devel/kf5/kwidgetsaddons \
		devel/kf5/kxmlgui \
		devel/kf5/solid \
		security/qca-qt5 \
		x11/libfakekey \
		x11/qt5/qtdeclarative \
		x11/qt5/qtquickcontrols2 \
		x11/qt5/qtwayland \
		x11/qt5/qtx11extras

MODPY_ADJ_FILES =	nautilus-extension/kdeconnect-share.py

pre-configure:
	${SUBST_CMD} ${WRKSRC}/plugins/sftp/mounter.cpp

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/nautilus-python/extensions

.include <bsd.port.mk>
