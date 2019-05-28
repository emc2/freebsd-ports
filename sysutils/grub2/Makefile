# Created by: sem@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2
PORTVERSION=	2.02
PORTREVISION=	15
CATEGORIES=	sysutils
MASTER_SITES=	GNU/grub
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	eric@metricspace.net
COMMENT=	Multiboot boot loader

LICENSE=	GPLv3

BROKEN_i386=	uses amd64 assembly
#DEPRECATED=	Unmaintained (more than five years), not updated (one-and-a-half years), does not build with modern compilers	# PR232961
#EXPIRATION_DATE=2019-02-04

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		gsed:textproc/gsed \
		help2man:misc/help2man
RUN_DEPENDS=	gsed:textproc/gsed

USES=		autoreconf bison cpe gettext gmake tar:xz
USE_GCC=	7	# Fails to build with GCC 8, cf. PR 232961, or clang

GNU_CONFIGURE=	yes
INFO=		grub grub-dev
MAKE_JOBS_UNSAFE=	yes
SSP_UNSAFE=	yes

CPE_PRODUCT=	grub
CPE_VENDOR=	gnu

CONFIGURE_ARGS= --with-unifont --disable-werror --localedir=${PREFIX}/share/locale
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

OPTIONS_DEFINE=	MKFONT FUSE
OPTIONS_RADIO=	PLATFORM
OPTIONS_RADIO_PLATFORM=	PC EFI COREBOOT QEMU
OPTIONS_SUB=	yes
MKFONT_DESC=	Build grub-mkfont (require freetype2)
FUSE_DESC=	Build grub-mount (require FUSE)
PLATFORM_DESC=	Platform
PC_DESC=	Legacy PC BIOS
EFI_DESC=	Extensible Firmware Interface
COREBOOT_DESC=	Coreboot payload (EXPERIMENTAL)
QEMU_DESC=	QEMU (EXPERIMENTAL)

MKFONT_CONFIGURE_ENABLE=	grub-mkfont
MKFONT_LIB_DEPENDS=		libfreetype.so:print/freetype2
MKFONT_BUILD_DEPENDS=		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

FUSE_CONFIGURE_ENABLE=		grub-mount
FUSE_LIB_DEPENDS=		libfuse.so:sysutils/fusefs-libs

PC_CONFIGURE_ON=		--with-platform=pc
EFI_CONFIGURE_ON=		--with-platform=efi

COREBOOT_CONFIGURE_ON=		--with-platform=coreboot
COREBOOT_BUILD_DEPENDS=		${LOCALBASE}/share/fonts/gnu-unifont-ttf/unifont.ttf:x11-fonts/gnu-unifont-ttf

QEMU_CONFIGURE_ON=		--with-platform=qemu
QEMU_BUILD_DEPENDS=		${LOCALBASE}/share/fonts/gnu-unifont-ttf/unifont.ttf:x11-fonts/gnu-unifont-ttf

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${PORT_OPTIONS:MPC}
PLIST_SUB+=	EFIEMU=""
.else
PLIST_SUB+=	EFIEMU="@comment "
.endif

post-patch:
	@${LN} -s ${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def
	@${REINPLACE_CMD} -e '/[^auU]sed/ s,sed,gsed,g' ${WRKSRC}/util/grub.d/*.in \
		${WRKSRC}/util/*.in ${WRKSRC}/util/i386/efi/grub-dumpdevtree \
		${WRKSRC}/util/bash-completion.d/grub-completion.bash.in

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 \
		${WRKSRC}/grub-core

.include <bsd.port.post.mk>
