#include "include/Produto.h"

Produto::Produto(string n, int p){
	nome = n;
	preco = p;
}

Produto::~Produto(){

}

Produto::Produto(){

}

string Produto::getNome() {
	return nome;
}

int Produto::getPreco() {
	return preco;
}

bool Produto::operator <(Produto& o) {
	return this->preco < o.preco;
}

bool Produto::operator >(Produto& o) {
	return this->preco > o.preco;
}

bool Produto::operator ==(Produto& o) {
	return this->preco == o.preco;
}
