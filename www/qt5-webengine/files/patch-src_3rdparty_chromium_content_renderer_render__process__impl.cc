--- src/3rdparty/chromium/content/renderer/render_process_impl.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/renderer/render_process_impl.cc
@@ -43,7 +43,7 @@
 #if defined(OS_WIN)
 #include "base/win/win_util.h"
 #endif
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #include "v8/include/v8-wasm-trap-handler-posix.h"
 #endif
 namespace {
@@ -156,7 +156,7 @@ RenderProcessImpl::RenderProcessImpl()
 
   SetV8FlagIfNotFeature(features::kWebAssemblyTrapHandler,
                         "--no-wasm-trap-handler");
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
     if (!command_line->HasSwitch(
