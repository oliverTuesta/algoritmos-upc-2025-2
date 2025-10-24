#pragma once

#include "Figura.h"

class Linea : public Figura {

private:
	int x2, y2;

public:

	Linea(int x, int y, int x2, int y2);
	~Linea();

	void dibujar(Graphics^ g) override;
	double getArea() override;
};

Linea::Linea(int x, int y, int x2, int y2) : Figura(x, y, 0, 0) {
	this->x2 = x2;
	this->y2 = y2;
}

Linea::~Linea() {
}

void Linea::dibujar(Graphics^ g) {
	Pen^ lapiz = gcnew Pen(Color::Green);
	g->DrawLine(lapiz, x, y, x2, y2);
}

double Linea::getArea() {
	return 0;
}