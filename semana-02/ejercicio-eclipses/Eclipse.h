#pragma once
#include "string"
#include "iostream"

using namespace std;

/*
b) Tipo de Eclipse
c) Fecha
d) Hora
e) Sismos
f) Lluvias
g) Visibilidad
*/

class Eclipse
{
private: 
	string tipo;
	string fecha;
	int hora;
	char sismos; // s de si y n de no
	char lluvias; // s de si y n de no
	string visibilidad;

public:
	Eclipse(string tipo, string fecha, int hora, char sismos, char lluvias, string visibilidad);

	// getters
	string getTipo();
	string getFecha();
	int getHora();
	char getSismos();
	char getLluvias();
	string getVisibilidad();
	
	// setters
	void setTipo(string tipo);
	void setFecha(string fecha);
	void setHora(int hora);
	void setSismos(char sismos);
	void setLluvias(char lluvias);
	void setVisibilidad(string visibilidad);

	void mostrarEclipse();
};

Eclipse::Eclipse(string tipo, string fecha, int hora, char sismos, char lluvias, string visibilidad) {
	this->tipo = tipo;
	this->fecha = fecha;
	this->hora = hora;
	this->sismos = sismos;
	this->lluvias = lluvias;
	this->visibilidad = visibilidad;
}

string Eclipse::getTipo() {
	return tipo;
}
string Eclipse::getFecha() {
	return fecha;
}
int Eclipse::getHora() {
	return hora;
}
char Eclipse::getSismos() {
	return sismos;
}
char Eclipse::getLluvias() {
	return lluvias;
}
string Eclipse::getVisibilidad() {
	return visibilidad;
}

void Eclipse::setTipo(string tipo) {
	this->tipo = tipo;
}
void Eclipse::setFecha(string fecha) {
	this->fecha = fecha;
}
void Eclipse::setHora(int hora) {
	this->hora = hora;
}
void Eclipse::setSismos(char sismos) {
	this->sismos = sismos;
}
void Eclipse::setLluvias(char lluvias) {
	this->lluvias = lluvias;
}
void Eclipse::setVisibilidad(string visibilidad) {
	this->visibilidad = visibilidad;
}

void Eclipse::mostrarEclipse() {
	cout << "Tipo de eclipse: " << tipo << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Hora: " << hora << endl;
	cout << "Sismos: " << sismos << endl;
	cout << "Lluvias: " << lluvias << endl;
	cout << "Visibilidad: " << visibilidad << endl;
}
