#ifndef IMPORTATIONS_H
#define IMPORTATIONS_H

#define True true
#define False false

#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

/**
 * @brief Abstration of our string's characters. Default is that '\0' isnt a char in the string.
 * @details
 * It was preferred to use a proprietary class to avoid using 'a toolbox too big for something small'
 */
class String {
private:

	char* array = nullptr; ///> Pointer to characters
	int size 	=       0; ///> Number of characters valids
	int capacity = 0; ///> Number of char's slots avaiable

public:

	/**
	 * @brief Default Constructor	
	 * @param 
	 */
	String(
		const int& size_to_be_reserve = 1
	){

		this->array = (char*)malloc(size_to_be_reserve * sizeof(char));
		this->size  = 0;
	}

	/**
	 * @brief Character pointer-based constructor
	 * @param conj_de_caracteres Const pointer for characters
	 */
	String(
		const char* conj_de_caracteres
	){

		this->array = (char*)malloc(sizeof(char));

		while(
			conj_de_caracteres[this->size] != '\0'
		){

			array[this->size] = conj_de_caracteres[this->size];
			this->size++;

			array = (char*)realloc(array, (this->size + 1) * sizeof(char));
			this->capacity++;
		}
		array[this->size] = '\0';
	}

	/**
	 * @brief Default Destructor	
	 */
	~String(){ if(array){ free(array); } }

	////////////////////////////////////////////////////////////

	/**
	 * @brief Getter the size
	 */
	inline
	const int&
	get_size() const { return this->size; }

	/**
	 * @brief Getter the pointer character	
	 */
	inline
	const char*
	get_string() const { return this->array; } 

	/**
	 * @brief Increments the size of the character array by one and reallocates to have one more unit available 	
	 * @param to_realloc If you need to relocate, default is True.
	 */
	inline
	void
	incrementer(bool to_realloc = True){
		this->size++;
		if(to_realloc){ this->array = (char*)realloc(this->array, (this->size + 1) * sizeof(char)); this->capacity++;}
	}
};

/**
 * @brief Responsible for represents the process indicators
 */
class ProcessIndicator {
private:

	char process_indicator;
	int position;
	int group;
public:

	ProcessIndicator() = default;

	/**
	 * @brief Constructor that will provide creation and validation methods.	
	 * @param process_indicator Character uppercase alphabetic 
	 * @param position Character's position in the pool 
	 * @param group Character1's group in the message, can be negative.
	 * @details
	 * A process indicator is valid when it is a capital alphabetic letter.
	 */
	ProcessIndicator(
		char process_indicator,
		int  position,
		int  group
	){

		// Verificamos se é válido
		if(
			process_indicator < 'A' || process_indicator >'Z' || position < 0 || position > 4
		){
			
			throw std::invalid_argument("Indicador de Processo inválido!");
		}

		this->process_indicator = process_indicator;
		this->position = position;
		this->group = group;
	}

	const char
	get_char() const { return this->process_indicator; }
};

/**
 * @brief Abstract class to standardize method development
 * @details
 * There's a pattern for method's class:
 * 
 * - cripto
 * Where a message is cripto.
 * - decripto
 * Where a message is decripto
 * - debug
 * Where is possible to see a example
 */
class Method {
private:

	char* keys[2] = {nullptr, nullptr};
	ProcessIndicator process_indicators[2];

public:

	/**
	 * @brief Function that checks if the message size is valid	
	 */
	inline
	static
	bool
	if_size_is_valid(
		const int& size_of_message
	){

		return !( (size_of_message - 2) % 5 );
	}

};

#endif // IMPORTATIONS_H