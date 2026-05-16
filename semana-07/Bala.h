#pragma once

#include "Constantes.h"
#include "Entidad.h"
#include <iostream>

using namespace System;
using namespace std;

class Bala : public Entidad {
private:
	int dx;
	int dy;

public:
	Bala(int x, int y, int dx, int dy) : Entidad(x, y, 1, 1) {
		this->dx = dx;
		this->dy = dy;
	}

	void mover() {
		if (esta_vivo == false) {
			return;
		}

		if (x + dx >= 0 && x + ancho - 1 + dx < ANCHO_PANTALLA) {
			x += dx;
		}
		else {
			esta_vivo = false;
		}
		if (y + dy >= 0 && y + alto - 1 + dy < ALTO_PANTALLA) {
			y += dy;
		}
		else {
			esta_vivo = false;
		}
	}

	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << "%";
	}
};