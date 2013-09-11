#include "Lancamento.h"
#include "Lista.h"

class ListaContabil : public Lista<Lancamento>{

public:

	ListaContabil();
	virtual ~ListaContabil();

	/** @brief Retorna objeto lançamento de índice i
	 *
	 * @param i é o índice
	 *
	 * @return Lancamento
	 *
	 * @remarks Essa função não pode ser chamada com a estrutura cheia
	 */
	Lancamento mostrar(int i);
};
