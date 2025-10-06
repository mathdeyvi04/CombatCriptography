#ifndef IMPORTATIONS_H
#define IMPORTATIONS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct String
 * @brief Abstration of our string's characters. Default is that '\0' isnt a char in the string.
 */
typedef struct _ {
	char* array;
	int    size;
} String;

/**
 * @brief Responsible for get a empty string from the user
 */
String*
get_string(){

	String* str = (String*)malloc(sizeof(String));
	str->array = (char*)malloc(sizeof(char));
	str->size = 0;

	char caract = '\0';
	while(
		(caract = getchar()) != '\n'
	){

		str->array[str->size] = caract;
		str->size++;

		str->array = (char*)realloc(str->array, (str->size + 1) * sizeof(char));		
	}

	str->array[str->size] = '\0';

	return str;
}

/**
 * @brief Responsible for Clean Up a string corretly.
 * @param str Pointer to a string
 */
void
cleanup(
	String* str
){	
	if(
		str->array != NULL
	){

		free(str->array);
	}

	if(
		str != NULL
	){

		free(str);
	}
}

#endif // IMPORTATIONS_H