#include "include/Parada.h"

Parada::Parada() {
}

Parada::~Parada() {
}

Parada::Parada(Cidade ci, std::string ho) {
	cidade = ci;
	horario = ho;

}

bool Parada::operator !=(Parada & p) {
	return cidade.getDescricao().compare(p.cidade.getDescricao()) != 0;
}

std::string Parada::toString(){
	return "Nome: " + cidade.getNome() + "\nHorário de chegada: " + horario + "\nDescricao da cidade: " + cidade.getDescricao();
}
