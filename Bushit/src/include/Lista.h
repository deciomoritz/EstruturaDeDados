#include "Elemento.h"
#include <stdexcept>
#include <string>

template<typename Tipo>

class Lista {

    Elemento<Tipo>* cabeca;
    int _tamanho;

public:

    /** @brief Inicializa Lista
     *
     * @return Lista
     *
     * @remarks inicializa lista encadeada
     */
    Lista() : cabeca(0), _tamanho(0) {
    }

    /** @brief adicona dado no inicio da estrutura
     *
     * @param Tipo t: dado a ser inserido
     *
     * @return void
     */
    void adicionarNoInicio(Tipo t) {
        Elemento<Tipo>* novo;
        novo = new Elemento<Tipo>(t);

        if (novo == 0)
            throw std::runtime_error("Impossível adicionar nova transação! Erro de lista cheia!");
        _tamanho++;
        if (cabeca == 0) {
            cabeca = novo;
            return;
        }
        novo->proximo = cabeca;
        cabeca = novo;
    }

    /** @brief adicona dado no final da estrutura
     *
     * @param Tipo t: dado a ser inserido 
     *
     * @return void
     */
    void adicionar(Tipo t) {
        adicionarNaPosicao(t, _tamanho);
    }

    /** @brief adicona dado na posicao indicada
     *
     * @param Tipo t: dado a ser inserido; int pos: posicao onde sera inserido o dado 
     *
     * @return void
     *
     * @remarks int pos deve ser positiva e menor ou igual a tamanho
     */
    void adicionarNaPosicao(Tipo t, int pos) {
        if (pos < 0 || pos > _tamanho)
            throw std::runtime_error("Deu merda");

        if (pos == 0) {
            adicionarNoInicio(t);
            return;
        }
        Elemento<Tipo> *novo = new Elemento<Tipo>(t);
        Elemento<Tipo> *aux;

        if (novo == 0)
            throw std::runtime_error("Deu merda");
        aux = cabeca;
        for (int i = 1; i < pos; i++)
            aux = aux->proximo;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        _tamanho++;
    }

    /** @brief remove dado do inicio da estrutura
     *
     * @param int pos: posicao da remocao
     *
     * @return Tipo
     *
     * @remarks int pos deve ser positiva e menor que tamanho
     */
    Tipo retirarDaPosicao(int pos) {
        if (pos >= _tamanho || pos < 0)
            throw std::runtime_error("Posição inválida");

        Elemento<Tipo> *aux, *eliminar;
        Tipo retorno;

        if (pos == 0)
            return removerDoInicio();
        aux = cabeca;
        for (int i = 0; i < pos; i++)
            aux = aux->proximo;
        eliminar = aux->proximo;
        retorno = aux->dado;
        aux->proximo = eliminar;
        _tamanho--;
        delete eliminar;
        return retorno;
    }

    /** @brief remove dado do inicio da estrutura
     *
     * @return Tipo
     */
    Tipo removerDoInicio() {
        if (!vazia()) {
            Elemento<Tipo>* aux = cabeca;
            Tipo dado = cabeca->dado;

            if (_tamanho == 1) {
                cabeca = 0;
                _tamanho--;
                return dado;
            }
            _tamanho--;
            cabeca = cabeca->proximo;
            delete aux;
            aux = 0;
            return dado;
        }
        throw std::runtime_error("Tentando remover elemento de lista vazia");
    }

    /** @brief remove elemento do final da estrutura 
     *
     * @return Tipo
     */
    Tipo remover() {
        return retirarDaPosicao(_tamanho - 1);
    }

    /** @brief retorna dado na posicao indicada
     *
     * @param int i: posicao do dado a ser retornado 
     *
     * @return Tipo
     *
     * @remarks int i deve ser positiva e menor que tamanho
     */
    Tipo mostra(int i) {
        if (i < 0 || i >= _tamanho)
            throw -1;

        if (i == 0)
            return cabeca->dado;

        Elemento<Tipo> *aux;
        aux = cabeca;

        for (int j = 0; j < i; j++)
            aux = aux->proximo;

        return aux->dado;
    }

    /** @brief limpa a estrutura
     *
     * @return void 
     *
     * @remarks remove todos os dados ate deixar a estrutura vazia.
     */
    void limpar() {
        while (!vazia())
            remover();
    }

    /** @brief retorna o tamanho da estrutura
     *
     * @return int
     */
    int tamanho() {
        return _tamanho;
    }

    /** @brief verifica se a estrutura esta vazia
     *
     * @return bool
     */
    virtual bool vazia() {
        return _tamanho == 0;
    }

};
