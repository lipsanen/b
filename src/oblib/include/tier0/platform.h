#pragma once

#include <algorithm>

inline void Error(const char* msg)
{

}

inline bool IsPC() { return true; }

#ifndef _WIN32
inline void* _aligned_malloc(size_t size, size_t alignment)
{
    return aligned_alloc(alignment, size);
}
#endif

template <typename T>
void V_swap(T& lhs, T& rhs)
{
    std::swap(lhs, rhs);
}

template <class T>
inline void Construct( T* pMemory )
{
	::new( pMemory ) T;
}

template <class T>
inline void CopyConstruct( T* pMemory, T const& src )
{
	::new( pMemory ) T(src);
}

template <class T>
inline void Destruct( T* pMemory )
{
	pMemory->~T();
}
