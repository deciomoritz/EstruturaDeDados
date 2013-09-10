#include "EDLinear.h"
#include <stdexcept>

template<typename Tipo>
class Lista : public EDLinear<Tipo> {

    void deslocarBaixo(int posicao) {
        int pos;
        for (pos = topo; pos >= posicao; pos--) {
            arr[pos + 1] = arr[pos];
        }
    }

    void deslocarCima(int posicao) {
        int pos;
        for (pos = posicao; pos <= topo; pos++) {
            arr[pos] = arr[pos + 1];
        }

    }
public:

    using EDLinear<Tipo>::vazia;
    using EDLinear<Tipo>::cheia;
    using EDLinear<Tipo>::arr;
    using EDLinear<Tipo>::tamanho;
    using EDLinear<Tipo>::topo;

    void adicionar(Tipo t) {
        if (!cheia()) {
            arr[topo] = t;
            topo++;
            return;
        }
        throw -2;
    }

    void adicionarNaPosicao(Tipo t, int posicao) {
        if (!cheia() && posicao >= 0 && posicao <= topo + 1) {
            topo++;
            deslocarBaixo(posicao);
            arr[posicao] = t;
            return;
        }
        if (cheia())
            throw -2;
        throw -3;
    }

    void adicionarEmOrdem(Tipo t) {
        if (!cheia())
            for (int i = 0; i < tamanho(); i++)
                if (menor(t, arr[i])) {
                    adicionarNaPosicao(t, i);
                    return;
                }
        throw -2;
    }

    Tipo remover() {
        if (!vazia()) {
            return arr[topo--];
        }
        throw -1;
    }

    Tipo retirarDaPosicao(int posicao) {
        if (!vazia() && posicao >= 0 && posicao <= topo) {
            Tipo aux = arr[posicao];
            deslocarCima(posicao);
            topo--;
            return aux;
        }
        if (vazia())
            throw -1;
        throw -3;
    }

    Tipo retirarEspecifico(Tipo t) {
        return retirarDaPosicao(posicao(t));
    }

    int posicao(Tipo t) {
        for (int i = 0; i < tamanho(); i++)
            if (igual(t, arr[i]))
                return i;
        throw -4;
    }

    bool contem(Tipo t) {
        for (int i = 0; i < tamanho(); i++)
            if (igual(t, arr[i]))
                return true;
        return false;
    }

    bool igual(Tipo t1, Tipo t2) {
        return t1 == t2;
    }

    bool maior(Tipo t1, Tipo t2) {
        return t1 > t2;
    }

    bool menor(Tipo t1, Tipo t2) {
        return t1 < t2;
    }

    //--------------------------------------------------------

    Tipo mostrar(int i) {
        return arr[i];
    }

    Tipo retirarDoInicio() {
        return retirarDaPosicao(0);
    }

    void adicionarNoInicio(Tipo t) {
        adicionarNaPosicao(t, 0);
    }

};