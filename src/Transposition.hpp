#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include "Importations.hpp"

/**
 * @brief Grouping Transposition-based Encryption Methods
 */
class Transposition {
public:

	/**
	 * @brief Responsible for grouping the functions of the inversion method
	 */
	class Inversion : public Method {
	public:

		/**
		 * @brief Constructor		
		 */
		Inversion() = default;

		/**
		 * @brief Encryption function
		 * @param message_to_be_crypto Self Explained
		 * @return message_crypted	
		 */
		String
		crypto(
			const String& message_to_be_crypto
		){

			String result;

			while(
				result.get_size() < message_to_be_crypto.get_size()
			){


				result.array[result.get_size()] = message_to_be_crypto.array[message_to_be_crypto.get_size() - 1 - result.get_size()];				
				result.incrementer();
			}
			result.array[result.get_size()] = '\0';

			return result;
		}

		/**
		 * @brief Decryption function
		 * @param message_to_be_decrypto Self Explained
		 * @return message_decrypted
		 * @details
		 * Note that, by isomorphism, it is the same encryption function.	
		 */
		String
		decrypto(
			const String& message_to_be_decrypto
		){

			return crypto(message_to_be_decrypto);
		}

		/**
		 * @brief Debug function
		 */
		static
		void
		debug(){

			Inversion cypher;
			String exemplo("Meu nome eh Matheus");
			printf("String de Teste:       \t'%s'", exemplo.get_string());
			printf("\nApós aplicar crypto: \t'%s'", cypher.crypto(exemplo).get_string());
			printf("\nVoltando:            \t'%s'\n", cypher.decrypto(cypher.crypto(exemplo)).get_string());
		}
	};

	/**
	 * @brief Responsible for grouping the functions of the grids method
	 */
	class Griding : public Method {
	private:
		
		bool grid[30] = {
			1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
			0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
			1, 0, 1, 0, 1, 1, 1, 0, 1, 0,
		};

		ProcessIndicator process_indicators[2];

		////////////////////////////////////////////////////
		/// Funções Inerentes ao Método
		////////////////////////////////////////////////////

	public:

		/**
		 * @brief Constructor	
		 * @param array_to_process_indicators Array reporting process, position and group indicators for each indicator
		 */
		Griding(
			const ProcessIndicator& pi_1,
			const ProcessIndicator& pi_2
		){

			process_indicators[0] = std::move(pi_1);
			process_indicators[1] = std::move(pi_2);
		}

		/**
		 * @brief Encrypted function
		 * @param message_to_be_crypto It is necessary to have 5m - 2 characters.
		 */
		String
		crypto(
			const String& message_to_be_crypto
		){

			if( !Method::if_size_is_valid(message_to_be_crypto.get_size()) ){ throw std::invalid_argument("Mensagem não tem tamanho válido"); }
			
			// ------------------
			// Iniciamos aplicação do algoritmo
			String temp; 


			return temp;
		}




		/**
		 * @brief Debug function for tests		
		 */
		static
		void
		debug(){

			Griding exemplo(
				{'A', 1, 2},
				{'B', 2, 1}
			);







		}



	};
};

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

#endif // TRANSPOSITION_H