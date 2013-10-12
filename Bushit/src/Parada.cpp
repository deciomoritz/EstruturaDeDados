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

bool Parada::operator ==(Parada & p) {
    return cidade.getNome().compare(p.cidade.getNome()) == 0;
}

std::string Parada::toString() {
    return "Nome: " + cidade.getNome() + "\nChegada: " + chegada.toString() + "\nPartida: " + partida.toString() + "\nDescricao: " + cidade.getDescricao();
}

bool Parada::semelhante(Parada p){
    std::string aux = cidade.getNome().substr(0, cidade.getNome().length()-1);
    std::string aux2 = p.cidade.getNome();
    return aux.compare(aux2) == 0;
}

Horario Parada::getHorarioChegada(){
    return chegada;
}
