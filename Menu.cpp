#include "Menu.h"

// Constructor
Menu::Menu(char codigo, string descripcion, float precio, string nombre, float descuento) : Producto(codigo, descripcion, precio)
{
    this->nombre = nombre;
    this->descuentoMenu = descuento;
    this->productosComunes = new OrderedDictionary();
    this->comun_menu = new OrderedDictionary();
}

// destrcutor
Menu::~Menu() {
    
}

// getters y setters

string Menu::getNombre()
{
    return this->nombre;
}

float Menu::getDescuentoMenu()
{
    return this->descuentoMenu;
}

IDictionary* Menu::getProductosComunes() {
    IDictionary* comunes = new OrderedDictionary();

    IIterator* it = productosComunes->getIterator();
    while (it->hasCurrent()) {
        ICollectible* ic = it->getCurrent();
        Comun* c = dynamic_cast<Comun*>(ic);

        if (c != nullptr) {
            DtComun* dt = (DtComun*)c->getDT(); // obtenemos el DTO
            char codChar = dt->getCodigo();     // suponemos que getCodigo devuelve un char
            char codStr[2] = { codChar, '\0' }; // lo convertimos a const char*
            IKey* key = new String(codStr);     // construimos el String válido
            comunes->add(key, dt);              // lo agregamos
        }

        it->next();
    }

    delete it;
    return comunes;
}

IDictionary *Menu::getComun_Menu()
{
    return this->comun_menu;
}

void Menu::setNombre(string nom)
{
    this->nombre = nom;
}

void Menu::setDescuentoMenu(float descMenu)
{
    this->descuentoMenu = descMenu;
}

void Menu::setProductosComunes(IDictionary *productosComunes)
{
    if (this->productosComunes != nullptr)
        delete this->productosComunes;
    this->productosComunes = productosComunes;
}

bool Menu::contieneProducto(char codigo)
{
    char codStr[2] = {codigo, '\0'};
    IKey *key = new String(codStr);
    bool existe = this->productosComunes->member(key);
    delete key;
    return existe;
}

void Menu::eliminarProductoComun(char codigo)
{
    char codStr[2] = {codigo, '\0'};
    IKey *key = new String(codStr);

    // 1. Eliminar de comun_menu
    if (comun_menu) {
        if (comun_menu->member(key)) {
            Comun_Menu* relacion = dynamic_cast<Comun_Menu*>(comun_menu->find(key));
            if (relacion) {
                comun_menu->remove(key);
                delete relacion;
            } 
        } 
    }

    // 2. Eliminar de productosComunes
    if (productosComunes) {
        if (productosComunes->member(key)) {
            productosComunes->remove(key); // Solo elimina la referencia, NO el objeto
        } 
    } 

    delete key;
}

bool Menu::esVacio(Menu *menu)
{
    return menu->getProductosComunes()->isEmpty();
}

void Menu::darBaja()
{
    // Eliminar todas las referencias a productos comunes
    IIterator *it = productosComunes->getIterator();
    while (it->hasCurrent())
    {
        Comun* comun = dynamic_cast<Comun*>(it->getCurrent());
        if (comun != nullptr) {
            char codigoChar = comun->getCodigo();
            char codigoStr[2] = {codigoChar, '\0'};
            IKey* key = new String(codigoStr);
            it->next(); // Avanzar antes de eliminar
            productosComunes->remove(key);
            delete key;
        } else {
            it->next();
        }
    }
    delete it;

    // Eliminar todas las relaciones Comun_Menu y liberar memoria
    IIterator* it2 = comun_menu->getIterator();
    while (it2->hasCurrent())
    {
        Comun_Menu* relacion = dynamic_cast<Comun_Menu*>(it2->getCurrent());
        if (relacion != nullptr) {
            char codigoChar = relacion->getComun()->getCodigo();
            char codigoStr[2] = {codigoChar, '\0'};
            IKey* key = new String(codigoStr);
            it2->next(); // Avanzar antes de eliminar
            comun_menu->remove(key);
            delete relacion; // LIBERAR MEMORIA
            delete key;
        } else {
            it2->next();
        }
    }
    delete it2;
}

DtProducto* Menu::getDT() {
    return new DtMenu(
        this->getCodigo(),
        this->getDescripcion(),
        this->getPrecio(),
        this->getCantidadVendida(), 
        this->getNombre(),
        this->getDescuentoMenu()
    );
}

void Menu::agregarProducto(IDictionary *pc)
{
    IIterator *it = pc->getIterator();
    while (it->hasCurrent())
    {
        ICollectible *ic = it->getCurrent();
        Comun *comun = dynamic_cast<Comun *>(ic); // casteamos a tipo real

        if (comun != nullptr)
        {
            char codStr1[2] = {comun->getCodigo(), '\0'};
            String *key1 = new String(codStr1);
            productosComunes->add(key1, comun);
        }

        it->next();
    }
    delete it;
}

void Menu::darAltaMenu(Comun *comun, int cantidad)
{
    char codStr1[2] = {comun->getCodigo(), '\0'};
    String *key1 = new String(codStr1);
    productosComunes->add(key1, comun);

    char codStr2[2] = {comun->getCodigo(), '\0'};
    String *key2 = new String(codStr2);
    Comun_Menu *relacion = new Comun_Menu(cantidad, comun);
    comun_menu->add(key2, relacion);
}