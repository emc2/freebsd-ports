--- grub-core/lib/libgcrypt_wrap/cipher_wrap.h.orig	2019-09-08 15:39:38.610283000 -0400
+++ grub-core/lib/libgcrypt_wrap/cipher_wrap.h	2019-09-08 15:40:06.759535000 -0400
@@ -43,6 +43,8 @@
 
 #define HAVE_U64_TYPEDEF 1
 
+typedef uint64_t u64;
+
 /* Selftests are in separate modules.  */
 static inline char *
 selftest (void)
