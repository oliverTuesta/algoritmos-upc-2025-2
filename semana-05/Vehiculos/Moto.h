#pragma once
#include "Vehiculo.h"

class Moto : public Vehiculo {
public:

	Moto(int x, int y) : Vehiculo(x,y, rand() % 3 + 1, 7, 3){
	}

	//     o  
	// ----|__
	// (*) (*)
	void mostrar() {
		Console::SetCursorPosition(x, y);
		cout << "    o  ";
		Console::SetCursorPosition(x, y+1);
		cout << "----|__";
		Console::SetCursorPosition(x, y+2);
		cout << "(*) (*)";
	}

};