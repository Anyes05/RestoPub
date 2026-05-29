#include "Producto.h"

using namespace std;

//constructor
Producto::Producto(char codigo, string descripcion, float precio)
{
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
    this->cantidadVendida = 0; // Inicializar cantidadVendida a 0
}

//destructor
Producto::~Producto(){}

char Producto::getCodigo(){
    return this->codigo;
}
string Producto::getDescripcion(){
    return this->descripcion;
}
float Producto::getPrecio(){
    return this->precio;
}

int Producto::getCantidadVendida() {
    return this->cantidadVendida;
}

bool Producto::esMenu(char codigo) {
    return false;
}

void Producto::setCodigo(char cod){
    this-> codigo=cod;
}

void Producto::setDescripcion(string desc){
    this-> descripcion=desc;
}

void Producto::setPrecio(float pre){
    this->precio=pre;
}

void Producto::setCantidadVendida(int cant){
    this->cantidadVendida=cant;
}

bool Producto::noExiste(char cod){
    return this->getCodigo() != cod;
}
