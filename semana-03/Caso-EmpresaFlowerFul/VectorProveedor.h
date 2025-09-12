#pragma once
#include "Proveedor.h"

class VectorProveedor
{
private:
	int cantidad;
	Proveedor** elementos;

public:
	VectorProveedor();
	void agregarElemento(Proveedor* eclipse);
	Proveedor* getElemento(int indice);
	int getCantidad();
};

VectorProveedor::VectorProveedor() {
	cantidad = 0;
	elementos = nullptr;
}

void VectorProveedor::agregarElemento(Proveedor* elemento) {
	Proveedor** temporal = new Proveedor * [cantidad + 1];
	for (int i = 0; i < cantidad; i++) {
		temporal[i] = elementos[i];
	}
	temporal[cantidad] = elemento;
	elementos = temporal;
	cantidad++;
}

Proveedor* VectorProveedor::getElemento(int indice) {
	if (indice < 0 || indice >= cantidad) {
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return elementos[indice];
}

int VectorProveedor::getCantidad() {
	return cantidad;
}