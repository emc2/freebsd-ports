--- build.sbt.orig	2019-12-15 08:45:25.606464000 -0500
+++ build.sbt	2019-12-15 08:44:08.088997000 -0500
@@ -89,11 +89,11 @@
 
 // Assembly
 
-assemblyJarName in assembly := "firrtl.jar"
+assemblyJarName in assembly := "firrtl_2.12-1.2.1.jar"
 
 test in assembly := {} // Should there be tests?
 
-assemblyOutputPath in assembly := file("./utils/bin/firrtl.jar")
+assemblyOutputPath in assembly := file("./utils/bin/firrtl_2.12-1.2.1.jar")
 
 // ANTLRv4
 
