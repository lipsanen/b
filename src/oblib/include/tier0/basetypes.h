#pragma once

#include <cstdint>
#include <cmath>

typedef float vec_t;
typedef uint8_t byte;

inline float FloatMakePositive( vec_t f )
{
	return (float)fabs( f );
}

inline bool IsFinite(float f) { return std::isfinite(f); }
