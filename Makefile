CC := gcc

BUILD_BINARY := $(wildcard build)

DBGCMD = zig cc build.c -o build -Wall -Wextra -Wpedantic -Werror -std=c99
BUILD_CMD = gcc build.c -o build

BASE_FLAGS = -Wall -Wextra -Wpedantic -std=c99
DEBUG_FLAGS = -g -std=c99 -Wconversion 

SRC_FILES := arguments configuring error-handling functions globals install programs setup update

OUT = -o setup
BASE_CMD = $(CC) $(SRC_FILES) $(OUT)

FILENAMES := $(addprefix c-scripts/, $(SRC_FILES))
SRC_FILES := $(addsuffix .c, $(FILENAMES))


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
	$(BASE_CMD) $(DEBUG_FLAGS)
	@./build std -e -v



debug:
	$(DBGCMD)

clean: bin
	@./build clean
