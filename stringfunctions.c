/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C source file contains different string function implementations to be used in main.c. 
** My_strlen reproduces the behavior of the function strlen.
** My_strcmp reproduces the behavior of the function strcmp. 
** My_strcpy reproduces the behavior of the function strcpy.
**
*/

#include "prototypes.h"
#include <stdio.h>

int my_strlen(char *str) {
    
    int length;

    for (length = 0; str[length] != '\0'; length++);
    
    return length;
}

int my_strcmp(char* s1, char* s2) {
    
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char* my_strcpy(char* destination, const char* source) {
	
	if (destination == NULL)
		return NULL;

	char *ptr = destination;
	
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	
	*destination = '\0';
	return ptr;
}
