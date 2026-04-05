BUILD_BINARY := $(wildcard build)

DEBUG_BUILD_COMMAND = build.c -o build -Wall -Wextra -pedantic

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

base: existing_binaries
	@./build zig -e

zig: existing_binaries
	@./build zig

debug:
	zig cc $(DEBUG_BUILD_COMMAND)

clean:
	@./build clean
