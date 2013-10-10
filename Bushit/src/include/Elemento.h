#include <iostream>

template<typename Tipo>
class Elemento {
public:

    Tipo dado;
    Elemento* proximo;

    /** @brief Inicializa um Elemento
     *
     * @param Tipo d: dado armazenado em Elemento do tipo definido na classe
     *
     * @return Elemento
     *
     * @remarks elemento para ser usado em listas com encadeamento simples
     */
    Elemento(Tipo d) {
        dado = d;
        proximo = 0;
    }

};
