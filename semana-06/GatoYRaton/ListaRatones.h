#pragma once

#include "Raton.h"

class ListaRatones {
private:
	Raton** ratones;
	int cantidad;

	bool indice_valido(int indice) {
		if (indice < 0 || indice >= cantidad) {
			return false;
		}
		return true;
	}

public:

	ListaRatones() {
		cantidad = 0;
		ratones = nullptr;
	}

	void agregar(Raton* nuevo_raton) {
		Raton** temporal = new Raton * [cantidad + 1];
		for (int i = 0; i < cantidad; i++) {
			temporal[i] = ratones[i];
		}
		temporal[cantidad] = nuevo_raton;
		if (cantidad > 0) {
			delete[]ratones;
		}
		ratones = temporal;
		cantidad++;
	}

	void eliminar(int indice) {
		if (!indice_valido(indice)) {
			return;
		}
		Raton** temporal = new Raton * [cantidad - 1];
		int j = 0; // indice para arreglo ratones
		int i = 0; // indice para arreglo temporal
		for (i = 0; i < cantidad - 1; i++) {
			if (j == indice) {
				j++;
			}
			temporal[i] = ratones[j];
			j++;
		}
		if (cantidad > 0) {
			delete[]ratones;
		}
		ratones = temporal;
		cantidad--;
	}

	Raton* traer(int indice) {
		if (!indice_valido(indice)) {
			return nullptr;
		}
		return ratones[indice];
	}

	int get_cantidad() {
		return cantidad;
	}
};