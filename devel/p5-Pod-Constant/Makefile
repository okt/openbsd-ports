# $OpenBSD: Makefile,v 1.5 2021/03/07 22:45:21 afresh1 Exp $

COMMENT =		source constants from POD to avoid repetition

DISTNAME =		Pod-Constant-0.1
REVISION =		1

CATEGORIES =		devel

MAINTAINER =		Alexander Bluhm <bluhm@openbsd.org>

# perl
PERMIT_PACKAGE =	Yes

MODULES =		cpan
PKG_ARCH =		*
RUN_DEPENDS =		textproc/p5-Pod-Parser
TEST_DEPENDS =		devel/p5-Test-Exception \
			devel/p5-Test-NoTabs \
			devel/p5-Test-Pod>=1.41 \
			devel/p5-Test-Warn

.include <bsd.port.mk>
