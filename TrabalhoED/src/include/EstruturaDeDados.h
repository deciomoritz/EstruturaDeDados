template<typename Tipo>
class EstruturaDeDados {

public:

	/** @brief Adiciona elemento na estrutura de dados
	 *
	 * @param t é o elemento que será adicionado à estrutura
	 *
	 * @return void
	 *
	 * @remarks Essa função não pode ser chamada com a estrutura cheia
	 */
	virtual void adicionar(Tipo t) = 0;
	/** @brief Remove elemento da estrutura de dados
	 *
	 * @return Elemento retirado da estrutura
	 *
	 * @remarks Essa função não pode ser chamada com a estrutura vazia
	 */
	virtual Tipo remover() = 0;
	/** @brief Informa tamanho da lista
	 *
	 * @return Inteiro representando o tamanho da lista
	 *
	 */
	virtual int tamanho() = 0;
	/** @brief Informa se lista está cheia
	 *
	 * @return true se lista estiver cheia
	 *
	 */
	virtual bool cheia() = 0;
	/** @brief Informa se lista está vazia
	 *
	 * @return true se lista estiver vazia
	 *
	 */
	virtual bool vazia() = 0;
};
