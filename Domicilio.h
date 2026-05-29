#ifndef DOMICLIO_H
#define DOMICLIO_H

#include "./datatypes/DtCliente.h"
#include "./datatypes/DtFacturaDomicilio.h"

#include "Cliente.h"
#include "Repartidor.h"
#include "Venta.h"



class Domicilio : public Venta // una coleccion de ventas a domicilio
{
public:
  Domicilio(int numero, float subTotal, float descuento, Cliente *cliente, Repartidor *repartidor); // constructor
  ~Domicilio();
  void setRepartidor(Repartidor *repartidor);
  DtRepartidor *getRepartidor();
  void setCliente(Cliente *cliente);
  DtCliente *getCliente();

  void agregarPedido(Pedido *pedido);
  DtFacturaDomicilio generarFacturaDomicilio();
  DtFacturaDomicilio generarFacturaDomicilio(DtFecha fecha);
private:
  Cliente *cliente;
  Repartidor *repartidor;
  ICollection *pedidos; 
};

#endif