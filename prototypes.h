/*
** QWASAR PROJECT, 2020
** my_ls
** File description: prototypes
** 
** 
*/
#include <dirent.h>
#ifndef PROTOTYPES_H
#define PROTOTYPES_H

//. stringfunctions.c
int my_strlen(char *str);
int my_strcmp(char *param_1, char *param_2);
char* my_strcpy(char* destination, const char* source);

//. sortfunctions.c
void selectionSort(char arr[][50], int n) ;
void timesort(int n, char name[][50] , int arr[]);

// directoryfunctions.c
int countdirectory (DIR* folder, struct dirent* entry);
void printdirectory(char arr[][50], int s);
void printdirectoryall(char arr[][50], int s);
#endif