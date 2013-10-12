#include "EDLinear.h"
#include <stdexcept>

template<typename Tipo>
class ListaArray : public EDLinear<Tipo> {
public:

    using EDLinear<Tipo>::vazia;
    using EDLinear<Tipo>::cheia;
    using EDLinear<Tipo>::arr;
    using EDLinear<Tipo>::tamanho;
    using EDLinear<Tipo>::topo;

    /** @brief adiciona um elemento na posicao desejada
     *
     * @param Tipo t: dado a ser adicionado do tipo definido da classe; int posicao: posicao do vetor onde sera inserido o dado
     *
     * @return void
     *
     * @remarks nao pode ser chamado se a lista estiver cheia. int posicao deve ser positivo e menor igual que tamanho
     */
    void adicionaNaPosicao(Tipo t, int posicao) {
        if (cheia())
            throw std::runtime_error("Lista cheia");
        topo++;
        for (int i = tamanho() - 1; i > posicao; i--)
            arr[i] = arr[i - 1];
        arr[posicao] = t;
    }

    /** @brief adiciona um elemento em uma ordem
     *
     * @param Tipo t: dado a ser adicionado do tipo definido da classe
     *
     * @return void
     *
     * @remarks so funciona corretamente se todos os outros elementos foram inseridos por adicionaEmOrdem
     */
    void adicionaEmOrdem(Tipo t) {
        if (cheia())
            throw std::runtime_error("Lista cheia");
        for (int i = 0; i < tamanho(); i++)
            if (menor(t, arr[i])) {
                adicionaNaPosicao(t, i);
                return;
            }
        adicionaNaPosicao(t, topo + 1);
    }

    /** @brief remove o ultimo elemento da lista
     *
     * @return Tipo
     *
     * @remarks nao pode ser chamado se a lista estiver vazia
     */
    Tipo remover() {
        if (!vazia()) {
            return arr[topo--];
        }
        throw std::runtime_error("Tentando remover elemento de pilha vazia");
    }

    /** @brief remove elemento da posicao indicada
     *
     * @param int posicao: indica a posicao do elemento a ser removido da lista
     *
     * @return Tipo
     *
     * @remarks nao pode ser chamado se a lista estiver vazia. int posicao deve estar nos limiter da lista
     */
    Tipo retiraDaPosicao(int posicao) {
        if (!vazia()) {
            Tipo aux = arr[posicao];
            for (int i = posicao; i < tamanho() - 1; i++)
                arr[i] = arr[i + 1];
            topo--;
            return aux;
        }
        throw std::runtime_error("Tentando remover elemento de pilha vazia");
    }

    /** @brief remove elemento especifico se existir
     *
     * @param Tipo t: dado a ser removido
     *
     * @return Tipo
     *
     * @remarks remove a primeira aparicao do elemento igual ao parametro 't'
     */
    Tipo retiraEspecifico(Tipo t) {
        for (int i = 0; i < tamanho(); i++)
            if (igual(t, arr[i])) {
                return retiraDaPosicao(i);
            }
        throw std::runtime_error("Elemento não encontrado");
    }

    /** @brief informa a posicao de um elemento, se existir
     *
     * @param Tipo t: dado a ser procurado na lista
     *
     * @return int
     *
     * @remarks retorna a posicao da primeira aparicao do elemento igual ao parametro 't'
     */
    int posicao(Tipo t) {
        for (int i = 0; i < tamanho(); i++)
            if (igual(t, arr[i]))
                return i;
        throw std::runtime_error("Elemento não encontrado");
    }

    /** @brief verifica se o elemento existe na lista
     *
     * @param Tipo t: dado a ser pesquisado
     *
     * @return bool
     */
    bool contem(Tipo t) {
        for (int i = 0; i < tamanho(); i++)
            if (igual(t, arr[i]))
                return true;
        return false;
    }

    /** @brief Pega elemento índice i da lista. Método a ser removido
     *
     * @return Elemento retirado da estrutura
     *
     * @remarks Essa função não pode ser chamada com a estrutura vazia
     */
    Tipo mostra(int i) {
        if (!vazia())
            return arr[i];
        throw std::runtime_error("Lista vazia");
    }

    /** @brief Pega índice do último elemento da estrutura
     *
     * @return int
     */
    int verUltimo() {
        return topo;
    }

    /** @brief verifica se os dados no parametro sao iguais.
     *
     * @param Tipo t1, t2: dados a serem comparados
     *
     * @return bool
     *
     * @remarks verifica se t1 eh igual a t2
     */
    bool igual(Tipo t1, Tipo t2) {
        return t1 == t2;
    }

    /** @brief verifica se um dado eh maior que outro.
     *
     * @param Tipo t1, t2: dados a serem comparados
     *
     * @return bool
     *
     * @remarks verifica se t1 eh maior que t2
     */
    bool maior(Tipo t1, Tipo t2) {
        return t1 > t2;
    }

    /** @brief verifica se um dado eh menor que outro.
     *
     * @param Tipo t1, t2: dados a serem comparados
     *
     * @return bool
     *
     * @remarks verifica se t1 eh menor que t2
     */
    bool menor(Tipo t1, Tipo t2) {
        return t1 < t2;
    }
};
