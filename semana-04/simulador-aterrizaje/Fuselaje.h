#pragma once


class Fuselaje {
private:
	// Avion *avion;
public:
	Fuselaje() {

	}

	void mostrar(int x, int y) {
		x += 4;
		Console::SetCursorPosition(x, y);
		cout << "_|_";
		Console::SetCursorPosition(x, y + 1);
		cout << "oOo";
	}
};