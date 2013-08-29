#include <string>

using namespace std;

class Produto {

	string nome;
	int preco;

public:

	Produto();
	Produto(string n, int p);
	~Produto();
	string getNome();
	int getPreco();

	bool operator < (Produto & o);
};
