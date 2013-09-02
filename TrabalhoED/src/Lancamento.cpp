#include "include/Lancamento.h"

Lancamento::Lancamento() {
	valor = 0;
	nome = 0;
}

Lancamento::Lancamento(char *n, double v) {
	nome = n;
	valor = v;
}

Lancamento::~Lancamento() {
}

double Lancamento::getValor(){
	return valor;
}

char * Lancamento::getNome(){
	return nome;
}


