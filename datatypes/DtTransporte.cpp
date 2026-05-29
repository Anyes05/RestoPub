
#include "DtTransporte.h"


DtTransporte::DtTransporte(int id, string desc) {
    this->id = id;
    this->descripcion = desc;
}

int DtTransporte::getId() {
    return this->id;
}

string DtTransporte::getDescripcion() {
    return this->descripcion;
}
