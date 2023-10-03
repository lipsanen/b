set(SRCS main_tests.cpp)
add_executable(plugin_tests ${SRCS})
target_link_libraries(plugin_tests PRIVATE gtest gtest_main steampipe_plugin ob_plugin)
