# Created by: Eric McCorkle <eric@metricspace.net>
# $FreeBSD$

PORTNAME=	xcb-util-image
PORTVERSION=	0.4.0
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	x11 linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Port of Xlib XImage and XShmImage functions on top of libxcb (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

USES=		linux:c7
USE_LINUX=	xcb-util
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
