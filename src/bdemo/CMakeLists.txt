set(SRCS parser.cpp version_utils.cpp)
add_library(bdemo ${SRCS})
target_include_directories(bdemo PUBLIC include)