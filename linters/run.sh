#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck matrix_lib/matrix/*.cpp matrix_lib/main.c --enable=all --inconclusive -I matrix_lib/matrix --suppress=missingIncludeSystem

print_header "RUN clang-tidy"
clang-tidy matrix_lib/matrix/*.cpp matrix_lib/main.cpp -- -std=c++20 -Imatrix_lib/matrix -Imatrix_lib/matrix/matrixRow -Imatrix_lib/matrix/matrixSimple -Imatrix_lib/matrix/matrixCol

print_header "SUCCESS"
