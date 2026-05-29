
#include "DtAsignacion.h"
#include <iostream>

DtAsignacion::DtAsignacion(int idMozo, int* idMesas, int cantMesas, bool ventas){
    this->idMozo = idMozo;
    this->cantMesas = cantMesas;
    this->ventas = ventas;

    this->idMesas = new int[cantMesas];
    for(int i=0;i<cantMesas;i++){
        this->idMesas[i] = idMesas[i];
    }
}
DtAsignacion::DtAsignacion(){}

DtAsignacion::~DtAsignacion(){}

int DtAsignacion::getidMozo(){
    return this->idMozo;
}

int* DtAsignacion::getidMesas(){
    return this->idMesas;
}
int DtAsignacion::getcantMesas(){
    return this->cantMesas;
}

bool DtAsignacion::getventas(){
    return this->ventas;
}

