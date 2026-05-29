#include "Comun.h"

// Constructor
Comun::Comun(char codigo, string descripcion, float precio) : Producto(codigo, descripcion, precio)
{
}

// Destructor
Comun::~Comun()
{
}

void Comun::darBaja() {
    // lógica aquí
}

DtProducto* Comun::getDT() {
    return new DtComun(codigo, descripcion, precio, cantidadVendida);
}