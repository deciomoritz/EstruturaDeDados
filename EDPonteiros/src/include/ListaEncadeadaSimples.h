#include "Elemento.h"
#include <stdexcept>

template<typename Tipo>
class ListaEncadeadaSimples{

	Elemento<Tipo>* cabeca;
	int _tamanho;

public:

	ListaEncadeadaSimples() :  cabeca(0), _tamanho(0) {
	}

	void adicionarNoInicio(Tipo t) {
		Elemento<Tipo>* novo;
		novo= new Elemento<Tipo>(t);

		if (novo == 0)
			throw std::runtime_error("Impossível adicionar nova transação! Erro de lista cheia!");
		_tamanho++;
		if (cabeca == 0) {
			cabeca = novo;
			return;
		}
		novo->proximo = cabeca;
		cabeca = novo;
	}

	void adicionar(Tipo t){
		adicionarNaPosicao(t, _tamanho);
	}

	void adicionarNaPosicao(Tipo t, int pos) {
		if (pos < 0 || pos > _tamanho)
			throw std::runtime_error("Deu merda");

		if (pos == 0) {
			adicionarNoInicio(t);
			return;
		}
		Elemento<Tipo> *novo = new Elemento<Tipo>(t);
		Elemento<Tipo> *aux;

		if (novo == 0)
			throw std::runtime_error("Deu merda");
		aux = cabeca;
		for (int i = 1; i < pos; i++)
			aux = aux->proximo;
		novo->proximo = aux->proximo;
		aux->proximo = novo;
		_tamanho++;
	}

	Tipo retirarDaPosicao(int pos) {
		if (pos >= _tamanho)
			throw std::runtime_error("Posição inválida");

		Elemento<Tipo> *aux, *eliminar;
		Tipo retorno;

		if (pos == 0)
			return removerDoInicio();
		aux = cabeca;
		for (int i = 0; i < pos; i++)
			aux = aux->proximo;
		eliminar = aux->proximo;
		retorno = aux->dado;
		aux->proximo = eliminar;
		_tamanho--;
		delete eliminar;
		return retorno;
	}

	Tipo removerDoInicio() {
		if (!vazia()) {
			Elemento<Tipo>* aux = cabeca;
			Tipo dado = cabeca->dado;

			if (_tamanho == 1){
				cabeca = 0;
				_tamanho--;
				return dado;
			}
			_tamanho--;
			cabeca = cabeca->proximo;
			delete aux;
			aux = 0;
			return dado;
		}
		throw std::runtime_error("Tentando remover elemento de lista vazia");
	}

	Tipo mostra(int i) {
		if (i < 0 || i >= _tamanho)
			throw -1;

		if (i == 0)
			return cabeca->dado;

		Elemento<Tipo> *aux;
		aux = cabeca;

		for (int j = 0; j < i; j++)
			aux = aux->proximo;

		return aux->dado;
	}

	void limpar() {
		while (!vazia())
			remover();
	}

	int tamanho() {
		return _tamanho;
	}

	Tipo remover() {
		return retirarDaPosicao(_tamanho - 1);
	}

	virtual bool vazia() {
		return _tamanho == 0;
	}

};
