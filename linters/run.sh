#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
cppcheck sync_lib/**/*.c async_lib/**/*.c sync_lib/main.c async_lib/main.c --enable=all --inconclusive --error-exitcode=1 -I sync_lib/matrix -I async_lib/matrix -I async_lib/processes --suppress=missingIncludeSystem

print_header "RUN clang-tidy"
clang-tidy sync_lib/**/*.c async_lib/**/*.c sync_lib/main.c async_lib/main.c -- -std=gnu99 -Isync_lib/matrix -Iasync_lib/processes -Iasync_lib/matrix

print_header "SUCCESS"
