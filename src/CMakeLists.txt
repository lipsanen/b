 
list(APPEND PLUGIN_SOURCES
 "plugin.cpp"
)

add_library(osplib osplib/utils.cpp)
target_include_directories(osplib PUBLIC osplib/include)

add_library(oblib oblib/cvar.cpp oblib/strtools.cpp oblib/utlbuffer.cpp oblib/utlstring.cpp)
target_include_directories(oblib PUBLIC oblib/include)
target_link_libraries(oblib PUBLIC osplib)

add_library(osp SHARED plugin.cpp)
target_link_libraries(osp PUBLIC osplib oblib)
