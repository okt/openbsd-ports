# $OpenBSD: Makefile,v 1.6 2021/11/02 00:02:02 sthen Exp $

MODPY_EGG_VERSION =	5.2.3
TRYTON_MODULE =		account_statement
REVISION =		1

TRYTON_DEPENDS +=	account \
			account_invoice \
			bank \
			company \
			currency \
			party

RUN_DEPENDS +=		databases/py-sql${MODPY_FLAVOR}

.include <bsd.port.mk>
