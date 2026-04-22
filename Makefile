BUILD_BINARY := $(wildcard build)

DEBUG_BUILD_COMMAND = build.c -o build -Wall -Wextra -pedantic -Werror -std=c99

existing_binaries:

ifeq ($(BUILD_BINARY),)
	@gcc build.c -o build
endif

full: existing_binaries
	@./build gcc -e

gcc: existing_binaries
	@./build gcc

setup: existing_binaries
	@./build gcc

log: existing_binaries
	@./build std -e log

base: existing_binaries
	@./build std -e

zig: existing_binaries
	@./build std

debug:
	zig cc $(DEBUG_BUILD_COMMAND)
	@#./build std

clean:
	@./build clean
