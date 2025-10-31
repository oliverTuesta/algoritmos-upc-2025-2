#pragma once

#include "Figura.h"

class Elipse : public Figura {

public:
	Elipse(int anchoPanel, int altoPanel);
	void dibujar(Graphics^ graficos) override;
};

Elipse::Elipse(int anchoPanel, int altoPanel) : Figura(anchoPanel, altoPanel, rand() % (100 - 10 + 1) + 10, rand() % (100 - 10 + 1) + 10) {}

void Elipse::dibujar(Graphics^ graficos) {
	Pen^ lapiz = gcnew Pen(Color::Blue);
	graficos->DrawEllipse(lapiz, x, y, ancho, alto);
}