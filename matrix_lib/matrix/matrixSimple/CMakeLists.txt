cmake_minimum_required(VERSION 3.14)
project(matrix_simple)

file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(MATRIX_SIMPLE ${INCLUDE_DIRS} PARENT_SCOPE)
