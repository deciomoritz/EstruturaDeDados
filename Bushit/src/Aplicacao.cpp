#include "include/Linha.h"
#include "include/Lista.h"
#include "include/RecebeDados.h"
#include "include/InformaDados.h"
#include "include/ListaArray.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

Lista<Linha> l;

RecebeDados r;
InformaDados i;

void pesquisar(Parada p);
void navegar(Linha l, Parada inicial);
void listarLinhas(Lista<Linha> l);

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int parse() {
    string gamb[6];
    ifstream fin;
    fin.open("bla.txt");
    
    char linhas[1];
    fin.getline(linhas, 2);

    int num = atoi(linhas);

    for (int q = 0; q < num; q++) {
        Linha linha;

        char paradas[1];
        fin.getline(paradas, 2);

        for (int w = 0; w < atoi(paradas); w++) {
            for (int a = 0; a < 6; a++) {
                char buf[MAX_CHARS_PER_LINE];
                fin.getline(buf, MAX_CHARS_PER_LINE);
                int n = 0;
                const char* token[MAX_TOKENS_PER_LINE] = {};
                token[0] = strtok(buf, DELIMITER);
                if (token[0]) {
                    for (n = 1; n < MAX_TOKENS_PER_LINE; n++) {
                        token[n] = strtok(0, DELIMITER);
                        if (!token[n]) break;
                    }
                }
                string aux;
                for (int i = 0; i < n; i++) {
                    aux += token[i];
                    if (a == 5 || a == 0)
                        aux += " ";
                }
                gamb[a] = aux;
            }

            Cidade c(gamb[0], gamb[5]);

            Parada p(c, Horario::fabrica(atoi(gamb[1].c_str()), atoi(gamb[2].c_str()), 0),
                    Horario::fabrica(atoi(gamb[3].c_str()), atoi(gamb[4].c_str()), 0));


            linha.adicionar(p);
            //cout << p.toString() << endl;

            if (fin.peek() == '@') {
                fin.get();
                fin.get();
                linha.setDestino(p);

            }
        }
        l.adicionar(linha);
    }
}

int main() {
    parse();

    bool sair = false;

    while (!sair) {
        i.exibeString("\nDigite o destino desejado: ");

        string d = r.pegaString();

        i.exibeString("\nDigite o horário desejado: ");

        i.exibeString("\nHoras: ");
        int h = r.pegaInt();

        i.exibeString("\nMinutos: ");
        int m = r.pegaInt();

        Cidade c(d, "");
        Parada p(c, Horario::fabrica(h, m, 0), Horario::fabrica(0, 0, 0));

        pesquisar(p);
    }
    return 0;
}

void pesquisar(Parada p) {
    Lista<Linha> aux;
    Linha li;
    Linha melhor;

    float dif = 25;
    for (int k = 0; k < l.tamanho(); k++) {
        li = l.mostra(k);
        for (int g = 0; g < li.getTamanho(); g++) {
            if (li.mostra(g).semelhante(p)) {
                aux.adicionar(l.mostra(k));
                Horario h1 = p.getHorarioChegada();
                Horario h2 = li.mostra(g).getHorarioChegada();
                if ((h1 - h2) < dif) {
                    dif = h1 - h2;
                    melhor = li;
                }
            }
        }
    }
    i.exibeString("\n\nRota sugerida: \n");
    i.exibeString(melhor.destino().toString() + "\n\n");
    i.exibeString("\nDigite 1 para navegar pela rota indicada pelo sistema, 2 para ver as outras rotas que a possuem o mesmo destino");
    int a = r.pegaInt();
    switch (a) {
        case 0:
            main();
            break;
        case 1:
        {
            navegar(melhor, melhor.mostra(0));
        }
            break;
        case 2:
        {
            listarLinhas(aux);
        }
            break;
        default:
            i.exibeString("Usuário, digite apenas numeros de 0 a 2");
            pesquisar(p);
            break;
    }
}

void listarLinhas(Lista<Linha> l) {
    i.exibeString("\nDigite o índice da rota a ser navegada\n\n");
    for (int q = 0; q < l.tamanho(); q++) {
        cout << "(" << q << ")";
        i.exibeString(l.mostra(q).destino().toString() + "\n");
    }
    
    int a = r.pegaInt();
    
    navegar(l.mostra(a), l.mostra(0).mostra(0));
}

void navegar(Linha l, Parada inicial) {

    i.exibeString(
            "\nDigite 1 para ir para a próxima parada, 2 para ir para a parada anterior, 3 para efetuar compra, 0 para escolher novo destino\n\n");
    int a = r.pegaInt();

    switch (a) {
        case 0:
            main();
            break;
        case 1:
        {
            Parada p = l.proxima(inicial);
            i.exibeString(p.toString() + "\n\n");
            navegar(l, p);
        }
            break;
        case 2:
        {
            Parada p = l.anterior(inicial);
            i.exibeString(p.toString() + "\n\n");
            navegar(l, p);
        }
        case 3:
        {
            i.exibeString("Por favor deposite um passe do RU na latinha e retire seu bilhete\n\n");
        }    
            break;
        default:
            i.exibeString("Usuário, digite apenas numeros de 0 a 2");
            navegar(l, inicial);
            break;
    }
}
