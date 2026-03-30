FLAGS = -Werror -Wall -Wextra -pedantic -Werror
ZIG_FLAGS = -Wall -Wextra -pedantic -fsanitize=undefined 
U_FLAGS = -Wno-implicit-function-declaration
NO_ERR_FLAGS = -Wall -Wextra -pedantic 

full_recompilation:
	gcc $(FLAGS) -c c-scripts/programs.c -o c-scripts/programs.o
	gcc $(FLAGS) -c c-scripts/functions.c -o c-scripts/functions.o
	gcc $(FLAGS) -c c-scripts/setup.c -o c-scripts/setup.o
	gcc $(FLAGS) -c c-scripts/install.c -o c-scripts/install.o
	gcc $(FLAGS) -c c-scripts/update.c -o c-scripts/update.o
	gcc $(FLAGS) -c c-scripts/globals.c -o c-scripts/globals.o
	gcc $(FLAGS) -c c-scripts/arguments.c -o c-scripts/arguments.o
	gcc $(FLAGS) -c c-scripts/configuring.c -o c-scripts/configuring.o
	gcc $(FLAGS) -c c-scripts/error-handling.c -o c-scripts/error-handling.o
	@echo "Compiling full application with all warnings treated as errors..."

zig_recompilation:
	@zig cc $(ZIG_FLAGS) -c c-scripts/programs.c -o c-scripts/programs.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/functions.c -o c-scripts/functions.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/setup.c -o c-scripts/setup.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/install.c -o c-scripts/install.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/update.c -o c-scripts/update.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/globals.c -o c-scripts/globals.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/arguments.c -o c-scripts/arguments.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/configuring.c -o c-scripts/configuring.o
	@zig cc $(ZIG_FLAGS) -c c-scripts/error-handling.c -o c-scripts/error-handling.o

user_compilation:
	@gcc $(U_FLAGS) -c c-scripts/programs.c -o c-scripts/programs.o
	@gcc $(U_FLAGS) -c c-scripts/functions.c -o c-scripts/functions.o
	@gcc $(U_FLAGS) -c c-scripts/setup.c -o c-scripts/setup.o
	@gcc $(U_FLAGS) -c c-scripts/install.c -o c-scripts/install.o
	@gcc $(U_FLAGS) -c c-scripts/update.c -o c-scripts/update.o
	@gcc $(U_FLAGS) -c c-scripts/globals.c -o c-scripts/globals.o
	@gcc $(U_FLAGS) -c c-scripts/arguments.c -o c-scripts/arguments.o
	@gcc $(U_FLAGS) -c c-scripts/configuring.c -o c-scripts/configuring.o
	@gcc $(U_FLAGS) -c c-scripts/error-handling.c -o c-scripts/error-handling.o
	@echo "Compiled full package"
	@echo "execute it with: ./setup"
clean: 
	@rm c-scripts/programs.o \
		c-scripts/functions.o \
		c-scripts/setup.o \
		c-scripts/install.o \
		c-scripts/update.o \
		c-scripts/globals.o \
		c-scripts/arguments.o \
		c-scripts/configuring.o \
		c-scripts/error-handling.o

setup: user_compilation
	@gcc $(U_FLAGS) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/globals.o c-scripts/programs.o c-scripts/arguments.c c-scripts/configuring.o c-scripts/error-handling.o -o setup

base: zig_recompilation
	gcc $(ZIG_FLAGS) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/globals.o c-scripts/programs.o c-scripts/arguments.c c-scripts/configuring.o c-scripts/error-handling.o -o setup

full: full_recompilation
	gcc $(FLAGS) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/globals.o c-scripts/programs.o c-scripts/arguments.c c-scripts/configuring.o c-scripts/error-handling.o -o setup
	@echo "Compiled successfully"

force: zig_recompilation
	gcc $(no_err_flags) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/globals.o c-scripts/programs.o c-scripts/arguments.c c-scripts/configuring.o c-scripts/error-handling.o -o setup

