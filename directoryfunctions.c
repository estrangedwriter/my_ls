/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C source file contains different directory functions to be used in main.c. 
** Countdirectory counts the number of objects within a directory.
** Printdirectory prints the files within a directory.
** Printdirectoryall prints all the objects within a directory including directory types.
** Storearray stores all the names of the objects within a directory, into a 2-d array.
*/
#include "prototypes.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int countdirectory (DIR* folder, struct dirent* entry, char* input) {
    int s = 0;

    folder = opendir(input);
    if(folder== NULL) {
        printf("./my_ls: cannot access '%s': No such file or directory\n", input);
        return(1);
    }
    while ( ( entry = readdir(folder)) ) {
        s++;
    }
    closedir(folder);
    return s;
}

int printdirectory (char arr[][256], int s) {
    int index;
    
    if ( ( s > 2) ) {
        for (index = 0; index < s; index++) {
            if (my_strcmp(arr[index], ".") != 0 && my_strcmp(arr[index], "..") != 0 && arr[index][0] !='.')
                printf("%s  ", arr[index]);
        }
        printf("\n");
    }
    else if ( (s <= 2) ) {
        return 0;    
    }
    return 0;
}

int printdirectoryall (char arr[][256], int s) {
    int index;
    if ( (s > 1) ) {
        for (index = 0; index < s; index++) {
                printf("%s  ", arr[index]);
        }
        printf("\n");
    }

    else if ( (s = 1) ) {
        return 0;
    }

    return 0;
}

int storearray (DIR* folder, struct dirent* entry, int s, char arr[s][256], char* input) {
    int index = 0;
    folder = opendir(input);
    
    if(folder== NULL) {
        return (1);
    }
    while( (entry=readdir(folder)) ) {              // read through the directory and add the objects into the 2d array
        my_strcpy(arr[index], entry->d_name);
        index++;
    }
    closedir(folder);
    return 0;
}
