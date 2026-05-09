#pragma once

#include <iostream>
#include "Entidad.h"

using namespace std;
using namespace System;

const int ANCHO_GATO= 7;
const int ALTO_GATO = 3;

class Gato : public Entidad {

private:

public:

	Gato(int x, int y) : Entidad(x, y, ANCHO_GATO, ALTO_GATO) { }

/*
 /\_/\
( o.o )
 > ^ <
 */
	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << " /\\_/\\ ";
		Console::SetCursorPosition(x, y+1);
		cout << "( o.o )";
		Console::SetCursorPosition(x, y + 2);
		cout << " > ^ < ";
	}

	void mover(char tecla) {
		dx = 0;
		dy = 0;

		switch (tecla) {
			case 'a': 
				dx = -1;
			break;
			case 'd':
				dx = 1;
				break;
			case 'w': 
				dy = -1;
				break;
			case 's':
				dy = 1;
				break;
		}

		if (movimiento_valido()) {
			x += dx;
			y += dy;
		}
	}
};