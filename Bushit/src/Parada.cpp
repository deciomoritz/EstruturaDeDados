#include "include/Parada.h"
Parada::Parada() {
}

Parada::~Parada() {
}

Parada::Parada(Cidade ci, Horario cheg, Horario part) {
	cidade = ci;
    chegada = cheg;
	partida = part;
}

bool Parada::operator !=(Parada & p) {
	return cidade.getNome().compare(p.cidade.getNome()) != 0 && chegada != p.chegada && partida != p.partida;
}

std::string Parada::toString(){
	return "Nome: " + cidade.getNome()+"\nChegada: "+ chegada.toString() +"\nPartida: "+partida.toString() + "\nDescricao: " + cidade.getDescricao();
}
