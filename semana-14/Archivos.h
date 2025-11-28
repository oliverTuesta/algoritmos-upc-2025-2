#pragma once

#include "string"
#include "fstream"

using namespace std;

class Archivos {

public:

	bool Texto(string nombreArchivo, string texto) {
		ofstream archivo(nombreArchivo, ios::app);

		if (!archivo.is_open()) return false;

		archivo << texto << '\n';
		archivo.close();
		return true;
	}

	string traerTexto(string nombreArchivo) {
		ifstream archivo(nombreArchivo, ios::in);

		if (!archivo.is_open()) return "";

		string texto = "";
		string linea;
		while (getline(archivo, linea)) {
			texto += linea + '\n';
		}

		return texto;
	}

};