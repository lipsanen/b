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

add_library(ob_plugin STATIC ob_plugin/plugin.cpp)
target_include_directories(bob PUBLIC ob_plugin/include)
target_link_libraries(ob_plugin PUBLIC bob)

add_library(bp SHARED plugin.cpp)
target_link_libraries(bp PUBLIC ob_plugin)
