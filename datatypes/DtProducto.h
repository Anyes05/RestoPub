#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtProducto : public ICollectible
{
private:
    char codigo;
    string descripcion;
    float precio;
    int cantidadVendida;
public:
    DtProducto(char, string, float, int);
    virtual ~DtProducto();
    DtProducto();
    char getCodigo();
    string getdescripcion();
    float getprecio();
    int getCantidadVendida();
};

#endif