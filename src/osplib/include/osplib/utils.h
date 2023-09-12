#pragma once

#include <cstdlib>
#include <cstdio>

#define OSP_ASSERT(expression, ...) if(!(expression)) { \
    fprintf(stderr, __VA_ARGS__); \
}

#define Assert(expression) OSP_ASSERT(expression, #expression)

#ifndef _WIN32
#define __cdecl 
#endif