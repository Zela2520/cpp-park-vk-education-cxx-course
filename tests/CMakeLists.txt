cmake_minimum_required(VERSION 3.14)
project(test_matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0 -pthread -lgtest")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} matrix_test.cpp)
target_link_libraries(${PROJECT_NAME} ${MATRIX_LIBRARIES} ${GTEST_LIBRARIES})
