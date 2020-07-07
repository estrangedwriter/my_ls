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

int main(int argc, char* argv[]) {

    DIR *folder = folder;
    struct dirent* entry = entry;
    struct stat filestat = filestat;
    char *input;

    // execution of basic my_ls command
    if (argc == 1) {
        input = ".";
        lsbasic(folder, entry, input);  // executes ls command for current directory
    }
    
    else if (argc > 1) {
        
        if (argv[1][0] != '-') {
            input = argv[1];
            lsbasic(folder, entry, input);
        }
    }
    #if 0
    // execution of my_ls -a command
    else if ( my_strcmp(argv[1], "-a") == 0 ) {
        lsall (folder, entry, s, arr); // executes ls -a command for current directory
    }
    // execution of my_ls -t command
    else if ( my_strcmp(argv[1], "-t") == 0) {
        int cool[s];
        folder = opendir(".");                      // open directory and check if null
        if (folder == NULL) {
            printf("unable to read directory");
            return (1);
        }
        while ( (entry = readdir(folder)) ) {       // read through the directory and add the objects into the 2d array
            stat(entry->d_name, &filestat);
            my_strcpy(arr[index], entry->d_name);
            cool[index] = filestat.st_mtime;
            index++;
        }
        closedir(folder);                           // close directory and add newline
        timesort(s, arr, cool);                     // timesort the 2d array
        printdirectory(arr, s);             // print the 2d array
    }
    #endif 

    else {
        printf("./my_ls: cannot access '%s': No such file or directory\n", argv[1]);
    }
}
