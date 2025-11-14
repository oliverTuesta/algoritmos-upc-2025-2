#pragma once


#include <cstdlib>

using namespace System::Windows::Forms;
using namespace System::Drawing;

class Caballo {

private:
	int pasos;
	int dx, dy;
	int x, y;
	int ancho, alto;
	double zoom;
	int idx, idy;
	int sumaIdx, sumaIdy;

public:
	Caballo(int x, int y, int ancho, int alto, double zoom);
	~Caballo();
	void mover(Graphics^ graficos);
	void mover(Keys tecla, Graphics^ graficos);
	void dibujar(Graphics^ graficos, Bitmap^ bmp);
	void cambiarColor(Keys tecla);
	void cambiarColor();
};

Caballo::Caballo(int x, int y, int ancho, int alto, double zoom) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->zoom = zoom;
	sumaIdx = 0;
	sumaIdy = 0;
	dx = dy = 0;
	pasos = 5;
	idx = idy = 0;
}

Caballo::~Caballo() {

}

void Caballo::mover(Graphics^ graficos) {
	int anchoPanel = graficos->VisibleClipBounds.Width;
	int altoPanel = graficos->VisibleClipBounds.Height;
	idx++;
	idx = idx % 3;
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
		idy = 3;
	}
	else if (dy > 0) {
		idy = 0;
	}
	if (dx < 0) {
		idy = 1;
	}
	else if (dx > 1) {
		idy = 2;
	}
	

	x += dx;
	y += dy;
}

void Caballo::mover(Keys tecla, Graphics^ graficos) {
	int anchoPanel = graficos->VisibleClipBounds.Width;
	int altoPanel = graficos->VisibleClipBounds.Height;

	this->dx = this->dy = 0;
	switch (tecla) {
	case Keys::Up: 
		idy = 3;
		this->dy = -pasos;
		break;
	case Keys::Down:
		idy = 0;
		this->dy = pasos;
		break;
	case Keys::Left:
		idy = 1;
		this->dx = -pasos;
		break;
	case Keys::Right:
		idy = 2;
		this->dx = pasos;
		break;
	}

	idx++;
	idx = idx % 3;
	if (x + dx < 0 || x + dx + ancho * zoom >= anchoPanel) {
		return;
	}
	if (y + dy < 0 || y + dy + alto * zoom >= altoPanel) {
		return;
	}
	this->x += this->dx;
	this->y += this->dy;

}

void Caballo::dibujar(Graphics^ graficos, Bitmap^ bmp) {
	Rectangle section = Rectangle((idx + sumaIdx) * ancho, (idy + sumaIdy) * alto, ancho, alto);
	Rectangle mostrar = Rectangle(x, y, ancho * zoom, alto * zoom);
	graficos->DrawImage(bmp, mostrar, section, GraphicsUnit::Pixel);
}
void Caballo::cambiarColor(Keys tecla) {
	switch (tecla) {
	case Keys::B:
		sumaIdx = 0;
		sumaIdy = 0;
		break;
	case Keys::V:
		sumaIdx = 0;
		sumaIdy = 4;
		break;
	case Keys::Z:
		sumaIdx = 3;
		sumaIdy = 4;
		break;
	case Keys::A:
		sumaIdx = 3;
		sumaIdy = 0;
		break;
	}
}

void Caballo::cambiarColor() {
	int numeroRandom = rand() % 4;
	switch (numeroRandom) {
	case 0:
		sumaIdx = 0;
		sumaIdy = 0;
		break;
	case 1:
		sumaIdx = 0;
		sumaIdy = 4;
		break;
	case 2:
		sumaIdx = 3;
		sumaIdy = 4;
		break;
	case 3:
		sumaIdx = 3;
		sumaIdy = 0;
		break;
	}
}