CC := gcc

BUILD_BINARY := $(wildcard build)

DBGCMD = $(CC) build.c -o build $(ALL_FLAGS) -Werror
BUILD_CMD = gcc build.c -o build

BASE_FLAGS = -Wall -Wextra -Wpedantic -std=c99
DEBUG_FLAGS = -g -std=c99 -Wconversion 

ALL_FLAGS = $(BASE_FLAGS) $(DEBUG_FLAGS)

SRC_FILES := arguments configuring error-handling functions globals install programs setup update

OUT = -o setup
BASE_CMD = $(CC) $(SRC_FILES) $(OUT)

FILENAMES := $(addprefix c-scripts/, $(SRC_FILES))
SRC_FILES := $(addsuffix .c, $(FILENAMES))


bin:

ifeq ($(BUILD_BINARY),)
	@$(BUILD_CMD)
endif

macos: setup
setup:
	$(BASE_CMD) $(DEBUG_FLAGS) $(BASE_FLAGS)

log:
	$(DBGCMD)
	@./build std -e log -v

zig: base
base:
	$(BASE_CMD) $(BASE_FLAGS) $(DEBUG_FLAGS)

clean: bin
	@./build clean
