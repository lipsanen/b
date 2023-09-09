#pragma once

#include <cstdlib>
#include <cstdio>

#define OSP_ASSERT(expression, ...) if(!(expression)) { \
    fprintf(stderr, __VA_ARGS__); \
}

#define Assert(expression) OSP_ASSERT(expression, #expression)

#ifndef _MSC_VER
#define __cdecl __attribute__((cdecl))
#endif