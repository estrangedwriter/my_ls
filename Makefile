
my_ls: main.c sortfunctions.c stringfunctions.c directoryfunctions.c
	gcc -g3 -fsanitize=address -Wall -Werror -Wextra -o my_ls main.c sortfunctions.c stringfunctions.c directoryfunctions.c
