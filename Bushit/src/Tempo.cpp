#include "include/Tempo.h"

Tempo::Tempo(){}

bool Tempo::operator==(Tempo& t) {
	if (un != t.un)
		throw std::runtime_error("Unidades de tempo diferentes");
	return tmp == t.tmp;
}

bool Tempo::operator<(Tempo& t) {
    if (un != t.un)
        throw std::runtime_error("Unidades de tempo diferentes");
    return tmp < t.tmp;
}

std::ostream& operator<<(std::ostream& out, const Tempo &o) {
    out << o.tmp << o.un;
    return out;
}
