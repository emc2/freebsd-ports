# $FreeBSD$

PORTNAME=	libsnark
#PORTVERSION=	1
#DISTVERSIONPREFIX=	v
CATEGORIES=	math

COMMENT=	C++ library for zkSNARK proofs

LICENSE=	BSD

LIB_DEPENDS=	libsodium.so:security/libsodium
BUILD_DEPENDS=	${PREFIX}/lib/libzm.a:math/ate-pairing \
		gcc:lang/gcc \
		markdown_py:textproc/py-markdown

CC=gcc
CXX=g++
NO_PROCPS=1
NO_GTEST=1
NO_SUPERCOP=1
CURVE=ALT_BN128

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	scipr-lab
GH_PROJECT=	libsnark
GH_TAGNAME=	2e6314a9f7efcd9af1c77669d7d9a229df86a777

.include <bsd.port.mk>
