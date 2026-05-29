#include "DtFacturacionDia.h"
#include "../ICollection/collections/List.h"

DtFacturacionDia::DtFacturacionDia() {
    fecha = DtFecha();
    facturasLocales = new List();
    facturasDomicilio = new List();
    montoTotalFacturado = 0.0;
}

DtFacturacionDia::DtFacturacionDia(DtFecha fecha, ICollection* facturasLocales, ICollection* facturasDomicilio, float montoTotal) {
    this->fecha = fecha;
    this->facturasLocales = facturasLocales;
    this->facturasDomicilio = facturasDomicilio;
    this->montoTotalFacturado = montoTotal;
}

DtFacturacionDia::~DtFacturacionDia() {}

DtFecha DtFacturacionDia::getFecha() {
    return fecha;
}

ICollection* DtFacturacionDia::getFacturasLocales() {
    return facturasLocales;
}

ICollection* DtFacturacionDia::getFacturasDomicilio() {
    return facturasDomicilio;
}

float DtFacturacionDia::getMontoTotalFacturado() {
    return montoTotalFacturado;
}

void DtFacturacionDia::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

void DtFacturacionDia::setFacturasLocales(ICollection* facturas) {
    this->facturasLocales = facturas;
}

void DtFacturacionDia::setFacturasDomicilio(ICollection* facturas) {
    this->facturasDomicilio = facturas;
}

void DtFacturacionDia::setMontoTotalFacturado(float monto) {
    this->montoTotalFacturado = monto;
}