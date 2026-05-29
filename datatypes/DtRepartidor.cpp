#include "DtRepartidor.h"

DtRepartidor::DtRepartidor() {}

DtRepartidor::DtRepartidor(int idRepartidor, string nombre, string transporte) {
    this->idRepartidor = idRepartidor;
    this->nombre = nombre;
    this->transporte = transporte;
}

int DtRepartidor::getIdRepartidor() {
    return idRepartidor;
}

string DtRepartidor::getNombre() {
    return nombre;
}

string DtRepartidor::getTransporte() {
    return transporte;
}
