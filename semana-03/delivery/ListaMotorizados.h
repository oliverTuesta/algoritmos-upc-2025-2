#pragma once

#include "iostream"
#include "Motorizado.h"


class ListaMotorizados {
private:
	Motorizado** elementos;
	int cantidad;

	// agregar_motorizado, eliminar_motorizado, motorizados_mapi, motorizados_glopo, motorizados_totales
public:

	ListaMotorizados() {
		cantidad = 0;
		elementos = nullptr;
	}

	void agregar(Motorizado* elemento) {
		Motorizado** temp = new Motorizado * [cantidad + 1];
		for (int i = 0; i < cantidad; i++) {
			temp[i] = elementos[i];
		}
		temp[cantidad] = elemento;
		delete[]elementos;
		elementos = temp;
		cantidad++;
	}

	void eliminar(int indice) {
		if (indice < 0 || indice >= cantidad) {
			cout << "Indice no valido" << endl;
			return;
		}

		Motorizado** temp = new Motorizado * [cantidad - 1];
		// i va a recorrer los elementos del arreglo temporal
		// j va a recorrer los elementos del arreglo original (elementos)
		int j = 0;
		for (int i = 0; i < cantidad - 1; i++) {
			if (j == indice) {
				j++;
			}
			temp[i] = elementos[j];
			j++;
		}

		delete[]elementos;
		elementos = temp;
		cantidad--;
	}

	int get_cantidad() {
		return cantidad;
	}

	Motorizado* get_elemento(int indice) {
		if (indice < 0 || indice >= cantidad) {
			cout << "Indice no valido" << endl;
			return nullptr;
		}

		return elementos[indice];
	}

	void motorizados_mapi() {
		cout << "MOTORIZADOS MAPI" << endl;
		for (int i = 0; i < cantidad; i++) {
			if (elementos[i]->getEmpresa() == "mapi") {
				elementos[i]->mostrar();
			}
		}
	}

	void motorizados_glopo() {
		cout << "MOTORIZADOS GLOPO" << endl;
		for (int i = 0; i < cantidad; i++) {
			if (elementos[i]->getEmpresa() == "glopo") {
				elementos[i]->mostrar();
			}
		}
	}

};