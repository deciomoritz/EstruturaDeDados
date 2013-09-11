#include "Lista.h"
#include <string>

class ListaChar: public Lista<char*> {

	/** @brief Usa ordem alfabética como critério de ordenação
	 *
	 * @return bool
	 *
	 */
	bool igual(char* t1, char* t2);

	/** @brief Usa ordem alfabética como critério de ordenação
	 *
	 * @return bool
	 *
	 */
	bool maior(char* t1, char* t2);

	/** @brief Usa ordem alfabética como critério de ordenação
	 *
	 * @return bool
	 *
	 */
	bool menor(char* t1, char* t2);
};
