#include "Domicilio.h"

Domicilio::Domicilio(int numero, float subTotal, float descuento, Cliente *cliente, Repartidor *repartidor)
    : Venta(numero, subTotal, descuento), cliente(cliente), repartidor(repartidor)
{
    // Inicializar la colección de pedidos
    pedidos = new List();
}

Domicilio::~Domicilio() {}

void Domicilio::setRepartidor(Repartidor *repartidor)
{
    this->repartidor = repartidor;
}

void Domicilio::setCliente(Cliente *cliente)
{
    this->cliente = cliente;
}

void Domicilio::agregarPedido(Pedido *pedido)
{
    // Agregar el pedido a la colección de pedidos
    if (pedidos != nullptr && pedido != nullptr)
    {
        pedidos->add(pedido);
    }
}

DtFacturaDomicilio Domicilio::generarFacturaDomicilio()
{
    // Crear DtVenta con los datos de la venta actual
    DtVenta dtVenta(getNumero(), getDescuento(), !getActiva(), getTotal());

    // Crear DtRepartidor con los datos del repartidor
    DtRepartidor *dtRepartidor = repartidor->getDtRepartidor();
    DtRepartidor dtRepartidorCopy(dtRepartidor->getIdRepartidor(), dtRepartidor->getNombre(), dtRepartidor->getTransporte());

    // Crear DtCliente con los datos del cliente
    DtCliente dtCliente(cliente->getTelefono(), cliente->getNombre(), cliente->getDireccion());

    // Crear y retornar DtFacturaDomicilio
    DtFacturaDomicilio factura(dtVenta, dtRepartidorCopy, dtCliente);

    // Limpiar memoria
    delete dtRepartidor;

    return factura;
}

DtFacturaDomicilio Domicilio::generarFacturaDomicilio(DtFecha fecha)
{
    // Crear DtVenta con los datos de la venta actual
    DtVenta dtVenta(getNumero(), getDescuento(), !getActiva(), getTotal());

    // Crear DtRepartidor con los datos del repartidor
    DtRepartidor *dtRepartidor = repartidor->getDtRepartidor();
    DtRepartidor dtRepartidorCopy(dtRepartidor->getIdRepartidor(), dtRepartidor->getNombre(), dtRepartidor->getTransporte());

    // Crear DtCliente con los datos del cliente
    DtCliente dtCliente(cliente->getTelefono(), cliente->getNombre(), cliente->getDireccion());

    // Crear y retornar DtFacturaDomicilio con la fecha proporcionada
    DtFacturaDomicilio factura(dtVenta, dtRepartidorCopy, dtCliente, fecha);

    // Limpiar memoria
    delete dtRepartidor;

    return factura;
}
