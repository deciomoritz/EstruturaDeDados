#include <string>

using namespace std;

class Produto {

	string nome;
	int preco;

public:

	Produto();
	Produto(string n, int p);
	~Produto();
	/** @brief Retorna nome do produto
	 *
	 * @return string
	 *
	 */
	string getNome();
	/** @brief Retorna preço do produto
	 *
	 * @return int
	 *
	 */
	int getPreco();

	/** @brief Usa preço como critério de comparação
	 *
	 */
	bool operator <(Produto & o);

	/** @brief Usa preço como critério de comparação
	 *
	 */
	bool operator >(Produto & o);

	/** @brief Usa preço como critério de comparação
	 *
	 */
	bool operator ==(Produto & o);
};
