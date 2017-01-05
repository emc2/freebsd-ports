--- common.mk.orig	2014-12-15 05:33:17 UTC
+++ common.mk
@@ -15,9 +15,7 @@ CFLAGS_ALWAYS = -D_FILE_OFFSET_BITS=64
 LDFLAGS = -lm -lzm $(LIB_DIR) -lgmp -lgmpxx
 AS = nasm
 AFLAGS = -f elf -D__unix__
-ifeq ($(SUPPORT_SNARK),1)
 CFLAGS += -DBN_SUPPORT_SNARK
-endif
 
 # for only 64-bit
 BIT=-m64
@@ -48,5 +46,5 @@ endif
 .c.o:
 	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGS_WARN) $(CFLAGS_ALWAYS) $(INC_DIR) $(BIT)
 
-INC_DIR+= -I../src -I../../xbyak -I../include
-LIB_DIR+= -L../lib
+INC_DIR+= -I../src -I/usr/local/include -I../include
+LIB_DIR+= -L../lib -L/usr/local/lib
