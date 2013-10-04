#include "ListaCircularDuplamenteEncadeada.h"
#include "Parada.h"

class Linha : public ListaCircularDuplamenteEncadeada<Parada> {

public:
	Linha();
	virtual ~Linha();

	void adicionarParada(std::string horario, Cidade c) {
		Parada p(c, horario);
		adicionar(p);
	}

	Parada proxima(Parada p) {
		ElementoDuplo<Parada>* aux;
		aux = cabeca;

		while (p != aux->dado) {
			aux = aux->proximo;
		}

		return aux->proximo->dado;
	}

	Parada anterior(Parada p) {
		ElementoDuplo<Parada>* aux;
		aux = cabeca;

		while (p != aux->dado) {
			aux = aux->proximo;
		}

		return aux->anterior->dado;
	}
};
