/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C source file handles options/inputs from the end-user.
**
*/
#include <stdio.h>
#include <dirent.h>
#include "prototypes.h"
#include <sys/stat.h>

void lsbasic (DIR* folder, struct dirent* entry, char* input) {
    int s = countdirectory(folder, entry, input);
    char arr[s][256];
    storearray(folder, entry, s, arr, input);  // open the directory and store all of the contents within the 2d array of size 's'
    selectionSort(arr, s);  // sort the 2d array and make it presentable for printing
    printdirectory(arr, s); // print the 2d array
}

void lsall (DIR* folder, struct dirent* entry, char* input) {
    int s = countdirectory(folder, entry, input);
    char arr[s][256];
    storearray(folder, entry, s, arr, input); // open the directory and store all of the contents within the 2d array
    selectionSort(arr, s);    // sort the 2d array and make it presentable for printing
    printdirectoryall(arr, s); // print the 2d array
}
