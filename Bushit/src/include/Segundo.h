#ifndef SEGUNDOS_H
#define	SEGUNDOS_H
#include <string>
#include "Tempo.h"
#include <stdexcept>

class Segundo : public Tempo {
    using Tempo::un;
    using Tempo::tmp;

public:

    /** @brief inicializa Segundo
     *
     * @param int temp: inteiro referente ao valor de um segundo qualquer
     *
     * @return Segundo
     *
     * @remarks int temp eh um valor no intervalo [0,59]
     */
    Segundo(int temp);

    Segundo();


};
#endif	

