#ifndef DTVENTA_H
#define DTVENTA_H

class DtVenta{
    private:
        int idVenta;
        float descuento;
        bool facturada;
        float total;
    public:
        DtVenta(int, float, bool, float);
        ~DtVenta();
        DtVenta();

        int getidVenta();
        float getDescuento();
        bool getFacturada();
        float getTotal();
};

#endif