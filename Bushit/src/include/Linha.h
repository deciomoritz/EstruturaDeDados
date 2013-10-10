#ifndef LINHA_H
#define	LINHA_H
#include "ListaCircularDuplamenteEncadeada.h"
#include "Parada.h"
#include "Horario.h"

class Linha : public ListaCircularDuplamenteEncadeada<Parada> {

public:

    Linha();
    virtual ~Linha();


    /** @brief mostra a proxima Parada da Linha
     *
     * @param Parada p: Parada referencia;
     *
     * @return Parada
     */
    Parada proxima(Parada p) {
        ElementoDuplo<Parada>* aux;
        aux = cabeca;

        while (p != aux->dado) {
            aux = aux->proximo;
        }

        return aux->proximo->dado;
    }

    /** @brief mostra a parada anterior a uma Parada da Linha
     *
     * @param Parada p: Parada referencia;
     *
     * @return Parada
     */
    Parada anterior(Parada p) {
        ElementoDuplo<Parada>* aux;
        aux = cabeca;

        while (p != aux->dado) {
            aux = aux->proximo;
        }

        return aux->anterior->dado;
    }
};
#endif
