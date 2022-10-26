TARGET = build/tests/test_matrix
TARGET_2 = build/matrix_lib/matrix_calculator

.PHONY: all build rebuild check test memtest covtest clean

all: clean check build test memtest covtest

build:
	./build.sh

rebuild: clean build

check:
	./linters/run.sh

test: build
	./${TARGET}

run: build
	./${TARGET_2}

memtest: build
	./tests/memtest.sh

covtest: test
	./coverage.sh

clean:
	rm -rf build valgrind.log coverage.info
