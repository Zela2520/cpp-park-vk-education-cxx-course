cmake_minimum_required(VERSION 3.14)
project(hw)

set(CMAKE_CXX_STANDARD 20)

option(DEBUG "Without optimization" ON)
option(CHECK "Check options" OFF)
option(TEST "Test options" ON)
# option(MEMTEST "Memtest options" OFF)
# option(COV "Coverage options" OFF)

set(RELEASE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -Wpedantic")
set(DEBUG_CXX_FLAGS "-g -O0")
set(TEST_CXX_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -pthread -lgtest")
set(LINKER_CXX_FLAGS "-coverage -lgcov")
set(SANITIZERS_CXX_FLAGS "-fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error")

set(CMAKE_CXX_FLAGS ${RELEASE_CXX_FLAGS})


if(DEBUG)
    set(CMAKE_CXX_FLAGS "${DEBUG_CXX_FLAGS} ${RELEASE_CXX_FLAGS}")
endif()

if(TEST)
    set(CMAKE_CXX_FLAGS "${DEBUG_CXX_FLAGS} ${RELEASE_CXX_FLAGS} ${TEST_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_CXX_FLAGS}")
endif()

add_subdirectory(matrix_lib)

if(TEST)
    if(CHECK)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZERS_CXX_FLAGS}")
    elseif(MEMTEST)
        message("run with memcheck")
    endif()

    enable_testing()
    add_subdirectory(tests)
endif()

