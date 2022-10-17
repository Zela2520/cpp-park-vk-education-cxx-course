TARGET = build/tests/sync_tests

.PHONY: all build rebuild check test memtest covtest clean

all: clean check build test memtest covtest

build:
	./build.sh

rebuild: clean build

check:
	./linters/run.sh

test:
	./build.sh
	./${TARGET}

memtest:
	./build.sh
	./tests/memtest.sh ./${TARGET}

covtest:
	./build.sh
	./coverage.sh ${TARGET}

clean:
	rm -rf build valgrind.log coverage.info