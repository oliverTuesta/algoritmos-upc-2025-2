#pragma once

#include <cstdlib>

using namespace System::Drawing;

class Figura {

protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int velocidad;

	Figura(int x, int y, int ancho, int alto) {
		dx = 1;
		dy = 0;
		this->ancho = ancho;
		this->alto = alto;
		this->x = x;
		this->y = y;
		velocidad = rand() % (10 - 2 + 1) + 2;
	}

public:
	virtual void dibujar(Graphics^ graficos) = 0;
	void mover(int ancho, int alto);
	void iniciarDeNuevo();
	bool estaEnMeta(int meta);
};

void Figura::mover(int anchoPanel, int altoPanel) {
	if (x + ancho - 1 + dx >= anchoPanel || x + dx < 0) {
		dx = 0;
	}
	x += dx * velocidad;
}

bool Figura::estaEnMeta(int meta) {
	if (x + ancho - 1 + dx >= meta) {
		return true;
	}
	return false;
}

void Figura::iniciarDeNuevo() {
	x = 1;
	velocidad = rand() % (10 - 2 + 1) + 2;
	dx = 1;
}