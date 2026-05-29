#include "Empleado.h"

Empleado::Empleado(string nom, int id, int idIngresado) {
    this->nombre = nom;
    this->id = id;
    this->idIngresado = idIngresado;
}
Empleado::~Empleado() {}

string Empleado::getNombre() {
    return this->nombre;
}

int Empleado::getIdEmpleado() {
    return this->id;
}

int Empleado::getIdIngresado() {
    return this->idIngresado;
}

void Empleado::setNombre(string nom) {
    this->nombre = nom;
}

void Empleado::setIdEmpleado(int id) {
    this->id = id;
}

void Empleado::setIdIngresado(int idIngresado) {
    this->idIngresado = idIngresado;
}

