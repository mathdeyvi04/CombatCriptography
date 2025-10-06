#ifndef INVERSION_H
#define INVERSION_H

#include "../importations.h"

/**
 * @brief Apply the method of inversion on the string
 * @param str String to be cript or decript
 * @details
 * 
 * Remember that this method is isomorphic.
 */
String*
apply_inversion(
	String* str
){

	String* output = (String*)malloc(sizeof(String));
	output->array = (char*)malloc(str->size * sizeof(char)); // Already reserve
	output->size = 0;

	while(
		output->size != str->size
	){

		output->array[output->size] = str->array[str->size - 1 - output->size];
		output->size++;
	}

	output->array[output->size] = '\0';

	return output;
}

#endif // INVERSION_H