#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <iostream>
#include <string>
#include "DtDireccion.h"
#include "../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtCliente : public ICollectible {
private:
    string telefono;
    string nombre;
    DtDireccion direccion;

public:
    DtCliente();
    DtCliente(string telefono, string nombre, DtDireccion direccion);
    string getTelefono();
    string getNombre();
    DtDireccion getDireccion();
    ~DtCliente();
};

#endif
