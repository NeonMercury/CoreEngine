#pragma once

#if defined(WIN32) || defined(_WIN32)
#   define CE_PLATFORM_WINDOWS 1
#   if defined(_MSC_VER) && (_MSC_VER >= 1700) && !_USING_V110_SDK71_
#       include <winapifamily.h>
#       if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#           define CE_PLATFORM_WINDOWS_UWP 1
#           define CE_PLATFORM_NO_MODPLUG 1
#           define CE_PLATFORM_NOMPG123 1
#       endif
#   endif
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
#   define CE_PLATFORM_LINUX 1
#endif

#if defined(__ANDROID__)
#   define CE_PLATFORM_ANDROID 1
#endif

#if defined(__APPLE__)
#   include <TargetConditionals.h>
#   if TARGET_OS_IPHONE
#       define CE_PLATFORM_IOS 1
#   elif TARGET_OS_MAC
#       define CE_PLATFORM_MACOSX 1
#   endif
#endif

// Yes, it is not Linux, but similar.
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#   define CE_PLATFORM_LINUX 1
#endif

#if defined(_M_IX86)
#   define CE_X86
#elif defined(_M_X64) || defined(_M_IA64)
#   define CE_X64
#endif

#if defined(NDEBUG)
#   define CE_CONFIGURATION_RELEASE
#else
#   define CE_CONFIGURATION_DEBUG
#endif
