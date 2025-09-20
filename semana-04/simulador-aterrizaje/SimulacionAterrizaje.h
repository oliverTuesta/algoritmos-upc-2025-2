#pragma once
#include "Avion.h"

class SimulacionAterrizaje {
private:
	Avion** aviones;
	int cantidad;
	bool detener;

public:

	~SimulacionAterrizaje() {
		delete (cantidad);
		delete (detener);
	}

	SimulacionAterrizaje(int n) {
		detener = true;
		aviones = new Avion*[n];
		cantidad = n;

		/*
		* si este profesor si hacemos una condicion 
		que espacio = Ancho/cantAviones; y despues en 
		el for pues creamos el avion de acuerdo a sus 
		posiciones y lo movemos de acuerdo al espacio 
		que le toco
		*/

		//10 - ANCHO - 1 - 10
		int izquierda = 0;
		int espacio = (ANCHO) / cantidad;
		for (int i = 0; i < cantidad; i++) {
			aviones[i] = new Avion(izquierda, izquierda+espacio);
			izquierda += espacio;
		}
	}

	void comenzar() {
		detener = false;
		while (detener == false) {
			for (int i = 0; i < cantidad; i++) {
				aviones[i]->mostrar();
			}
			_sleep(100);

			bool todosAterrizaron = true;
			for (int i = 0; i < cantidad; i++) {
				aviones[i]->borrar();
				aviones[i]->mover();
				if (!aviones[i]->aterrizo()) {
					todosAterrizaron = false;
				}
			}

			if (todosAterrizaron) {
				detener = true;
			}
		}
	}

	Avion* getAvion(int indice) {
		if (indice < 0 || indice >= cantidad) {
			return nullptr;
		}
		return aviones[indice];
	}
};