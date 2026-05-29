#include "Mozo.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/Integer.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"

Mozo::Mozo(string nombre, int idEmpleado, int cantMesas, int idIngresado) : Empleado(nombre, idEmpleado, idIngresado), cantMesas(cantMesas) {
    misMesas = new OrderedDictionary(); // Inicializa el diccionario de mesas
}

Mozo::~Mozo() {}

int Mozo::getCantMesas() {
    return cantMesas;
}

void Mozo::setCantMesas(int cantMesas) {
    this->cantMesas = cantMesas;
}

void Mozo::agregarMesa(Mesa* mesa) {
    IKey* k = new Integer(mesa->getNumeroMesa());
    this->misMesas->add(k, mesa); // Agrega la mesa al diccionario usando su número como clave
    this->cantMesas++; // Incrementa la cantidad de mesas del mozo
}

void Mozo::eliminarMesa(Mesa* mesa) {
    if (mesa == nullptr) {
        throw std::invalid_argument("No hay mesas para eliminar.");
    }
    IKey* k = new Integer(mesa->getNumeroMesa());
    if (!misMesas->member(k)) {
        delete k; // Liberar memoria del objeto clave
        throw std::invalid_argument("La mesa no existe en la colección.");
    }
    misMesas->remove(k); 
    delete k;
}

int* Mozo::getMesasId() {
    int* ids = new int[cantMesas];
    IIterator* it = misMesas->getIterator();
    int i = 0;
    while (it->hasCurrent() && i < cantMesas) {
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        if (mesa != nullptr) {
            ids[i] = mesa->getNumeroMesa();
            i++;
        }
        it->next();
    }
    
    delete it; // Liberar el iterador
    return ids; // Retorna un arreglo de IDs de las mesas
}

IDictionary* Mozo::getMisMesas() {
    return this->misMesas;
}

