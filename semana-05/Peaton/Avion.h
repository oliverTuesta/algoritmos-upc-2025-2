#pragma once
#include "iostream"
#include "Entidad.h"

using namespace std;
using namespace System;

class Avion : public Entidad {
private:

public:
	Avion(int x, int y) : Entidad(x, y){
		ancho = 9;
		alto = 2;
		dx = 0;
		dy = 1;
	}

	void mostrar() {
		Console::SetCursorPosition(x, y);
		cout << "  __|__  ";
		Console::SetCursorPosition(x, y + 1);
		cout << "---oOo---";
	}

	void volver_arriba() {
		if (y + alto - 1 + dy >= ALTO) {
			y = 0;
			x = rand() % (ANCHO - 1 - ancho);
		}
	}
};