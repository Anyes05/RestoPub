#ifndef DTFACTURADOMICILIO_H
#define DTFACTURADOMICILIO_H

#include "DtVenta.h"
#include "DtRepartidor.h"
#include "DtCliente.h"
#include "DtFecha.h"
#include "../ICollection/interfaces/ICollectible.h"

class DtFacturaDomicilio : public ICollectible {
private:
    DtVenta venta;
    DtRepartidor repartidor;
    DtCliente cliente;
    DtFecha fecha;
public:
    DtFacturaDomicilio();
    DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor);
    DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor, DtCliente cliente);
    DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor, DtCliente cliente, DtFecha fecha);
   // virtual ~DtFacturaDomicilio() = default;

    DtVenta getVenta();
    DtRepartidor getRepartidor();
    DtCliente getCliente();
    DtFecha getFecha();
};

#endif