#pragma once
#include "iostream"
#include "Entidad.h"

using namespace std;
using namespace System;

class Persona : public Entidad {

private: 

	char matriz[3][3] = {
		{32, 111, 32},
		{45, 124, 45},
		{108, 32, 108},
	};

public:
	Persona(int x, int y) : Entidad(x, y) {
		ancho = 3;
		alto = 3;
	}

	void mostrar() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << char(matriz[i][j]);
			}
		}
	}

	void cambiar_direccion(char tecla) {
		switch (tecla) {
		case 'a':
			dx = -1;
			break;
		case 'd':
			dx = 1;
			break;
		case 'w':
			dy = -1;
			break;
		case 's':
			dy = 1;
			break;
		}
	}
};