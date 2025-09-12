#include "VectorProveedor.h"
#include "conio.h"

void mostrarMenu() {
	cout << "\t\FLOWER FUL" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Insertar Producto" << endl;
	cout << "2. Insertar Proveedor" << endl;
	cout << "3. Modificar Producto" << endl;
	cout << "4. Eliminar Productos vencidos" << endl;
	cout << "5. Mostrar todos los productos en stock" << endl;
	cout << endl;
	cout << "0. Salir" << endl;
}

void menu() {
	VectorProveedor* proveedores = new VectorProveedor();
	int opcion;
	do {
		mostrarMenu();
		cout << "Ingrese opcion: "; cin >> opcion;
		if (opcion == 1) {
			cout << "1. Insertar Producto" << endl;
			cout << "---------------------" << endl;
			cout << "Selecciona un proveedor de la lista" << endl;
			for (int i = 0; i < proveedores->getCantidad(); i++) {
				cout << i + 1 << ": " << proveedores->getElemento(i)->getRazonSocial() << endl;
			}

			cout << "Ingrese el indice: " << endl;
			int indiceProv; 
			cin >> indiceProv;
			indiceProv--;
			if (indiceProv < 0 || indiceProv >= proveedores->getCantidad()) {
				cout << "Fuera de rango" << endl;
			}
			else {
				string nombre;
				string tipo;
				int cantidad;
				int anio;
				double precio;

				cout << "Ingrese los valores del producto: " << endl;
				cout << "nombre: "; cin >> nombre;
				cout << "tipo: "; cin >> tipo;
				cout << "cantidad: "; cin >> cantidad;
				cout << "anio: "; cin >> anio;
				cout << "precio: "; cin >> precio;

				proveedores->getElemento(indiceProv)->crearProducto(nombre, tipo, cantidad, anio, precio);
			}
		}
		else if (opcion == 2) {
			string ruc;
			string razonSocial;
			char categoria;
			string direccion;
			string telefono;
			cout << "2. Insertar Proveedor" << endl;
			cout << "---------------------" << endl;
			cout << "Ingrese los valores del proveedor: " << endl;
			cout << "ruc: "; cin >> ruc;
			cout << "razonSocial: "; cin >> razonSocial;
			cout << "categoria: "; cin >> categoria;
			cout << "direccion: "; cin >> direccion;
			cout << "telefono: "; cin >> telefono;

			Proveedor* nuevoProveedor = new Proveedor(ruc, razonSocial, categoria, direccion, telefono);
			proveedores->agregarElemento(nuevoProveedor);
		}
		else if (opcion == 3) {
			cout << "3. Modificar Producto" << endl;
			cout << "---------------------" << endl;
			cout << "Selecciona el proveedor donde está su producto" << endl;
			for (int i = 0; i < proveedores->getCantidad(); i++) {
				cout << i + 1 << ": " << proveedores->getElemento(i)->getRazonSocial() << endl;
			}

			cout << "Ingrese el indice: " << endl;
			int indiceProv;
			cin >> indiceProv;
			indiceProv--;
			if (indiceProv < 0 || indiceProv >= proveedores->getCantidad()) {
				cout << "Fuera de rango" << endl;
			}
			else {
				Proveedor* proveedorSelec = proveedores->getElemento(indiceProv);
				proveedorSelec->mostrarProductos();
				int idProducto;
				cout << "Ingrese el id del producto: "; cin >> idProducto;
				Producto* productoModificar = nullptr;
				for (int i = 0; i < proveedorSelec->getCantidadProductos(); i++) {
					if (proveedorSelec->getProducto(i)->getId() == idProducto) {
						productoModificar = proveedorSelec->getProducto(i);
						break;
					}
				}
				if (productoModificar == nullptr) {
					cout << "No se ha encontrado el producto ingresado" << endl;
				}
				else {
					string nombre;
					string tipo;
					int cantidad;
					int anio;
					double precio;
					cout << "Ingrese los nuevos  valores del producto: " << endl;
					cout << "nombre: "; cin >> nombre;
					cout << "tipo: "; cin >> tipo;
					cout << "cantidad: "; cin >> cantidad;
					cout << "anio: "; cin >> anio;
					cout << "precio: "; cin >> precio;
					productoModificar->actualizar(nombre, tipo, cantidad, anio, precio);
					cout << "*producto actualizado correctamente" << endl;
				}
			}
		}
		else if (opcion == 4) {
			for (int i = 0; i < proveedores->getCantidad(); i++) {
				proveedores->getElemento(i)->eliminarProductosVencidos();
			}
		}
		else if (opcion == 5) {
			for (int i = 0; i < proveedores->getCantidad(); i++) {
				proveedores->getElemento(i)->mostrarProductos();
			}
		}
		cout << "presione cualquier tecla para continuar" << endl;
		_getch();
		system("cls");
	} while (opcion != 0);
}


int main() {
	menu();
}