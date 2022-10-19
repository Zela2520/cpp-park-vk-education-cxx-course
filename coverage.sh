#!/usr/bin/env bash

set -e

project_dir=$(pwd)

cd build/
lcov -d lib  -t "tests/matrix_tests" -o coverage.info -c --include "$project_dir/matrix/*"
genhtml -o report coverage.info