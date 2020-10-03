#include <stdio.h>
#include <stdlib.h>

int blankfix (char* str);

int blankfix (char* str) {
	int start = 0, counter = 0;
	char* buffer = (char*) calloc (my_strlen (str), sizeof (char));

	for (int i = 0; *(str + i) != '\0'; ++i) {
		if      (*(str + i) == '\t' || *(str + i) == ' ')
			start = i + 1;
		else
			break;
	}

	for (counter = 0; *(str + start + counter) != '\0'; ++counter)
	 	*(buffer + counter) = *(str + start + counter);
	*(buffer + counter) = '\0';
	
	for (int i = 0; (*(str + i) = *(buffer + i)) != '\0'; ++i);
	
	free (buffer);
	return start;
}


