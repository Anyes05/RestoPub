#ifndef DTFACTURA_H
#define DTFACTURA_H

#include <iostream>
#include <string>
using namespace std;

#include "DtFecha.h"
#include "DtProducto.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"

//#include "DtFecha.h"

class DtFactura : public ICollectible
{
private:
    int codigoVenta;
    DtFecha fecha;
    ICollection* productos;
    float descuento; 
    float subTotal;

public:
    DtFactura();
    DtFactura(int codigoVenta, DtFecha fecha, ICollection* productos, float descuento, float subtotal);
    int getCodigoVenta();
    DtFecha getFecha();
    ICollection* getProductos();
    float getDescuento();
    float getSubtotal();
    float getMontoConDescuento(); // calculado
    float getTotalConIVA();       // calculado
};



#endif