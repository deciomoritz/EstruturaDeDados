#include "Lista.h"
#include <iostream>

using namespace std;

int main() {
	Lista<int> l;

	cout << l.vazia() << endl;

	l.adicionarNoInicio(2);
	l.adicionarNoInicio(3);
	l.adicionarNoInicio(4);

	cout << l.vazia() << endl;

	int a;
	while (!l.vazia()) {
		a = l.removerDoInicio();
		cout << a << endl;
	}

	return 0;
}
