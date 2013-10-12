#include "include/Cidade.h"

Cidade::Cidade() {
}

Cidade::~Cidade() {
}

Cidade::Cidade(std::string n, std::string d){
	descricao = d;
	nome = n;
}

std::string Cidade::getDescricao(){
	return descricao;
}

std::string Cidade::getNome() const{
	return nome;
}

