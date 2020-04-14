# $FreeBSD$

PORTNAME=	zoom
PORTVERSION=	3.5.385850.0413
CATEGORIES=	net-im linux
MASTER_SITES=	https://zoom.us/client/${PORTVERSION}/
PKGNAMEPREFIX=	linux-c7-
DISTFILES=	${PORTNAME}_x86_64.rpm
SRC_DISTFILES=

MAINTAINER=	eric@metricspace.net
COMMENT=	Popular teleconferencing application

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs pulseaudio-libs sqlite3 alsa-lib xcb-util-image xcb-util-keysyms libxslt libglvnd
USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	amd64
INSTALLS_ICONS=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RESTRICTED=	Redistribution not allowed

.include <bsd.port.mk>
