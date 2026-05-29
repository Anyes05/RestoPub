#include "DtFacturaDomicilio.h"


DtFacturaDomicilio::DtFacturaDomicilio() {}

DtFacturaDomicilio::DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor) {
    this->venta = venta;
    this->repartidor = repartidor;
}

DtFacturaDomicilio::DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor, DtCliente cliente) {
    this->venta = venta;
    this->repartidor = repartidor;
    this->cliente = cliente;
}

DtFacturaDomicilio::DtFacturaDomicilio(DtVenta venta, DtRepartidor repartidor, DtCliente cliente, DtFecha fecha) {
    this->venta = venta;
    this->repartidor = repartidor;
    this->cliente = cliente;
    this->fecha = fecha;
}

/*DtFacturaDomicilio::~DtFacturaDomicilio() {

}
*/
DtVenta DtFacturaDomicilio::getVenta() {
    return venta;
}

DtRepartidor DtFacturaDomicilio::getRepartidor() {
    return repartidor;
}

DtCliente DtFacturaDomicilio::getCliente() {
    return cliente;
}

DtFecha DtFacturaDomicilio::getFecha() {
    return fecha;
}