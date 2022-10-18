cmake_minimum_required(VERSION 3.14)
project(hw)

add_subdirectory(matrix_lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

# add_subdirectory(tests)