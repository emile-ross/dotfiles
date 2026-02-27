FLAGS = -Werror -Wall -Wextra
U_FLAGS = -Wno-implicit-function-declaration

full_recompilation:
	gcc $(FLAGS) -c c-scripts/programs.c -o c-scripts/programs.o
	gcc $(FLAGS) -c c-scripts/functions.c -o c-scripts/functions.o
	gcc $(FLAGS) -c c-scripts/setup.c -o c-scripts/setup.o
	gcc $(FLAGS) -c c-scripts/install.c -o c-scripts/install.o
	gcc $(FLAGS) -c c-scripts/update.c -o c-scripts/update.o
	@echo "Compiling full application"

user_compilation:
	@gcc $(U_FLAGS) -c c-scripts/programs.c -o c-scripts/programs.o
	@gcc $(U_FLAGS) -c c-scripts/functions.c -o c-scripts/functions.o
	@gcc $(U_FLAGS) -c c-scripts/setup.c -o c-scripts/setup.o
	@gcc $(U_FLAGS) -c c-scripts/install.c -o c-scripts/install.o
	@gcc $(U_FLAGS) -c c-scripts/update.c -o c-scripts/update.o
clean: 
	@rm c-scripts/programs.o \
		c-scripts/functions.o \
		c-scripts/setup.o \
		c-scripts/install.o \
		c-scripts/update.o

setup: user_compilation
	@gcc $(U_FLAGS) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/programs.o -o setup

full: full_recompilation
	gcc $(FLAGS) c-scripts/setup.o c-scripts/functions.o c-scripts/install.o c-scripts/update.o c-scripts/programs.o -o setup
	@echo "Compiled successfully"
