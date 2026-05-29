#ifndef DTHORA_H
#define DTHORA_H

#include <string>
using namespace std;

class DtHora{
private:
    int hora;
    int minutos;

public:
    DtHora(int hora, int minutos);
    ~DtHora();

    int getHora();
    int getMinutos();
};

#endif
