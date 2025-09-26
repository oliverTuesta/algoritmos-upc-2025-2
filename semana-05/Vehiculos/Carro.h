#pragma once

#include "Vehiculo.h"

class Carro : public Vehiculo {
public:

	Carro(int x, int y) : Vehiculo(x, y, rand() % 2 + 1, 9, 3) {
	}

	//   _____  
	//  /__|__\
	// (*)   (*)
	void mostrar() {
		Console::SetCursorPosition(x, y);
		cout << "  _____  ";
		Console::SetCursorPosition(x, y + 1);
		cout << " /__|__\\ ";
		Console::SetCursorPosition(x, y + 2);
		cout << "(*)   (*)";
	}

};