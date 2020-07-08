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

int main(int argc, char* argv[]) {

    DIR *folder = folder;
    struct dirent* entry = entry;
    char* input;
    
    // execution of basic my_ls command
    if (argc == 1) {
        input = ".";
        lsbasic(folder, entry, input);  // executes ls command for current directory
    }
    else if (argc == 2) {

        if (argv[1][0] != '-') {
            input = argv[1];
            lsbasic(folder, entry,input);
        }
        else if (argv[1][0] == '-') {

            if (argv[1][1] == 'a') {
                input = ".";
                lsall(folder, entry, input);
            }
            else if (argv[1][1] == 't') {
                input = ".";
                lstime(folder, entry, input);
            }
        }
    }
    
    else if (argc > 2) {

    }

}




