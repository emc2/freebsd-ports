--- util/grub-install.c.orig	2019-05-27 19:38:03.316491000 -0400
+++ util/grub-install.c	2019-05-27 19:48:33.778506000 -0400
@@ -45,6 +45,8 @@
 
 #include <string.h>
 
+#include <sys/utsname.h>
+
 #pragma GCC diagnostic ignored "-Wmissing-prototypes"
 #pragma GCC diagnostic ignored "-Wmissing-declarations"
 #include <argp.h>
@@ -63,6 +65,7 @@
 static char *bootdir = NULL;
 static int allow_floppy = 0;
 static int force_file_id = 0;
+static int force_fs_label = 0;
 static char *disk_module = NULL;
 static char *efidir = NULL;
 static char *macppcdir = NULL;
@@ -86,17 +89,18 @@
     OPTION_ROOT_DIRECTORY,
     OPTION_TARGET,
     OPTION_SETUP,
-    OPTION_MKRELPATH, 
-    OPTION_MKDEVICEMAP, 
-    OPTION_PROBE, 
-    OPTION_EDITENV, 
-    OPTION_ALLOW_FLOPPY, 
-    OPTION_RECHECK, 
+    OPTION_MKRELPATH,
+    OPTION_MKDEVICEMAP,
+    OPTION_PROBE,
+    OPTION_EDITENV,
+    OPTION_ALLOW_FLOPPY,
+    OPTION_RECHECK,
     OPTION_FORCE,
     OPTION_FORCE_FILE_ID,
-    OPTION_NO_NVRAM, 
-    OPTION_REMOVABLE, 
-    OPTION_BOOTLOADER_ID, 
+    OPTION_FORCE_LABEL,
+    OPTION_NO_NVRAM,
+    OPTION_REMOVABLE,
+    OPTION_BOOTLOADER_ID,
     OPTION_EFI_DIRECTORY,
     OPTION_FONT,
     OPTION_DEBUG,
@@ -114,13 +118,16 @@
 
 static int fs_probe = 1;
 
-static error_t 
+static error_t
 argp_parser (int key, char *arg, struct argp_state *state)
 {
   if (grub_install_parse (key, arg))
     return 0;
   switch (key)
     {
+    case OPTION_FORCE_LABEL:
+      force_fs_label = 1;
+      return 0;
     case OPTION_FORCE_FILE_ID:
       force_file_id = 1;
       return 0;
@@ -272,6 +279,8 @@
    N_("install even if problems are detected"), 2},
   {"force-file-id", OPTION_FORCE_FILE_ID, 0, 0,
    N_("use identifier file even if UUID is available"), 2},
+  {"force-label", OPTION_FORCE_LABEL, 0, 0,
+   N_("use filesystem label even if UUID is available"), 2},
   {"disk-module", OPTION_DISK_MODULE, N_("MODULE"), 0,
    N_("disk module to use (biosdisk or native). "
       "This option is only available on BIOS target."), 2},
@@ -362,7 +371,7 @@
   N_("Install GRUB on your drive.")"\v"
   N_("INSTALL_DEVICE must be system device filename.\n"
      "%s copies GRUB images into %s.  On some platforms, it"
-     " may also install GRUB into the boot sector."), 
+     " may also install GRUB into the boot sector."),
   NULL, help_filter, NULL
 };
 
@@ -389,13 +398,20 @@
 push_partmap_module (const char *map, void *data __attribute__ ((unused)))
 {
   char buf[50];
+  struct utsname name;
 
-  if (strcmp (map, "openbsd") == 0 || strcmp (map, "netbsd") == 0)
+  if (strcmp (map, "openbsd") == 0 || strcmp (map, "netbsd") == 0 ||
+      strcmp (map, "freebsd") == 0)
     {
       grub_install_push_module ("part_bsd");
       return;
     }
 
+  if (uname (&name) == 0 && strcmp (name.sysname, "FreeBSD") == 0)
+    {
+      grub_install_push_module ("part_bsd");
+    }
+
   snprintf (buf, sizeof (buf), "part_%s", map);
   grub_install_push_module (buf);
 }

