/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the
 * Boost Software License, Version 1.0. (See accompanying file
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         config.hpp
  *   VERSION      see <boost/version.hpp>
  *   DESCRIPTION: regex extended config setup.
  */

#ifndef BOOST_REGEX_CONFIG_HPP
#define BOOST_REGEX_CONFIG_HPP

#if defined(BOOST_REGEX_RECURSIVE)
#error "All support for the C++03 recursive engine has been removed, this define has no effect anymore."
#endif

#if defined(__has_include)
#if !defined(BOOST_REGEX_STANDALONE) && !__has_include(<boost/version.hpp>)
#define BOOST_REGEX_STANDALONE
#endif
#endif

#ifndef BOOST_REGEX_MODULE_EXPORT
#define BOOST_REGEX_MODULE_EXPORT
#define BOOST_REGEX_STATIC_CONST constexpr
#else
#define BOOST_REGEX_STATIC_CONST inline constexpr
#define BOOST_REGEX_STANDALONE
#endif

/*
 * Borland C++ Fix/error check
 * this has to go *before* we include any std lib headers:
 */
#if defined(__BORLANDC__) && !defined(__clang__)
#  include <boost/regex/config/borland.hpp>
#endif

#ifndef BOOST_REGEX_STANDALONE
#include <boost/version.hpp>
#endif

/*************************************************************************
*
* Asserts:
*
*************************************************************************/

#ifdef BOOST_REGEX_STANDALONE
#ifndef BOOST_REGEX_AS_MODULE
#include <cassert>
#  define BOOST_REGEX_ASSERT(x) assert(x)
#else
#  define BOOST_REGEX_ASSERT(x) do{ if(x == 0) { std::printf("%s:%d Assertion Failed", __FILE__, __LINE__); std::abort(); } }while(0)
#endif
#else
#include <boost/assert.hpp>
#  define BOOST_REGEX_ASSERT(x) BOOST_ASSERT(x)
#endif

/*****************************************************************************
 *
 *  Include all the headers we need here:
 *
 ****************************************************************************/

#ifdef __cplusplus

#  ifndef BOOST_REGEX_USER_CONFIG
#     define BOOST_REGEX_USER_CONFIG <boost/regex/user.hpp>
#  endif

#  include BOOST_REGEX_USER_CONFIG

#ifndef BOOST_REGEX_STANDALONE
#  include <boost/config.hpp>
#  include <boost/predef.h>
#endif

#else
   /*
    * C build,
    * don't include <boost/config.hpp> because that may
    * do C++ specific things in future...
    */
#  include <stdlib.h>
#  include <stddef.h>
#  ifdef _MSC_VER
#     define BOOST_MSVC _MSC_VER
#  endif
#endif

#define BOOST_REGEX_MAX_RECURSION_DEPTH 100

/*****************************************************************************
 *
 *  Boilerplate regex config options:
 *
 ****************************************************************************/

/* Obsolete macro, use BOOST_VERSION instead: */
#define BOOST_RE_VERSION 600

/* fix: */
#if defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#define BOOST_REGEX_JOIN(X, Y) BOOST_REGEX_DO_JOIN(X, Y)
#define BOOST_REGEX_DO_JOIN(X, Y) BOOST_REGEX_DO_JOIN2(X,Y)
#define BOOST_REGEX_DO_JOIN2(X, Y) X##Y

#ifdef BOOST_FALLTHROUGH
#  define BOOST_REGEX_FALLTHROUGH BOOST_FALLTHROUGH
#else

#if defined(__clang__) && (__cplusplus >= 201103L) && defined(__has_warning)
#  if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")
#    define BOOST_REGEX_FALLTHROUGH [[clang::fallthrough]]
#  endif
#endif
#if !defined(BOOST_REGEX_FALLTHROUGH) && defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1800) && (__cplusplus >= 201703)
#  define BOOST_REGEX_FALLTHROUGH [[fallthrough]]
#endif
#if !defined(BOOST_REGEX_FALLTHROUGH) && defined(__GNUC__) && (__GNUC__ >= 7)
#  define BOOST_REGEX_FALLTHROUGH __attribute__((fallthrough))
#endif

#if !defined(BOOST_REGEX_FALLTHROUGH)
#  define BOOST_REGEX_FALLTHROUGH [[fallthrough]]
#endif
#endif

#ifdef BOOST_NORETURN
#  define BOOST_REGEX_NORETURN BOOST_NORETURN
#else
#  define BOOST_REGEX_NORETURN [[noreturn]]
#endif


/*
* Define a macro for the namespace that details are placed in, this includes the Boost
* version number to avoid mismatched header and library versions:
*/
#define BOOST_REGEX_DETAIL_NS BOOST_REGEX_JOIN(re_detail_, BOOST_RE_VERSION)

/*
 * If Win32 support has been disabled for boost in general, then
 * it is for regex in particular:
 */
#if defined(BOOST_DISABLE_WIN32) && !defined(BOOST_REGEX_NO_W32)
#  define BOOST_REGEX_NO_W32
#endif

/* disable our own file-iterators and mapfiles if we can't
 * support them: */
#if defined(_WIN32)
#  if defined(BOOST_REGEX_NO_W32) || defined(BOOST_PLAT_WINDOWS_RUNTIME)
#    define BOOST_REGEX_NO_FILEITER
#  endif
#else /* defined(_WIN32) */
#  if !defined(BOOST_HAS_DIRENT_H)
#    define BOOST_REGEX_NO_FILEITER
#  endif
#endif

/* backwards compatibitity: */
#if defined(BOOST_RE_NO_LIB)
#  define BOOST_REGEX_NO_LIB
#endif

#if defined(__GNUC__) && !defined(_MSC_VER) && (defined(_WIN32) || defined(__CYGWIN__))
/* gcc on win32 has problems if you include <windows.h>
   (sporadically generates bad code). */
//#  define BOOST_REGEX_NO_W32
#endif
#if defined(__COMO__) && !defined(BOOST_REGEX_NO_W32) && !defined(_MSC_EXTENSIONS)
#  define BOOST_REGEX_NO_W32
#endif

#ifdef BOOST_REGEX_STANDALONE
#  if defined(_MSC_VER) && !defined(__clang__) && !defined(__GNUC__)
#     define BOOST_REGEX_MSVC _MSC_VER
#endif
#elif defined(BOOST_MSVC)
#  define BOOST_REGEX_MSVC BOOST_MSVC
#endif


/*****************************************************************************
 *
 *  Set up dll import/export options:
 *
 ****************************************************************************/

#if (defined(BOOST_REGEX_DYN_LINK) || defined(BOOST_ALL_DYN_LINK)) && !defined(BOOST_REGEX_STATIC_LINK) && defined(BOOST_SYMBOL_IMPORT)
#  if defined(BOOST_REGEX_SOURCE)
#     define BOOST_REGEX_BUILD_DLL
#     define BOOST_REGEX_DECL BOOST_SYMBOL_EXPORT
#  else
#     define BOOST_REGEX_DECL BOOST_SYMBOL_IMPORT
#  endif
#else
#  define BOOST_REGEX_DECL
#endif

/*****************************************************************************
 *
 *  Set up function call type:
 *
 ****************************************************************************/

#if defined(_MSC_VER) && defined(_MSC_EXTENSIONS)
#if defined(_DEBUG) || defined(__MSVC_RUNTIME_CHECKS) || defined(_MANAGED) || defined(BOOST_REGEX_NO_FASTCALL)
#  define BOOST_REGEX_CALL __cdecl
#else
#  define BOOST_REGEX_CALL __fastcall
#endif
#  define BOOST_REGEX_CCALL __cdecl
#endif

#if defined(__BORLANDC__) && !defined(BOOST_DISABLE_WIN32)
#if defined(__clang__)
#  define BOOST_REGEX_CALL __cdecl
#  define BOOST_REGEX_CCALL __cdecl
#else
#  define BOOST_REGEX_CALL __fastcall
#  define BOOST_REGEX_CCALL __stdcall
#endif
#endif

#ifndef BOOST_REGEX_CALL
#  define BOOST_REGEX_CALL
#endif
#ifndef BOOST_REGEX_CCALL
#define BOOST_REGEX_CCALL
#endif

/*****************************************************************************
 *
 *  Set up localisation model:
 *
 ****************************************************************************/

/* backwards compatibility: */
#ifdef BOOST_RE_LOCALE_C
#  define BOOST_REGEX_USE_C_LOCALE
#endif

#ifdef BOOST_RE_LOCALE_CPP
#  define BOOST_REGEX_USE_CPP_LOCALE
#endif

#if defined(__CYGWIN__)
#  define BOOST_REGEX_USE_C_LOCALE
#endif

/* use C++ locale when targeting windows store */
#if defined(BOOST_PLAT_WINDOWS_RUNTIME)
#  define BOOST_REGEX_USE_CPP_LOCALE
#  define BOOST_REGEX_NO_WIN32_LOCALE
#endif

/* Win32 defaults to native Win32 locale: */
#if defined(_WIN32) && \
    !defined(BOOST_REGEX_USE_WIN32_LOCALE) && \
    !defined(BOOST_REGEX_USE_C_LOCALE) && \
    !defined(BOOST_REGEX_USE_CPP_LOCALE) && \
    !defined(BOOST_REGEX_NO_W32) && \
    !defined(BOOST_REGEX_NO_WIN32_LOCALE)
#  define BOOST_REGEX_USE_WIN32_LOCALE
#endif
/* otherwise use C++ locale if supported: */
#if !defined(BOOST_REGEX_USE_WIN32_LOCALE) && !defined(BOOST_REGEX_USE_C_LOCALE) && !defined(BOOST_REGEX_USE_CPP_LOCALE) && !defined(BOOST_NO_STD_LOCALE)
#  define BOOST_REGEX_USE_CPP_LOCALE
#endif
/* otherwise use C locale: */
#if !defined(BOOST_REGEX_USE_WIN32_LOCALE) && !defined(BOOST_REGEX_USE_C_LOCALE) && !defined(BOOST_REGEX_USE_CPP_LOCALE)
#  define BOOST_REGEX_USE_C_LOCALE
#endif

#ifndef BOOST_REGEX_MAX_STATE_COUNT
#  define BOOST_REGEX_MAX_STATE_COUNT 100000000
#endif


/*****************************************************************************
 *
 *  Error Handling for exception free compilers:
 *
 ****************************************************************************/

#ifdef BOOST_NO_EXCEPTIONS
/*
 * If there are no exceptions then we must report critical-errors
 * the only way we know how; by terminating.
 */
#  define BOOST_REGEX_NOEH_ASSERT(x) assert(x);
#else
/*
 * With exceptions then error handling is taken care of and
 * there is no need for these checks:
 */
#  define BOOST_REGEX_NOEH_ASSERT(x)
#endif


/*****************************************************************************
 *
 *  Stack protection under MS Windows:
 *
 ****************************************************************************/

#if !defined(BOOST_REGEX_NO_W32) && !defined(BOOST_REGEX_V3)
#  if(defined(_WIN32) || defined(_WIN64) || defined(_WINCE)) \
        && !(defined(__GNUC__) || defined(__BORLANDC__) && defined(__clang__)) \
        && !(defined(__BORLANDC__) && (__BORLANDC__ >= 0x600)) \
        && !(defined(__MWERKS__) && (__MWERKS__ <= 0x3003))
#     define BOOST_REGEX_HAS_MS_STACK_GUARD
#  endif
#elif defined(BOOST_REGEX_HAS_MS_STACK_GUARD)
#  undef BOOST_REGEX_HAS_MS_STACK_GUARD
#endif

#if defined(__cplusplus) && defined(BOOST_REGEX_HAS_MS_STACK_GUARD)

namespace boost{
namespace BOOST_REGEX_DETAIL_NS{

BOOST_REGEX_DECL void BOOST_REGEX_CALL reset_stack_guard_page();

}
}

#endif

#  ifndef BOOST_REGEX_BLOCKSIZE
#     define BOOST_REGEX_BLOCKSIZE 4096
#  endif
#  if BOOST_REGEX_BLOCKSIZE < 512
#     error "BOOST_REGEX_BLOCKSIZE must be at least 512"
#  endif
#  ifndef BOOST_REGEX_MAX_BLOCKS
#     define BOOST_REGEX_MAX_BLOCKS 1024
#  endif
#  ifdef BOOST_REGEX_HAS_MS_STACK_GUARD
#     undef BOOST_REGEX_HAS_MS_STACK_GUARD
#  endif
#  ifndef BOOST_REGEX_MAX_CACHE_BLOCKS
#     define BOOST_REGEX_MAX_CACHE_BLOCKS 16
#  endif


/*****************************************************************************
 *
 *  Diagnostics:
 *
 ****************************************************************************/

#ifdef BOOST_REGEX_CONFIG_INFO
BOOST_REGEX_DECL void BOOST_REGEX_CALL print_regex_library_info();
#endif

#if defined(BOOST_REGEX_DIAG)
#  pragma message ("BOOST_REGEX_DECL" BOOST_STRINGIZE(=BOOST_REGEX_DECL))
#  pragma message ("BOOST_REGEX_CALL" BOOST_STRINGIZE(=BOOST_REGEX_CALL))
#  pragma message ("BOOST_REGEX_CCALL" BOOST_STRINGIZE(=BOOST_REGEX_CCALL))
#ifdef BOOST_REGEX_USE_C_LOCALE
#  pragma message ("Using C locale in regex traits class")
#elif BOOST_REGEX_USE_CPP_LOCALE
#  pragma message ("Using C++ locale in regex traits class")
#else
#  pragma message ("Using Win32 locale in regex traits class")
#endif
#if defined(BOOST_REGEX_DYN_LINK) || defined(BOOST_ALL_DYN_LINK)
#  pragma message ("Dynamic linking enabled")
#endif
#if defined(BOOST_REGEX_NO_LIB) || defined(BOOST_ALL_NO_LIB)
#  pragma message ("Auto-linking disabled")
#endif
#ifdef BOOST_REGEX_NO_EXTERNAL_TEMPLATES
#  pragma message ("Extern templates disabled")
#endif

#endif

#endif

