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
    /** @brief Remove elemento da estrutura de dados e o retorna
     *
     * @return Tipo
     *
     * @remarks Essa função não pode ser chamada com a estrutura vazia
     */
    virtual Tipo remover() = 0;
    /** @brief Retorna número de elementos da estrutura
     *
     * @return int
     *
     */
    virtual int tamanho() = 0;
    /** @brief Retorna true se estrutura estiver vazia
     *
     * @return bool
     *
     */
    virtual bool vazia() = 0;
};
