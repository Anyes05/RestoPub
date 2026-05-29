
#ifndef DTPEDIDO_H
#define DTPEDIDO_H

#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"

using namespace std;

class DtPedido : public ICollectible
{
private:
    int cantProductos;
    char codigo;
    string descripcion;
    float precio;
public:
    DtPedido(int, char, string, float);
    virtual ~DtPedido();
    DtPedido();
    int getCantProductos();
    char getCodigo();
    string getdescripcion();
    float getprecio();
};

#endif

