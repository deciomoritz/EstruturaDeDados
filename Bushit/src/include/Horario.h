#ifndef HORARIO_H
#define	HORARIO_H
#include <string>
#include <sstream>
#include "Hora.h"
#include "Minuto.h"
#include "Segundo.h"

class Horario {
    Hora h;
    Minuto m;
    Segundo s;
public:

    /** @brief 'fabrica' um Horario
     *
     * @param int h, m, s: inteiros referentes a um numero de horas, minutos e segundos, respectivamente
     *
     * @return Horario
     *
     * @remarks A consistencia dos parametros eh verificada pelas classes Hora, Minuto e Segundo
     */
    static Horario fabrica(int h, int m, int s) {
        Hora hr(h);
        Minuto min(m);
        Segundo seg(s);
        Horario hor(hr, min, seg);
        return hor;
    }

    /** @brief cria um horario
     *
     * @param Hora hr, Minuto min, Segundo seg: representao, respectivamente, a hora, minuto e segundo de um horario
     *
     * @return Horario
     *
     */
    Horario(Hora hr, Minuto min, Segundo seg) {
        h = hr;
        m = min;
        s = seg;
    }

    /** @brief Sobrescreve o operador '<<'
     *
     * @param ostream& out: necessario para realizar a funcao; Horario &o: Horario a ser impresso
     *
     * @return ostream&
     *
     * @remarks redefine '<<' para imprimir o objeto da forma implementada no metodo
     */
    friend std::ostream& operator<<(std::ostream& out, const Horario &o) {
        out << o.h << ":" << o.m;
        return out;
    }

    /** @brief retorna uma string representando o horario 
     *
     * @return string
     *
     * @remarks O horario retornado esta na forma "h:m"
     */
    std::string toString() {
        std::stringstream sstm;
        sstm << h << ":" << m;
        return sstm.str();
    }

    /** @brief Sobrescreve o operado '<'
     *
     * @param Horario& hr: um dos objetos alvos da comparacao
     *
     * @return bool
     *
     * @remarks '<' 'e sobrescrito para permitir comparacao entre objetos do tipo Horario
     */
    bool operator<(Horario& hr) {
        if (this->h < hr.h || (this->h == hr.h && this->m < hr.m) || (this->h == hr.h && this->m == hr.m && this->s < hr.s))
            return true;
        return false;

    }

    Horario() {
    }

};
#endif

