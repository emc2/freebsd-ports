# Created by: Hsin-Hsiung Chang
# $FreeBSD$

PORTNAME=	mailmgr
PORTVERSION=	1.2.3
CATEGORIES=	mail
MASTER_SITES=	http://sarg.sourceforge.net/

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Sendmail Analysis Report Generator

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mailmgr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mailmgr.conf \
		${STAGEDIR}${PREFIX}/etc/mailmgr.conf.sample

.include <bsd.port.mk>
