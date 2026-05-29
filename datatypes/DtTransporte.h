
#ifndef DTMEDIOTRANSPORTE_H
#define DTMEDIOTRANSPORTE_H
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;

class DtTransporte : public ICollectible {
private:
    int id;               // o el código que uses internamente
    string descripcion;
public:
    DtTransporte(int id, string desc);
    int getId();
    string getDescripcion();
};

#endif
