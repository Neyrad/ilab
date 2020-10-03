#include "my_str.h"
#include "blankfix.h"

const int MAX_SIZE = 1000;

int isBlank (char* string);	

int main () {
	FILE *text, *sorted;
	char str [MAX_SIZE] = {};
	char path [] = "hamlet.txt";
	char path_out [] = "sortedDUMB.txt";
	int nStrings = 0;

	text = fopen (path, "r");

	while (fgets (str, sizeof (str), text) != NULL)
		++nStrings;

	fclose (text);	

	char** mass = (char**) calloc (nStrings, sizeof (char*));
	for (int i = 0; i < nStrings; ++i)
		*(mass + i)	= (char*) calloc (MAX_SIZE, sizeof (char));
	
	text = fopen (path, "r");

	for (int i = 0; i < nStrings; ++i) {
		fgets (*(mass + i), MAX_SIZE, text); 
		blankfix (*(mass + i));
	}
//how can I put sizeof(...) instead of MAX_SIZE ???

	fclose (text);

	qsort (mass, nStrings, sizeof (char*), my_strcmp);

	sorted = fopen (path_out, "w");

	for (int i = 0; i < nStrings; ++i)
		if (!isBlank (*(mass + i)))
			fprintf (sorted, "%s", *(mass + i));

	fclose (sorted);

	for (int i = 0; i < nStrings; ++i)
		free (*(mass + i));
	free (mass);	

	return 0;
}

int isBlank (char* string) {
	int counter = 0, blanks = 0;
	for (counter = 0; *(string + counter) != '\0'; ++counter)
		if (*(string + counter) == ' '
	    ||  *(string + counter) == '\t'
	    ||  *(string + counter) == '\n')
			++blanks;
	return blanks == counter;
}
