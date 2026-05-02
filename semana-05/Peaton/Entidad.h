#pragma once

#define ANCHO 80
#define ALTO 40

class Entidad {

protected:
	int x;
	int y;
	int dx, dy;
	int ancho;
	int alto;

public:
	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
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

	void set_x(int x) {
		this->x = x;
	}
	void set_y(int y) {
		this->y = y;
	}

	void mover() {
		if (x + ancho - 1 + dx < ANCHO && x + dx >= 0) {
			x += dx;
		}
		if (y + alto - 1 + dy < ALTO && y + dy >= 0) {
			y += dy;
		}
	}

	bool hubo_colision(Entidad* b) {
		return x < b->get_x() + b->get_ancho() &&
			x + ancho > b->get_x() &&
			y < b->get_y() + b->get_alto() &&
			y + alto > b->get_y();
	}
};