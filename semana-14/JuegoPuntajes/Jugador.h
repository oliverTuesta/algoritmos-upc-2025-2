#pragma once

#include "Entidad.h"
using namespace System::Windows::Forms;

class Jugador : public Entidad {
private:
	int vidas = 5;

public:
	Jugador(Bitmap^ bmp, int x, int y) : Entidad(0, 0, 3, 4, 1) {
		ancho = bmp->Width / 3;
		alto = bmp->Height / 4;
		maxCol = 3;
		maxFila = 4;
		pasos = 3;


		this->x = x;
		this->y = y;
	}

	void mover(Keys tecla, Graphics^ graficos) {
		int anchoPanel = graficos->VisibleClipBounds.Width;
		int altoPanel = graficos->VisibleClipBounds.Height;

		this->dx = this->dy = 0;
		switch (tecla) {
		case Keys::Up:
			fila = 3;
			this->dy = -pasos;
			break;
		case Keys::Down:
			fila = 0;
			this->dy = pasos;
			break;
		case Keys::Left:
			fila = 1;
			this->dx = -pasos;
			break;
		case Keys::Right:
			fila = 2;
			this->dx = pasos;
			break;
		}

		columna++;
		columna = columna % maxCol;
		if (x + dx < 0 || x + dx + ancho * zoom >= anchoPanel) {
			return;
		}
		if (y + dy < 0 || y + dy + alto * zoom >= altoPanel) {
			return;
		}
		this->x += this->dx;
		this->y += this->dy;
	}
};