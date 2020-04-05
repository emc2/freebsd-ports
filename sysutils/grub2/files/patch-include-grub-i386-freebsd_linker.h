--- include/grub/i386/freebsd_linker.h.orig	2020-04-04 18:30:09.528583000 -0400
+++ include/grub/i386/freebsd_linker.h	2020-04-04 18:33:16.300613000 -0400
@@ -65,9 +65,18 @@
 #define FREEBSD_MODINFOMD_HOWTO		0x0007	/* boothowto */
 #define FREEBSD_MODINFOMD_KERNEND	0x0008	/* kernend */
 #define FREEBSD_MODINFOMD_SHDR		0x0009	/* section header table */
+#define FREEBSD_MODINFOMD_CTORS_ADDR    0x000a  /* address of .ctors */
+#define FREEBSD_MODINFOMD_CTORS_SIZE    0x000b  /* size of .ctors */
+#define FREEBSD_MODINFOMD_FW_HANDLE     0x000c  /* firmware dependent handle */
+#define FREEBSD_MODINFOMD_KEYBUF        0x000d  /* crypto key intake buffer */
 #define FREEBSD_MODINFOMD_NOCOPY	0x8000	/* don't copy this metadata to the kernel */
 
 #define FREEBSD_MODINFOMD_SMAP		0x1001
+#define FREEBSD_MODINFOMD_SMAP_XATTR    0x1002
+#define FREEBSD_MODINFOMD_DTBP          0x1003
+#define FREEBSD_MODINFOMD_EFI_MAP       0x1004
+#define FREEBSD_MODINFOMD_EFI_FB        0x1005
+#define FREEBSD_MODINFOMD_EFI_MODULEP   0x1006
 
 #define FREEBSD_MODINFOMD_DEPLIST	(0x4001 | FREEBSD_MODINFOMD_NOCOPY)  /* depends on */
 
