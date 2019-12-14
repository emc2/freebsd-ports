PORTNAME=       chisel3
PORTVERSION=    3.2.1
PORTREVISION=   0
CATEGORIES=     cad
MASTER_SITES=   GH
GH_ACCOUNT=	freechipsproject
GH_PROJECT=	${PORTNAME}
DISTVERSIONPREFIX=	v
USE_GITHUB=	yes

MAINTAINER=     eric@metricspace.net
COMMENT=        Scala-based hardware definition language

LICENSE=        BSD

BUILD_DEPENDS=  ${LOCALBASE}/bin/scalac:lang/scala \
                ${LOCALBASE}/bin/sbt:devel/sbt

USES=           tar:tgz gmake
NO_ARCH=        yes
USE_JAVA=       yes
ALL_TARGET=	compile
INSTALL_TARGET=	publish-local

.include <bsd.port.mk>

