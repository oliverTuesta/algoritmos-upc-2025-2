#pragma once

#include "string"
#include "fstream"

using namespace std;

struct Puntaje {
	int puntaje;
	char nombre[30];
};

class GestorPuntajes {
private:
	string nombreArchivo;

public:
	GestorPuntajes(string nombreArchivo) {
		this->nombreArchivo = nombreArchivo;
	}
	~GestorPuntajes() {
	}

	void agregarPuntaje(string nombre, int puntaje) {
		Puntaje p = { strcpy_s(p.nombre, nombre.c_str()), *nombre.c_str()};

		ofstream archivo(nombreArchivo, ios::binary | ios::app);
		if (!archivo.is_open()) return;

		archivo.write((char*)(&p), sizeof(Puntaje));

		archivo.close();
	}

	string puntajesHistoricos() {
		Puntaje* puntajes;
		ifstream archivo(nombreArchivo, ios::binary | ios::in);
		if (!archivo.is_open()) return "";

		archivo.seekg(0, ios::end);
		int bytes = archivo.tellg();
		int cnt = bytes / sizeof(Puntaje);

		puntajes = new Puntaje[cnt];

		string text = "";

		for (int i = 0; i < cnt; i++) {
			archivo.seekg((i) * sizeof(Puntaje), ios::beg);
			archivo.read((char*)(&puntajes[i]), sizeof(Puntaje));
			string nombre(puntajes[i].nombre);
			text += nombre + " - " + to_string(puntajes[i].puntaje) + "\r\n";
		}
		archivo.close();
		return text;
	}
};