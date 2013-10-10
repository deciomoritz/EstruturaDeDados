#ifndef TEMPO_H
#define	TEMPO_H
#include <ostream>
#include <sstream>
#include <stdexcept>
class Tempo {
protected:
    char un;
    int tmp;
public:

    Tempo() {
    }

    /** @brief Sobrescreve o operador '<<'
     *
     * @param ostream& out: necessario para realizar a funcao; Tempo &o: Tepo a ser impresso
     *
     * @return ostream&
     *
     * @remarks redefine '<<' para imprimir o objeto da forma implementada no metodo
     */
    friend std::ostream& operator<<(std::ostream& out, const Tempo &o) {
        out << o.tmp << o.un;
        return out;
    }

    /** @brief Sobrescreve o operador '<'
     *
     * @param Tempo& t: um dos objetos usados na comparacao
     *
     * @return bool
     *
     * @remarks redefine '<' para permitir comparacao entre objetos Tempo de mesma unidade
     */
    bool operator<(Tempo& t) {
        if (un != t.un)
            throw std::runtime_error("Unidades de tempo diferentes");
        return tmp < t.tmp;
    }

    /** @brief Sobrescreve o operador '=='
     *
     * @param Tempo& t: um dos objetos usados na comparacao
     *
     * @return bool
     *
     * @remarks redefine '==' para permitir comparacao entre objetos Tempo de mesma unidade
     */
    bool operator==(Tempo& t) {
        if (un != t.un)
            throw std::runtime_error("Unidades de tempo diferentes");
        return tmp == t.tmp;
    }

};
#endif

