#include "Cidade.h"
#include <ostream>

class Parada {

	Cidade cidade;
	std::string horario;

public:
	Parada();
	virtual ~Parada();

	Parada(Cidade ci, std::string ho);

	bool operator !=(Parada & p);

	std::string toString();
};
