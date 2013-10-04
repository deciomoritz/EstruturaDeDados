#include "include/FachadaPilha.h"
#include "include/Pilha.h"
#include "include/RecebeDados.h"
#include "include/InformaDados.h"

FachadaPilha::FachadaPilha() {
	chamaPilha();
}

void FachadaPilha::chamaPilha() {

	Pilha<int> p;
	Pilha<int> aux;

	InformaDados in;
	RecebeDados r;

	int op;

	while (true) {

		in.exibeString(
					"\nDigite a operacao: \n1) empilhar\n2) desempilhar\n3) limpar\n4) mostrar\n5) sair\n");

		op = r.pegaInt();

		switch (op) {
		case 1:
			in.exibeString("Digite o valor a ser empilhado\n");
			int a;
			a = r.pegaInt();
			if (p.cheia()) {
				in.exibeString("Pilha cheia");
				break;
			}
			p.adicionar(a);
			break;
		case 2:
			if (!p.vazia()) {
				int f;
				f = p.remover();
				in.exibeInteiro(&f);
				in.exibeString(" foi removido.");
				break;
			}
			in.exibeString("Pilha vazia");
			break;
		case 3:
			while (!p.vazia())
				p.remover();
			break;
		case 4:
			for (int i = p.tamanho(); i > 0; i--) {
				int a;
				a = p.remover();

				in.exibeString("\nElemento: ");
				in.exibeInteiro(&a);
				in.exibeString("\n  Indice: " + i);
				in.exibeInteiro(&i);

				aux.adicionar(a);
			}

			while (!aux.vazia())
				p.adicionar(aux.remover());
			break;
		case 5:
			return;
		}
	}
}

