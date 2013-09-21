#include "Lancamento.h"
#include "ListaArray.h"

class ListaContabil : public ListaArray<Lancamento>{

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
