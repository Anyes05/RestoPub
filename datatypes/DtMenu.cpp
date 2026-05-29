#include "DtMenu.h"

using namespace std;

DtMenu::DtMenu(char codigo, string descripcion, float precio, int cantidadVendida, string nombre, float descuento) : DtProducto(codigo, descripcion, precio, cantidadVendida)
{
    this->nombre = nombre;
    this->descuentoMenu = descuento;
}

DtMenu::DtMenu() : DtProducto() {
    // cout << "Debug DtMenu::Constructor: Iniciando construcción por defecto" << endl;
    // cout << "Debug DtMenu::Constructor: Construcción por defecto completada" << endl;
    this->nombre = "";
    this->descuentoMenu = 0.0;
}

DtMenu::~DtMenu(){}

string DtMenu::getNombre(){
    return this->nombre;
}

float DtMenu::getDescuentoMenu(){
    return this->descuentoMenu;
}
