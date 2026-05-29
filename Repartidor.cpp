#include "Repartidor.h"

Repartidor::Repartidor(string nom, int id, string transporte, int idIngresado) : Empleado(nom, id, idIngresado) {
    this->medioDeTransporte = transporte;
}

Repartidor::~Repartidor() {}

string Repartidor::getTransporte() {
    return this->medioDeTransporte;
}

void Repartidor::setTransporte(string transporte) {
    this->medioDeTransporte = transporte;
}

DtRepartidor* Repartidor::getDtRepartidor(){
    return new DtRepartidor(this->getIdEmpleado(),this->getNombre(),this->getTransporte());
}