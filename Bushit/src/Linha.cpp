#include "include/Linha.h"

Linha::Linha() {
}

Linha::~Linha() {

}

Parada Linha::anterior(Parada p) {
    ElementoDuplo<Parada>* aux;
    aux = cabeca;

    
    while (!(p == aux->dado)) {
        aux = aux->proximo;
    }
    
    if(aux->anterior == 0)        
        return anterior(aux->anterior->dado);
                
    return aux->anterior->dado;
}

Parada Linha::proxima(Parada p) {
    ElementoDuplo<Parada>* aux;
    aux = cabeca;
    
    while (!(p == aux->dado)) {
        aux = aux->proximo;
    }
    if(aux->anterior == 0)        
        return proxima(aux->proximo->dado);

    return aux->proximo->dado;
}

void Linha::setDestino(Parada p){
    _destino = p;
}

Parada Linha::destino(){
    return _destino;
}


