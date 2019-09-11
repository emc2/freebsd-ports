--- grub-core/osdep/generic/blocklist.c.orig	2018-11-24 12:13:02.000000000 -0500
+++ grub-core/osdep/generic/blocklist.c	2019-09-08 15:28:47.163879000 -0400
@@ -59,7 +59,7 @@
 
       grub_disk_cache_invalidate_all ();
 
-      file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | FILE_TYPE_NO_DECOMPRESS);
+      file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | GRUB_FILE_TYPE_NO_DECOMPRESS);
       if (file)
 	{
 	  if (grub_file_size (file) != core_size)
@@ -116,7 +116,7 @@
 
   grub_file_t file;
   /* Now read the core image to determine where the sectors are.  */
-  file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | FILE_TYPE_NO_DECOMPRESS);
+  file = grub_file_open (core_path_dev, GRUB_FILE_TYPE_NONE | GRUB_FILE_TYPE_NO_DECOMPRESS);
   if (! file)
     grub_util_error ("%s", grub_errmsg);
 
