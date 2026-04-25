#pragma once

#include "iostream"
#include "Constantes.h"

using namespace System;
using namespace std;

class Bala {

private:
	int x;
	int y;

	int dx;
	int dy;

	bool existe;

public:
	Bala(int x, int y) {
		this->x = x;
		this->y = y;
		dx = 0;
		dy = -1;
		existe = true;
	}

	void mover() {
		if (existe == false) {
			return;
		}

		if (x + dx < 0 || x + dx >= ANCHO) {
			existe = false;
			return;
		}

		if (y + dy < 0 || y + dy >= ALTO) {
			existe = false;
			return;
		}

		x += dx;
		y += dy;
	}

	bool hay_colision(Roca* r) {
		if (x == r->get_x() && y == r->get_y()) {
			return true;
		}
		return false;
	}

	void mostrar() {
		if (existe == false) {
			return;
		}
		Console::SetCursorPosition(x, y);
		cout << "|";
	}

	bool get_existe() {
		return existe;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}
};