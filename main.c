/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C source file is the main executable C file for the project/command my_ls.
**
**
*/
#include <stdio.h>
#include <dirent.h>
#include "prototypes.h"
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    DIR *folder = folder;
    struct dirent* entry = entry;
    char* input;
    int array[2] = {0,0};
    // execution of basic my_ls command
    if (argc == 1) {
        input = ".";
        lsbasic(folder, entry, input);  // executes ls command for current directory
    }
    // handling my_ls command with one additional input or flag
    else if (argc == 2) {
        flagparse(argv, argc, array);
        if (argv[1][0] != '-') {
            input = argv[1];
            lsbasic(folder, entry,input);
        }
        else if (my_strcmp(argv[1], "-a") ==0) {
            input = ".";
            lsall(folder, entry, input);
        }
        else if (my_strcmp(argv[1], "-t") == 0) {
            input = ".";
            lstime(folder, entry, input);
        }
        else if (my_strcmp(argv[1], "-ta") == 0) {
            input = ".";
            lstimeall(folder, entry, input);
        }
        else {
            printf("my_ls: invalid option -- '%s'\n", argv[1]);
            printf("Try 'ls --help' for more information.\n");
        }
    }

    else if (argc > 2) {
        flagparse(argv, argc, array);
    }
}

    
    





