#include "EstruturaDeDados.h"
#include <stdexcept>
const int MAX = 30000;

template<typename Tipo>
class EDLinear : public EstruturaDeDados<Tipo> {
protected:
    Tipo arr[MAX];
    int topo;

public:

    /** @brief Cria uma estrutura linear
     *
     * @return EDLinear
     *
     */
    EDLinear() {
        limpar();
    }

    /** @brief Adiciona elemento na estrutura de dados
     *
     * @param Tipo t: elemento do tipo definido em EDLinear
     *
     * @return void
     *
     * @remarks Essa função não pode ser chamada com a estrutura cheia
     */
    void adicionar(Tipo t) {
        if (cheia())
            throw std::runtime_error("Estrutura cheia");
        topo++;
        arr[topo] = t;

    }

    /** @brief retorna o tamanho da estrutura
     *
     * @return int
     *
     * @remarks retorna topo+1, pois 'topo' eh a ultima casa ocupada por um elemento e a estrutura come'ca na casa '0'
     */
    int tamanho() {
        return topo + 1;
    }

    /** @brief verifica se a pilha esta vazia
     *
     * @return bool
     *
     */
    bool vazia() {
        return topo == -1;
    }

    /** @brief verifica se a pilha esta cheia
     *
     * @return bool
     *
     */
    bool cheia() {
        return topo == (MAX - 1);
    }

    /** @brief limpa a pilha reinicializando o valor de 'topo'  
     *
     * @return void
     *
     * @remarks 
     */
    void limpar() {
        topo = -1;
    }
};
