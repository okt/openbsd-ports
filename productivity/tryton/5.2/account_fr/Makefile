# $OpenBSD: Makefile,v 1.4 2021/11/02 00:02:01 sthen Exp $

MODPY_EGG_VERSION =	5.2.1
TRYTON_MODULE =		account_fr
REVISION =		1

TRYTON_DEPENDS +=	account \
			party_siret

RUN_DEPENDS +=		devel/py-dateutil${MODPY_FLAVOR}

.include <bsd.port.mk>
