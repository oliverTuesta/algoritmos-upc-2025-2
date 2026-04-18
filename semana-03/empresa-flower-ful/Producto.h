#pragma once
#include<string>
#include <iostream>
#include "Proveedor.h"

using namespace std;

class Proveedor;

class Producto {
private:
	int id;
	string nombre;
	string tipo;
	int cantidad;
	int anio;
	double precio;

public:
	Producto(int id, string nombre, string tipo, int cantidad, int anio, double precio);

	int getId();

	void actualizar(string nombre, string tipo, int cantidad, int anio, double precio);
	int getAnio();
	void mostrarProducto();
};


Producto::Producto(int id, string nombre, string tipo, int cantidad, int anio, double precio) {
	this->id = id;
	this->nombre = nombre;
	this->tipo = tipo;
	this->cantidad = cantidad;
	this->anio = anio;
	this->precio = precio;
}

void Producto::actualizar(string nombre, string tipo, int cantidad, int anio, double precio) {
	this->nombre = nombre;
	this->tipo = tipo;
	this->cantidad = cantidad;
	this->anio = anio;
	this->precio = precio;
}

int Producto::getId() {
	return id;
}

int Producto::getAnio() {
	return anio;
}

void Producto::mostrarProducto() {
	cout << "id: " << this->id << endl;
	cout << "nombre: " << this->nombre << endl;
	cout << "tipo: " << this->tipo << endl;
	cout << "cantidad: " << this->cantidad << endl;
	cout << "anio: " << anio << endl;
	cout << "precio: " << precio << endl;
}