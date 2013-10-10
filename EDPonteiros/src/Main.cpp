#include <iostream>
#include "include/Linha.h"

using namespace std;

int main() {

	Linha l;

	Cidade c("Urussanga", "Lugar onde se deu início à vida(literalmente) do nosso querido amigo Luiz");
	Parada p1(c, "12:30");
	l.adicionar(p1);

	Cidade c2("Fplis - UFSC", "Lugar onde se deu fim à vida(figurativamente) do nosso querido amigo Luiz");
	Parada p2(c2, "7:30");
	l.adicionar(p2);

	cout << l.proxima(p1).toString() << endl << endl;

	cout << l.anterior(p2).toString() << endl;

	return 0;
}
