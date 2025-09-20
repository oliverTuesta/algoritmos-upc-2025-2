#pragma once
#include "Alas.h"
#include "TrenAterrizaje.h"
#include "Fuselaje.h"

#define ANCHO 60
#define ALTO 40

class Avion {
private:
	int x, y;
	int dx, dy;
	int velocidad;
	int alto, ancho;
	int limiteIzquierdo;
	int limiteDerecho;

	Alas* alas;
	TrenAterrizaje* tren;
	Fuselaje* fuselaje;

public:
	Avion(int limiteIzquierdo, int limiteDerecho) {
		alto = 3;
		ancho = 10;
		x = rand() % (limiteDerecho - limiteIzquierdo - ancho) + limiteIzquierdo;
		y = 1;
		this->limiteIzquierdo = limiteIzquierdo;
		this->limiteDerecho = limiteDerecho;
		velocidad = 1;
		dx = velocidad;
		dy = velocidad;
		this->x = x;
		alas = new Alas();
		tren = new TrenAterrizaje();
		fuselaje = new Fuselaje();
	}

	~Avion() {
		delete(alas);
		delete(tren);
		delete(fuselaje);
	}

	void mostrar() {
		alas->mostrar(x, y);
		fuselaje->mostrar(x, y);
		tren->mostrar(x, y);
	}

	void borrar() {
		for (int i = 0; i < alto; i++) {
			Console::SetCursorPosition(x, y+i);
			for (int j = 0; j < ancho; j++) {
				cout << " ";
			}
		}
	}

	void mover() {
		if (y + alto < ALTO) {
			y += dy;
			if (x + ancho + dx >= limiteDerecho) {
				dx = -velocidad;
			}
			if (x + dx < limiteIzquierdo) {
				dx = +velocidad;
			}
			x += dx;
		}
	}

	bool aterrizo() {
		if (y + alto >= ALTO) return true;
		else return false;
	}
};