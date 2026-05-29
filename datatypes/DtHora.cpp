#include "DtHora.h"

DtHora::DtHora(int hora, int minutos){
    this->hora = hora;
    this->minutos = minutos;
}

DtHora::~DtHora(){}

int DtHora::getHora(){
    return this->hora;
}

int DtHora::getMinutos(){
    return this->minutos;
}

