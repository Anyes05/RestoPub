#include "Venta.h"

using namespace std;

Venta::Venta(int numero, float subTotal, float descuento) {
    this->numero = numero;
    this->subTotal = subTotal;
    this->descuento = descuento;
    this->total = subTotal - descuento; // Calcular el total correctamente
    this->factura = nullptr; 
    productos = new OrderedDictionary();
    pedido = new List(); // Inicializar la colección de pedidos
}

Venta::~Venta() {}

int Venta::getNumero() {
    return numero;
}

float Venta::getSubTotal() {
    return subTotal;
}

float Venta::getDescuento() {
    return descuento;
}

float Venta::getTotal() {
    return total;
}

Factura* Venta::getFactura() {
    return factura;
}

IDictionary* Venta::getProductos() {
    return productos;
}

void Venta::setNumero(int numero) {
    this->numero = numero;
}

void Venta::setSubTotal(float subTotal) {
    this->subTotal = subTotal;
}

void Venta::setDescuento(float descuento) {
    this->descuento = descuento;
}

void Venta::setTotal(float total) {
    this->total = total;
}

void Venta::setFactura(Factura* factura) {
    this->factura = factura;
}

void Venta::setProductos(IDictionary * productos) {
    this->productos = productos;
}

bool Venta::getActiva() {
    return (factura == nullptr); // Si no hay factura, la venta está activa
}

void Venta::setActiva(bool activa) {
    if (activa) {
        factura = nullptr; // Si se activa, no hay factura
    }
    // Si se desactiva, la factura ya debe estar asignada desde generarFactura
}

void Venta::agregarPedido(Pedido* pedido) {
    if (pedido != nullptr && this->pedido != nullptr) {
        this->pedido->add(pedido);
    }
}


void Venta::eliminarProductoVenta(char codigo) {
    char keyStr[2] = {codigo, '\0'};
    IKey *key = new String(keyStr);
    if (productos->member(key)) {
        productos->remove(key);
    }
    delete key;
    // Actualizar el total después de eliminar un producto
    float nuevoSubTotal = 0.0f;
    IIterator *it = productos->getIterator();
    while (it->hasCurrent()) {
        Pedido *pedido = dynamic_cast<Pedido *>(it->getCurrent());
        if (pedido != nullptr) {
            nuevoSubTotal += pedido->getProducto()->getPrecio() * pedido->getCantProductos();
        }
        it->next();
    }
    delete it;
    this->setSubTotal(nuevoSubTotal);
}
