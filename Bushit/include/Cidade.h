#ifndef CIDADE_H
#define	CIDADE_H
#include <string>

class Cidade {
    std::string descricao;
    std::string nome;

public:
    Cidade();
    /** @brief construtor da Classe Cidade
     *
     * @param string nome: Nome da cidade; string descricao: descricao da cidade
     *
     * @return Cidade
     */
    Cidade(std::string nome, std::string descricao);
    virtual ~Cidade();
    /** @brief  Pega a descricao da Cidade
     *
     * @return string
     *
     */
    std::string getDescricao();
    /** @brief  Pega o nome da cidade
     *
     * @return string
     *
     */
    std::string getNome();
};
#endif

