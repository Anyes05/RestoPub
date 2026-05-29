#ifndef DTASIGNACION_H
#define DTASIGNACION_H

#include "../ICollection/interfaces/ICollectible.h"



#include "../ICollection/interfaces/ICollectible.h"


class DtAsignacion : public ICollectible{
    private:
        int idMozo;
        int* idMesas;
        int cantMesas;
        bool ventas;
    public:
        DtAsignacion(int, int*, int, bool);
        DtAsignacion();
        ~DtAsignacion();

        int getidMozo();
        int* getidMesas();
        int getcantMesas();
        bool getventas();
};

#endif