#include <iostream>
#include "include/Linha.h"

using namespace std;

int main1() {
    Horario tc = Horario::fabrica(12,14,59);
    Horario tp = Horario::fabrica(12,14,00);
    bool x = tc<tp;
    cout <<x;
    Linha l;
    Cidade cid("Urussanga", "Lugar onde se deu início à vida(literalmente) do nosso querido amigo Luiz");
    Parada p1(cid, tc, tp);
    l.adicionar(p1);

    Cidade cid2("Fpolis - UFSC", "Lugar onde se deu fim à vida(figurativamente) do nosso querido amigo Luiz");
    Parada p2(cid2, tc, tp);
    l.adicionar(p2);

    cout << l.proxima(p1).toString() << endl;

    cout << l.anterior(p2).toString() << endl;

    l.remover();
    l.remover();

    return 0;
}
