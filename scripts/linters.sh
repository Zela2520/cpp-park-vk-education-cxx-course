#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck set_lib/set/*.cpp set_lib/main.cpp --enable=all --inconclusive -I set_lib/set --suppress=missingIncludeSystem

print_header "RUN clang-tidy"
clang-tidy set_lib/set/*.cpp set_lib/main.cpp -- -std=c++20 -Iset_lib/set

print_header "SUCCESS"

# -Iset_lib/set/set_... -Imatrix_lib/matrix/matrixSimple -Imatrix_lib/matrix/matrixCol
