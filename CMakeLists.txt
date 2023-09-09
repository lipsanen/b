cmake_minimum_required(VERSION 3.15)
project(osp VERSION 1.0.0)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(DEBUG_BUILD "$<CONFIG:Debug>")
set(CMAKE_CXX_STANDARD 20)

if(gcc_like_cxx)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
endif()

add_subdirectory(src)
