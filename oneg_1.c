#include "my_str.h"
#include <stdio.h>
#include <assert.h>

//------------------------------------------------------------

const int MAX_SIZE = 1000;
const int END      =   -1;

//------------------------------------------------------------

int getLine (char to [], int length); 
int isBlank (char* string);
 
//------------------------------------------------------------

int main () {

	int nStrings = -1;
	char str [MAX_SIZE] = {};

	printf ("\n  *** StringSorter by Neyrad, 2020 *** \n"  );
	printf ("\n>>> How many strings do you want to sort?\n");
	printf ("\n>>> Enter a number: "                       );

	fgets (str, sizeof (str), stdin);
	while (sscanf (str, "%d", &nStrings) != 1) {
		printf (">>> Wrong input. Try again please: ");
		fgets (str, sizeof (str), stdin);
	}

	char **mass = (char**) calloc (nStrings, sizeof(char*));

	for (int i = 0; i < nStrings; ++i) 
		*(mass + i) = (char*) calloc (MAX_SIZE, sizeof (char));

	for (int i = 0; i < nStrings; ++i)
		getLine (*(mass + i), MAX_SIZE);

	qsort (mass, nStrings, sizeof (char*), my_strcmp);

	printf ("\n>>> Output:\n\n");
	for (int i = 0; i < nStrings; ++i)
		if (!isBlank (*(mass + i)))
 			printf ("%s\n", *(mass + i));
	printf ("\n");

	for (int i = 0; i < nStrings; ++i)
		free (*(mass + i));

	free (mass);

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
		putchar ('\n');
		return END;
	}
}

//------------------------------------------------------------

int isBlank (char* string) {
	int counter = 0, blanks = 0;
	for (counter = 0; *(string + counter) != '\0'; ++counter)
		if (*(string + counter) == ' '
	    ||  *(string + counter) == '\t')
			++blanks;
	return blanks == counter;
}
