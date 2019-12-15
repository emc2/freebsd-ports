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
ALL_TARGET=	package
SCALA_VERSION=	2.12
SCALA_DIR=	scala-${SCALA_VERSION}
CHISEL_JAR=	chisel3_${SCALA_VERSION}-${PORTVERSION}.jar
SHARE_DIR=	usr/local/share
CHISEL3_DIR=    ${SHARE_DIR}/chisel3
JAR_DIR=	${CHISEL3_DIR}/${SCALA_DIR}

PLIST_SUB=	SCALA_VERSION=${SCALA_VERSION} \
		PORTVERSION=${PORTVERSION}

pre-install:
	mkdir	${STAGEDIR}/${CHISEL3_DIR}
	mkdir	${STAGEDIR}/${JAR_DIR}

do-install:
	install -C -m 644 -g wheel ${WRKSRC}/target/${SCALA_DIR}/${CHISEL_JAR} ${STAGEDIR}/${JAR_DIR}
	${RLN} ${STAGEDIR}/${JAR_DIR}/${CHISEL_JAR} ${STAGEDIR}/${CHISEL3_DIR}/chisel3.jar

.include <bsd.port.mk>

