
#ifndef DTFACTURACIONDIA_H
#define DTFACTURACIONDIA_H

#include "DtFecha.h"
#include "DtFactura.h"
#include "DtFacturaDomicilio.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/ICollectible.h"

class DtFacturacionDia : public ICollectible{
private:
    DtFecha fecha;
    ICollection* facturasLocales;  
    ICollection* facturasDomicilio;  
    float montoTotalFacturado;

public:
    DtFacturacionDia();
    DtFacturacionDia(DtFecha fecha, ICollection* facturasLocales, ICollection* facturasDomicilio, float montoTotal);
    virtual ~DtFacturacionDia();
    
    DtFecha getFecha();
    ICollection* getFacturasLocales();
    ICollection* getFacturasDomicilio();
    float getMontoTotalFacturado();
    
    void setFecha(DtFecha fecha);
    void setFacturasLocales(ICollection* facturas);
    void setFacturasDomicilio(ICollection* facturas);
    void setMontoTotalFacturado(float monto);
};

#endif
