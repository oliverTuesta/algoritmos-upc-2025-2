#pragma once
#include "Eclipse.h"

class VectorEclipses
{
private:
	int cantidad;
	Eclipse** eclipses;

public:
	VectorEclipses();
	void agregarEclipse(Eclipse* eclipse);
	void eliminarEclipse(int indice);
	Eclipse* getEclipse(int indice);
	int getCantidad();
};

VectorEclipses::VectorEclipses() {
	cantidad = 0;
	eclipses = nullptr;
}

void VectorEclipses::agregarEclipse(Eclipse* eclipse) {
	Eclipse** temporal = new Eclipse * [cantidad + 1];
	for (int i = 0; i < cantidad; i++) {
		temporal[i] = eclipses[i];
	}
	temporal[cantidad] = eclipse;
	delete[] eclipses;
	eclipses = temporal;
	cantidad++;
}

void VectorEclipses::eliminarEclipse(int indice) {
	if (indice < 0 || indice >= cantidad) {
		cout << "Indice fuera de rango" << endl;
		return;
	}

	Eclipse** temporal = new Eclipse * [cantidad - 1];

	for (int i = 0, j = 0; i < cantidad; i++) {
		if(i != indice) {
			temporal[j] = eclipses[i];
			j++;
		}
	}
	delete[] eclipses;
	eclipses = temporal;
	cantidad--;
}

Eclipse* VectorEclipses::getEclipse(int indice) {
	if (indice < 0 || indice >= cantidad) {
		cout << "Indice fuera de rango" << endl;
		return nullptr;
	}
	return eclipses[indice];
}

int VectorEclipses::getCantidad() {
	return cantidad;
}