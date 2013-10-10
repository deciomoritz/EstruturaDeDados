#include "include/Hora.h"

Hora::Hora(int temp) {
	if (temp >= 24 || temp < 0)
		throw std::runtime_error("Hora fora do limite");
	tmp = temp;
	un = 'h';
}

Hora::Hora() {
}
