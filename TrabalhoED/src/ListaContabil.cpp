#include "include/ListaContabil.h"

ListaContabil::ListaContabil() {
}

ListaContabil::~ListaContabil() {
}

Lancamento ListaContabil::mostrar(int i) {
	Lancamento l(this->retiraDaPosicao(i));
	adicionaNaPosicao(l, i);
	return l;
}
