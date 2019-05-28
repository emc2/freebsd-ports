--- util/getroot.c.orig	2019-05-27 20:08:06.552358000 -0400
+++ util/getroot.c	2019-05-27 20:08:26.241007000 -0400
@@ -47,6 +47,11 @@
 
 #include <sys/types.h>
 
+typedef unsigned int uint_t;
+typedef unsigned char uchar_t;
+typedef int boolean_t;
+typedef uint64_t hrtime_t;
+
 #if defined(HAVE_LIBZFS) && defined(HAVE_LIBNVPAIR)
 # include <grub/util/libzfs.h>
 # include <grub/util/libnvpair.h>
