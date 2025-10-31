#pragma once

#include "Figura.h"

class Triangulo : public Figura {

public:
	Triangulo(int y);
	void dibujar(Graphics^ graficos) override;
};

Triangulo::Triangulo(int y) :
	Figura(1, y, rand() % (100 - 10 + 1) + 10, rand() % (100 - 10 + 1) + 10) {
}

void Triangulo::dibujar(Graphics^ graficos) {
	Pen^ lapiz = gcnew Pen(Color::Red);

	Point p1 = Point(x, y + alto);
	Point p2 = Point(x+ancho/2, y);
	Point p3 = Point(x + ancho, y + alto);

	array<Point>^ points = { p1,p2,p3 };

	graficos->DrawPolygon(lapiz, points);
}
