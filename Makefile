CC := clang

BASE_FLAGS = -Wall -Wextra -Wpedantic -std=c99
DEBUG_FLAGS = -g -std=c99 -Wconversion 

ALL_FLAGS = $(BASE_FLAGS) $(DEBUG_FLAGS)
SRC_FILES := arguments configuring error-handling functions globals install programs setup update

OUT = -o setup
BASE_CMD = $(CC) $(SRC_FILES) $(OUT)

FILENAMES := $(addprefix src/, $(SRC_FILES))
SRC_FILES := $(addsuffix .c, $(FILENAMES))



macos: setup
setup:
	$(BASE_CMD) $(DEBUG_FLAGS) $(BASE_FLAGS)

zig: base
base:
	$(BASE_CMD) $(BASE_FLAGS) $(DEBUG_FLAGS)

clean:
	rm src/*.o
