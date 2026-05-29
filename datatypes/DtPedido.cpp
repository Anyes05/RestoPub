
#include "DtPedido.h"

DtPedido::DtPedido(int cant, char codigo, string descripcion, float precio)
{
    this->cantProductos = cant;
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
}

DtPedido::DtPedido() {
    this->cantProductos = 0;
    this->codigo = '\0';
    this->descripcion = "";
    this->precio = 0.0;
}

DtPedido::~DtPedido(){}

int DtPedido::getCantProductos() {
    return this->cantProductos;
}

char DtPedido::getCodigo(){
    return this->codigo;
}

string DtPedido::getdescripcion(){
    return this->descripcion;
}

float DtPedido::getprecio(){
    return this->precio;
}


