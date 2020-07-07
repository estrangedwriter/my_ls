/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C source file contains different sort functions to be used in main.c. 
** SelectionSort uses the selection sorting method to sort 2d arrays by alphabetical (ascii decimal) order.
** Swap swaps between 2 parameters within an array.
** Timesort uses the bubblesorting method to sort 2 separate arrays by 'time modified' order.
**
*/
#include "prototypes.h"
#include <stdio.h>

void selectionSort(char arr[][50], int n) 
{ 
    int i, j;
   
    // One by one move boundary of unsorted subarray 
    char minStr[50]; 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        int min_idx = i; 
        my_strcpy(minStr, arr[i]); 
        for (j = i+1; j < n; j++) 
        { 
            // If min is greater than arr[j] 
            if (my_strcmp(minStr, arr[j]) > 0) 
            { 
                // Make arr[j] as minStr and update min_idx 
                my_strcpy(minStr, arr[j]); 
                min_idx = j; 
            } 
        } 
   
        // Swap the found minimum element with the first element 
        if (min_idx != i) 
        { 
            char temp[100]; 
            my_strcpy(temp, arr[i]); //swap item[pos] and item[i] 
            my_strcpy(arr[i], arr[min_idx]); 
            my_strcpy(arr[min_idx], temp); 
        } 
    } 
} 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void timesort(int n, char name[][50] , int arr[]) {

   int i, j; 
   char temp[50];

   for (i = 0; i < n-1; i++)    {
       
        for (j = 0; j < n-i-1; j++)  {
            
            if (arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]); 
                my_strcpy(temp,name[j]);
                my_strcpy(name[j],name[j+1]);
                my_strcpy(name[j+1],temp);
            }
        } 
    }
}

