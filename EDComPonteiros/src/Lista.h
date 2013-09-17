#include "Elemento.h"

template<typename Tipo>
class Lista{

	Elemento<Tipo>* cabeca;
	int tamanho;

public:

	Lista() : cabeca(NULL), tamanho(0){
	}

	void adicionarNaCabeca(Tipo t){
		Elemento<Tipo>* novo = new Elemento<Tipo>(t,0);

		if(cabeca == 0){
			cabeca = novo;
			return;
		}
		novo->proximo = cabeca;
		cabeca = novo;
	}
};
