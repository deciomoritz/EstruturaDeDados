#include "Lancamento.h"
#include <cstring>

Lancamento::Lancamento() {
	valor = 0;
	nome = 0;
}

Lancamento::Lancamento(char *n, double v) {
	int quant;
	quant = strlen(n);

	nome = new char[quant];
	strcpy(nome, n);

	valor = v;
}

Lancamento::~Lancamento() {
}

double Lancamento::getValor(){
	return valor;
}

char* Lancamento::getNome(){
	return nome;
}
