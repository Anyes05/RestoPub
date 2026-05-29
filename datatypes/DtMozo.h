#ifndef DTMOZO_H
#define DTMOZO_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"

class DtMozo : public ICollectible {
private:
    int idEmpleado;
    string nombre;

public:
    DtMozo(int idEmpleado,string nombre);

    int getIdEmpleado();
    string getNombre();
};

#endif
