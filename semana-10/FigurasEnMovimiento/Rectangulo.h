#pragma once

#include "Figura.h"

class Rectangulo : public Figura {

public:
	Rectangulo(int anchoPanel, int altoPanel);
	void dibujar(Graphics^ graficos) override;
};

Rectangulo::Rectangulo(int anchoPanel, int altoPanel) : 
	Figura(anchoPanel, altoPanel, rand() % (100 - 10 + 1) + 10, rand() % (100 - 10 + 1) + 10) {
}

void Rectangulo::dibujar(Graphics^ graficos) {
	Pen^ lapiz = gcnew Pen(Color::Red);
	graficos->DrawRectangle(lapiz, x, y, ancho, alto);
}

