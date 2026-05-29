#ifndef DTCOMUN_H
#define DTCOMUN_H

#include "DtProducto.h"

class DtComun : public DtProducto{
    private:

    public:
        DtComun(char, string, float, int);
        DtComun();
        ~DtComun();
};

#endif