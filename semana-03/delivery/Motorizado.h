#pragma once

#include "Persona.h"
#include <string>

using namespace std;

class Motorizado {
private:
	Persona *persona;
	string placa; 
	string empresa;
	double kilometraje;

public:

	Motorizado(string nombre, string apellido, string placa, string empresa, double _kilometraje) {
		persona = new Persona(nombre, apellido);
		this->placa = placa;
		this->empresa = empresa;
		this->kilometraje = _kilometraje;
	}

	double precio() {
		return kilometraje * 1.5;
	}

	string getEmpresa() {
		return empresa;
	}

	void mostrar() {
		persona->mostrar();
		cout << "placa: " << placa << endl;
		cout << "empresa: " << empresa << endl;
		cout << "km: " << kilometraje << endl;
		cout << "precio: " << precio() << endl;
		cout << endl;
	}
};