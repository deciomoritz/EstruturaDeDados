/* 
 * File:   EstruturaDeDados.h
 * Author: lhc
 *
 * Created on 28 de Agosto de 2013, 19:32
 */

#ifndef ESTRUTURADEDADOS_H
#define	ESTRUTURADEDADOS_H
template <typename Tipo>
class EstruturaDeDados{

	public:
		virtual void adiciona(Tipo t) = 0;
		virtual Tipo remover() = 0;
		virtual int tamanho() = 0;
		virtual bool cheia() = 0;
		virtual bool vazia() = 0;
};



#endif	/* ESTRUTURADEDADOS_H */

