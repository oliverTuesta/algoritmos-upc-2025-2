#pragma once

#pragma once

#include "Producto.h"

using namespace std;

class Proveedor {

private:
	string ruc;
	string razonSocial;
	char categoria;
	string direccion;
	string telefono;

	int cantidadProductos;
	Producto** productos;

	void eliminarProducto(int idProducto);

public:

	Proveedor(string ruc, string razonSocial, char categoria, string direccion, string telefono);
	void crearProducto(string nombre, string tipo, int cantidad, int anio, double precio);
	Producto* getProducto(int indice);
	int getCantidadProductos();
	void eliminarProductosVencidos();
	string getRazonSocial();
	void mostrarProductos();
};

Proveedor::Proveedor(string ruc, string razonSocial, char categoria, string direccion, string telefono) {
	this->ruc = ruc;
	this->razonSocial = razonSocial;
	this->categoria = categoria;
	this->direccion = direccion;
	this->telefono = telefono;
	this->cantidadProductos = 0;
	this->productos = nullptr;
};

void Proveedor::crearProducto(string nombre, string tipo, int cantidad, int anio, double precio) {
	int idProducto = 1;
	if (cantidadProductos > 0) {
		Producto* ultimoProducto = productos[cantidadProductos - 1];
		idProducto = ultimoProducto->getId() + 1;
	}
	Producto* nuevoProducto = new Producto(idProducto, nombre, tipo, cantidad, anio, precio);

	Producto** temporal = new Producto * [cantidadProductos + 1];
	for (int i = 0; i < cantidadProductos; i++) {
		temporal[i] = productos[i];
	}
	temporal[cantidadProductos] = nuevoProducto;
	productos = temporal;
	cantidadProductos++;
}


Producto* Proveedor::getProducto(int indice) {
	if (indice < 0 || indice >= cantidadProductos) {
		cout << "Fuera de rango" << endl;
		return nullptr;
	}

	return productos[indice];
}

int Proveedor::getCantidadProductos() {
	return cantidadProductos;
}

void Proveedor::eliminarProducto(int idProducto) {

	bool productoEncontrado = false;
	Producto** temporal = new Producto * [cantidadProductos - 1];

	for (int i = 0, j = 0; i < cantidadProductos; i++) {
		if (productos[i]->getId() == idProducto) {
			productoEncontrado = true;
		}
		else {
			temporal[j] = productos[i];
			j++;
		}
	}

	if (productoEncontrado == false) {
		return;
	}

	productos = temporal;
	cantidadProductos--;
}

void Proveedor::eliminarProductosVencidos() {
	int cnt = 0;
	int* idsProductosVencidos = new int[cantidadProductos];
	for (int i = 0; i < cantidadProductos; i++) {
		if (productos[i]->getAnio() <= 2022) {
			idsProductosVencidos[cnt] = productos[i]->getId();
			cnt++;
		}
	}

	for (int i = 0; i < cnt; i++) {
		cout << "eliminando producto con id: " << idsProductosVencidos[i] << endl;
		this->eliminarProducto(idsProductosVencidos[i]);
	}

	if (cnt == 0) {
		cout << "no se han eliminado productos" << endl;
	}
	else {
		cout << cnt << " productos eliminados" << endl;
	}
}

string Proveedor::getRazonSocial() {
	return razonSocial;
}

void Proveedor::mostrarProductos() {
	if (cantidadProductos == 0) {
		cout << "Proveedor " << razonSocial << " NO tiene productos registrados" << endl;
		return;
	}

	cout << "Produtos del proveedor: " << razonSocial << endl;

	for (int i = 0; i < cantidadProductos; i++) {
		productos[i]->mostrarProducto();
	}
	cout << endl;
}