#pragma once
#include "Cuadrado.h"

class VectorCuadrado {
private:
	Cuadrado** elementos;
	int cantidad;

public:
	VectorCuadrado();

	Cuadrado* getElemento(int indice);

	void addElemento(Cuadrado* cuadrado);

	void deleteElemento(int indice);
	int getCantidad();
};

VectorCuadrado::VectorCuadrado() {
	cantidad = 0;
}

Cuadrado* VectorCuadrado::getElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return elementos[indice];
}

void VectorCuadrado::addElemento(Cuadrado* elemento) {
	Cuadrado** temp = new Cuadrado * [cantidad + 1];
	for (int i = 0; i < cantidad; i++) {
		temp[i] = elementos[i];
	}
	temp[cantidad] = elemento;
	cantidad++;
	//delete(elementos)
	elementos = temp;
}

void VectorCuadrado::deleteElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		//cout << "Indice fuera de rango" << endl;
		return;
	}
	Cuadrado** temp = new Cuadrado * [cantidad - 1];
	for (int i = 0, j = 0; i < cantidad; i++) {
		if (indice != i) {
			temp[j] = elementos[i];
			j++;
		}
	}
	cantidad--;
	//delete(elementos)
	elementos = temp;
}

int VectorCuadrado::getCantidad() {
	return cantidad;
}