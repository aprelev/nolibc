#pragma once

#include <nolibc/predefined/compiler.h>
#include <nolibc/predefined/language.h>

/* `_Alignof` attribute may be applied to declaration of a variable to
 * get an alignment requirement.
 */

#if _LANGUAGE_IS_CXX11 || _LANGUAGE_IS_CXX14 || _LANGUAGE_IS_CXX17
    /* We do nothing, `alignof` is a keyword. */

#else
    /* We define `alignof` manually. */
    #if !defined _Alignof
        #if _COMPILER_IS_MSVC || _COMPILER_IS_GCC || _COMPILER_IS_CLANG || _COMPILER_IS_ICC
            #define _Alignof(what) \
                __alignof(what)

        #endif
    #endif

    /* Defines `alignas` convenience macro. */
    #if !defined alignof && !define NOLIBC_NO_ALIGNOF
        #define alignof \
            _Alignof

        #define __alignof_is_defined 1

    #endif
#endif