#!/usr/bin/env bash

set -e
./build/tests/sync_tests

lcov -t build/tests/sync_tests -o coverage.info -c -d build/sync_lib/
genhtml -o build/report/ coverage.info