#include "Lancamento.h"
#include "Lista.h"
#include <iostream>

using namespace std;

int main1() {

	Lista<int> l;

	l.adicionarNoInicio(10);
	l.adicionarNoInicio(44);
	l.adicionarNoInicio(56);

	//for(int i=l.getTamanho()-1;i>=0;i--)
		//cout << l.remover() << endl;
	while(!l.vazia())
		cout << l.removerDoInicio() << endl;

	return 0;
}
