#include "include/Lancamento.h"
#include <cstring>

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

char* Lancamento::getNome(){
	return nome;
}

Lancamento::Lancamento(const Lancamento& outro) {
	valor = outro.valor;

	int quant;
	quant = strlen(outro.nome);

	nome = new char[quant];
	strcpy(nome, outro.nome);
}
