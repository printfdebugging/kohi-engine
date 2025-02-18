#ifndef DEFINES_H
#define DEFINES_H

// unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point types
typedef float f32;
typedef double f64;

// boolean types
typedef int b32;
typedef char b8;

// properly define static assertions.
#if defined(__gcc__) || defined(__GNUC__)
    #define STATIC_ASSERT _Static_assert
#else
    #include <assert.h>
    #define STATIC_ASSERT static_assert
#endif

// ensure that all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "expected u16 to be 2 byte.");
STATIC_ASSERT(sizeof(u32) == 4, "expected u32 to be 4 byte.");
STATIC_ASSERT(sizeof(u64) == 8, "expected u64 to be 8 byte.");

STATIC_ASSERT(sizeof(i8) == 1, "expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "expected i16 to be 2 byte.");
STATIC_ASSERT(sizeof(i32) == 4, "expected i32 to be 4 byte.");
STATIC_ASSERT(sizeof(i64) == 8, "expected i64 to be 8 byte.");

STATIC_ASSERT(sizeof(f32) == 4, "expected f32 to be 4 byte.");
STATIC_ASSERT(sizeof(f64) == 8, "expected f64 to be 8 byte.");

#define TRUE  1
#define FALSE 0

// platform detection code
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define KPLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
#elif defined(__linux__) || defined(__gnu_linux__)
    #define KPLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define KPLATFORM_ANDROID 1
    #endif
#elif defined(__unix__)
    // catch anything not caught by the above
    #define KPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
    #define KPLATFORM_POSIX 1
#elif __APPLE__
    #define KPLATFORM_APPLE 1
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        // ios simulator
        #define KPLATFORM_IOS           1
        #define KPLATOROM_IOS_SIMULATOR 1
    #elif TARGET_OS_IPHONE
        #define KPLATFORM_IOS 1
    #elif TARGET_OS_MAC
        // other kinds of mac os
    #else
        #error "unknown apple platform"
    #endif
#else
    #error "unknown platform!"
#endif

// visibility and linkage preprocessor
#ifdef KEXPORT
    #ifdef _MSC_VER
        #define KAPI __declspec(dllexport)
    #else
        #define KAPI __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define KAPI __declspec(dllimport)
    #else
        #define KAPI
    #endif
#endif

#endif
