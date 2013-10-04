#include <iostream>

template<typename Tipo>
class ElementoDuplo {

public:

	Tipo dado;
	ElementoDuplo* proximo;
	ElementoDuplo* anterior;

	ElementoDuplo(Tipo d) {
		dado = d;
		proximo = 0;
		anterior = 0;
	}

	ElementoDuplo(){}

};
