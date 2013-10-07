#ifndef MINUTO_H
#define	MINUTO_H
#include <string>
#include "Tempo.h"
#include <stdexcept>

class Minuto : public Tempo {
    using Tempo::un;
    using Tempo::tmp;
public:

    /** @brief inicializa Minuto
     *
     * @param int tempo: inteiro referente ao valor de um minuto qualquer
     *
     * @return Minuto
     *
     * @remarks int temp eh um valor no intervalo [0,59]
     */

    Minuto(int temp) {
        if (temp >= 60 || temp < 0)
            throw std::runtime_error("Minutos fora do limite");
        tmp = temp;
        un = 'm';
    }

    Minuto() {
    }
};

#endif	

