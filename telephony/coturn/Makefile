# $OpenBSD: Makefile,v 1.10 2022/01/13 10:15:54 tb Exp $

COMMENT =	coturn STUN/TURN server

V =		4.5.2
DISTNAME =	turnserver-${V}
REVISION =	1

CATEGORIES =	telephony

HOMEPAGE =	https://github.com/coturn/coturn

MAINTAINER =		Ingo Feinerer <feinerer@logic.at>

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB += c crypto event_core event_extra event_openssl event_pthreads
WANTLIB += hiredis intl mariadb pq pthread sqlite3 ssl

MASTER_SITES =		http://turnserver.open-sys.org/downloads/v${V}/ \
			http://coturn.net/turnserver/v${V}/

LIB_DEPENDS =		databases/mariadb \
			databases/postgresql \
			databases/sqlite3 \
			devel/gettext,-runtime \
			devel/libevent2 \
			databases/libhiredis

CONFIGURE_STYLE =	simple
CONFIGURE_ARGS =	--localstatedir='${LOCALSTATEDIR}'
# There is no port for MongoDB development libraries and/or headers
CONFIGURE_ENV =		TURN_NO_MONGO=1 \
			TURN_NO_PROMETHEUS=1 \
			TURN_NO_SYSTEMD=1

post-install:
	rm -rf ${PREFIX}/etc
	mv ${WRKINST}${LOCALSTATEDIR}/db/turndb \
		${PREFIX}/share/examples/turnserver

.include <bsd.port.mk>
