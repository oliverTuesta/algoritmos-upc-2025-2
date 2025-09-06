#include <iostream>
#include "Eclipse.h"
#include "VectorEclipses.h"

using namespace std;

Eclipse* registrarEclipse() {
	string tipo;
	string fecha;
	int hora;
	char sismos; // s de si y n de no
	char lluvias; // s de si y n de no
	string visibilidad;

	cout << "Ingrese el tipo de eclipse: "; cin >> tipo;
	cout << "Ingrese la fecha del eclipse: "; cin >> fecha;
	cout << "Ingrese la hora del eclipse: "; cin >> hora;
	cout << "Ingrese si hubo sismos (s o n): "; cin >> sismos;
	cout << "Ingrese si hubo lluvias (s o n): "; cin >> lluvias;
	cout << "Ingrese hasta que contienente fue visible: "; cin >> visibilidad;

	Eclipse* ec = new Eclipse(tipo, fecha, hora, sismos, lluvias, visibilidad);
	return ec;
}

void modificarEclipse(Eclipse *ec) {
	string tipo;
	string fecha;
	int hora;
	char sismos; // s de si y n de no
	char lluvias; // s de si y n de no
	string visibilidad;

	cout << "Ingrese el tipo de eclipse: "; cin >> tipo;
	cout << "Ingrese la fecha del eclipse: "; cin >> fecha;
	cout << "Ingrese la hora del eclipse: "; cin >> hora;
	cout << "Ingrese si hubo sismos (s o n): "; cin >> sismos;
	cout << "Ingrese si hubo lluvias (s o n): "; cin >> lluvias;
	cout << "Ingrese hasta que contienente fue visible: "; cin >> visibilidad;

	ec->setTipo(tipo);
	ec->setFecha(fecha);
	ec->setHora(hora);
	ec->setSismos(sismos);
	ec->setLluvias(lluvias);
	ec->setVisibilidad(visibilidad);
}

void mostrarMenu() {
	cout << "\t\tECLIPSES" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Registrar eclipse" << endl;
	cout << "2. Modificar eclipse" << endl;
	cout << "3. Eliminar eclipse" << endl;
	cout << "4. Reporte eclipses" << endl;
	cout << endl;
	cout << "0. Salir" << endl;
}

void menu() {
	VectorEclipses* vectore = new VectorEclipses();
	int opcion;
	do {
		mostrarMenu();
		cout << "Ingrese opcion: "; cin >> opcion;
		if (opcion == 1) {
			cout << "Agregar eclipse" << endl;
			cout << "---------------------------" << endl;
			vectore->agregarEclipse(registrarEclipse());
		}
		else if (opcion == 2) {

			cout << "Modificar eclipse" << endl;
			cout << "---------------------------" << endl;
			int indice;
			cout << "Ingrese el indice: "; cin >> indice;
			Eclipse* ec = vectore->getEclipse(indice);
			if (ec != nullptr) {
				modificarEclipse(ec);
			}
		}
		else if (opcion == 3) {
			cout << "Eliminar eclipse" << endl;
			cout << "---------------------------" << endl;
			int indice;
			cout << "Ingrese el indice: "; cin >> indice;
			vectore->eliminarEclipse(indice);
		} else if (opcion == 4) {
			cout << "Eclipse" << endl;
			cout << "---------------------------" << endl;
			for (int i = 0; i < vectore->getCantidad(); i++) {
				Eclipse* ec = vectore->getEclipse(i);
				ec->mostrarEclipse();
				cout << endl;
			}
		}
	} while (opcion != 0);
}

int main() {
	menu();
	return 0;
}