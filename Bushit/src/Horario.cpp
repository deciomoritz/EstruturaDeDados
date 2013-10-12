#include <stdlib.h>
#include "include/Horario.h"

Horario::Horario() {}

bool Horario::operator<(Horario& hr) {
	if (this->h < hr.h || (this->h == hr.h && this->m < hr.m)
			|| (this->h == hr.h && this->m == hr.m && this->s < hr.s))
		return true;
	return false;
}

std::string Horario::toString() {
	std::stringstream sstm;
	sstm << h << ":" << m;
	return sstm.str();
}

std::ostream& operator<<(std::ostream& out, const Horario &o) {
	out << o.h << ":" << o.m;
	return out;
}

Horario::Horario(Hora hr, Minuto min, Segundo seg) {
	h = hr;
	m = min;
	s = seg;
}

bool Horario::operator!=(Horario& hr){
	return !(h == hr.h) && !(m == hr.m) && !(s == hr.s);
}

Horario Horario::fabrica(int h, int m, int s) {
	Hora hr(h);
	Minuto min(m);
	Segundo seg(s);
	Horario hor(hr, min, seg);
	return hor;
}

float Horario::operator-(Horario& hr){
    return abs(h - hr.h) + abs(m - hr.m)*0.01;
}
