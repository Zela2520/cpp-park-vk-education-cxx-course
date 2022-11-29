cmake_minimum_required(VERSION 3.14)
project(hw)

set(CMAKE_CXX_STANDARD 20)

option(DEBUG "Without optimization" ON)
option(CHECK "Check options" OFF)
option(TEST "Test options" ON)
option(MEMTEST "Memtest options" ON)
option(COV "Coverage options" ON)

# -Wall -Wextra -Wpedantic -Werror
set(RELEASE_CXX_FLAGS " -Wno-error=deprecated-copy")
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
    if (COV)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_CXX_FLAGS}")
    endif()
endif()

add_subdirectory(set_lib)

if(TEST)
    if(CHECK)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZERS_CXX_FLAGS}")
    elseif(MEMTEST)
        message("run with memcheck")
    endif()

    enable_testing()
    add_subdirectory(tests)
endif()
