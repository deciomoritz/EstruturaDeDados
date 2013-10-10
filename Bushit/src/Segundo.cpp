#include "include/Segundo.h"

Segundo::Segundo(int temp) {
	if (temp >= 60 || temp < 0)
		throw std::runtime_error("Segundos fora do limite");
	tmp = temp;
	un = 's';
}

Segundo::Segundo() {
}

