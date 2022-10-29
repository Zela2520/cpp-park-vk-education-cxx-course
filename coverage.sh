#!/usr/bin/env bash

set -e

project_dir=$(pwd)

cd build/
lcov -d tests  -t "matrix_lib/matrix" -o coverage.info -c --include "$project_dir/matrix_lib/matrix*"
genhtml -o report coverage.info
 