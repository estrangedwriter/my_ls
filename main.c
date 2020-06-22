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
    struct stat filestat;

    int s = countdirectory(folder, entry);      // first we must open the directory and count how many objects are inside of the directory
    char arr[s][50];                            // initializing a 2d array 'arr' of size 's' that will store all the names of the objects within the directory.
    int index = 0;

    //
    // execution of basic my_ls command
    //
    if (argc == 1) {

        storearray(folder, entry, s, arr);  // open the directory and store all of the contents within the 2d array of size 's'

        selectionSort(arr, s);  // sort the 2d array and make it presentable for printing

        printdirectory(arr, s); // print the 2d array
    }
    //
    // execution of my_ls -a command
    //
    else if ( my_strcmp(argv[1], "-a") == 0 ) {

        storearray(folder, entry, s, arr); // open the directory and store all of the contents within the 2d array

        selectionSort(arr, s);    // sort the 2d array and make it presentable for printing

        printdirectoryall(arr, s); // print the 2d array
    }
    //
    // execution of my_ls -t command
    //
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

    else {
        printf("%s: cannot access '%s': No such file or directory\n", argv[0], argv[1]);
    }
}
