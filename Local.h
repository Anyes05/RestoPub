#ifndef LOCAL_H
#define LOCAL_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "Venta.h"
#include "Mozo.h"
using namespace std;

class Local : public Venta // una coleccion de ventas locales
{
public:
    Local(int numero, float subTotal, float descuento); // constructor
    virtual ~Local(); // destructor
    // Getters y setters
    ICollection * getMesas();
    void setMesas(ICollection *mesas); // establece la coleccion de mesas del local
    void agregarMesa(ICollectible *mesa); // agrega una mesa a la coleccion de mesas del local
    Mozo * getMozo();
    void setMozo(Mozo *mozo);
private:
    ICollection * mesas;
    Mozo * mozo;
};

#endif