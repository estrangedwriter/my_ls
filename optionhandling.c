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
#include <stdlib.h>

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

int lstime (DIR* folder, struct dirent* entry, char* input) {
    struct stat filestat;
    int s = countdirectory(folder, entry, input);
    int cool[s];
    char arr[s][256];
    int index = 0;
    
    folder = opendir(input);
    if (folder == NULL) {
        return 0;
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
    return 0;
}


int lstimeall (DIR* folder, struct dirent* entry, char* input) {

    struct stat filestat;
    int s = countdirectory(folder, entry, input);
    int cool[s];
    char arr[s][256];
    int index = 0;
    
    folder = opendir(input);
    if (folder == NULL) {
        return 0;
    }
    while ( (entry = readdir(folder)) ) {       // read through the directory and add the objects into the 2d array
        stat(entry->d_name, &filestat);
        my_strcpy(arr[index], entry->d_name);
        cool[index] = filestat.st_mtime;
        index++;
    }
    closedir(folder);                           // close directory and add newline
    timesort(s, arr, cool);                     // timesort the 2d array
    printdirectoryall(arr, s);             // print the 2d array
    return 0;
}

int* flagparse (char* argv[], int argc, int array[3]) {
    
    int index = 1;
    int index2 = 1;

    for (index = 1; index < argc; index++) {

        int length = my_strlen(argv[index]);

        if (argv[index][0] == '-') {
            index2 = 1;
            while (index2 < length) {  
                if (argv[index][index2] == 'a') {
                    array[0] += 1;
                    index2++;
                }
                else if (argv[index][index2] == 't') {
                    array[1] +=1;
                    index2++;
                }
                else if (argv[index][index2] != 'a' && argv[index][index2] != 't') {
                    printf("./my_ls: invalid option -- '%c'\n", argv[index][index2]);
                    printf("Try 'ls --help' for more information.\n");
                    exit(0);
                }
            }
        }
        else if (argv[index][0] != '-') {
            array[2]++;
            continue;
        }
    }
    // for (index = 0; index < 3; index++) {
    //     printf("%d \n", array[index]);
    // }
    return array;
}

int output (DIR* folder, struct dirent* entry, char* argv[], int argc, int array[2]) {

    char* input; 
    int index;
    for (index = 1; index < argc; index ++ ) {
        
        if ( array[0] == 0 && array[1] == 0 )  { 
            if (array[2] == 0) {
                input = ".";
                lsbasic(folder, entry, input);
                break;
            }
            else if (array[2] > 0) {
                if (argv[index][0] != '-') {
                    input = argv[index];
                    printf("%s:\n", input);
                    lsbasic(folder, entry, input);
                    printf("\n");
                }
                else if (argv[index][0] == '-') {
                    continue;
                }
            }
        }
        else if ( array[0] > 0  &&  array[1] == 0 )  {
            if (array[2] == 0) {
                input = ".";
                lsall(folder, entry, input);
                break;
            }
            else if (array[2] > 1) {
                if (argv[index][0] != '-') {
                    input = argv[index];
                    printf("%s:\n", input);
                    lsall(folder, entry, input);
                    printf("\n");
                }
                else if (argv[index][0] == '-') {
                    continue;
                }
            }
        }
        else if ( array[0] == 0 && array[1] > 0)  {
            if (array[2] == 0) {
                input = ".";
                lstime(folder, entry, input);
                break;
            }
            else if (array[2] > 1) {
                if (argv[index][0] != '-') {
                input = argv[index];
                printf("%s:\n", input);
                lstime(folder, entry, input);
                printf("\n");
                }
            }
        }
        else if ( array[0] > 0 && array[1] > 0) {
            if (array[2] == 0) {
                input = ".";
                lstimeall(folder, entry, input);
                break;
            }
            else if (argc > 1) {
                if (argv[index][0] != '-') {
                input = argv[index];
                printf("%s:\n", input);
                lstimeall(folder, entry, input);
                printf("\n");
                }
            }
        }
    }
    return 0;
}
