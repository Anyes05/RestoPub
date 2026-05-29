#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "datatypes/DtDireccion.h"
using namespace std;

class Cliente : public ICollectible // una coleccion de clientes. 
{
protected:
    string telefono;
    string nombre;
    DtDireccion direccion;
public:
    Cliente(string, string, DtDireccion); // constructor
    virtual ~Cliente(); // destructor
    
    // Getters y setters
    string getNombre();
    string getTelefono();
    DtDireccion getDireccion();
    void setNombre(string); 
    void setTelefono(string);
    void setDireccion(DtDireccion);
};

#endif