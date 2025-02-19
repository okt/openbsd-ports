# $OpenBSD: Makefile,v 1.11 2022/01/05 08:02:50 rsadowski Exp $

COMMENT =	PIM Akonadi calendar support library
DISTNAME =	akonadi-calendar-${VERSION}
CATEGORIES =	devel

SHARED_LIBS +=  KF5AkonadiCalendar     2.0 # 5.6

WANTLIB += ${COMPILER_LIBCXX} Grantlee_Templates KF5AkonadiContact
WANTLIB += KF5AkonadiCore KF5AkonadiMime KF5AkonadiWidgets KF5Auth
WANTLIB += KF5AuthCore KF5CalendarCore KF5CalendarUtils KF5Codecs
WANTLIB += KF5Completion KF5ConfigCore KF5ConfigGui KF5ConfigWidgets
WANTLIB += KF5Contacts KF5CoreAddons KF5GrantleeTheme KF5I18n
WANTLIB += KF5IdentityManagement KF5ItemModels KF5JobWidgets KF5KIOCore
WANTLIB += KF5KIOGui KF5KIOWidgets KF5MailTransport KF5MailTransportAkonadi
WANTLIB += KF5Mime KF5PimTextEdit KF5Service KF5Solid KF5Wallet
WANTLIB += KF5WidgetsAddons KF5WindowSystem KF5XmlGui Qt5Concurrent
WANTLIB += Qt5Core Qt5DBus Qt5Gui Qt5Network Qt5Widgets Qt5Xml
WANTLIB += X11 m

MODKDE5_TRANSLATIONS = yes

BUILD_DEPENDS =	devel/boost

LIB_DEPENDS +=	devel/kf5/kauth \
		devel/kf5/kcalendarcore \
		devel/kf5/kcodecs \
		devel/kf5/kconfig \
		devel/kf5/kconfigwidgets \
		devel/kf5/kcontacts \
		devel/kf5/kwindowsystem \
		devel/kf5/ki18n \
		devel/kf5/kio \
		devel/kf5/kitemmodels \
		devel/kf5/kjobwidgets \
		devel/kf5/kservice \
		devel/kf5/kwallet \
		devel/kf5/kwidgetsaddons \
		devel/kf5/kxmlgui \
		x11/kde-applications/akonadi \
		x11/kde-applications/akonadi-contacts \
		x11/kde-applications/kcalutils \
		x11/kde-applications/kidentitymanagement \
		x11/kde-applications/kmailtransport \
		x11/kde-applications/kmime

TEST_IS_INTERACTIVE =	X11

.include <bsd.port.mk>
