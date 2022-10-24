#!/usr/bin/env bash

set -e

project_dir=$(pwd)

cd build/
lcov -t "matrix_lib/" -o coverage.info -c -d tests/
genhtml -o report coverage.info
 