# Created by: Eric McCorkle <eric@metricspace.net>
# $FreeBSD$

PORTNAME=	xcb-util
PORTVERSION=	0.4.0
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Convenience libraries sitting on top of libxcb (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

USES=		linux:c7
USE_LINUX=	xorglibs
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
