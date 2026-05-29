#include "DtVenta.h"

#include <iostream>

DtVenta::DtVenta(int id, float descuento, bool facturada, float total){
    this->idVenta = id;
    this->descuento = descuento;
    this->facturada = facturada;
    this->total = total;
}

DtVenta::DtVenta() {
    // Valores por defecto (ajustá según tu lógica)
    this->idVenta = 0;
    this->descuento = 0.0;
    this->facturada = false;
    this->total = 0.0;
}


DtVenta::~DtVenta(){}

int DtVenta::getidVenta(){
    return this->idVenta;
}

float DtVenta::getDescuento(){
    return this->descuento;
}

bool DtVenta::getFacturada(){
    return this->facturada;
}

float DtVenta::getTotal(){
    return this->total;
}