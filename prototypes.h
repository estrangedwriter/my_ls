/*
** QWASAR PROJECT, 2020
** my_ls
** File description: prototypes
** 
** 
*/
#include <dirent.h>

// stringfunctions.c
int my_strlen(char *str);
int my_strcmp(char *param_1, char *param_2);
char* my_strcpy(char* destination, const char* source);

// sortfunctions.c
void selectionSort(char arr[][256], int n) ;
void timesort(int n, char name[][256] , int arr[]);

// directoryfunctions.c
int countdirectory (DIR* folder, struct dirent* entry, char* input);
int printdirectory(char arr[][256], int s);
int printdirectoryall(char arr[][256], int s);
int storearray (DIR* folder, struct dirent* entry, int s, char arr[s][256], char* input);

// optionhandling.c
void lsbasic (DIR* folder, struct dirent* entry, char* input); 
void lsall (DIR* folder, struct dirent* entry, char* input);
int lstime (DIR* folder, struct dirent* entry, char* input);
int lstimeall (DIR* folder, struct dirent* entry, char* input);
int* flagparse (char* userinput[], int argc, int array[2]); 
