--- grub-core/loader/i386/bsd.c.orig	2019-04-23 04:54:47.000000000 -0400
+++ grub-core/loader/i386/bsd.c	2020-04-04 21:47:56.073361000 -0400
@@ -76,6 +76,29 @@
 static struct grub_relocator *relocator = NULL;
 static struct grub_openbsd_ramdisk_descriptor openbsd_ramdisk;
 
+#ifdef GRUB_MACHINE_EFI
+struct freebsd_efi_fb
+{
+  grub_uint64_t fb_addr;
+  grub_uint64_t fb_size;
+  grub_uint32_t fb_height;
+  grub_uint32_t fb_width;
+  grub_uint32_t fb_stride;
+  grub_uint32_t fb_mask_red;
+  grub_uint32_t fb_mask_green;
+  grub_uint32_t fb_mask_blue;
+  grub_uint32_t fb_mask_reserved;
+};
+
+struct freebsd_efi_map_header
+{
+  grub_uint64_t memory_size;
+  grub_uint64_t descriptor_size;
+  grub_uint32_t descriptor_version;
+  grub_uint8_t data[];
+};
+#endif
+
 struct bsd_tag
 {
   struct bsd_tag *next;
@@ -1567,7 +1590,56 @@
 				   FREEBSD_MODINFOMD_KERNEND, &data, len);
 	  if (err)
 	    return err;
+
+          /* TODO: add keys to keybuf */
+#ifdef GRUB_MACHINE_EFI
+          /* Add EFI firmware handle */
+          err = grub_bsd_add_meta (FREEBSD_MODINFO_METADATA |
+				   FREEBSD_MODINFOMD_FW_HANDLE,
+                                   &grub_efi_system_table,
+                                   sizeof (grub_efi_system_table));
+
+          if (err)
+            return err;
+
+          /* Add EFI frame buffer info */
+          struct freebsd_efi_fb efifb;
+          struct grub_video_mode_info mode_info;
+          void *framebuffer;
+
+          err = grub_video_get_info_and_fini (&mode_info, &framebuffer);
+
+          if (err)
+            return err;
+
+          efifb.fb_addr = (grub_addr_t) framebuffer;
+          efifb.fb_height = mode_info.height;
+          efifb.fb_width = mode_info.width;
+          efifb.fb_stride = mode_info.pitch / mode_info.bytes_per_pixel;
+          efifb.fb_size = mode_info.height * mode_info.pitch;
+          efifb.fb_mask_red =
+            ((1 << mode_info.red_mask_size) - 1) <<
+            mode_info.red_field_pos;
+          efifb.fb_mask_green =
+            ((1 << mode_info.green_mask_size) - 1) <<
+            mode_info.green_field_pos;
+          efifb.fb_mask_blue =
+            ((1 << mode_info.blue_mask_size) - 1) <<
+            mode_info.blue_field_pos;
+          efifb.fb_mask_reserved =
+            ((1 << mode_info.reserved_mask_size) - 1) <<
+            mode_info.reserved_field_pos;
+          err = grub_bsd_add_meta (FREEBSD_MODINFO_METADATA |
+				   FREEBSD_MODINFOMD_EFI_FB,
+                                   &efifb, sizeof (efifb));
+
+          if (err)
+            return err;
+
+          /* TODO: add EFI map */
+#endif
 	}
+
       grub_bsd_get_device (&freebsd_biosdev, &unit, &slice, &part);
       freebsd_zfsguid = 0;
       if (!is_64bit)

