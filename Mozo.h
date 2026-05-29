#ifndef MOZO_H
#define MOZO_H

#include <iostream>
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "Empleado.h"
#include "Mesa.h"
using namespace std;

class Mozo : public Empleado 
{
private:
    int cantMesas; 
    IDictionary* misMesas;// referencia a mesa, coleccion
    // Apunta solo a las mesas que le pertenecen al mozo, no a todas las mesas del sistema. Tiene que tambien apuntar a todas?
    // El mozo apunta a las de si mismo, pero en la coleccion mesas estan las de todos los mozos? 
public:
    Mozo(string, int, int, int); // constructor
    ~Mozo(); // destructor
    // Getters y setters
    int getCantMesas();
    void setCantMesas(int);
    int* getMesasId();
    IDictionary* getMisMesas();
    // metodos adicionales
    // set<Mesas> buscarMesa(); ??
    void agregarMesa(Mesa*); // agrega una mesa a la coleccion de mesas del mozo
    void eliminarMesa(Mesa*); // elimina una mesa de la coleccion de mesas del mozo
};

#endif