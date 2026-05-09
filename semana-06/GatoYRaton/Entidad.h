#pragma once

#include "Constantes.h"

class Entidad {
protected:
	int x;
	int y;
	int ancho;
	int alto;
	int dx, dy;

public:

	Entidad(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
	}

	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_ancho() {
		return ancho;
	}
	int get_alto() {
		return alto;
	}
	int get_dx() {
		return dx;
	}
	int get_dy() {
		return dy;
	}

	bool movimiento_valido() {
		if (x + dx + ancho - 1 >= ANCHO || x + dx < 0) {
			return false;
		}
		if (y + dy + alto - 1 >= ALTO || y + dy < 0) {
			return false;
		}

		return true;
	}

	virtual void dibujar() = 0;

	bool hubo_colision(Entidad* b) {
		return x <  b->get_x() + b->get_ancho() &&
			x + ancho > b->get_x() &&
			y < b->get_y() + b->get_alto() &&
			y + alto > b->get_y();
	}
};