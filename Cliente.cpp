#include "Cliente.h"

Cliente::Cliente(string nom, string tel, DtDireccion dir){
    this->nombre = nom;
    this->telefono = tel;
    this->direccion = dir;
}

Cliente::~Cliente() {}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getTelefono() {
    return telefono;
}

DtDireccion Cliente::getDireccion() {
    return direccion;
}   

void Cliente::setNombre(string nom) {
    nombre = nom;
}

void Cliente::setTelefono(string tel) {
    telefono = tel;
}

void Cliente::setDireccion(DtDireccion dir) {
    direccion = dir;
}
