add_subdirectory(bdemo)

list(APPEND PLUGIN_SOURCES
 "plugin.cpp"
)

add_library(osplib osplib/utils.cpp)
target_include_directories(osplib PUBLIC osplib/include)

add_library(mathlib INTERFACE)
target_include_directories(mathlib INTERFACE mathlib/include)

add_library(bob STATIC bob/cvar.cpp bob/interface_connect.cpp bob/strtools.cpp bob/utlbuffer.cpp bob/utlstring.cpp)
target_include_directories(bob PUBLIC bob/include)
target_link_libraries(bob PUBLIC osplib mathlib)

add_library(osp SHARED plugin.cpp)
target_link_libraries(osp PUBLIC osplib bob)
