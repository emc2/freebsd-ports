# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	${GH_TAGNAME:C/(stable|patch)_([0-9]{1,2})([A-Z][a-z][a-z])([0-9]{4})/\4.\3.\2/S/Jan/01/S/Feb/02/S/Mar/03/S/Apr/04/S/May/05/S/Jun/06/S/Jul/07/S/Aug/08/S/Sep/09/S/Oct/10/S/Nov/11/S/Dec/12/}
PORTREVISION=	6
CATEGORIES=	science

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	89f119e8aa44ab31139cf4caceacb546c08f199d.patch:-p1 \
		c18efdbfa70f42390a3d535ccb1b8a423260f63a.patch:-p1 \
		613b8a759666b4e2e15fca38323cf5455e154a6c.patch:-p1 \
		2b542eacb7def4c6da6ff94ab716cb012111551e.patch:-p1 \
		795e2cb133b99ed3b77fc73f367fff7bc9368b78.patch:-p1 # https://github.com/lammps/lammps/pull/2051

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Classical molecular dynamics code with a focus on materials modeling

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	undefined reference to `__atomic_load'
CONFLICTS_BUILD=	ga mpich mpich2 # conflicts with include/error.h from ga, already fixed in the head

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		blaslapack:openblas cmake:noninja eigen:3 fortran localbase:ldflags shebangfix
USE_GITHUB=	yes
GH_TAGNAME=	patch_15Apr2020
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh *.bash
SHEBANG_FILES=	lib/kokkos/bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS" ${CMAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
CMAKE_ARGS_gcc=	-DBUILD_OMP:BOOL=false

# enable packages (for a complete list see STANDARD_PACKAGES in cmake/CMakeLists.txt)
CMAKE_ON+=	PKG_ASPHERE PKG_BODY PKG_CLASS2 PKG_COLLOID PKG_COMPRESS PKG_DIPOLE
CMAKE_ON+=	PKG_GRANULAR PKG_KSPACE PKG_MANYBODY PKG_MC PKG_MESSAGE PKG_MISC PKG_MOLECULE PKG_PERI PKG_POEMS PKG_QEQ
CMAKE_ON+=	PKG_REPLICA PKG_RIGID PKG_SHOCK PKG_SPIN PKG_SNAP PKG_SRD
CMAKE_ON+=	PKG_USER-ATC PKG_USER-AWPMD PKG_USER-BOCS PKG_USER-CGDNA PKG_USER-MESODPD PKG_USER-CGSDK PKG_USER-COLVARS
CMAKE_ON+=	PKG_USER-DIFFRACTION PKG_USER-DPD PKG_USER-DRUDE PKG_USER-EFF PKG_USER-FEP PKG_USER-LB
CMAKE_ON+=	PKG_USER-MANIFOLD PKG_USER-MEAMC PKG_USER-MGPT PKG_USER-MISC PKG_USER-MOFFF PKG_USER-MOLFILE
CMAKE_ON+=	PKG_USER-PHONON PKG_USER-PTM PKG_USER-QTB PKG_USER-REACTION
CMAKE_ON+=	PKG_USER-REAXC PKG_USER-SDPD PKG_USER-SMD PKG_USER-SMTBQ PKG_USER-SPH PKG_USER-TALLY
CMAKE_ON+=	PKG_USER-UEF PKG_USER-QMMM PKG_USER-YAFF
# Packages requiring extra downloades or dependencies: PKG_MSCG PKG_USER-ADIOS2 PKG_USER-NETCDF PKG_USER-QUIP PKG_KIM PKG_USER-PLUMED PKG_USER-SCAFACOS

OPTIONS_DEFINE=		JPEG PNG GZIP FFMPEG
OPTIONS_GROUP=		PARALLEL PACKAGES
OPTIONS_DEFAULT=	MPI OPENMP JPEG PNG GZIP FFMPEG H5MD KOKKOS VORONOI LATTE ${OPTIONS_DEFAULT_${CHOSEN_COMPILER_TYPE}}
OPTIONS_SUB=		yes
PARALLEL_DESC=		Enable parallelizations:
PACKAGES_DESC=		Enable packages:
OPTIONS_GROUP_PARALLEL=	MPI OPENMP ${OPTIONS_DEFINE_${CHOSEN_COMPILER_TYPE}}
OPTIONS_GROUP_PACKAGES=	H5MD KOKKOS VORONOI LATTE VTK

MPI_CMAKE_BOOL=		BUILD_MPI PKG_MPIIO
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
MPI_USES=		compiler:c11

FFMPEG_BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

JPEG_CMAKE_BOOL=	WITH_JPEG
JPEG_USES=		jpeg

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

GZIP_DESC=		Enable GZIP support
GZIP_CMAKE_BOOL=	WITH_GZIP

FFMPEG_CMAKE_BOOL=	WITH_FFMPEG

H5MD_DESC=		USER-H5MD package based on libhdf5
H5MD_CMAKE_BOOL=	PKG_USER-H5MD
H5MD_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip

KOKKOS_DESC=		kokkos package based on the libkokkos library
KOKKOS_CMAKE_BOOL=	PKG_KOKKOS EXTERNAL_KOKKOS
KOKKOS_LIB_DEPENDS=	libkokkoscore.so:devel/kokkos

VORONOI_DESC=		voro++, Voronoi tessellation package
VORONOI_CMAKE_BOOL=	PKG_VORONOI
VORONOI_LIB_DEPENDS=	libvoro++.so:science/voro++

LATTE_DESC=		latte package based on the liblatte library
LATTE_CMAKE_BOOL=	PKG_LATTE
LATTE_LIB_DEPENDS=	liblatte.so:science/latte

VTK_DESC=		USER-VTK package based on the external vtk package
VTK_CMAKE_BOOL=		PKG_USER-VTK
VTK_CMAKE_ON=		-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2
VTK_USES=		qt:5 xorg
VTK_USE=		qt=core,gui,sql,widgets xorg=ice,sm,x11,xext,xt
VTK_LIB_DEPENDS=	libvtkImagingMath-8.2.so:math/vtk8 \
			libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libtiff.so:graphics/tiff

PORTSCOUT=	ignore:1 # due to a special version tagging scheme that this project uses portscout fails to find new versions, watching their GitHub release page instead

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP}
CMAKE_ARGS+=	-DBUILD_OMP:BOOL=true
.endif

post-patch:
	@${REINPLACE_CMD} 's|SHELL = /bin/bash|SHELL = ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/Makefile

post-patch-FFMPEG-off:
	@${REINPLACE_CMD} 's|find_program(FFMPEG_EXECUTABLE|#&|' ${WRKSRC}/cmake/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/python*

.include <bsd.port.mk>
