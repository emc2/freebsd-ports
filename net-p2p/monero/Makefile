# $FreeBSD$

PORTNAME=	monero
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p finance

COMMENT=	Private, secure, untraceable, decentralised digital currency

LICENSE=	BSD

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libboost_system.so:devel/boost-all \
		libunbound.so:dns/unbound \
		libminiupnpc.so:net/miniupnpc \
		liblmdb.so:databases/lmdb

USES=	cmake
USE_GITHUB=	yes
GH_ACCOUNT=	monero-project
GH_PROJECT=	monero

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   ******************************************************"
	@${ECHO_MSG} "   * Database backend LMDB uses SYSVIPC.  If you are    *"
	@${ECHO_MSG} "   * running Monero inside a jail, you must explicitly  *"
	@${ECHO_MSG} "   * enable SYSVIPC in the jail (allow.sysvipc) or else *"
	@${ECHO_MSG} "   * Monero will not work properly.                     *"
	@${ECHO_MSG} "   ******************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
