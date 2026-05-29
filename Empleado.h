#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Empleado : public ICollectible // una coleccion de empleados
{
protected:
    string nombre;
    int id;
    int idIngresado;
public:
    Empleado(string, int, int); // constructor
    virtual ~Empleado(); // destructor
    // Getters y setters
    string getNombre();
    int getIdEmpleado();
     int getIdIngresado();
    void setNombre(string); 
    void setIdEmpleado(int);
    void setIdIngresado(int);
};

#endif