#pragma once

#include "iostream"
#include "Constantes.h"
#include <cstdlib>

using namespace System;
using namespace std;

class Roca {

private:
	int x;
	int y;
	int dx;
	int dy;


public:
	Roca(int x, int y) {
		this->x = x;
		this->y = y;
		dx = 0;
		dy = +1;
	}

	void mover() {
		if (y + dy >= ALTO) {
			reinciar_posicion();
			return;
		}
		y += dy;
	}

	void reinciar_posicion() {
		y = rand() % 5;
		x = rand() % ANCHO;
	}

	void mostrar() {
		Console::SetCursorPosition(x, y);
		cout << "@";
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}
};