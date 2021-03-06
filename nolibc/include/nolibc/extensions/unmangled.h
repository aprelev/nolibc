#pragma once

#include <nolibc/predefined/language.h>

/* Defines export specification for public declarations
 * which require plain C linkage (no mangling).
 */
#if !defined _Unmangled
    #if _LANGUAGE_IS_CXX
        #define _Unmangled \
            extern "C"

    #else
        #define _Unmangled \
            extern

    #endif

#endif
