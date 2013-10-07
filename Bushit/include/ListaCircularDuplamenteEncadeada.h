#include "ElementoDuplo.h"
#include <stdexcept>

template<typename Tipo>
class ListaCircularDuplamenteEncadeada {
protected:

    int tamanho;
    ElementoDuplo<Tipo>* cabeca;

public:

    /** @brief cria uma ListaCircularDuplamenteEncadeada com sentinela
     *
     * @return ListaCircularDuplamenteEncadeada
     */
    ListaCircularDuplamenteEncadeada() : cabeca(new ElementoDuplo<Tipo>()), tamanho(0) {
        cabeca->proximo = cabeca;
        cabeca->anterior = cabeca;
    }

    /** @brief adiciona dado no inicio
     *
     * @param Tipo d: dado do tipo definido na classea ser adicionado.
     *
     * @return void
     *
     * @remarks adiciona depois do sentinela, fazendo todas as conexoes necessarias para manter a estrutura
     */
    void adicionarNoInicio(Tipo t) {
        ElementoDuplo<Tipo>* novo;
        novo = new ElementoDuplo<Tipo>(t);

        if (novo == 0)
            throw std::runtime_error("Impossível adicionar nova transação! Erro de lista cheia!");
        tamanho++;

        novo->proximo = cabeca->proximo;
        novo->anterior = cabeca;
        cabeca->proximo = novo;
        novo->proximo->anterior = novo;
    }

    /** @brief adiciona dado no fim
     *
     * @param Tipo d: dado do tipo definido na classea ser adicionado.
     *
     * @return void
     *
     * @remarks adiciona antes do sentinela, fazendo todas as conexoes necessarias para manter a estrutura
     */
    void adicionar(Tipo t) {
        ElementoDuplo<Tipo> *novo = new ElementoDuplo<Tipo>(t);
        if (novo == 0)
            throw std::runtime_error("Deu merda");
        novo->anterior = cabeca->anterior;
        novo->anterior->proximo = novo;
        novo->proximo = cabeca;
        cabeca->anterior = novo;
        tamanho++;
    }

    /** @brief adiciona dado na posicao indicada
     *
     * @param Tipo d: dado do tipo definido na classea ser adicionado; int pos: posicao onde sera inserido o dado
     *
     * @return void
     *
     * @remarks adiciona na posicao correta, fazendo todas as conexoes necessarias para manter a estrutura. posicao deve ser positiva e menos igual a 'tamanho'
     */
    void adicionarNaPosicao(Tipo t, int pos) {
        if (pos < 0 || pos > tamanho)
            throw std::runtime_error("Deu merda");

        if (pos == 0) {
            adicionarNoInicio(t);
            return;
        }
        ElementoDuplo<Tipo> *novo = new ElementoDuplo<Tipo>(t);
        ElementoDuplo<Tipo> *aux;

        if (novo == 0)
            throw std::runtime_error("Deu merda");
        aux = cabeca->proximo;
        for (int i = 1; i < pos; i++)
            aux = aux->proximo;
        novo->proximo = aux->proximo;
        novo->proximo->anterior = novo;
        novo->anterior = aux;
        aux->proximo = novo;
        tamanho++;
    }

    /** @brief remove dado na posicao indicada
     *
     * @param int pos: posicao de onde sera removido o dado
     *
     * @return Tipo
     *
     * @remarks remove da posicao correta, fazendo todas as conexoes necessarias para manter a estrutura. posicao deve ser positiva e menor que 'tamanho'
     */
    Tipo removerDaPosicao(int pos) {
        if (pos >= tamanho || pos <0)
            throw std::runtime_error("Posição inválida");

        ElementoDuplo<Tipo> *aux, *eliminar;
        Tipo retorno;

        if (pos == 0)
            return removerDoInicio();
        aux = cabeca->proximo;
        for (int i = 0; i < pos; i++)
            aux = aux->proximo;
        eliminar = aux;
        eliminar->proximo->anterior = eliminar->anterior;
        eliminar->anterior->proximo = eliminar->proximo;
        retorno = aux->dado;
        tamanho--;
        delete eliminar;
        return retorno;
    }

    /** @brief remove dado no inicio
     *
     * @return void
     *
     * @remarks remove depois do sentinela, fazendo todas as conexoes necessarias para manter a estrutura
     */
    Tipo removerDoInicio() {
        if (!vazia()) {
            ElementoDuplo<Tipo>* aux = cabeca->proximo;
            Tipo dado = aux->dado;
            cabeca->proximo = aux->proximo;
            aux->proximo->anterior = cabeca;
            delete aux;
            tamanho--;
            return dado;
        }
        throw std::runtime_error("Tentando remover ElementoDuplo de lista vazia");
    }

    /** @brief remove dado do fim
     *
     * @return Tipo
     *
     * @remarks remove antes do sentinela, fazendo todas as conexoes necessarias para manter a estrutura
     */
    Tipo remover() {
        if (!vazia()) {
            ElementoDuplo<Tipo>* aux = cabeca->anterior;
            Tipo dado = aux->dado;
            cabeca->anterior = aux->anterior;
            aux->anterior->proximo = cabeca;
            delete aux;
            tamanho--;
            return dado;
        }
        throw std::runtime_error("Tentando remover ElementoDuplo de lista vazia");
    }

    /** @brief retorna o dado da posicao indicada
     *
     * @param int i: posicao indicada
     *
     * @return Tipo
     *
     * @remarks int i deve ser positiva e menor que tamanho
     */
    Tipo mostra(int i) {
        if (i < 0 || i >= tamanho)
            throw -1;

        if (i == 0)
            return cabeca->proximo->dado;

        ElementoDuplo<Tipo> *aux;
        aux = cabeca->proximo;
        for (int j = 0; j < i; j++)
            aux = aux->proximo;

        return aux->dado;
    }

    /** @brief retorna Elemento da ListaCircularDuplamenteEncadeada
     *
     * @param int i: posicao indicada
     *
     * @return ElementoDuplo<Tipo>
     *
     * @remarks int i deve ser positiva e menor que tamanho
     */
    ElementoDuplo<Tipo> getElemento(int i) {
        if (i < 0 || i >= tamanho)
            throw -1;

        if (i == 0)
            return cabeca->proximo->dado;

        ElementoDuplo<Tipo> *aux;
        aux = cabeca->proximo;
        for (int j = 0; j < i; j++)
            aux = aux->proximo;

        return *aux;
    }

    /** @brief limpa a pilha
     *
     * @return void 
     *
     * @remarks elimina elemento a elemento, ate deixar a lista vazia
     */
    void limpar() {
        while (!vazia())
            remover();
    }

    /** @brief retorna o tamanho da lista
     *
     * @return int 
     */
    int getTamanho() {
        return tamanho;
    }

    /** @brief verifica se a lista esta vazia
     *
     * @return bool 
     */
    bool vazia() {
        return tamanho == 0;
    }
};
