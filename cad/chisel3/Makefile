PORTNAME=       chisel3
PORTVERSION=    3.1.7
PORTREVISION=   0
CATEGORIES=     cad
MASTER_SITES=   GH
GH_ACCOUNT=	freechipsproject
GT_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=     eric@metricspace.net
COMMENT=        Scala-based hardware definition language

LICENSE=        BSD

BUILD_DEPENDS=  ${LOCALBASE}/bin/scalac:lang/scala \
                ${LOCALBASE}/bin/sbt:devel/sbt

#USES=           tar:tgz
NO_ARCH=        yes
USE_JAVA=       yes
#WRKSRC=         ${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>

