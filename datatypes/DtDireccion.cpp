#include "DtDireccion.h"

// Constructor por defecto
DtDireccion::DtDireccion()
{
    this->nombreCalle = "";
    this->numero = 0;
    this->calleEsquina = "";
}

// Constructor con parámetros
DtDireccion::DtDireccion(string nombreCalle, int numero, string calleEsquina)
{
    this->nombreCalle = nombreCalle;
    this->numero = numero;
    this->calleEsquina = calleEsquina;
}
// Destructor
DtDireccion::~DtDireccion()
{
}

// Getters
string DtDireccion::getnombreCalle()
{
    return nombreCalle;
}

int DtDireccion::getnumero()
{
    return numero;
}


string DtDireccion::getcalleEsquina()
{
    return calleEsquina;
}

