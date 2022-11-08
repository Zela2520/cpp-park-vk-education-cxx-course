cmake_minimum_required(VERSION 3.14)
project(test_set)

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${SET_LIBRARIES} ${GTEST_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SET_LIB_INCLUDE_DIRS})

gtest_discover_tests(${PROJECT_NAME})