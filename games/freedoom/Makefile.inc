# $OpenBSD: Makefile.inc,v 1.4 2021/10/14 16:08:54 sdk Exp $

COMMENT =	free content game based on the Doom engine

V ?=		0.12.1
DISTNAME ?=	${DOOM_PROJECT}-$V
REVISION =	0

CATEGORIES ?=	games

HOMEPAGE ?=	https://freedoom.github.io/

# BSD 3-clause
PERMIT_PACKAGE ?=	Yes

MASTER_SITES =		https://github.com/freedoom/freedoom/releases/download/v$V/

EXTRACT_SUFX ?=		.zip

NO_BUILD ?=		Yes
NO_TEST ?=		Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${DOOM_PROJECT}
	${INSTALL_DATA} ${WRKDIST}/*.txt ${WRKDIST}/*.html ${WRKDIST}/*.pdf \
		${PREFIX}/share/doc/${DOOM_PROJECT}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doom
	${INSTALL_DATA} ${WRKDIST}/*.wad ${PREFIX}/share/doom
