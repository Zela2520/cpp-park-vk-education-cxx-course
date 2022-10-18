cmake_minimum_required(VERSION 3.14)
project(matrix_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")

enable_testing()
find_package(GTest REQUIRED)

set(SOURCE_MATRIX_TESTS matrix_test.cpp)

add_executable(matrix_tests ${SOURCE_MATRIX_TESTS})
target_link_libraries(matrix_tests ${MATRIX_LIBRARIES} ${GTEST_LIBRARIES})
