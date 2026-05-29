#ifndef DTMENU_H
#define DTMENU_H

#include "DtProducto.h"

class DtMenu : public DtProducto
{
private:
    string nombre;
    float descuentoMenu;

public:
    DtMenu(char, string, float, int, string, float);
    DtMenu();
    ~DtMenu();

    string getNombre();
    float getDescuentoMenu();
};

#endif