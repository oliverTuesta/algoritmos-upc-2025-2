#pragma once

#include "Avion.h"
#include "conio.h"

class Juego {
private:
	Avion* avion;
	Roca** rocas;
	int cantidad_rocas;

	void mostrar_vidas() {
		for (int i = 0; i < avion->get_vidas(); i++) {
			Console::SetCursorPosition(i, ALTO + 1);
			cout << "O";
		}
	}

	void detectar_colisiones() {
		for (int i = 0; i < cantidad_rocas; i++) {
			avion->colision_roca_balas(rocas[i]);
			avion->hay_colision(rocas[i]);
		}
	}

public:
	Juego() {
		avion = new Avion(ANCHO / 2, ALTO - 5);
		cantidad_rocas = 10;
		rocas = new Roca * [10];
		for (int i = 0; i < cantidad_rocas; i++) {
			rocas[i] = new Roca(rand() % ANCHO, rand() % 5);
		}
	}


	void iniciar_juego() {
		while (avion->esta_vivo()) {
			// mover
			if (_kbhit()) {
				char tecla = _getch();
				avion->mover(tecla);
				if (tecla == 'x') {
					avion->disparar();
				}
			}
			avion->mover_balas();
			detectar_colisiones();
			for (int i = 0; i < cantidad_rocas; i++) {
				rocas[i]->mover();
			}
			
			// mostrar
			mostrar_vidas();
			avion->mostrar();
			avion->mostrar_balas();
			for (int i = 0; i < cantidad_rocas; i++) {
				rocas[i]->mostrar();
			}

			// detectar colisiones
			detectar_colisiones();

			_sleep(100);

			// borrar
			Console::Clear();
		}

		game_over();
	}

	void game_over() {
		_sleep(1000);
		Console::SetCursorPosition(ANCHO / 2 - 5, ALTO / 2);
		cout << "GAME OVER" << endl;

		_getch();
	}
};