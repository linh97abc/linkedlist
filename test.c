# 0 ".\\src\\os_mem.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 ".\\src\\os_mem.c"
# 1 "inc/os_mem.h" 1
# 1 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stdint.h" 1 3 4
# 9 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stdint.h" 3 4
# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 1 3 4

# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */





# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */




# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */




# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */




# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 18 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
/* This macro holds an monotonic increasing value, which indicates
   a specific fix/patch is present on trunk.  This value isn't related to
   minor/major version-macros.  It is increased on demand, if a big
   fix was applied to trunk.  This macro gets just increased on trunk.  For
   other branches its value won't be modified.  */
# 35 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
/* mingw.org's version macros: these make gcc to define
   MINGW32_SUPPORTS_MT_EH and to use the _CRT_MT global
   and the __mingwthr_key_dtor() function from the MinGW
   CRT in its private gthr-win32.h header. */



/* Set VC specific compiler target macros.  */
# 92 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
   /* MS does not prefix symbols by underscores for 64-bit.  */

     /* As we have to support older gcc version, which are using underscores
      as symbol prefix for x64, we have to check here for the user label
      prefix defined by gcc. */

             
# 107 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
             
# 169 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
/* Special case nameless struct/union.  */
# 193 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
/* MinGW-w64 has some additional C99 printf/scanf feature support.
   So we add some helper macros to ease recognition of them.  */
# 346 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3 4
/* If _FORTIFY_SOURCE is enabled, some inline functions may use
   __builtin_va_arg_pack().  GCC may report an error if the address
   of such a function is used.  Set _FORTIFY_VA_ARG=0 in this case.  */







/* Enable workaround for ABI incompatibility on affected platforms */
# 11 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3 4
# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */




/* http://msdn.microsoft.com/en-us/library/ms175759%28v=VS.100%29.aspx */
# 28 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 3 4
/* Templates won't work in C, will break if secure API is not enabled, disabled */
# 54 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 3 4
/* https://blogs.msdn.com/b/sdl/archive/2010/02/16/vc-2010-and-memcpy.aspx?Redirected=true */
/* fallback on default implementation if we can't know the size of the destination */
# 12 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3 4

/* Include _cygwin.h if we're building a Cygwin application. */




/* Target specific macro replacement for type "long".  In the Windows API,
   the type long is always 32 bit, even if the target is 64 bit (LLP64).
   On 64 bit Cygwin, the type long is 64 bit (LP64).  So, to get the right
   sized definitions and declarations, all usage of type long in the Windows
   headers have to be replaced by the below defined macro __LONG32. */






/* C/C++ specific language defines.  */
# 49 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* Note the extern. This is needed to work around GCC's
limitations in handling dllimport attribute.  */
# 163 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
# 223 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/*  High byte is the major version, low byte is the minor. */
# 287 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */



# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 612 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* for backward compatibility */
# 621 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3 4
# 622 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3 4
# 10 "C:/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 2 3 4




#pragma pack(push,_CRT_PACKING)
# 24 "C:/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 3 4
  typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 46 "C:/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 3 4
/* Use GCC builtins */
# 103 "C:/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 3 4
#pragma pack(pop)
# 288 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3 4
# 324 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* We have to define _DLL for gcc based mingw version. This define is set
   by VC, when DLL-based runtime is used. So, gcc based runtime just have
   DLL-base runtime, therefore this define has to be set.
   As our headers are possibly used by windows compiler having a static
   C-runtime, we make this definition gnu compiler specific here.  */
# 416 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* MSVC defines _NATIVE_NULLPTR_SUPPORTED when nullptr is supported. We emulate it here for GCC. */






/* We are activating __USE_MINGW_ANSI_STDIO for various define indicators.
 * printf ll modifier (unsupported by msvcrt.dll) is required by C99 and C++11 standards. */
# 433 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* Enable __USE_MINGW_ANSI_STDIO if user did _not_ specify it explicitly... */



/* We are defining __USE_MINGW_ANSI_STDIO as 0 or 1 */
# 446 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* _dowildcard is an int that controls the globbing of the command line.
 * The MinGW32 (mingw.org) runtime calls it _CRT_glob, so we are adding
 * a compatibility definition here:  you can use either of _CRT_glob or
 * _dowildcard .
 * If _dowildcard is non-zero, the command line will be globbed:  *.*
 * will be expanded to be all files in the startup directory.
 * In the mingw-w64 library a _dowildcard variable is defined as being
 * 0, therefore command line globbing is DISABLED by default. To turn it
 * on and to leave wildcard command line processing MS's globbing code,
 * include a line in one of your source modules defining _dowildcard and
 * setting it to -1, like so:
 * int _dowildcard = -1;
 */
# 533 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
/* Macros for __uuidof template-based emulation */
# 584 "C:/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3 4
void __attribute__((__cdecl__)) __debugbreak(void);
extern __inline__ __attribute__((__always_inline__,__gnu_inline__)) void __attribute__((__cdecl__)) __debugbreak(void)
{

  __asm__ __volatile__("int {$}3":);







}



/* mingw-w64 specific functions: */
const char *__mingw_get_crt_info (void);
# 11 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 2 3 4




#pragma pack(push,_CRT_PACKING)
# 35 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
__extension__ typedef unsigned long long size_t;
# 45 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
__extension__ typedef long long ssize_t;






typedef size_t rsize_t;
# 62 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
__extension__ typedef long long intptr_t;
# 75 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
__extension__ typedef unsigned long long uintptr_t;
# 88 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
__extension__ typedef long long ptrdiff_t;
# 98 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;





typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;
# 138 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
typedef __time64_t time_t;
# 430 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {





  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;

} threadlocinfo;
# 501 "C:/msys64/mingw64/x86_64-w64-mingw32/include/corecrt.h" 3 4
#pragma pack(pop)
# 11 "C:/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 2 3 4
# 29 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 2 3 4



# 1 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 1 3 4
# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

# 1 "C:/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 1 3 4
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
# 8 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 2 3 4
# 18 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
  __attribute__ ((__dllimport__)) extern int *__attribute__((__cdecl__)) _errno(void);

  errno_t __attribute__((__cdecl__)) _set_errno(int _Value);
  errno_t __attribute__((__cdecl__)) _get_errno(int *_Value);


  __attribute__ ((__dllimport__)) extern unsigned long __attribute__((__cdecl__)) __threadid(void);

  __attribute__ ((__dllimport__)) extern uintptr_t __attribute__((__cdecl__)) __threadhandle(void);







/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 58 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
# 90 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 115 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 167 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 244 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 356 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
# 391 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
/* A null pointer constant.  */
# 2 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 2 3 4
/* Copyright (C) 1989-2021 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */





/* snaroff@next.com says the NeXT needs this.  */




/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */
# 87 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 112 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 155 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 236 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 388 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* A null pointer constant.  */
# 406 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stddef.h" 3 4
/* Offset of member MEMBER in a struct of type TYPE. */






/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
  /* _Float128 is defined as a basic type, so max_align_t must be
     sufficiently aligned for it.  This code must work in C++, so we
     use __float128 here; that is only available on some
     architectures, but only on i386 is extra alignment needed for
     __float128.  */



} max_align_t;
# 33 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 2 3 4

/* 7.18.1.1  Exact-width integer types */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
__extension__ typedef long long int64_t;
__extension__ typedef unsigned long long uint64_t;

/* 7.18.1.2  Minimum-width integer types */
typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
__extension__ typedef long long int_least64_t;
__extension__ typedef unsigned long long uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
__extension__ typedef long long int_fast64_t;
__extension__ typedef unsigned long long uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
__extension__ typedef long long intmax_t;
__extension__ typedef unsigned long long uintmax_t;

/* 7.18.2  Limits of specified-width integer types */



/* 7.18.2.1  Limits of exact-width integer types */
# 91 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/* 7.18.2.2  Limits of minimum-width integer types */
# 107 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/* 7.18.2.3  Limits of fastest minimum-width integer types */
# 123 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
# 135 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/* 7.18.2.5  Limits of greatest-width integer types */




/* 7.18.3  Limits of other integer types */
# 165 "C:/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
/*
 * wint_t is unsigned short for compatibility with MS runtime
 */






/* 7.18.4  Macros for integer constants */



/* 7.18.4.1  Macros for minimum-width integer constants

    Accoding to Douglas Gwyn <gwyn@arl.mil>:
	"This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
	9899:1999 as initially published, the expansion was required
	to be an integer constant of precisely matching type, which
	is impossible to accomplish for the shorter types on most
	platforms, because C99 provides no standard way to designate
	an integer constant with width less than that of type int.
	TC1 changed this to require just an integer constant
	*expression* with *promoted* type."

	The trick used here is from Clive D W Feather.
*/




/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */







/* 7.18.4.2  Macros for greatest-width integer constants */
# 10 "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/11.2.0/include/stdint.h" 2 3 4
# 2 "inc/os_mem.h" 2
# 15 "inc/os_mem.h"

# 15 "inc/os_mem.h"
typedef struct os_mem { /* MEMORY CONTROL BLOCK                                      */
    void *OSMemAddr; /* Pointer to beginning of memory partition                  */
    void *OSMemFreeList; /* Pointer to list of free memory blocks                     */
    int32_t OSMemBlkSize; /* Size (in bytes) of each block of memory                   */
    int32_t OSMemNBlks; /* Total number of blocks in this partition                  */
    int32_t OSMemNFree; /* Number of memory blocks remaining in this partition       */
} OS_MEM;


typedef struct os_mem_data {
    void *OSAddr; /* Pointer to the beginning address of the memory partition     */
    void *OSFreeList; /* Pointer to the beginning of the free list of memory blocks   */
    int32_t OSBlkSize; /* Size (in bytes) of each memory block                         */
    int32_t OSNBlks; /* Total number of blocks in the partition                      */
    int32_t OSNFree; /* Number of memory blocks free                                 */
    int32_t OSNUsed; /* Number of memory blocks used                                 */
} OS_MEM_DATA;
# 2 ".\\src\\os_mem.c" 2

// #define OS_CPU_SR_DEFINE OS_CPU_SR cpu_sr = 0
# 15 ".\\src\\os_mem.c"
static OS_MEM OSMemTbl1 = {.OSMemFreeList = (void*)0};

static OS_MEM OSMemTbl2 = {.OSMemFreeList = &OSMemTbl1};


static OS_MEM OSMemTbl3 = {.OSMemFreeList = &OSMemTbl2};





static OS_MEM *OSMemFreeList = &OSMemTblOS_MAX_MEM_PART;

static void OS_MemClr(int8_t *pdest, int16_t size)
{
    while (size > 0u)
    {
        *pdest++ = (int8_t)0;
        size--;
    }
}

/*

*********************************************************************************************************

*                                        CREATE A MEMORY PARTITION

*

* Description : Create a fixed-sized memory partition that will be managed by uC/OS-II.

*

* Arguments   : addr     is the starting address of the memory partition

*

*               nblks    is the number of memory blocks to create from the partition.

*

*               blksize  is the size (in bytes) of each block in the memory partition.

*

*               perr     is a pointer to a variable containing an error message which will be set by

*                        this function to either:

*

*                        OS_ERR_NONE              if the memory partition has been created correctly.

*                        OS_ERR_MEM_INVALID_ADDR  if you are specifying an invalid address for the memory

*                                                 storage of the partition or, the block does not align

*                                                 on a pointer boundary

*                        OS_ERR_MEM_INVALID_PART  no free partitions available

*                        OS_ERR_MEM_INVALID_BLKS  user specified an invalid number of blocks (must be >= 2)

*                        OS_ERR_MEM_INVALID_SIZE  user specified an invalid block size

*                                                   - must be greater than the size of a pointer

*                                                   - must be able to hold an integral number of pointers

* Returns    : != (OS_MEM *)0  is the partition was created

*              == (OS_MEM *)0  if the partition was not created because of invalid arguments or, no

*                              free partition is available.

*********************************************************************************************************

*/
# 67 ".\\src\\os_mem.c"
OS_MEM *OSMemCreate(void *addr, int32_t nblks, int32_t blksize, int8_t *perr)
{
    OS_MEM *pmem;
    int8_t *pblk;
    void **plink;
    int32_t i;

    ((void)0);

    ((void)0);
    pmem = OSMemFreeList; /* Get next free memory partition                */
    if (OSMemFreeList)
    { /* See if pool of free partitions was empty      */
        OSMemFreeList = (OS_MEM *)OSMemFreeList->OSMemFreeList;
    }
    ((void)0);
    if (!pmem)
    { /* See if we have a memory partition             */
        *perr = 90u;
        return ((OS_MEM *)0);
    }
    plink = (void **)addr; /* Create linked list of free memory blocks      */
    pblk = (int8_t *)((int32_t)addr + blksize);
    for (i = 0; i < (nblks - 1); i++)
    {
        *plink = (void *)pblk; /* Save pointer to NEXT block in CURRENT block   */
        plink = (void **)pblk; /* Position to  NEXT      block                  */
        pblk = (int8_t *)((int32_t)pblk + blksize); /* Point to the FOLLOWING block                  */
    }
    *plink = (void *)0; /* Last memory block points to NULL              */
    pmem->OSMemAddr = addr; /* Store start address of memory partition       */
    pmem->OSMemFreeList = addr; /* Initialize pointer to pool of free blocks     */
    pmem->OSMemNFree = nblks; /* Store number of free blocks in MCB            */
    pmem->OSMemNBlks = nblks;
    pmem->OSMemBlkSize = blksize; /* Store block size of each memory blocks        */
    *perr = 0u;
    return (pmem);
}

/*

*********************************************************************************************************

*                                          GET A MEMORY BLOCK

*

* Description : Get a memory block from a partition

*

* Arguments   : pmem    is a pointer to the memory partition control block

*

*               perr    is a pointer to a variable containing an error message which will be set by this

*                       function to either:

*

*                       OS_ERR_NONE             if the memory partition has been created correctly.

*                       OS_ERR_MEM_NO_FREE_BLKS if there are no more free memory blocks to allocate to caller

*                       OS_ERR_MEM_INVALID_PMEM if you passed a NULL pointer for 'pmem'

*

* Returns     : A pointer to a memory block if no error is detected

*               A pointer to NULL if an error is detected

*********************************************************************************************************

*/
# 126 ".\\src\\os_mem.c"
void *OSMemGet(OS_MEM *pmem, int8_t *perr)
{
    void *pblk;

    ((void)0);

    ((void)0);
    if (pmem->OSMemNFree > 0)
    { /* See if there are any free memory blocks       */
        pblk = pmem->OSMemFreeList; /* Yes, point to next free memory block          */
        pmem->OSMemFreeList = *(void **)pblk; /*      Adjust pointer to new free list          */
        pmem->OSMemNFree--; /*      One less memory block in this partition  */
        ((void)0);
        *perr = 0u; /*      No error                                 */
        return (pblk); /*      Return memory block to caller            */
    }
    ((void)0);
    *perr = 93u; /* No,  Notify caller of empty memory partition  */
    return ((void *)0); /*      Return NULL pointer to caller            */
}

/*$PAGE*/
/*

*********************************************************************************************************

*                                         RELEASE A MEMORY BLOCK

*

* Description : Returns a memory block to a partition

*

* Arguments   : pmem    is a pointer to the memory partition control block

*

*               pblk    is a pointer to the memory block being released.

*

* Returns     : OS_ERR_NONE              if the memory block was inserted into the partition

*               OS_ERR_MEM_FULL          if you are returning a memory block to an already FULL memory

*                                        partition (You freed more blocks than you allocated!)

*               OS_ERR_MEM_INVALID_PMEM  if you passed a NULL pointer for 'pmem'

*               OS_ERR_MEM_INVALID_PBLK  if you passed a NULL pointer for the block to release.

*********************************************************************************************************

*/
# 166 ".\\src\\os_mem.c"
int8_t OSMemPut(OS_MEM *pmem, void *pblk)
{
    ((void)0);

    ((void)0);
    if (pmem->OSMemNFree >= pmem->OSMemNBlks)
    { /* Make sure all blocks not already returned          */
        ((void)0);
        return (94u);
    }
    *(void **)pblk = pmem->OSMemFreeList; /* Insert released block into free block list         */
    pmem->OSMemFreeList = pblk;
    pmem->OSMemNFree++; /* One more memory block in this partition            */
    ((void)0);
    return (0u); /* Notify caller that memory block was released       */
}
