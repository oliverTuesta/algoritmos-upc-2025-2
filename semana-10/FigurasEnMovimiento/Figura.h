#pragma once

#include <cstdlib>

using namespace System::Drawing;

class Figura {

protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int velocidad;

	Figura(int anchoPanel, int altoPanel, int ancho, int alto) {
		dx = 1;
		dy = -1;
		this->ancho = ancho;
		this->alto = alto;
		x = rand() % (anchoPanel - ancho);
		y = rand() % (altoPanel - alto);
		velocidad = rand() % (10 - 2 + 1) + 2;
	}

public:
	virtual void dibujar(Graphics^ graficos) = 0;
	void mover(int ancho, int alto);
};

void Figura::mover(int anchoPanel, int altoPanel) {
	if (x + ancho - 1 + dx >= anchoPanel || x + dx < 0) {
		dx *= -1;
	}
	if (y + alto - 1 + dy >= altoPanel || y + dx < 0) {
		dy *= -1;
	}
	x += dx * velocidad;
	y += dy * velocidad;
}