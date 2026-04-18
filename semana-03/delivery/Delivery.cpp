#include <iostream>

#include "Motorizado.h"
#include "ListaMotorizados.h"
#include "iostream"

using namespace std;

void mostrarMenu() {
	cout << "1.- Agregar Motorizado" << endl;
	cout << "2. - Eliminar Motorizado" << endl;
	cout << "3. - Mostrar Todos los Motorizados" << endl;
	cout << "4. - Motorizados Mapi" << endl;
	cout << "5. - Motorizados Glopo" << endl;
	cout << "0. - Salir" << endl;
	cout << "Seleccione la opción : ";
}

Motorizado* usuario_crea_motorizado() {
	string nombre;
	string apellido;
	string placa;
	string empresa;
	double kilometraje;

	cout << "Ingrese datos del motorizado" << endl;
	cout << "nombre: "; 
	cin >> nombre;
	cout << "apellido: ";
	cin >> apellido;
	cout << "placa: ";
	cin >> placa;
	cout << "empresa: ";
	cin >> empresa;
	cout << "km: ";
	cin >> kilometraje;

	Motorizado* moto = new Motorizado(nombre, apellido, placa, empresa, kilometraje);
	return moto;
}

int main()
{
	setlocale(LC_ALL, "spanish");
	int opcion;
	ListaMotorizados* lista = new ListaMotorizados();
	do {
		mostrarMenu();
		cin >> opcion;

		if (opcion == 1) {
			cout << "CREAR MOTORIZADO" << endl;
			lista->agregar(usuario_crea_motorizado());
		}
		else if (opcion == 2) {
			cout << "ELIMINAR MOTORIZADO" << endl;
			cout << "Ingrese indice: ";
			int indice;
			cin >> indice;
			indice--;
			lista->eliminar(indice);
		}
		else if (opcion == 3) {
			if (lista->get_cantidad() == 0) {
				cout << "NADA PARA MOSTRAR" << endl;
			}
			for (int i = 0; i < lista->get_cantidad(); i++) {
				cout << "indice: " << i + 1 << endl;
				lista->get_elemento(i)->mostrar();
			}
		}
		else if (opcion == 4) {
			lista->motorizados_mapi();
		}
		else if (opcion == 5) {
			lista->motorizados_glopo();
		}
	} while (opcion != 0);
}
