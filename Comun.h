#ifndef COMUN_H
#define COMUN_H

#include "Producto.h"
#include "./datatypes/DtComun.h"

class Comun : public Producto //una coleccion de Comun
{
private:

public:
    Comun(char, string, float);
    ~Comun();

    void eliminarProducto(); // es lo mismo que darBaja, no la preciso creo
    void agregarProductoComun(char codigoComun, string descripcion, float precio);
    void darBaja(); //funcion heredada y polimorfica
    void agregarCant();
    DtProducto* getDT();
};

#endif