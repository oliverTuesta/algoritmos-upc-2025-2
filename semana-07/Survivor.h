#pragma once
#include "iostream"

#include "Constantes.h"
#include "Entidad.h"
#include "Bala.h"
#include "vector"

using namespace System;
using namespace std;


const char IZQUIERDA = 'a';
const char DERECHA = 'd';
const char ARRIBA = 'w';
const char ABAJO = 's';

class Survivor : public Entidad {
private:
	int vidas;
	char direccion;
	int balas_disponibles;
	vector<Bala*> balas;

public:
	Survivor(int x, int y) : Entidad(x, y, 2, 2) {
		vidas = 3;
		balas_disponibles = 5;
		direccion = DERECHA;
	}

	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << "O";
		Console::SetCursorPosition(x, y+1);
		cout << "/\\";

	}

	void mover(char tecla) {
		int dx = 0;
		int dy = 0;

		switch (tecla) {
		case IZQUIERDA:
			dx = -1;
			break;
		case DERECHA:
			dx = +1;
			break;
		case ARRIBA:
			dy = -1;
			break;
		case ABAJO:
			dy = +1;
			break;
		default:
			return;
		}
		direccion = tecla;

		if (x + dx >= 0 && x + ancho - 1 + dx < ANCHO_PANTALLA) {
			x += dx;
		}
		if (y + dy >= 0 && y + alto - 1 + dy < ALTO_PANTALLA) {
			y += dy;
		}
	}

	void agregar_bala() {
		balas_disponibles++;
	}

	void disparar() {
		if (balas_disponibles < 0) {
			return;
		}
		int dx = 1, dy = 0;
		switch (direccion) {
		case IZQUIERDA:
			dx = -1;
			dy = 0;
			break;
		case DERECHA:
			dx = 1;
			dy = 0;
			break;
		case ARRIBA:
			dx = 0;
			dy = -1;
			break;
		case ABAJO:
			dx = 0;
			dy = +1;
			break;
		}

		Bala* bala = new Bala(x, y, dx, dy);
		balas.push_back(bala);
		balas_disponibles--;
	}

	void dibujar_balas() {
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->dibujar();

			if (balas[i]->get_esta_vivo() == false) {
				balas.erase(balas.begin() + i);
				i--;
			}
		}
	}

	void mover_balas() {
		for (int i = 0; i < balas.size(); i++) {
			balas[i]->mover();
		}
	}

	bool detectar_colision_y_eliminar_bala(Entidad* entidad) {
		for (int i = 0; i < balas.size(); i++) {
			if (entidad->hubo_colision(balas[i])) {
				balas.erase(balas.begin() + i);
				i--;
				return true;
			}
		}

		return false;
	}

	void reducir_vida() {
		vidas--;
		if (vidas <= 0) {
			esta_vivo = false;
		}
	}
};