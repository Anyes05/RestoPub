#include "Mesa.h"

Mesa::Mesa(int numero) {
    this->numeroMesa = numero;
    this->local = nullptr; 
}

Mesa::~Mesa() {}

int Mesa::getNumeroMesa() {
    return this->numeroMesa;
}

void Mesa::setNumeroMesa(int numero) {
    this->numeroMesa = numero;
}

Local* Mesa::getLocal() {
    return this->local;
}

void Mesa::setLocal(Local* local) {
    this->local = local;
}