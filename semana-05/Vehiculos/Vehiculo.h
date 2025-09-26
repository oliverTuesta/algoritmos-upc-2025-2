#pragma once
#include <iostream>

#define ANCHO 80
#define ALTO 40

using namespace std;
using namespace System;

class Vehiculo {
public:
	int x, y;
	int velocidad;
	int dx, dy;
	int ancho, alto;

	Vehiculo(int x, int y, int velocidad, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->velocidad = velocidad;
		this->ancho = ancho;
		this->alto = alto;
		dx = velocidad;
		dy = 0;
	}

	void mostrar() {
		for (int i = 0; i < alto; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < ancho; j++) {
				cout << "#";
			}
		}
	}

	void borrar() {
		for (int i = 0; i < alto; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < ancho; j++) {
				cout << " ";
			}
		}
	}

	void mover() {
		if (x + dx < ANCHO && x + dx >= 0) {
			x += dx;
		}
		if (y + dy < ALTO && y + dy >= 0) {
			y += dy;
		}
	}

	bool llegoMeta() {
		if (x + dx >= ANCHO) {
			return true;
		}
		return false;
	}
};