#pragma once

#include "Constantes.h"
#include "Entidad.h"
#include <iostream>

using namespace System;
using namespace std;

const int ANCHO_COCO = 1;
const int ALTO_COCO = 1;

class Coco : public Entidad {
public:

	Coco(int x, int y) : Entidad(x, y, ANCHO_COCO, ALTO_COCO) {

	}

	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << "O";
	}
};