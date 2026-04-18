#pragma once

#include <iostream>
#include <string>

using namespace std;


class Persona {
private:
	string nombre;
	string apellido;

public:

	Persona(string nombre, string apellido) {
		this->nombre = nombre;
		this->apellido = apellido;
	}

	void mostrar() {
		cout << "nombre: " << nombre << endl;
		cout << "apellido: " << apellido << endl;
	}
};