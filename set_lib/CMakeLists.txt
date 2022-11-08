cmake_minimum_required(VERSION 3.14)
project(set)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/set/*.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/set)

add_library(set_lib ${SOURCES})
target_include_directories(set_lib PUBLIC ${INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC set_lib)

set(SET_LIBRARIES set_lib PARENT_SCOPE)
set(SET_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
