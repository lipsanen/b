add_subdirectory(bdemo)

list(APPEND PLUGIN_SOURCES
 "plugin.cpp"
)

list(APPEND COMMON_PLUGIN_SOURCES
 "bcommon/feature.cpp"
 "bcommon/plugin.cpp"
)

add_library(mathlib INTERFACE)
target_include_directories(mathlib INTERFACE mathlib/include)

add_library(tier0 STATIC tier0/dbg.cpp)
target_include_directories(tier0 PUBLIC tier0/include)

# Orangebox
add_library(bob STATIC bob/cvar.cpp bob/interface_connect.cpp bob/strtools.cpp bob/utlbuffer.cpp bob/utlstring.cpp)
target_include_directories(bob PUBLIC bob/include)
target_link_libraries(bob PUBLIC mathlib tier0)

add_library(ob_plugin STATIC ob_plugin/plugin.cpp ${COMMON_PLUGIN_SOURCES})
target_include_directories(ob_plugin PRIVATE bcommon/include)
target_compile_definitions(ob_plugin PRIVATE bcommon=bcommon_ob)
target_include_directories(ob_plugin PUBLIC ob_plugin/include)
target_compile_definitions(ob_plugin PUBLIC SSDK2007)
target_link_libraries(ob_plugin PRIVATE bob)

# Steampipe
add_library(bipe STATIC bipe/cvar.cpp bipe/interface_connect.cpp bipe/strtools.cpp bipe/utlbuffer.cpp bipe/utlstring.cpp)
target_include_directories(bipe PUBLIC bipe/include)
target_link_libraries(bipe PUBLIC mathlib tier0)

add_library(steampipe_plugin STATIC steampipe_plugin/plugin.cpp ${COMMON_PLUGIN_SOURCES})
target_include_directories(steampipe_plugin PRIVATE bcommon/include)
target_compile_definitions(steampipe_plugin PRIVATE bcommon=bcommon_steampipe)
target_include_directories(steampipe_plugin PUBLIC steampipe_plugin/include)
target_compile_definitions(steampipe_plugin PUBLIC STEAMPIPE)
target_link_libraries(steampipe_plugin PRIVATE bipe)

add_library(bp SHARED plugin.cpp)
target_link_libraries(bp PUBLIC ob_plugin steampipe_plugin)
