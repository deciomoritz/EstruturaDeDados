#ifndef LINHA_H
#define	LINHA_H
#include "ListaCircularDuplamenteEncadeada.h"
#include "Parada.h"
#include "Horario.h"

class Linha : public ListaCircularDuplamenteEncadeada<Parada> {
    
    Parada _destino;
    
public:
    
    Linha();
    virtual ~Linha();

    /** @brief mostra a proxima Parada da Linha
     *
     * @param Parada p: Parada referencia;
     *
     * @return Parada
     */
    Parada proxima(Parada p);

    /** @brief mostra a parada anterior a uma Parada da Linha
     *
     * @param Parada p: Parada referencia;
     *
     * @return Parada
     */
    Parada anterior(Parada p);
    
    Parada destino();
    
    void setDestino(Parada p);
};
#endif
