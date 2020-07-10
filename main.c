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
    int array[3] = {0,0,0};
    // execution of basic my_ls command
    if (argc == 1) {
        input = ".";
        lsbasic(folder, entry, input);  // executes ls command for current directory
    }
    // handling my_ls command with one additional input or flag
    else if (argc >= 2) {
        flagparse(argv, argc, array);
        output(folder, entry, argv, argc, array);
    }
}