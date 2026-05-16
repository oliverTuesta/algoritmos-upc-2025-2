#pragma once

#include "Constantes.h"
#include "Entidad.h"
#include <iostream>

using namespace System;
using namespace std;

const int ANCHO_MONIGOTE = 2;
const int ALTO_MONIGOTE = 2;

class Monigote : public Entidad {

public:
	Monigote(int x, int y) : Entidad(x, y, ANCHO_MONIGOTE, ALTO_MONIGOTE) {
	}

	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << "X";
		Console::SetCursorPosition(x, y + 1);
		cout << "/\\";
	}

	void mover(Entidad* casa) {
		// mover en x
		if (casa->get_x() < x) {
			// izquierda
			x--;
		}
		else if (casa->get_x() > x){
			// derecha
			x++;
		}

		// mover en y
		if (casa->get_y() < y) {
			y--;
		}
		else if (casa->get_y() > y) {
			y++;
		}
	}
};