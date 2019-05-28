--- grub-core/osdep/unix/getroot.c.orig	2019-05-27 20:10:57.082707000 -0400
+++ grub-core/osdep/unix/getroot.c	2019-05-27 20:11:08.847003000 -0400
@@ -57,6 +57,11 @@
 #include <sys/sysmacros.h>
 #endif
 
+typedef unsigned int uint_t;
+typedef unsigned char uchar_t;
+typedef int boolean_t;
+typedef uint64_t hrtime_t;
+
 #if defined(HAVE_LIBZFS) && defined(HAVE_LIBNVPAIR)
 # include <grub/util/libzfs.h>
 # include <grub/util/libnvpair.h>

