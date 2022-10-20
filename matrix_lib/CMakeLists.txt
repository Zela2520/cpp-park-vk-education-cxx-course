cmake_minimum_required(VERSION 3.14)
project(matrix_calculator)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/matrix/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/matrix)

add_library(matrix_lib STATIC ${SOURCES})
target_include_directories(matrix_lib PUBLIC ${INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} matrix_lib)

set(MATRIX_LIBRARIES matrix_lib PARENT_SCOPE)
set(MATRIX_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)