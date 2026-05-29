#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include "ICollection/collections/List.h"
#include "datatypes/DtFecha.h"
#include "datatypes/DtHora.h"
#include "datatypes/DtVenta.h"
#include "datatypes/DtProducto.h"
#include "datatypes/DtHora.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/OrderedDictionary.h"

using namespace std;

class Factura
{
    private:
        string codigo;
        DtFecha fecha;
        DtHora hora;
        DtVenta venta; 
        DtProducto ** productos; 
    public:
        Factura(string, DtFecha, DtHora); // constructor
        virtual ~Factura(); // destructor
        // getters y setters
        string getCodigo();
        DtFecha getFecha(); 
        DtHora getHora(); 
        DtVenta getVenta(); 
        DtProducto** getProductos();
        void setCodigo(string codigo);
        void setProducto(ICollection * productos);
        void setFecha(DtFecha fecha); 
        void setHora(DtHora hora);
        void setVenta(DtVenta venta);
};

#endif
