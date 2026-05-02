#pragma once
#include "Persona.h"
#include "Avion.h"
#include "conio.h"

class Controlador {
private:
	bool game_over;
	Persona* persona;
	Avion* avion;

public: 
	Controlador() {
		game_over = false;
		avion = new Avion(0, 0);
		avion->set_x(rand() % (ANCHO - avion->get_ancho()));
		persona = new Persona(ANCHO/2, ALTO/2);
		persona->set_y(ALTO - persona->get_alto());
	}

	void iniciar_juego() {

		while (game_over == false) {
			// dibujar
			persona->mostrar();
			avion->mostrar();

			// esperar
			_sleep(100);

			// limpiar consola
			Console::Clear();

			// detecar teclas
			if (_kbhit()) {
				char tecla = _getch();
				persona->cambiar_direccion(tecla);
			}

			// mover
			persona->mover();
			avion->mover();
			avion->volver_arriba();

			// colision
			if (persona->hubo_colision(avion)) {
				game_over = true;
			}
		}
	}
};