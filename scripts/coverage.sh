#!/usr/bin/env bash

set -e

project_dir=$(pwd)

cd build/
lcov -d tests  -t "set_lib/set" -o coverage.info -c --include "$project_dir/set_lib/set*"
genhtml -o report coverage.info
