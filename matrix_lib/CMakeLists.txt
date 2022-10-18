cmake_minimum_required(VERSION 3.14)
project(matrix_calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-std=gnu99 -g -O0 -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

# create a static library
add_library(matrix_lib STATIC matrix/matrix.cpp)

# passing the paths for the source files of the library
target_include_directories(matrix_lib PUBLIC matrix)

# create a project
add_executable(${PROJECT_NAME} main.c)

# building a project with a static library
target_link_libraries(${PROJECT_NAME} matrix_lib)

# transfer the static library to a higher level
set(MATRIX_LIBRARIES matrix_lib PARENT_SCOPE)