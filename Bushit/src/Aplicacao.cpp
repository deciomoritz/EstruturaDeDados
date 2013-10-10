#include "include/Linha.h"
#include "include/Lista.h"
#include "include/RecebeDados.h"
#include "include/InformaDados.h"
#include <cstring>

using namespace std;

Lista<Linha> l;

RecebeDados r;
InformaDados i;

void adicionar();
void remover();

int main() {
	bool sair = false;

	int op = 0;

	while (!sair) {
		i.exibeString(
				"\nDigite a opção desejada: \n1 para adicionar uma linha\n2 para remover uma linha");
		op = r.pegaInt();

		switch (op) {
		case 1:
			adicionar();
			break;
		case 2:
			remover();
			break;
		default:
			main();
			break;
		}
	}
	return 0;
}

void remover() {
	Linha linha;
	i.exibeString("\nDigite 1 para remover linha, 0 para finalizar");
	int a = r.pegaInt();

	switch (a) {
	case 0:
		main();
		break;
	case 1:
	{
		i.exibeString("\nDigite o índice da linha a ser removida");

		for (int i = 0; i < l.tamanho(); i++) {
			linha = l.mostra(i);
			cout << "\n(" << i << ") " << "Partida: " << linha.mostra(0).toString() << " Destino final: " << linha.mostra(linha.getTamanho()-1).toString() << endl;
		}

		int b = r.pegaInt();
		Linha aux = l.retirarDaPosicao(b);
		i.exibeString("Linha removida: \n");
		cout << "Partida: " << aux.mostra(0).toString() << " Destino final: "
				<< aux.mostra(aux.getTamanho()).toString() << endl;
	}
		break;
	default:
		remover();
		break;
	}
}

Linha linha;
void adicionar() {

	i.exibeString(
			"\nDigite 1 para adicionar parada, 2 para finalizar a linha, 0 para cancelar");
	int a = r.pegaInt();
	switch (a) {
	case 0:
		main();
		break;
	case 1:
	{
		i.exibeString("Digite o nome da cidade\n");
		string nome = r.pegaString();
		i.exibeString("Digite a descrição da cidade\n");
		string desc = r.pegaString();
		i.exibeString("Digite horário de chegada\n");
		i.exibeString("Digite a hora\n");
		int hora1 = r.pegaInt();
		i.exibeString("Digite o minuto\n");
		int min1 = r.pegaInt();

		i.exibeString("Digite horário de saída\n");
		i.exibeString("Digite a hora\n");
		int hora2 = r.pegaInt();
		i.exibeString("Digite o minuto\n");
		int min2 = r.pegaInt();

		Cidade c(nome, desc);
		Parada p(c, Horario::fabrica(hora1, min1, 0),
				Horario::fabrica(hora2, min2, 0));

		linha.adicionar(p);
		adicionar();
	}
		break;
	case 2:
		l.adicionar(linha);
		main();
		break;
	default:
		adicionar();
		break;
	}
}

