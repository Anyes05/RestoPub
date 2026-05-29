#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/List.h" 
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/OrderedKey.h" 

#include "Factura.h"
#include "Pedido.h"
#include "datatypes/DtVenta.h"

using namespace std;

class Venta : public ICollectible //una coleccion de ventas
{
private:
    int numero;
    float subTotal;
    float descuento;
    float total;
    bool activa; // indica si la venta está activa o no
    Factura* factura;
    IDictionary * productos; // lista de productos 
    ICollection * pedido;
public:
    Venta(int numero, float subTotal, float descuento); //constructor
    virtual ~Venta(); //destructor
    //getters y setters
    int getNumero();
    float getSubTotal();
    float getDescuento();
    float getTotal();
    bool getActiva();
    Factura* getFactura(); 
    IDictionary * getProductos();
    void setNumero(int numero);
    void setSubTotal(float subTotal);
    void setDescuento(float descuento);
    void setTotal(float total);
    void setFactura(Factura* factura); 
    void setProductos(IDictionary * productos);
    void setActiva(bool activa); 
    //metodos
    void eliminarMenu(); // donde esta esto en el diagrama de comunicacion? creo que no está o no le corresponde a venta 
    ListNode productosVenta();  
    void eliminarProductoVenta(char codigo);
    virtual void agregarPedido(Pedido *pedido);
        
};


#endif