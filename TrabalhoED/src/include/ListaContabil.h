#include "Lancamento.h"
#include "Lista.h"

class ListaContabil : public Lista<Lancamento>{

public:

	ListaContabil();
	~ListaContabil();
	Lancamento mostrar(int i);
};
