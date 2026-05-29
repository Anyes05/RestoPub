#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "./datatypes/DtProducto.h"
#include "ICollection/String.h"
using namespace std;

class Producto : public ICollectible // una coleccion de productos
{
protected:
    char codigo;
    string descripcion;
    float precio;
    int cantidadVendida; // cantidad vendida del producto
public:
    Producto(char, string, float); // constructor
    virtual ~Producto();             // destructor
    // getterts y setters
    char getCodigo();
    string getDescripcion();
    float getPrecio();
    int getCantidadVendida();
    // setters
    void setCantidadVendida(int);
    void setCodigo(char);
    void setDescripcion(string);
    void setPrecio(float);
    // metodos
    bool esProductoBaja();
    bool esMenu(char codigo);
    bool noExiste(char codigo);
    void cancelarBaja();
    virtual void darBaja() = 0;
    virtual DtProducto *getDT() = 0; 
};

#endif