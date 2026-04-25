#pragma once

#include <iostream>
#include "Roca.h"
#include "Bala.h"

#include "Constantes.h"

using namespace System;
using namespace std;

class Avion {
private:
	Bala** balas;
	int cantidad_balas;
	int x;
	int y;
	int ancho;
	int alto;
	int pasos;
	int vidas;


public:
	Avion(int x, int y) {
		this->x = x;
		this->y = y;
		ancho = 5;
		alto = 3;
		cantidad_balas = 0;
		pasos = 1;
		vidas = 5;
	}

	void mostrar() {
		Console::SetCursorPosition(x, y);
		cout << "  ^  ";
		Console::SetCursorPosition(x, y + 1);
		cout << " /|\\ ";
		Console::SetCursorPosition(x, y + 2);
		cout << "/_|_\\";
	}


	void mostrar_balas() {
		for (int i = 0; i < cantidad_balas; i++) {
			balas[i]->mostrar();
		}
	}


	void mover_balas() {
		for (int i = 0; i < cantidad_balas; i++) {
			balas[i]->mover();
		}

		for (int i = 0; i < cantidad_balas; i++) {
			if (balas[i]->get_existe() == false) {
				borrar_bala(i);
				i--;
			}
		}
	}

	void borrar_bala(int indice_borrar) {
		Bala** temporal = new Bala * [cantidad_balas - 1];

		int j = 0;
		for (int i = 0; i < cantidad_balas - 1; i++) {
			if (j == indice_borrar) {
				j++;
			}
			temporal[i] = balas[j];
			j++;
		}

		if (cantidad_balas > 0) {
			delete balas;
		}
		balas = temporal;
		cantidad_balas--;
	}


	void mover(char tecla) {
		int dx = 0;
		int dy = 0;
		switch (tecla) {
		case 'a':
			dx = -pasos;
			break;

		case 'd':
			dx = pasos;
			break;
		}

		if (x + ancho - 1 + dx >= ANCHO || y + alto - 1 + dy >= ALTO || x + dx < 0 || y + dy < 0) {
			return;
		}
		x += dx;
	}

	bool hay_colision(Roca* r) {
		if (r->get_x() >= x && r->get_x() <= x + ancho - 1) {
			if (r->get_y() >= y && r->get_y() <= y + alto - 1) {
				vidas--;
				r->reinciar_posicion();
				return true;
			}
		}
		return false;
	}

	void colision_roca_balas(Roca* r) {
		for (int i = 0; i < cantidad_balas; i++) {
			if (balas[i]->hay_colision(r)) {
				r->reinciar_posicion();
			}
		}
	}

	bool esta_vivo() {
		if (vidas >= 1) {
			return true;
		}
		return false;
	}

	void disparar() {
		Bala* bala_nueva = new Bala(x + 2, y);

		Bala** temporal = new Bala * [cantidad_balas + 1];
		for (int i = 0; i < cantidad_balas; i++) {
			temporal[i] = balas[i];
		}
		temporal[cantidad_balas] = bala_nueva;
		if (cantidad_balas >= 1) {
			delete balas;
		}
		balas = temporal;
		cantidad_balas++;
	}

	int get_vidas() {
		return vidas;
	}

};