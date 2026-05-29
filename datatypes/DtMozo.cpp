#include "DtMozo.h"

DtMozo::DtMozo(int idEmpleado,string nombre) {
    this->idEmpleado = idEmpleado;
    this->nombre = nombre;
}

int DtMozo::getIdEmpleado() {
    return this->idEmpleado;
}

std::string DtMozo::getNombre() {
    return this->nombre;
}
