#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "Producto.h"
using namespace std;

class Pedido : public ICollectible //una coleccion de pedidos
{
private:
    int cantProductos;
    Producto* producto; // puntero a un producto, ya que un pedido puede tener un solo producto
public:
    Pedido(int); //constructor
    ~Pedido(); //destructor
    //getterts y setters
    int getCantProductos();
    void setCantProductos(int);
    Producto* getProducto();
    void setProducto(Producto*);
    //metodos adicionales
    bool estaEnPedido(Producto*); // creo que es el objeto, y no el Dt como tenemos en el dcd
    int restarProductos(int);
};

#endif