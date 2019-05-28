--- util/grub-mkimagexx.c.orig	2017-04-24 05:16:00.000000000 -0400
+++ util/grub-mkimagexx.c	2019-06-02 21:21:28.517626000 -0400
@@ -832,6 +832,7 @@
 		  break;
 
 		case R_X86_64_PC32:
+                case R_X86_64_PLT32:
 		  {
 		    grub_uint32_t *t32 = (grub_uint32_t *) target;
 		    *t32 = grub_host_to_target64 (grub_target_to_host32 (*t32)

