cmake_minimum_required(VERSION 3.14)
project(hw)

# option(CHECK "Check options" OFF)
# option(BUILD "Build options" OFF)
# option(TEST "Test options" OFF)
# option(MEMTEST "Memtest options" OFF)
# option(COV "Coverage options" OFF)

add_subdirectory(matrix_lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

add_subdirectory(tests)
