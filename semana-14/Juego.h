#pragma once

#include "vector"
#include "Enemigo.h"
#include "Jugador.h"
#include "GestorCoordenadas.h"
#include "Archivos.h"

using namespace std;
using namespace System;

class Juego {
private:
	vector<Enemigo*> enemigos;
	Jugador* jugador;
	GestorCoordenadas gestorCoord;
	int cntEnemigos;
	string archivoJugador;
	string archivoEnemigos;
	string archivoScores;
	Archivos gestorArchivos;

public:

	Juego(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo) {

		archivoJugador = "jugador.txt";
		archivoEnemigos = "enemigos.txt";
		archivoScores = "scores.txt";
		Coordenada* coordJug = gestorCoord.traerCoordenada(archivoJugador, 0);

		if (coordJug == nullptr) {
			jugador = new Jugador(bmpJugador, 0, 0);
		}
		else {
			jugador = new Jugador(bmpJugador, coordJug->x, coordJug->y);
		}


		int anchoPantalla = g->VisibleClipBounds.Width;
		int altoPantalla = g->VisibleClipBounds.Height;

		cntEnemigos = 5;

		for (int i = 0; i < cntEnemigos; i++) {
			Coordenada* coord = gestorCoord.traerCoordenada(archivoEnemigos, i);
			Enemigo* ene;
			if (coord == nullptr) {
				ene = new Enemigo(bmpEnemigo, g);
			}
			else {
				ene = new Enemigo(bmpEnemigo, coord->x, coord->y);
			}
			enemigos.push_back(ene);
		}
	}


	~Juego() {

	}

	void mostrarTodo(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo) {
		jugador->dibujar(g, bmpJugador);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->dibujar(g, bmpEnemigo);
		}
	}

	void moverEnemigos(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(g);
		}
	}

	void terminarJuego() {
		gestorCoord.borrarYAgregarCoordenada(archivoJugador, jugador->getX(), jugador->getY());

		// el primer enemigo borra y agrega el enemigo
		gestorCoord.borrarYAgregarCoordenada(archivoEnemigos, enemigos[0]->getX(), enemigos[0]->getY());
		// los siguientes enemigos se agregan al archivo sin borrar nada
		for (int i = 1; i < enemigos.size(); i++) {
			gestorCoord.agregarCoordenada(archivoEnemigos, enemigos[i]->getX(), enemigos[i]->getY());
		}
	}

	void moverJugador(Graphics^ g, Keys tecla) {
		jugador->mover(tecla, g);
	}

	void guardarScore(String^ nombre, String^ score) {
		String^ texto = IO::File::ReadAllText("scores.txt");
		texto += "\r\n" + nombre + " - " + score;
		IO::File::WriteAllText("scores.txt", texto);
	}

	String ^traerScores() {
		return IO::File::ReadAllText("scores.txt");
	}
};