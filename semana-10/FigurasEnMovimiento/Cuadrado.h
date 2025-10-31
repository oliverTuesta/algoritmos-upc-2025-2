#pragma once

#include "Figura.h"

class Cuadrado : public Figura {

public:
	Cuadrado(int anchoPanel, int altoPanel);
	void dibujar(Graphics^ graficos) override;
};

Cuadrado::Cuadrado(int anchoPanel, int altoPanel) :
	Figura(anchoPanel, altoPanel, 1, 1) {
	this->ancho = rand() % (100 - 10 + 1) + 10;
	this->alto = this->ancho;
	this->x = rand() % (anchoPanel - ancho);
	this->y = rand() % (altoPanel - alto);
}

void Cuadrado::dibujar(Graphics^ graficos) {
	Pen^ lapiz = gcnew Pen(Color::Purple);
	graficos->DrawRectangle(lapiz, x, y, ancho, alto);
}

