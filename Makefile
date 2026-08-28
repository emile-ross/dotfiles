CC := clang

BASE_FLAGS = -Wall -Wextra -Wpedantic -std=c99 -Wconversion -Wshadow -Wundef -Wcast-qual -Wcast-align
DEBUG_FLAGS = -g -std=c99  

ALL_FLAGS = $(BASE_FLAGS) $(DEBUG_FLAGS)
SRC_FILES := arguments compare configuring errors files functions globals install os packages programs setup update

OUT = -o setup
BASE_CMD = $(CC) $(SRC_FILES) $(OUT)

FILENAMES := $(addprefix src/, $(SRC_FILES))
SRC_FILES := $(addsuffix .c, $(FILENAMES))

setup:
	$(BASE_CMD) $(BASE_FLAGS)

zig: base
base:
	$(BASE_CMD) $(BASE_FLAGS) $(DEBUG_FLAGS) -Werror 

clean:
	rm src/*.o
