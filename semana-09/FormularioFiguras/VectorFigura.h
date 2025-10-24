#pragma once

#include "Figura.h"
#include <iostream>

using namespace std;

class VectorFigura {
private:
	Figura** elementos;
	int cantidad;

public:
	VectorFigura();

	Figura* getElemento(int indice);

	void addElemento(Figura* cuadrado);

	void deleteElemento(int indice);
	int getCantidad();
};

VectorFigura::VectorFigura() {
	cantidad = 0;
}

Figura* VectorFigura::getElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return elementos[indice];
}

void VectorFigura::addElemento(Figura* elemento) {
	Figura** temp = new Figura * [cantidad + 1];
	for (int i = 0; i < cantidad; i++) {
		temp[i] = elementos[i];
	}
	temp[cantidad] = elemento;
	cantidad++;
	//delete(elementos)
	elementos = temp;
}

void VectorFigura::deleteElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		//cout << "Indice fuera de rango" << endl;
		return;
	}
	Figura** temp = new Figura * [cantidad - 1];
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

int VectorFigura::getCantidad() {
	return cantidad;
}