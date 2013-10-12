#ifndef PARADA_H
#define	PARADA_H
#include "Cidade.h"
#include <ostream>
#include "Horario.h"

class Parada {
    Cidade cidade;
    Horario chegada;
    Horario partida;

public:
    Parada();
    virtual ~Parada();
    /** @brief cria uma parada
     *
     * @param Cidade ci, Horario cheg, Horario part: contem as informacoes necessarias para criar uma Parada
     *
     * @return Parada
     */
    Parada(Cidade ci, Horario cheg, Horario part);
    /** @brief redefine o operador '!='.
     *
     * @param TParada & p: Parada a ser comparada.
     *
     * @return bool
     *
     * @remarks verifica se a Parada chamadora eh diferente do parametro
     */
    bool operator !=(Parada & p);
    /** @brief retorna string com todas as informacoes da Parada
     *
     * @return string
     */
    std::string toString();
    
    bool semelhante(Parada p);
    
    Horario getHorarioChegada();
    
    bool operator ==(Parada & p);
    
};
#endif

