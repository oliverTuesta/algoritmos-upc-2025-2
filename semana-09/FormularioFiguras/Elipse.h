#pragma once

#include "Figura.h"

#define PI 3.1415927

class Elipse : public Figura {

private:

public:

	Elipse(int x, int y, int lado1, int lado2);
	~Elipse();

	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Elipse::Elipse(int x, int y, int lado1, int lado2) : Figura(x, y, lado1, lado2) {

}

Elipse::~Elipse() {

}

void Elipse::dibujar(Graphics^ g) {
	SolidBrush^ brocha = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(brocha, x, y, lado1, lado2);
}

double Elipse::getArea() {
	return lado1/2 * lado2/2 * PI;
}