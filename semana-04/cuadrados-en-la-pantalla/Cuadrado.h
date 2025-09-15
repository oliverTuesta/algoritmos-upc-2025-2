#pragma once
#include <iostream>

#define ANCHO 60
#define ALTO 31

using namespace std;
using namespace System;

class Cuadrado {
private:
	int x; 
	int y;
	int color;
	int dx;
	int dy;
	int velocidad = 2;

public:
	Cuadrado();
	Cuadrado(int x, int y);

	void cambiarColorRandom();
	void mostrar();
	void desplazar();
	void borrar();
	int getX();
	int getY();
};

Cuadrado::Cuadrado() {
	x = 0;
	y = 0;
	dx = velocidad;
	dy = 0;
	this->cambiarColorRandom();
}

Cuadrado::Cuadrado(int x, int y) {
	this->x = x;
	this->y = y;
	dx = velocidad;
	dy = 0;
	color = 1;
}

void Cuadrado::mostrar() {
	System::Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(color);
	std::cout << char(219);
}

void Cuadrado::desplazar() {
	x += dx;
	y += dy;
	if (dx != 0 && x >= ANCHO) {
		x-=dx;
		dx = 0;
		dy = velocidad;
	}
	else if (dy != 0 && y >= ALTO) {
		y -= dy;
		dy = 0;
		dx = -velocidad;
	}
	else if (dx != 0 && x <= 0) {
		x -= dx;
		dx = 0;
		dy = -velocidad;
	}
	else if (dy != 0 && y <= 0) {
		y -= dy;
		dy = 0;
		dx = velocidad;
	}
}


void Cuadrado::borrar() {
	System::Console::SetCursorPosition(x, y);
	std::cout << " ";
}

int Cuadrado::getX() {
	return x;
}

int Cuadrado::getY() {
	return y;
}

void Cuadrado::cambiarColorRandom() {
	color = rand() % 15 + 1;
}