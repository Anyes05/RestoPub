#ifndef MESA_H
#define MESA_H

#include <iostream>
class Local;
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Mesa : public ICollectible // una coleccion de mesas 
{
private:
    int numeroMesa;
    Local *local; // utilizo un punetero a local, ya que esta relacion hace referencia a la venta actual de la mesa
    // y el historial de ventas de la mesa?? referencia a la coleccion?
public:
    Mesa(int); // constructor
    ~Mesa(); // destructor
    // Getters y setters
    int getNumeroMesa();
    void setNumeroMesa(int); 
    Local* getLocal(); // devuelve la venta actual de la mesa
    void setLocal(Local* local); // establece la venta actual de la mesa
};

#endif