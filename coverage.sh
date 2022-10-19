#!/usr/bin/env bash

set -e

project_dir=$(pwd)

cd build/
lcov -t "tests/matrix_lib/matrix" -o coverage.info -c -d matrix_lib
genhtml -o report coverage.info
 