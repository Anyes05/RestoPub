#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"

#include "Venta.h"
#include "Mozo.h"
#include "Mesa.h"
#include "Producto.h"
#include "Menu.h"
#include "Local.h"
#include "Repartidor.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Domicilio.h"

#include "datatypes/DtFactura.h"
#include "datatypes/DtMenu.h"
#include "datatypes/DtComun.h"
#include "datatypes/DtProducto.h"
#include "datatypes/DtFacturacionDia.h"
#include "datatypes/DtPedido.h"
#include "datatypes/DtMozo.h"
#include "datatypes/DtTransporte.h"



class Sistema : public ISistema
{
private:
    Sistema();
    static Sistema *instance;
    IDictionary *productos;
    IDictionary *ventas;
    IDictionary *repartidores;
    IDictionary *empleados;
    IDictionary *mozos;
    IDictionary *mesas;
    ICollection *clientes;

    ICollection *mesasElegidasParaVenta; // Coleccion de mesas elegidas temporalmente, son seleccionadas por el mozo para iniciar una venta
    int idMozoSeleccionado;              // ID del mozo seleccionado para iniciar una venta
    Venta *ventaTemp;                    // Venta seleccionada temporalmente para agregar productos
    Pedido *pedidoTemp;                  // Pedido seleccionado temporalmente para agregar productos
    bool estaEnPedido;                   // Indica si el producto seleccionado está en un pedido
    bool esMenu;                         // Indica si el producto seleccionado es un menú
    char codigoProductoInformar;         // Código del producto seleccionado para informar
    // int cantidadVentas; // Campo no utilizado
    DtComun *productoComunTemp;
    DtMenu *menuTemp;
    IDictionary *productosComunSeleccionados;
    string nomEmp;
    Transporte medioSeleccionado;
    int ultimoIdEmpleado;
    Transporte medios[3];
    int cantidadMedios;
    int idE;
    DtCliente *clienteTemp;
    Mesa *mesaSeleccionada;
    Producto *productoAQuitar;
    int cantidadAQuitar;
    Mesa *mesaTemp;
    Local * ventaTemporal;
    IDictionary *productosEnPedidoDomicilio;
    int idRepartidorSeleccionado;
    Producto *productoBaja;

public:
    ~Sistema();
    static Sistema *getInstance();

    /*------ ALTA PRODCUTO -----*/
    bool existeProducto(char codigo);                              // retorna true si existe un producto con es codigo
    IDictionary *agregarMenu(char codigoMenu, string descripcion); // devuele una coleccion de DtComun
    void seleccionarProductoComun(char codigoComun, int cantProducto);
    void agregarProductoComun(char codigoComun, string descripcion, float precio);
    void darAltaProducto();

    /*----- ALTA CLIENTE -----*/
    DtCliente altaCliente(string, string, DtDireccion);
    void confirmarAlta();
    void cancelarAlta();
    bool existeCliente(string);
    ICollection* listarClientes();

    /*------ ALTA EMPLEADO ------*/
    void agregarEmpleado(string nombre, int idIngresado);
    ICollection *listarMedioTransporte(); // devuelve una coleccion de DtTransporte
    void elegirMedio(int opcion);
    void darAltaEmpleado();
    ICollection* mostrarEmpleados();
    bool existeEmpleado(int idEmpleado);
    string transporteToString(Transporte t);

    /*------ ASIGNAR MESAS A MOZOS ------*/
    ICollection *calcularAsignacion(int cantMesas, int cantMozos);

    /*------ INICIAR VENTA EN MESA ------*/
    DtAsignacion *ingresarIdMozo(int idMozo); // devuele un DtAsignacion
    void elegirMesas(int numero);             // devuele una coleccion de DtMesas
    void confirmarVentaEnMesa();

    /*------ VENTA A DOMICILIO ------*/
    bool ventaDomicilio(string telefono); // Retorna true si el cliente existe
    ICollection *listarProductos();       // retorna una coleccion de DtProducto
    void agregarProductoPedido(char codigo, int cantidad);
    ICollection *listarRepartidores(); // Retruna una coleccion de Dtrepartidor
    void asignarRepartidorDomicilio(int idRepartidor);
    DtFacturaDomicilio confirmarPedido(DtFecha fechaFactura);

    /*------ VENTAS DE UN MOZO ------*/
    ICollection *listarMozos();
    ICollection *mostrarVentasMozo(int idMozo, DtFecha fecha1, DtFecha fecha2);
    
    /*------ AGREGAR PRODUCTO A UNA VENTA ------*/
    ICollection *listarParaAgregar(int idMesa); // devuele una coleccion de DtProducto
    void seleccionarProductoAgregar(char codigo, int cantidad);
    void confirmarAgregarProducto();

    /*------ QUITAR PRODUCTO A UNA VENTA -------*/
    void ingresarMesa(int idMesa);
    ICollection *productosVenta(); // devuele una coleccion de DtProducto
    void seleccionarProductoQuitar(char codigo, int cant);
    void quitarProductoVenta();

    ICollection *pedidosVentaActual(); // funcion auxiliar, me sirve para ver la cant de pedido en la venta actual y mostrarlo
    
    /*------ FACTURACION DE UNA VENTA ------*/
    DtVenta finalizarVenta(int nroMesa);
    void aplicarDescuento(int descuento);
    DtFactura generarFactura(DtVenta venta, DtFecha fechaFactura);
    void agregarMesaAFacturacion(int nroMesa);
    IDictionary *getMesas(); // Devuelve un diccionario de DtMesa AUXILIAR // nuevo

    /*------ INFORMACION DE UN PRODUCTO ------*/
    ICollection* obtenerProductos();
    bool ingresarCodigoProducto(char codigo);
    DtProducto* infoProducto();
    ICollection* infoProductosIncluidosMenu();  
    IDictionary* obtenerProductosMenu(char codigoMenu); // Devuelve un diccionario de DtProducto AUXULIAR
    
    /*------ BAJA PRODUCTO ------*/
    ICollection *mostrarProductos(); // devuele una coleccion de DtProducto
    void seleccionarProductoBaja(char codigo);
    void darBajaProducto();
    ICollection* retornarMenus();
    
    /*------ RESUMEN FACTURACION DE UN DIA ------*/
    DtFacturacionDia *mostrarInforme(DtFecha fecha);
};

#endif