#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>
using namespace std;

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/Integer.h"

#include "./datatypes/DtVenta.h"
#include "./datatypes/DtFactura.h"
#include "./datatypes/DtAsignacion.h"
#include "./datatypes/DtFacturaDomicilio.h"
#include "./datatypes/Transporte.h"
#include "./datatypes/DtCliente.h"
#include "./datatypes/DtFacturacionDia.h"

class DtVenta;

class ISistema
{
public:
    virtual ~ISistema();

    /*----- ALTA PRODUCTO -----*/
    virtual bool existeProducto(char codigo) = 0;
    virtual IDictionary *agregarMenu(char codigoMenu, string descripcion) = 0; // devuele una coleccion de DtComun
    virtual void seleccionarProductoComun(char codigoComun, int cantProducto) = 0;
    virtual void agregarProductoComun(char codigoComun, string descripcion, float precio) = 0;
    virtual void darAltaProducto() = 0;

    /*----- ALTA CLIENTE -----*/
    virtual DtCliente altaCliente(string, string, DtDireccion) = 0;
    virtual void confirmarAlta() = 0;
    virtual void cancelarAlta() = 0;
    virtual bool existeCliente(string) = 0;
    virtual ICollection* listarClientes() = 0;

    /*----- ALTA EMPLEADO -----*/
    virtual void agregarEmpleado(string nombre, int idIngresado) = 0;
    virtual ICollection *listarMedioTransporte() = 0; 
    virtual void elegirMedio(int opcion) = 0;
    virtual void darAltaEmpleado() = 0;
    virtual ICollection* mostrarEmpleados() = 0;
    virtual bool existeEmpleado(int idEmpleado) = 0;
    virtual string transporteToString(Transporte t) = 0;

    /*------ ASIGNAR MESAS A MOZOS ------*/
    virtual ICollection *calcularAsignacion(int cantMesas, int cantMozos) = 0;

    /*------ INICIAR VENTA EN MESA ------*/
    virtual DtAsignacion *ingresarIdMozo(int idMozo) = 0;
    virtual void elegirMesas(int numero) = 0; // devuele una coleccion de DtMesas
    virtual void confirmarVentaEnMesa() = 0;

    /*------ VENTA A DOMICILIO ------*/
    virtual bool ventaDomicilio(string telefono) = 0; // Returns true if client exists, false otherwise
    virtual ICollection *listarProductos() = 0;       // Returns a collection of DtProducto
    virtual void agregarProductoPedido(char codigo, int cantidad) = 0;
    virtual ICollection *listarRepartidores() = 0; // Returns a collection of DtRepartidor
    virtual void asignarRepartidorDomicilio(int idRepartidor) = 0;
    virtual DtFacturaDomicilio confirmarPedido(DtFecha fechaFactura) = 0;

    /*------ VENTAS DE UN MOZO ------*/
    virtual ICollection *listarMozos() = 0;
    virtual ICollection *mostrarVentasMozo(int idMozo, DtFecha fecha1, DtFecha fecha2) = 0;

    /*------ AGREGAR PRODUCTO A UNA VENTA ------*/
    virtual ICollection *listarParaAgregar(int idMesa) = 0; // devuele una coleccion de DtProducto
    virtual void seleccionarProductoAgregar(char codigo, int cantidad) = 0;
    virtual void confirmarAgregarProducto() = 0;

    /*------- QUITAR PRODUCTO A UNA VENTA -------*/
    virtual void ingresarMesa(int idMesa) = 0;
    virtual ICollection *productosVenta() = 0; // devuele una coleccion de DtProducto
    virtual void seleccionarProductoQuitar(char codigo, int cant) = 0;
    virtual void quitarProductoVenta() = 0;

    /*------ FACTURACION DE UNA VENTA ------*/
    virtual DtVenta finalizarVenta(int nroMesa) = 0;
    virtual void aplicarDescuento(int descuento) = 0;
    virtual DtFactura generarFactura(DtVenta venta, DtFecha fechaFactura) = 0;
    virtual void agregarMesaAFacturacion(int nroMesa) = 0;
    virtual IDictionary* getMesas() = 0; // Devuelve un diccionario de DtMesa AUXULIAR // nueevo


    virtual ICollection *pedidosVentaActual() = 0; // funcion auxiliar, me sirve para ver la cant de pedido en la venta actual y mostrarlo

    /*------ INFORMACION DE UN PRODUCTO ------*/
    virtual ICollection* obtenerProductos() = 0;
    virtual bool ingresarCodigoProducto(char codigo) = 0;
    virtual DtProducto* infoProducto() = 0;
    virtual ICollection* infoProductosIncluidosMenu() = 0;
    virtual IDictionary* obtenerProductosMenu(char codigoMenu) = 0; // Devuelve un diccionario de DtProducto AUXULIAR

    /*------ BAJA PRODUCTO ------*/
    virtual ICollection *mostrarProductos() = 0;                   // devuele una coleccion de DtProducto
    virtual void seleccionarProductoBaja(char codigo) = 0;
    virtual void darBajaProducto() = 0;
    virtual ICollection* retornarMenus() = 0;

    /*------ RESUMEN FACTURACION DE UN DIA ------*/
    virtual DtFacturacionDia *mostrarInforme(DtFecha fecha) = 0;
};

#endif