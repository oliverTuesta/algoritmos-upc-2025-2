#pragma once

#include "Figura.h"

class Elipse : public Figura {

public:
	Elipse(int y);
	void dibujar(Graphics^ graficos) override;
};

Elipse::Elipse(int y) : Figura(1, y, rand() % (100 - 10 + 1) + 10, rand() % (100 - 10 + 1) + 10) {}

void Elipse::dibujar(Graphics^ graficos) {
	Pen^ lapiz = gcnew Pen(Color::Blue);
	graficos->DrawEllipse(lapiz, x, y, ancho, alto);
}