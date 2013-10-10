#include "include/Minuto.h"

Minuto::Minuto(int temp) {
	if (temp >= 60 || temp < 0)
		throw std::runtime_error("Minutos fora do limite");
	tmp = temp;
	un = 'm';
}

Minuto::Minuto() {

}
