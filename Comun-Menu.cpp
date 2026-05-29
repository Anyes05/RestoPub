#include "Comun-Menu.h"
#include <iostream>

using namespace std;

//constructor
Comun_Menu::Comun_Menu(int cant, Comun *pc)
{
    this->productoComun = pc;
    this->cantProducto = cant;
}

//destructor
Comun_Menu::~Comun_Menu()
{
    // if (productoComun != nullptr) {
    //     // delete productoComun; // No lo eliminamos aquí, lo hace el menú
    // }
    // std::cout << "[Depuración] Destructor de Comun_Menu llamado. Puntero productoComun=" << productoComun << std::endl;
}

int Comun_Menu::getCantProducto(){
    return this->cantProducto;
}

void Comun_Menu::setCantProducto(int cant){
    this->cantProducto=cant;
}

Comun * Comun_Menu::getComun(){ // 
    return this->productoComun;
}