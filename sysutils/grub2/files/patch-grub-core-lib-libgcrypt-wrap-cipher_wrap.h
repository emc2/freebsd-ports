--- grub-core/lib/libgcrypt_wrap/cipher_wrap.h.orig	2019-05-27 20:34:31.465879000 -0400
+++ grub-core/lib/libgcrypt_wrap/cipher_wrap.h	2019-05-27 20:34:45.184492000 -0400
@@ -41,6 +41,8 @@
 
 #define CIPHER_INFO_NO_WEAK_KEY    1
 
+typedef uint64_t u64;
+
 #define HAVE_U64_TYPEDEF 1
 
 /* Selftests are in separate modules.  */
