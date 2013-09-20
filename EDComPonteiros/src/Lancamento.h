class Lancamento {

	char *nome;
	double valor;

public:
	Lancamento();
	Lancamento(char *n, double p);
	virtual ~Lancamento();
	/** @brief Retorna valor do lançamento
	 *
	 * @return double
	 */
	double getValor();
	/** @brief Retorna ponteiro para primeira posição do nome do lançamento
	 *
	 * @return *char
	 */
	char* getNome();

	/** @brief Construtor de cópia do lançamento
	 *
	 * @param outro é o objeto Lancamento a ser copiado
	 *
	 */
	Lancamento(const Lancamento& outro);
};
