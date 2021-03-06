# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$
# Check v4l_compat and v4l-utils slave ports

PORTNAME?=	libv4l
PORTVERSION=	1.18.0
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/v4l-utils/:master \
		http://www.selasky.org/hans_petter/distfiles/:local \
		http://home.selasky.org/distfiles/:local
WEBCAMDVERSION=	5.7.1.1
DISTFILES=	v4l-utils-${PORTVERSION}.tar.bz2:master \
		webcamd-${WEBCAMDVERSION}.tar.bz2:local

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Video4Linux library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

USES=		tar:bzip2
WRKSRC=		${WRKDIR}/v4l-utils-${PORTVERSION}

.if ${PORTNAME} == v4l-utils || ${PORTNAME} == libv4l
LIB_DEPENDS+=	libargp.so:devel/argp-standalone \
		libudev.so:devel/libudev-devd
BUILD_DEPENDS+= gsed>0:textproc/gsed \
		v4l_compat>=${PORTVERSION}:multimedia/v4l_compat

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	\
	--disable-qv4l2 \
	--disable-qvidcap \
	--disable-nls
BINARY_ALIAS=	sed=gsed
INSTALL_TARGET=	install-strip
.endif

.if ${PORTNAME} == v4l_compat
RUN_DEPENDS+=	evdev-proto>=5.3:devel/evdev-proto
.endif

.if ${PORTNAME} == v4l-utils
USES+=		perl5
BUILD_DEPENDS+=	libv4l>=${PORTVERSION}:multimedia/libv4l
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim \
		libv4l2.so:multimedia/libv4l
LDFLAGS+=	-lepoll-shim
CONFIGURE_ARGS+= \
	--enable-v4l-utils \
	--without-v4l2-compliance
.endif

.if ${PORTNAME} == libv4l
CONFIGURE_ENV+= \
	libudev_CFLAGS=" "
CONFIGURE_ARGS+= \
	--disable-v4l-utils \
	--enable-dyn-libv4l \
	--enable-libdvbv5
.endif

post-patch:
# Remove old FreeBSD include files (to be removed upstream)
	@${RM} -r ${WRKDIR}/v4l-utils-${PORTVERSION}/contrib/freebsd/include/*
# Apply webcamd patches first
	@(cd ${WRKDIR}/webcamd-${WEBCAMDVERSION}/patches && ${SH} ./do_patch.sh)
# Patch all source files
	@${FIND} ${WRKDIR} -type f \( -iname "*.[ch]" -or -iname "*.cpp" -or -iname "msg2ctl.pl" \) | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
			-e 's|__inline__|inline|g' \
			-e 's|__u8|uint8_t|g' \
			-e 's|__s8|int8_t|g' \
			-e 's|__le16|uint16_t|g' \
			-e 's|__be16|uint16_t|g' \
			-e 's|__u16|uint16_t|g' \
			-e 's|__s16|int16_t|g' \
			-e 's|__le32|uint32_t|g' \
			-e 's|__be32|uint32_t|g' \
			-e 's|__u32|uint32_t|g' \
			-e 's|__s32|int32_t|g' \
			-e 's|__le64|uint64_t|g' \
			-e 's|__be64|uint64_t|g' \
			-e 's|__u64|uint64_t|g' \
			-e 's|__s64|int64_t|g' \
			-e 's|uint16_t_to_cpu|letoh16|g' \
			-e 's|uint32_t_to_cpu|letoh32|g' \
			-e 's|uint64_t_to_cpu|letoh64|g' \
			-e 's|error_t|int|g' \
			-e 's|"gettext.h"|<stdio.h>|g' \
			-e 's|MSG_MORE|0|g' \
			-e 's|EBADR|EFAULT|g' \
			-e 's|ENONET|EHOSTDOWN|g' \
			-e 's|_IOC_READ|IOC_OUT|g' \
			-e 's|_IOC_WRITE|IOC_IN|g' \
			-e 's|_IOC_NONE|IOC_VOID|g' \
			-e 's|<endian.h>|<sys/endian.h>|g' \
			-e 's|<linux/compiler.h>|<sys/cdefs.h>|g' \
			-e 's|<linux/errno.h>|<errno.h>|g' \
			-e 's|<linux/ioctl.h>|<sys/ioctl.h>|g' \
			-e '/^.*\<linux\/kernel.h\>.*/d' \
			-e 's|<linux/string.h>|<string.h>|g' \
			-e 's|<linux/sysmacros.h>|<sys/types.h>|g' \
			-e 's|<malloc.h>|<stdlib.h>|g' \
			-e 's|<sys/epoll.h>|<libepoll-shim/sys/epoll.h>|g' \
			-e 's|<sys/sysmacros.h>|<sys/types.h>|g' \
			-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
			-e 's|__user||g'

# Duplicate some files to avoid patching
	@${CP} ${WRKSRC}/utils/common/ir-encode.c ${WRKSRC}/utils/ir-ctl/ir-encode.c
	@${CP} ${WRKSRC}/utils/common/ir-encode.c ${WRKSRC}/utils/keytable/ir-encode.c
	@${CP} ${WRKSRC}/utils/common/keymap.h ${WRKSRC}/utils/ir-ctl/keymap.h
	@${CP} ${WRKSRC}/utils/common/keymap.h ${WRKSRC}/utils/keytable/keymap.h

.include <bsd.port.mk>
