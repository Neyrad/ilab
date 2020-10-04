#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

//-----------------------------------------------------------------------------------

const int    MAX_SIZE  = 1000;
const int 	 ERROR     =  328;
const double tolerance = 1e-2;

//-----------------------------------------------------------------------------------

int isBlank (wchar_t* string);	
int my_strcmp (const void* stringA, const void* stringB);
int blankfix (wchar_t* str);
int my_strlen (wchar_t* str); 
int isLetter (wchar_t X);
int my_compare (wchar_t A, wchar_t B);

//-----------------------------------------------------------------------------------
 
int main () {

	setlocale (LC_ALL, "ru_RU.utf8");
	FILE *text, *sorted;
	wchar_t str [MAX_SIZE] = {};
	const char path [] = "ONEGIN.txt";
	const char path_out [] = "SORTED_ONEGIN.txt";
	int nStrings = 0;
	int notletters = 0;
	int length = 0;

	text = fopen (path, "r");

	while (fgetws (str, MAX_SIZE, text) != NULL)
		++nStrings;

	fclose (text);	

	wchar_t** mass = (wchar_t**) calloc (nStrings, sizeof (wchar_t*));
	for (int i = 0; i < nStrings; ++i)
		*(mass + i)	= (wchar_t*) calloc (MAX_SIZE, sizeof (wchar_t));
	
	text = fopen (path, "r");

	for (int i = 0; i < nStrings; ++i) {
		fgetws (*(mass + i), MAX_SIZE, text); //how can I put sizeof(...) 
		blankfix (*(mass + i));               //instead of MAX_SIZE ???
	}

	fclose (text);

	qsort (mass, nStrings, sizeof (wchar_t*), my_strcmp);

	sorted = fopen (path_out, "w");

	for (int i = 0; i < nStrings; ++i)
		if (!isBlank (*(mass + i))) {
			notletters = 0;
			length = my_strlen (*(mass + i));
			for (int j = 0; j < length; ++j)
				if ( !isLetter ( *(*(mass + i) + j) ) )
					++notletters;
			if (notletters < length)
				fprintf (sorted, "%ls", *(mass + i));
		}

	fclose (sorted);

	for (int i = 0; i < nStrings; ++i)
		free (*(mass + i));
	free (mass);	

	return 0;
}

//-----------------------------------------------------------------------------------

int isBlank (wchar_t* string) {
	int counter = 0, blanks = 0;
	for (counter = 0; *(string + counter) != '\0'; ++counter)
		if (*(string + counter) == ' '
	    ||  *(string + counter) == '\t'
	    ||  *(string + counter) == '\n')
			++blanks;
	return blanks == counter;
}

//-----------------------------------------------------------------------------------

int my_strcmp (const void* stringA, const void* stringB) {
	const wchar_t* strAA = *((const wchar_t**) stringA);
	const wchar_t* strBB = *((const wchar_t**) stringB);

	int counter = 0;
	int shiftAA = 0;
	int shiftBB = 0;

	for (shiftAA = 0; !isLetter (*(strAA + shiftAA))
	       						  && *(strAA + shiftAA) != '\0'; ++shiftAA);
	for (shiftBB = 0; !isLetter (*(strBB + shiftBB))
								  && *(strBB + shiftBB) != '\0'; ++shiftBB);			
		


	for (counter = 0; *(strAA + shiftAA + counter) != '\0' 
		 	 	   && *(strBB + shiftBB + counter) != '\0'; ++counter) {
		
	
		if      (  my_compare ( *(strAA + shiftAA + counter), *(strBB + shiftBB + counter) ) == 2    ) //the second arg is bigger
			return -1;
		else if (  my_compare ( *(strAA + shiftAA + counter), *(strBB + shiftBB + counter) ) == 1    ) //the first  arg is bigger
			return  1;
	}

	if (*(strAA + shiftAA + counter) == '\0' && !isLetter (*(strAA + shiftAA + counter - 1)))
		return 1;

	if (*(strBB + shiftBB + counter) == '\0' && !isLetter (*(strBB + shiftBB + counter - 1)))
		return -1;

	if      (*(strAA + shiftAA + counter) == '\0'
		  && *(strBB + shiftBB + counter) == '\0')
		return  0;
	else if (*(strAA + shiftAA + counter) == '\0')
		return -1;
	else if (*(strBB + shiftBB + counter) == '\0')
		return  1;
	else
		return ERROR;
}

//-----------------------------------------------------------------------------------
 
int blankfix (wchar_t* str) {
	int start = 0, counter = 0;
	wchar_t* buffer = (wchar_t*) calloc (my_strlen (str), sizeof (wchar_t));

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

//-----------------------------------------------------------------------------------

int my_strlen (wchar_t* str) {
	int counter = 0;
	for (counter = 0; *(str + counter) != '\0'; ++counter);
	return counter + 1;
}

//-----------------------------------------------------------------------------------

int isLetter (wchar_t X) {
	return ((X >= 1040 && X <= 1103) || (X == 1025) || (X == 1105) );
}

//-----------------------------------------------------------------------------------

int my_compare (wchar_t symbA, wchar_t symbB) {

	int A = (int) symbA;
	int B = (int) symbB;

	double myCodeA = 0.0;
	double myCodeB = 0.0;

	if 		(A == 1025) 
		myCodeA = 1045.5;
	else if (A == 1105)
		myCodeA = 1077.5;
	else
		myCodeA = (double) A;

 	if 		(B == 1025) 
		myCodeA = 1045.5;
	else if (B == 1105)
		myCodeB = 1077.5;
	else    
		myCodeB = (double) B;
	
	if 		( (myCodeA - myCodeB) > tolerance )
		return 1;
	else if ( (myCodeB - myCodeA) > tolerance )
		return 2;
	else
		return 0;
}
