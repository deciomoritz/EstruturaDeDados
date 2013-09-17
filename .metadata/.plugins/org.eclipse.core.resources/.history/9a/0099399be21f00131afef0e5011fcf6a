#include "Elemento.h"
#include <stdexcept>

template<typename Tipo>
class Lista{

	Elemento<Tipo>* cabeca;
	int tamanho;

public:

	Lista() : cabeca(0), tamanho(0){}

	void adicionarNoInicio(Tipo t){
		Elemento<Tipo>* novo = new Elemento<Tipo>(t,0);
		tamanho++;
		if(cabeca == 0){
			cabeca = novo;
			return;
		}
		novo->proximo = cabeca;
		cabeca = novo;
	}

	Tipo removerDoInicio(){
		if(!vazia()){
			Elemento<Tipo>* aux = cabeca;
			if(tamanho == 1)
				cabeca = 0;
			else
				cabeca = cabeca->proximo;
			tamanho--;
			return aux->dado;
		}
		throw std::runtime_error("Tentando remover elemento de lista vazia");
	}

	bool vazia(){
		return cabeca == 0;
	}
};
