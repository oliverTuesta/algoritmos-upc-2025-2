#pragma once

class TrenAterrizaje {

public:
	TrenAterrizaje() {

	}

	void mostrar(int x, int y) {
		y += 1;
		Console::SetCursorPosition(x, y);
		cout << "*";
		Console::SetCursorPosition(x, y+1);
		cout << "*";
	}
};