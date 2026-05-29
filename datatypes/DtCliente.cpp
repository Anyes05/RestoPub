#include "DtCliente.h"

DtCliente::DtCliente() {}

DtCliente::DtCliente(string telefono, string nombre, DtDireccion direccion) {
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
}

string DtCliente::getTelefono() {
    return telefono;
}

string DtCliente::getNombre() {
    return nombre;
}

DtDireccion DtCliente::getDireccion() {
    return direccion;
}

DtCliente::~DtCliente() {
    // Destructor virtual
}
