TARGET = build/tests/test_set
TARGET_2 = build/set_lib/set

.PHONY: all build rebuild check test memtest covtest clean

all: clean check build test covtest

build:
	./scripts/build.sh

rebuild: clean build

check:
	./scripts/linters.sh

test: build
	./${TARGET}

run: build
	./${TARGET_2}

memtest: build
	./scripts/memtest.sh

covtest: test
	./scripts/coverage.sh

clean:
	rm -rf build valgrind.log coverage.info
