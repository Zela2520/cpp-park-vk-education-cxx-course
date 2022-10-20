cmake_minimum_required(VERSION 3.14)
project(test_matrix)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} matrix_test.cpp)
target_link_libraries(${PROJECT_NAME} ${MATRIX_LIBRARIES} ${GTEST_LIBRARIES})

# add_test(
#     NAME ${PROJECT_NAME}
#     COMMAND ${PROJECT_NAME}
# )
gtest_discover_tests(${PROJECT_NAME})