#pragma once

#include "Entidad.h"
using namespace System::Windows::Forms;

class Enemigo : public Entidad {
private:

public:
	Enemigo(Bitmap^ bmp, Graphics^ g) : Entidad(0, 0, 3, 4, 0.5) {
		ancho = bmp->Width / 3;
		alto = bmp->Height / 4;
		maxCol = 3;
		maxFila = 4;

		int anchoPantalla = g->VisibleClipBounds.Width;
		int altoPantalla = g->VisibleClipBounds.Height;
		x = rand() % int(anchoPantalla - ancho * zoom);
		y = rand() % int(altoPantalla - alto * zoom);
	}

	Enemigo(Bitmap^ bmp, int x, int y) : Entidad(0, 0, 3, 4, 0.5) {
		ancho = bmp->Width / 3;
		alto = bmp->Height / 4;
		maxCol = 3;
		maxFila = 4;

		this->x = x;
		this->y = y;
	}

	void mover(Graphics^ graficos) {
		int anchoPanel = graficos->VisibleClipBounds.Width;
		int altoPanel = graficos->VisibleClipBounds.Height;
		columna++;
		columna = columna % maxCol;
		if (dx == 0 && dy == 0) {
			dx = pasos;
			dy = pasos;
		}

		int numeroRandom = rand() % 100 + 1;
		if (numeroRandom >= 95) {
			dx *= -1;
		}
		numeroRandom = rand() % 100 + 1;
		if (numeroRandom >= 95) {
			dy *= -1;
		}

		if (x + dx < 0 || x + dx + ancho * zoom >= anchoPanel) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + alto * zoom >= altoPanel) {
			dy *= -1;
		}

		if (dy < 0) {
			fila = 3;
		}
		else if (dy > 0) {
			fila = 0;
		}
		if (dx < 0) {
			fila = 1;
		}
		else if (dx > 1) {
			fila = 2;
		}

		x += dx;
		y += dy;
	}


};