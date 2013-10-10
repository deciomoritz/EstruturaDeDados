#include <iostream>

template<typename Tipo>
class ElementoDuplo {
public:

    Tipo dado;
    ElementoDuplo* proximo;
    ElementoDuplo* anterior;

    /** @brief Inicializa um ElementoDuplo
     *
     * @param Tipo d: dado armazenado por ElementoDuplo do tipo definido na classe
     *
     * @return ElementoDuplo
     *
     * @remarks Construtor de um elemento para ser usado em listas do tipo duplamente encadeadas
     */
    ElementoDuplo(Tipo d) {
        dado = d;
        proximo = 0;
        anterior = 0;
    }

    ElementoDuplo() {
    }

};
