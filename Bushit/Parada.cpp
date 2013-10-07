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
	return cidade.getDescricao().compare(p.cidade.getDescricao()) != 0;
}

std::string Parada::toString(){
	return "Nome: " + cidade.getNome()+"\nChegada: "+ chegada.toString() +"\nPartida: "+partida.toString() + "\nDescricao: " + cidade.getDescricao();
}
