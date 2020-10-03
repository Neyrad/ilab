#include <stdlib.h>

//-----------------------------------------------------------------

const int ERROR = 238;

//-----------------------------------------------------------------

int my_strlen (char* str);
void my_strncopy (char* str2, char* str1, int size);
char* my_strstr (char* str1, char* str2); 
int my_strcmp (const void* stringA, const void* stringB); 
char*  my_strtok (char* ptr, const char* token);
char* my_strncat (char* str1, char* str2);

//-----------------------------------------------------------------

int my_strlen (char* str) {
	int counter = 0;
	for (counter = 0; *(str + counter) != '\0'; ++counter);
	return counter + 1;
}

//-----------------------------------------------------------------

void my_strncopy (char* str2, char* str1, int size) {
	int counter = 0;
	for (counter = 0; counter < size; ++counter)
		*(str2 + counter) = *(str1 + counter);
	*(str2 + counter - 1) = '\0';
}

//-----------------------------------------------------------------

char* my_strstr (char* str1, char* str2) {
	int i = 0, eqsymb = 0;
	int len2 = my_strlen(str2);

	for (i = 0; *(str1 + i) != '\0'; ++i) {
		if (*(str1 + i) == *str2) {
			for (int j = 0; *(str2 + j)     != '\0'
						 && *(str1 + i + j) != '\0'; ++j) {
				if (*(str1 + i + j) == *(str2 + j))
					++eqsymb;
				else
					break;
			}
		}
		if (eqsymb + 1 == len2)
			return str1 + i;
		else
			eqsymb = 0;
	}
	return NULL;
}

//-----------------------------------------------------------------

int my_strcmp (const void* stringA, const void* stringB) {
	const char* strAA = *((const char**) stringA);
	const char* strBB = *((const char**) stringB);

	int i = 0;
	for (i = 0; *(strAA + i) != '\0' 
		 	 && *(strBB + i) != '\0'; ++i) {
		if      (*(strAA + i) < *(strBB + i))
			return -1;
		else if (*(strAA + i) > *(strBB + i))
			return  1;
	}
	if      (*(strAA + i) == '\0'
		  && *(strBB + i) == '\0')
		return  0;
	else if (*(strAA + i) == '\0')
		return -1;
	else if (*(strBB + i) == '\0')
		return  1;
	else
		return ERROR;
}

//-----------------------------------------------------------------

char*  my_strtok (char* ptr, const char* token) {
	int counter = 0;
	for (int j = 0; *(token + j) != '\0'; ++j) {
		for (counter = 0; *(ptr + counter) != *(token + j)
					   && *(ptr + counter) != '\0'; ++counter);
		if (*(ptr + counter) == *(token + j)) {
			*(ptr + counter)  = '\0';
			return ptr;
		}
	}
	return ptr;
}

//-----------------------------------------------------------------

char* my_strncat (char* str1, char* str2) {
	int counter = 0;
	for (counter = 0; *(str1 + counter) != '\0'; ++counter);
	for (int   i = 0; (*(str1 + counter + i) = *(str2 + i)) != '\0'; ++i);
}
