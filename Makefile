BUILD_BINARY := $(wildcard build)

DBGCMD = zig cc build.c -o build -Wall -Wextra -pedantic -Werror -std=c99
BUILD_CMD = gcc build.c -o build

bin:

ifeq ($(BUILD_BINARY),)
	@$(BUILD_CMD)
endif

full: bin
	@./build gcc -e

setup: bin gcc
gcc: bin
	@./build gcc

macos:
	@$(BUILD_CMD)
	@./build macos

log: debug
	@./build std -e log -v

zig: bin
	@./build std

base: debug
	@./build std -e -v

debug:
	$(DBGCMD)

clean: bin
	@./build clean
