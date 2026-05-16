#pragma once

#include "Constantes.h"
#include "Entidad.h"
#include <iostream>

using namespace System;
using namespace std;

class Casa : public Entidad {
public:

	Casa(int x, int y) : Entidad(x, y, 5, 5) {

	}

	void dibujar() override {
		Console::SetCursorPosition(x, y);
		cout << " /-\\";
		Console::SetCursorPosition(x, y + 1);
		cout << "/   \\";
		Console::SetCursorPosition(x, y + 2);
		cout << "-----";
		Console::SetCursorPosition(x, y + 2);
		cout << "|   |";
		Console::SetCursorPosition(x, y + 3);
		cout << "-----";
	}
};