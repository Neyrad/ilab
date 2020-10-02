#include "my_str.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

//------------------------------------------------------------

const int MAX_SIZE = 1000;
const int END      =   -1;

//------------------------------------------------------------

int getLine (char to [], int length); 

//------------------------------------------------------------

int main () {
	char* str1 = (char*) calloc (MAX_SIZE, sizeof (str1 [0]));
	char* str2 = (char*) calloc (MAX_SIZE, sizeof (str2 [0]));
	char* str3 = (char*) calloc (MAX_SIZE, sizeof (str3 [0]));

	getLine (str1, MAX_SIZE);
	getLine (str2, MAX_SIZE);
	getLine (str3, MAX_SIZE);

	char** mass = (char**) calloc (3, sizeof(char*));
	
	* mass      = str1;
	*(mass + 1) = str2;
	*(mass + 2) = str3;

	printf ("before\nmass [0] = %s\n", * mass     );
 	printf (		"mass [1] = %s\n", *(mass + 1));
 	printf (		"mass [2] = %s\n", *(mass + 2));

	qsort (mass, 3, sizeof (char*), my_strcmp);

	printf ("after\nmass [0] = %s\n", * mass     );
 	printf (	   "mass [1] = %s\n", *(mass + 1));
 	printf (       "mass [2] = %s\n", *(mass + 2));

	printf ("hand mode\nmy_strcmp (str1, str2) = %d\n", my_strcmp (str1, str2));
 	printf (	       "my_strcmp (str2, str3) = %d\n", my_strcmp (str2, str3));
 	printf (           "my_strcmp (str3, str1) = %d\n", my_strcmp (str3, str1));

	return 0;
}

//------------------------------------------------------------

int getLine (char to [], int length) {
	int c = 0, i = 0;

	for (i = 0; i < length
		    && (c = getchar ()) != '\n'
		    && c != '\0'
		    && c != EOF; ++i)
		to [i] = c;

	if (i  >= length) {
		assert (i == length);
		--i;
	}
	to [i] = '\0';
	
	if (c == EOF) {
		putchar('\n');
		return END;
	}
}
