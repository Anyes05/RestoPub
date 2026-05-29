#include "DtProducto.h"

DtProducto::DtProducto(char codigo, string descripcion, float precio, int cantidadVendida)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
    this->cantidadVendida = cantidadVendida; // Inicializar cantidadVendida a 0
}

DtProducto::DtProducto() {
    this->codigo = '\0';
    this->descripcion = "";
    this->precio = 0.0;
    this->cantidadVendida = 0; // Inicializar cantidadVendida a 0
}

DtProducto::~DtProducto(){}

char DtProducto::getCodigo(){
    return this->codigo;
}

string DtProducto::getdescripcion(){
    return this->descripcion;
}

float DtProducto::getprecio(){
    return this->precio;
}

int DtProducto::getCantidadVendida() {
    return this->cantidadVendida;
}

