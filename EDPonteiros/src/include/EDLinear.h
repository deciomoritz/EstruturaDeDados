#include "EstruturaDeDados.h"

const int MAX = 30;

template<typename Tipo>
class EDLinear: public EstruturaDeDados<Tipo> {

protected:
	Tipo arr[MAX];
	int topo;

public:

	EDLinear() {
		limpar();
	}

	void adicionar(Tipo t) {
		if (!cheia()) {
			topo++;
			arr[topo] = t;
		}
	}

	int tamanho() {
		return topo + 1;
	}

	bool vazia() {
		return topo == -1;
	}

	bool cheia() {
		return topo == (MAX - 1);
	}

	void limpar(){
		topo = -1;
	}
};
