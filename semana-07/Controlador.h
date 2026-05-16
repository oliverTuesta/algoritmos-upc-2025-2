#pragma once

#include "Constantes.h"
#include "Monigote.h"
#include "Coco.h"
#include "Casa.h"
#include "Survivor.h"
#include <conio.h>
#include <iostream>
#include <vector>

using namespace System;
using namespace std;

class Controlador {
private:
	Survivor* survivor;
	vector<Monigote*> monigotes;
	vector<Coco*> cocos;
	Casa* casa;
	bool ganaste;

public:
	Controlador() {
		ganaste = false;
		int cantidadMonigotes = rand() % 3 + 4;
		for (int i = 0; i < cantidadMonigotes; i++) {
			int x = rand() % (ANCHO_PANTALLA - ANCHO_MONIGOTE - 1);
			int y = ALTO_PANTALLA - 1 - (rand() % 5 + 1);
			Monigote* monigote = new Monigote(x, y);
			monigotes.push_back(monigote);
		}

		int cantidadCocos = rand() % (12 - 6 + 1) + 6;
		for (int i = 0; i < cantidadCocos; i++) {
			int y = rand() % (ALTO_PANTALLA - ALTO_COCO - 1);
			int x = rand() % (ANCHO_PANTALLA - ANCHO_COCO - 1);
			Coco* coco = new Coco(x, y);
			cocos.push_back(coco);
		}

		survivor = new Survivor(25, 3);
		casa = new Casa(30, 3);
	}

	void iniciar_juego() {

		int tiempo_transcurrido = 0;


		while(survivor->get_esta_vivo()) {
			// dibujar
			survivor->dibujar();
			survivor->dibujar_balas();
			casa->dibujar();
			for (int i = 0; i < cocos.size(); i++) {
				cocos[i]->dibujar();
			}
			for (int i = 0; i < monigotes.size(); i++) {
				monigotes[i]->dibujar();
			}

			// sleep
			_sleep(100);
			tiempo_transcurrido += 100;


			// borrar todo
			Console::Clear();

			// mover
			if (_kbhit()) {
				char tecla = _getch();
				survivor->mover(tecla);
				if (tecla == 'c') {
					survivor->disparar();
				}
			}
			for (int i = 0; i < monigotes.size(); i++) {
				monigotes[i]->mover(casa);
			}
			survivor->mover_balas();


			// detectar colisiones
			// 
			// monigotes con casa
			for (int i = 0; i < monigotes.size(); i++) {
				if (casa->hubo_colision(monigotes[i])) {
					monigotes.erase(monigotes.begin() + i);
					i--;
					survivor->reducir_vida();
				}
			}

			// survivor con cocos
			for (int i = 0; i < cocos.size(); i++) {
				if (survivor->hubo_colision(cocos[i])) {
					cocos.erase(cocos.begin() + i);
					i--;
					survivor->agregar_bala();
				}
			}

			// balas con mongotes
			for (int i = 0; i < monigotes.size(); i++) {
				if (survivor->detectar_colision_y_eliminar_bala(monigotes[i])) {
					monigotes.erase(monigotes.begin() + i);
					i--;
				}
			}
			if (monigotes.size() == 0 && survivor->get_esta_vivo()) {
				ganaste = true;
				break;
			}


			if (tiempo_transcurrido >= 180000) {
				break;
			}
		}

		mostrar_fin_juego();
	}

	void mostrar_fin_juego() {
		Console::Clear();
		if (ganaste) {
			cout << "YOU WIN";
		} else {
			cout << "YOU LOST";
		}
		_sleep(5000);
	}
};