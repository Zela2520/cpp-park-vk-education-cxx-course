cmake_minimum_required(VERSION 3.14)
project(matrix_calculator)

# create a static library
add_library(matrix_lib STATIC matrix/matrix.cpp)

# passing the paths for the source files of the library
target_include_directories(matrix_lib PUBLIC matrix)

# create a project
add_executable(${PROJECT_NAME} main.cpp)

# building a project with a static library
target_link_libraries(${PROJECT_NAME} matrix_lib)

# transfer the static library to a higher level
set(MATRIX_LIBRARIES matrix_lib PARENT_SCOPE)