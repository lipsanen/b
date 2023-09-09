 
list(APPEND PLUGIN_SOURCES
 "plugin.cpp"
)

add_library(osplib osplib/utils.cpp)
target_include_directories(osplib PUBLIC osplib/include)

add_library(oblib oblib/utils.cpp)
target_include_directories(oblib PUBLIC oblib/include)
target_link_libraries(oblib INTERFACE osplib)

add_library(osp plugin.cpp)
target_link_libraries(osp PUBLIC osplib oblib)
