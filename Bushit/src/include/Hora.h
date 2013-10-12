#ifndef HORA_H
#define	HORA_H
#include <string>
#include "Tempo.h"
#include <stdexcept>

class Hora : public Tempo {
    using Tempo::un;
    using Tempo::tmp;

public:

    /** @brief inicializa uma Hora
     *
     * @param int tempo: inteiro referente ao valor de uma hora qualquer
     *
     * @return Hora
     *
     * @remarks int temp eh um valor no intervalo [0,23]
     */
    Hora(int temp);

    Hora();
    
    int operator-(Hora& hr);
};



#endif	

