#pragma once

#include <iostream>
#include "Entidad.h"

const int ANCHO_RATON = 7;
const int ALTO_RATON = 1;

using namespace std;
using namespace System;

class Raton : public Entidad {

private:

public:

	Raton(int x, int y) : Entidad(x, y, ANCHO_RATON, ALTO_RATON) {
		dx = rand() % 3 - 1; // -1, 0 , 1
		dy = rand() % 3 - 1; // -1, 0 , 1
	}

	/*
	--(_c'>
	 */
	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << "--(_c'>";
	}

	void mover(int dx, int dy) {
		this->dx = dx;
		this->dy = dy;
		if (movimiento_valido()) {
			x += dx;
			y += dy;
		}

	}
};