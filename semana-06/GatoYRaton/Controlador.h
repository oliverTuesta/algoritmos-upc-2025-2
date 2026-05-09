#pragma once

#include "conio.h"
#include "Gato.h"
#include "ListaRatones.h"

class Controlador {
private:
	Gato* gato;
	ListaRatones* ratones;

	void crear_raton() {		
		Raton* raton;
		do {
			int x = rand() % (ANCHO - ANCHO_RATON);
			int y = rand() % (ALTO - ALTO_RATON);
			raton = new Raton(x, y);
		} while (gato->hubo_colision(raton));

		ratones->agregar(raton);
	}

public:
	Controlador() {
	}

	void iniciar_juego() {
		gato = new Gato(0, 0);
		ratones = new ListaRatones();
		int maximo_ratones = rand() % (15 - 7 + 1) + 7;
		int ratones_creados = 0;

		bool juego_terminado = false;
		int milisegundos = 0;

		int milisegundos_ultimo_raton = 0;

		int ratones_atrapados = 0;

		while (!juego_terminado) {
			// dibujar
			gato->dibujar();
			for (int i = 0; i < ratones->get_cantidad(); i++) {
				ratones->traer(i)->dibujar();
			}

			// sleep
			_sleep(100);

			// crear ratones
			if (ratones_creados < maximo_ratones) {
				milisegundos += 100;

				if (milisegundos - milisegundos_ultimo_raton >= 2000) {
					milisegundos_ultimo_raton = milisegundos;
					crear_raton();
					ratones_creados++;
				}
			}

			// mover
			if (_kbhit()) {
				char tecla = _getch();
				gato->mover(tecla);
			}
			for (int i = 0; i < ratones->get_cantidad(); i++) {
				ratones->traer(i)->mover(gato->get_dx(), gato->get_dy());
			}

			// detectar colisiones
			for (int i = 0; i < ratones->get_cantidad(); i++) {
				if (gato->hubo_colision(ratones->traer(i))) {
					ratones->eliminar(i);
					i--;
					ratones_atrapados++;
					if (ratones_atrapados >= maximo_ratones / 2) {
						juego_terminado = true;
					}
				}
			}

			// limpiar pantalla
			Console::Clear();
		}
	}
};