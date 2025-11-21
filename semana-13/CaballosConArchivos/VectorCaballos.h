#pragma once
#include "Caballo.h"


class VectorCaballos {
private:
	Caballo** elementos;
	int cantidad;

public:
	VectorCaballos();

	Caballo* getElemento(int indice);

	void addElemento(Caballo* cuadrado);

	void deleteElemento(int indice);
	int getCantidad();
};

VectorCaballos::VectorCaballos() {
	cantidad = 0;
}

Caballo* VectorCaballos::getElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		return nullptr;
	}
	return elementos[indice];
}

void VectorCaballos::addElemento(Caballo* elemento) {
	Caballo** temp = new Caballo * [cantidad + 1];
	for (int i = 0; i < cantidad; i++) {
		temp[i] = elementos[i];
	}
	temp[cantidad] = elemento;
	cantidad++;
	//delete(elementos)
	elementos = temp;
}

void VectorCaballos::deleteElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		//cout << "Indice fuera de rango" << endl;
		return;
	}
	Caballo** temp = new Caballo * [cantidad - 1];
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

int VectorCaballos::getCantidad() {
	return cantidad;
}