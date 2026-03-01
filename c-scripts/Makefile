FLAGS = -Werror -Wall -Wextra

full_recompilation:
	gcc $(FLAGS) -c programs.c
	gcc $(FLAGS) -c functions.c
	gcc $(FLAGS) -c setup.c
	gcc $(FLAGS) -c install.c
	gcc $(FLAGS) -c update.c
	@echo "Compiling full application"

clean: 
	@rm programs.o \
		functions.o \
		setup.o \
		install.o \
		update.o

setup: full_recompilation
	gcc $(FLAGS) setup.o functions.o install.o update.o programs.o -o setup
	@echo "Compiled successfully"

full: full_recompilation
	gcc $(FLAGS) setup.o functions.o install.o update.o programs.o -o setup
	@echo "Compiled successfully"
