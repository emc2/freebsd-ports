PORTNAME=       firrtl
PORTVERSION=    1.2.1
PORTREVISION=   0
CATEGORIES=     cad
MASTER_SITES=   GH
GH_ACCOUNT=     freechipsproject
GH_PROJECT=     ${PORTNAME}
DISTVERSIONPREFIX=      v
USE_GITHUB=     yes

MAINTAINER=     eric@metricspace.net
COMMENT=        Scala-based hardware definition language

LICENSE=        BSD

BUILD_DEPENDS=  ${LOCALBASE}/bin/scalac:lang/scala \
                ${LOCALBASE}/bin/sbt:devel/sbt

USES=           tar:tgz gmake                                    
NO_ARCH=        yes
USE_JAVA=       yes
ALL_TARGET=	build

SCALA_VERSION=	2.12
FIRRTL_JAR=	firrtl_${SCALA_VERSION}-${PORTVERSION}.jar
SCALA_DIR=	scala-${SCALA_VERSION}
SHARE_DIR=	usr/local/share
FIRRTL_DIR=	${SHARE_DIR}/firrtl
JAR_DIR=	${FIRRTL_DIR}/${SCALA_DIR}

PLIST_SUB=	SCALA_VERSION=${SCALA_VERSION} \
		PORTVERSION=${PORTVERSION}

pre-install:
	mkdir ${STAGEDIR}/${FIRRTL_DIR}
	mkdir ${STAGEDIR}/${JAR_DIR}

do-install:
	install -C -m 755 ${WRKSRC}/utils/bin/firrtl ${STAGEDIR}/usr/local/bin
	install -C -m 644 -g wheel ${WRKSRC}/utils/bin/${FIRRTL_JAR} ${STAGEDIR}/${JAR_DIR}
	${RLN} ${STAGEDIR}/${JAR_DIR}/${FIRRTL_JAR} ${STAGEDIR}/${FIRRTL_DIR}/firrtl.jar

.include <bsd.port.mk>

