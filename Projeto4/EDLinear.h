/* 
 * File:   EDLinear.h
 * Author: lhc
 *
 * Created on 28 de Agosto de 2013, 19:31
 */

#ifndef EDLINEAR_H
#define	EDLINEAR_H
#include "EstruturaDeDados.h" 

const int MAX = 3;

template<typename Tipo>
class EDLinear: public EstruturaDeDados<Tipo> {

protected:
	Tipo arr[MAX];
	int topo;

public:

	EDLinear() {
		topo = -1;
	}

	void adiciona(Tipo t) {
		if (!cheia()) {
			topo++;
			arr[topo] = t;
		}
	}

	int tamanho() {
		return topo+1;
	}

	bool vazia() {
		return topo == -1;
	}

	bool cheia() {
		return topo == (MAX - 1);
	}

	void limpar(){
		topo = -1;
	}
        Tipo mostra(int i){
            return arr[i];
        }
};


#endif	/* EDLINEAR_H */

