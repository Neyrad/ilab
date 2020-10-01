#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getLine.h"

const int ERROR = 328;

int my_strcmp (char* stringA, char* stringB); 
char*  my_strtok (char* ptr, const char token);
char* my_strcat (char* str1, const char* str2);

int main () {
	char* str1 = (char*) calloc (50, sizeof (str1 [0]));
	char* str2 = (char*) calloc (50, sizeof (str2 [0]));

	getLine (str1, 200);
	getLine (str2, 50);


	int flag = my_strcmp (str1, str2);
	printf ("The %d line is bigger (B > A)\n", my_strcmp (str1, str2));
	printf ("str1: %s\n", str1);
	printf ("str2: %s\n", str2);
	printf ("my_strtok (str1, '7'): %s\n", my_strtok (str1, '7'));
	my_strcat (str1, str2);

	printf ("after my_strcat (str1, str2): str1: %s\n", str1);
	return 0;
}

int my_strcmp (char* stringA, char* stringB) {
	int i = 0;
	for (i = 0; stringA [i] != '\0' && stringB [i] != '\0'; ++i) {
		if      (stringA [i] < stringB [i])
			return 2;
		else if (stringA [i] > stringB [i])
			return 1;
	}
	if      (stringA [i] == '\0' && stringB [i] == '\0')
		return 0;
	else if (stringA [i] == '\0')
		return 2;
	else if (stringB [i] == '\0')
		return 1;
	else
		return ERROR;
}

char*  my_strtok (char* ptr, const char token) {
	int i = 0;
	for (i = 0; *(ptr + i) != token && *(ptr + i) != '\0'; ++i);
	if (*(ptr + i) == token) 
		*(ptr + i) = '\0';
	return ptr;
}

char* my_strcat (char* str1, const char* str2) {
	int counter = 0;
	for (counter = 0; *(str1 + counter) != '\0'; ++counter);
	printf ("counter = %d\n", counter);
	for (int   i = 0; (*(str1 + counter + i) = *(str2 + i)) != '\0'; ++i)
/*		printf ("*(str + counter + i) = %c, *(str2 + i) = %c\n", *(str1 + counter + i), *(str2 + i)) */;
}
