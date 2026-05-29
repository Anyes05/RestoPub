#ifndef DTREPARTIDOR_H
#define DTREPARTIDOR_H

#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;

class DtRepartidor : public ICollectible{
private:
    int idRepartidor;
    string nombre;
    string transporte;

public:
    DtRepartidor();
    DtRepartidor(int idRepartidor, string nombre, string transporte);

    int getIdRepartidor();
    string getNombre();
    string getTransporte();
};

#endif
