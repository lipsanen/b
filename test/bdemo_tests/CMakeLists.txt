set(SRCS main_tests.cpp)
add_executable(bdemo_tests ${SRCS})
target_link_libraries(bdemo_tests PRIVATE gtest gtest_main bdemo)
