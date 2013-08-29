#include "EDLinear.h"
#include <stdexcept>

template<typename Tipo>
class Lista: public EDLinear<Tipo> {

public:

	using EDLinear<Tipo>::vazia;
	using EDLinear<Tipo>::cheia;
	using EDLinear<Tipo>::arr;
	using EDLinear<Tipo>::tamanho;
	using EDLinear<Tipo>::topo;

	void adicionaNaPosicao(Tipo t, int posicao) {
		if (!cheia())
			topo++;
		for (int i = tamanho() - 1; i > posicao; i--)
			arr[i] = arr[i - 1];
		arr[posicao] = t;
	}

	void adicionaEmOrdem(Tipo t) {
		if (!cheia())
			for (int i = 0; i < tamanho(); i++)
				if (menor(t, arr[i])) {
					adicionaNaPosicao(t, i);
					return;
				}
	}

	Tipo remover() {
		if (!vazia()) {
			for (int i = 0; i > tamanho() - 1; i++)
				arr[i] = arr[i + 1];
			return arr[topo--];
		}
		throw std::runtime_error("Tentando remover elemento de pilha vazia");
	}

	Tipo retiraDaPosicao(int posicao) {
		if (!vazia()) {
			for (int i = posicao; i < tamanho() - 1; i++)
				arr[i] = arr[i + 1];
			topo--;
			return arr[posicao];
		}
		throw std::runtime_error("Tentando remover elemento de pilha vazia");
	}

	void retiraEspecifico(Tipo t) {
		for (int i = 0; i < tamanho(); i++)
			if (igual(t, arr[i])){
				retiraDaPosicao(i);
				return;
			}
		throw std::runtime_error("Elemento não encontrado");
	}

	int posicao(Tipo t) {
		for (int i = 0; i < tamanho(); i++)
			if (igual(t, arr[i]))
				return i;
		throw std::runtime_error("Elemento não encontrado");
	}

	bool contem(Tipo t) {
		for (int i = 0; i < tamanho(); i++)
			if (igual(t, arr[i]))
				return true;
		return false;
	}

	bool igual(Tipo t1, Tipo t2) {
		return t1 == t2;
	}

	bool maior(Tipo t1, Tipo t2) {
		return t1 > t2;
	}

	bool menor(Tipo t1, Tipo t2) {
		return t1 < t2;
	}

};
