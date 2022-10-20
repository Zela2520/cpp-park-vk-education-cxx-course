cmake_minimum_required(VERSION 3.14)
project(test_matrix)

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${MATRIX_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${MATRIX_LIBRARIES} ${GTEST_LIBRARIES})

# add_test(
#     NAME ${PROJECT_NAME}
#     COMMAND ${PROJECT_NAME}
# )
gtest_discover_tests(${PROJECT_NAME})