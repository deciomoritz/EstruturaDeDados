#include "EDLinear.h"
#include <stdexcept>

template<typename Tipo>
class Pilha: public EDLinear<Tipo> {

public:

	using EDLinear<Tipo>::vazia;
	using EDLinear<Tipo>::topo;
	using EDLinear<Tipo>::arr;

/** @brief Remove elemento da estrutura de dados
*
* 
* @return Tipo
*
* @remarks Essa função lança uma exceção de chamada com a pilha vazia
*/
	Tipo remover() {
		if (vazia())
			  throw std::runtime_error("Tentando remover  de pilha vazia");
		topo--;
		return arr[topo + 1];
	}
};
