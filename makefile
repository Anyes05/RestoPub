INTERFACES = ICollection/interfaces/
COLECCIONES = ICollection/collections/


all: Cliente.o DtFacturacionDia.o DtTransporte.o DtMozo.o DtPedido.o DtCliente.o DtFactura.o DtFacturaDomicilio.o DtRepartidor.o DtHora.o DtVenta.o DtFecha.o DtMesa.o DtComun.o DtMenu.o DtProducto.o DtAsignacion.o DtDireccion.o Domicilio.o Local.o Venta.o Producto.o Comun.o Comun-Menu.o Menu.o Empleado.o Factura.o Mesa.o Mozo.o Pedido.o Repartidor.o ISistema.o Sistema.o Factory.o ICollectible.o IIterator.o ICollection.o ListNode.o ListIterator.o List.o OrderedDictionary.o IDictionary.o OrderedDictionaryEntry.o String.o IKey.o OrderedKey.o Integer.o main.o
	g++ Cliente.o DtFacturacionDia.o DtTransporte.o DtMozo.o DtPedido.o DtCliente.o DtFactura.o DtFacturaDomicilio.o  DtRepartidor.o DtHora.o DtVenta.o DtFecha.o DtMesa.o DtComun.o DtMenu.o DtProducto.o DtAsignacion.o DtDireccion.o Domicilio.o Local.o Venta.o Producto.o Comun.o Comun-Menu.o Menu.o Empleado.o Factura.o Mesa.o Mozo.o Pedido.o Repartidor.o ISistema.o Sistema.o Factory.o ICollectible.o IIterator.o ICollection.o ListNode.o ListIterator.o List.o main.o String.o Integer.o OrderedDictionary.o OrderedKey.o  IDictionary.o OrderedDictionaryEntry.o  IKey.o  -o programa


ICollectible.o: $(INTERFACES)ICollectible.h
	g++ -c $(INTERFACES)ICollectible.cpp

IIterator.o: $(INTERFACES)IIterator.h
	g++ -c $(INTERFACES)IIterator.cpp

ICollection.o: $(INTERFACES)ICollection.h IIterator.o ICollectible.o
	g++ -c $(INTERFACES)ICollection.cpp

ListNode.o: $(COLECCIONES)ListNode.h
	g++ -c $(COLECCIONES)ListNode.cpp

ListIterator.o: $(COLECCIONES)ListIterator.h ListNode.o
	g++ -c $(COLECCIONES)ListIterator.cpp

List.o: $(COLECCIONES)List.h ICollection.o ListIterator.o
	g++ -c $(COLECCIONES)List.cpp

IKey.o: $(INTERFACES)IKey.cpp
	g++ -c $(INTERFACES)IKey.cpp

OrderedKey.o: $(INTERFACES)OrderedKey.cpp
	g++ -c $(INTERFACES)OrderedKey.cpp

IDictionary.o: $(INTERFACES)IDictionary.h IKey.o ICollectible.o IIterator.o
	g++ -c $(INTERFACES)IDictionary.cpp
	
 OrderedDictionaryEntry.o: $(COLECCIONES)OrderedDictionaryEntry.h OrderedKey.o  ICollectible.o
	g++ -c $(COLECCIONES)OrderedDictionaryEntry.cpp

OrderedDictionary.o: $(COLECCIONES)OrderedDictionary.cpp OrderedDictionaryEntry.o IDictionary.o
	g++ -c $(COLECCIONES)OrderedDictionary.cpp 

String.o: ICollection/String.cpp ICollectible.o OrderedKey.o
	g++ -c ICollection/String.cpp

Integer.o: ICollection/Integer.cpp ICollectible.o OrderedKey.o
	g++ -c ICollection/Integer.cpp

DtDireccion.o:
	g++ -c "./datatypes/DtDireccion.cpp"

DtAsignacion.o:
	g++ -c "./datatypes/DtAsignacion.cpp"

DtProducto.o:
	g++ -c "./datatypes/DtProducto.cpp"

DtComun.o:
	g++ -c "./datatypes/DtComun.cpp"

DtMenu.o:
	g++ -c "./datatypes/DtMenu.cpp"

DtMesa.o:
	g++ -c "./datatypes/DtMesa.cpp"

DtFecha.o:
	g++ -c "./datatypes/DtFecha.cpp"

DtVenta.o:
	g++ -c "./datatypes/DtVenta.cpp"

DtHora.o:
	g++ -c "./datatypes/DtHora.cpp"

DtCliente.o: datatypes/DtCliente.cpp 
	g++ -c datatypes/DtCliente.cpp 

DtFactura.o: datatypes/DtFactura.cpp 
	g++ -c datatypes/DtFactura.cpp 

DtFacturaDomicilio.o: datatypes/DtFacturaDomicilio.cpp
	g++ -c datatypes/DtFacturaDomicilio.cpp

DtFacturacionDia.o:
	g++ -c "datatypes/DtFacturacionDia.cpp"

DtMozo.o:
	g++ -c "datatypes/DtMozo.cpp"

DtTransporte.o:
	g++ -c "datatypes/DtTransporte.cpp"
	
DtRepartidor.o: datatypes/DtRepartidor.cpp 
	g++ -c datatypes/DtRepartidor.cpp 

DtPedido.o: datatypes/DtPedido.cpp
	g++ -c datatypes/DtPedido.cpp

Factura.o: Factura.cpp ICollectible.o
	g++ -c Factura.cpp

Producto.o: Producto.cpp ICollectible.o
	g++ -c Producto.cpp

Comun.o: Producto.o
	g++ -c Comun.cpp

Menu.o:Producto.o
	g++ -c Menu.cpp

Comun-Menu.o: Comun-Menu.cpp
	g++ -c Comun-Menu.cpp

Venta.o: Venta.cpp ICollectible.o
	g++ -c Venta.cpp

Domicilio.o: Venta.o
	g++ -c Domicilio.cpp

Local.o: Venta.o
	g++ -c Local.cpp

Empleado.o: Empleado.cpp ICollectible.o
	g++ -c Empleado.cpp

Mozo.o: Empleado.o
	g++ -c Mozo.cpp

Repartidor.o: Empleado.o
	g++ -c Repartidor.cpp

Cliente.o: Cliente.cpp ICollectible.o
	g++ -c Cliente.cpp

Mesa.o: Mesa.cpp ICollectible.o
	g++ -c Mesa.cpp

Pedido.o: Pedido.cpp ICollectible.o
	g++ -c Pedido.cpp

ISistema.o: ISistema.h
	g++ -c ISistema.cpp

Sistema.o: ISistema.o Sistema.h
	g++ -c Sistema.cpp

Factory.o: Factory.h ISistema.o Sistema.o
	g++ -c Factory.cpp
	
main.o: ISistema.o Factory.o
	g++ -c main.cpp

clean:
	rm -f programa *.o $(INTERFACES)*.o $(COLECCIONES)*.o

run:
	make clean
	make
	clear
	./programa

