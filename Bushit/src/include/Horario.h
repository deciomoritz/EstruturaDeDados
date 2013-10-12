#ifndef HORARIO_H
#define	HORARIO_H
#include <string>
#include <sstream>
#include "Hora.h"
#include "Minuto.h"
#include "Segundo.h"

class Horario {
	Hora h;
	Minuto m;
	Segundo s;
public:

	/** @brief 'fabrica' um Horario
	 *
	 * @param int h, m, s: inteiros referentes a um numero de horas, minutos e segundos, respectivamente
	 *
	 * @return Horario
	 *
	 * @remarks A consistencia dos parametros eh verificada pelas classes Hora, Minuto e Segundo
	 */
	static Horario fabrica(int h, int m, int s);

	/** @brief cria um horario
	 *
	 * @param Hora hr, Minuto min, Segundo seg: representao, respectivamente, a hora, minuto e segundo de um horario
	 *
	 * @return Horario
	 *
	 */
	Horario(Hora hr, Minuto min, Segundo seg);

	/** @brief Sobrescreve o operador '<<'
	 *
	 * @param ostream& out: necessario para realizar a funcao; Horario &o: Horario a ser impresso
	 *
	 * @return ostream&
	 *
	 * @remarks redefine '<<' para imprimir o objeto da forma implementada no metodo
	 */
	friend std::ostream& operator<<(std::ostream& out, const Horario &o);

	/** @brief retorna uma string representando o horario
	 *
	 * @return string
	 *
	 * @remarks O horario retornado esta na forma "h:m"
	 */
	std::string toString();

	/** @brief Sobrescreve o operado '<'
	 *
	 * @param Horario& hr: um dos objetos alvos da comparacao
	 *
	 * @return bool
	 *
	 * @remarks '<' 'e sobrescrito para permitir comparacao entre objetos do tipo Horario
	 */
	bool operator<(Horario& hr);

	/** @brief Sobrescreve o operado '<'
	 *
	 * @param Horario& hr: um dos objetos alvos da comparacao
	 *
	 * @return bool
	 *
	 * @remarks '<' 'e sobrescrito para permitir comparacao entre objetos do tipo Horario
	 */
	bool operator!=(Horario& hr);
        
        float operator-(Horario& hr);

	Horario();

};
#endif

