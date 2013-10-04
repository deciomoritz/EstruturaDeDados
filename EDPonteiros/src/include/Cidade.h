#include <string>

class Cidade {

	std::string descricao;
	std::string nome;

public:
	Cidade();
	Cidade (std::string nome, std::string descricao);
	virtual ~Cidade();

	std::string getDescricao();
	std::string getNome();

};

