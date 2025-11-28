#pragma once

#include "string"
#include "fstream"
#include "vector"

using namespace std;


struct Coordenada {
	int x, y;
};

class GestorCoordenadas {
public:

	Coordenada* traerCoordenada(string nombreArchivo, int pos) {
		ifstream archivo(nombreArchivo, ios::binary | ios::in);
		if (!archivo.is_open()) return nullptr;
		archivo.seekg(0, ios::end);
		int bytes = archivo.tellg();
		int cnt = bytes / sizeof(Coordenada);
		if (cnt <= pos) return nullptr;

		Coordenada* coord = new Coordenada;

		archivo.seekg(pos * sizeof(Coordenada), ios::beg);
		archivo.read((char*)(coord), sizeof(Coordenada));

		archivo.close();
		return coord;
	}

	vector<Coordenada*> traerCoordenadas(string nombreArchivo) {
		ifstream archivo(nombreArchivo, ios::binary | ios::in);
		if (!archivo.is_open()) return vector<Coordenada*>();
		archivo.seekg(0, ios::end);
		int bytes = archivo.tellg();
		int cnt = bytes / sizeof(Coordenada);

		vector<Coordenada*> coordenadas(cnt);

		for (int i = 0; i < cnt; i++) {
			archivo.seekg(i * sizeof(Coordenada), ios::beg);
			archivo.read((char*)(coordenadas[i]), sizeof(Coordenada));
		}
		archivo.close();
		return coordenadas;
	}

	void agregarCoordenada(string nombreArchivo, int x, int y) {
		ofstream archivo(nombreArchivo, ios::binary | ios::app);

		Coordenada* coord = new Coordenada;
		coord->x = x;
		coord->y = y;

		archivo.write((char*)(coord), sizeof(Coordenada));
		archivo.close();
	}

	void borrarYAgregarCoordenada(string nombreArchivo, int x, int y) {
		ofstream archivo(nombreArchivo, ios::binary | ios::out);

		Coordenada* coord = new Coordenada;
		coord->x = x;
		coord->y = y;

		archivo.write((char*)(coord), sizeof(Coordenada));
		archivo.close();
	}
};