#ifndef COMUN_MENU_H
#define COMUN_MENU_H

#include "ICollection/interfaces/ICollectible.h"
#include "Comun.h"
using namespace std;

class Comun;

class Comun_Menu : public ICollectible //una coleccion de productos
{
protected:
    int cantProducto;
    Comun * productoComun;
public:
    Comun_Menu(int, Comun*); //constructor
    virtual ~Comun_Menu(); //destructor
    //getterts y setters
    int getCantProducto();
    void setCantProducto(int);
    Comun * getComun(); // 
    
};

#endif