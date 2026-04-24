BUILD_BINARY := $(wildcard build)

DBGCMD = zig cc build.c -o build -Wall -Wextra -pedantic -Werror -std=c99

bin:

ifeq ($(BUILD_BINARY),)
	@gcc build.c -o build
endif

full: bin
	@./build gcc -e

setup: bin gcc
gcc: bin
	@./build gcc

log: debug
	@./build std -e log

zig: bin
	@./build std

base: debug
	@./build std -e

debug:
	$(DBGCMD)

clean: bin
	@./build clean
