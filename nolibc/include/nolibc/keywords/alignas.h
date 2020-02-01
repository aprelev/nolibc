#pragma once

#include <nolibc/predefined/compiler.h>
#include <nolibc/predefined/language.h>

/* `_Alignas` attribute may be applied to declaration of a variable to
 * specify an alignment requirement.
 */
#if _LANGUAGE_IS_CXX11 || _LANGUAGE_IS_CXX14 || _LANGUAGE_IS_CXX17
    /* We do nothing, `alignas` is a keyword. */

#else
    #if !defined _Align_as
        #if _COMPILER_IS_MSVC
            #define _Align_as(boundary) \
                __declspec(align(boundary))

        #elif _COMPILER_IS_GCC || _COMPILER_IS_CLANG || _COMPILER_IS_ICC
            #define _Align_as(boundary) \
                __attribute__((__aligned__(boundary)))

        #endif

    #endif

    /* Defines `alignas` convenience macro. */
    #if !defined alignas && !define NOLIBC_NO_ALIGNAS
        #define alignas \
            _Align_as

        #define __alignas_is_defined 1

    #endif

#endif
