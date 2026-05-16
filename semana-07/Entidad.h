#pragma once

class Entidad {
protected:
	int x;
	int y;
	int ancho;
	int alto;
	bool esta_vivo;

public:
	Entidad(int x, int y, int ancho, int alto) {
		this->x = x; 
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		esta_vivo = true;
	}

	// getters
	int get_x() { return x; }
	int get_y() { return y; }
	int get_ancho() { return ancho; }
	int get_alto() { return alto; }
	bool get_esta_vivo() { return esta_vivo; }

	virtual void dibujar() = 0;

	bool hubo_colision(Entidad* b) {
		return x <  b->get_x() + b->get_ancho() &&
			x + ancho > b->get_x() &&
			y < b->get_y() + b->get_alto() &&
			y + alto > b->get_y();
	}

};