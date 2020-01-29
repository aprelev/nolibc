#pragma once

#include <nolibc/predefined/language.h>

/* `_Nil` expands to universal zero-initialiser. */
#if !defined _Nil
    #if defined _LANGUAGE_IS_CXX
        #define _Nil \
            {}

    #else
        #define _Nil \
            {0}

    #endif

#endif

/* Defines `nil` convenience macro. */
#if !defined nil && !defined NOLIBC_NO_NIL
    #define nil \
        _Nil

#endif
