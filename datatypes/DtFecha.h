#ifndef DTFECHA_H
#define DTFECHA_H

#include <stdexcept>

using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
        static bool esBisiesto(int anio);
    public:
        DtFecha(int dia, int mes, int anio);
        DtFecha();
        bool validar();

        int setDia(int);
        int setMes(int);
        int setAnio(int);

        int getDia();
        int getMes();
        int getAnio();
};

#endif