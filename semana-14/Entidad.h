#pragma once
#include <iostream>

using namespace System::Drawing;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int velocidad;
	int ancho, alto;
	int columna, fila;
	int maxCol, maxFila;
	int pasos;
	float zoom;
	bool visible;

public:
	Entidad(int dx, int dy, int maxCol, int maxFila, float zoom)
	{
		this->dx = dx;
		this->dy = dy;
		this->velocidad = 10;
		this->columna = 0;
		this->fila = 0;
		this->maxCol = maxCol;
		this->maxFila = maxFila;
		this->zoom = zoom;
		this->visible = true;
		pasos = 1;
	}

	~Entidad() {}

	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho * zoom; }
	int getAlto() { return alto * zoom; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	void setZoom(int zoom) { this->zoom = zoom; }

	bool getVisible() { return visible; }
	void setVisible(bool visible) { this->visible = visible; }

	Rectangle getRectangle()
	{
		return Rectangle(x, y, ancho * zoom, alto * zoom);
	}

	void dibujar(Graphics^ graficos, Bitmap^ bmp) {
		Rectangle section = Rectangle(columna * ancho, fila * alto, ancho, alto);
		Rectangle mostrar = Rectangle(x, y, ancho * zoom, alto * zoom);
		graficos->DrawImage(bmp, mostrar, section, GraphicsUnit::Pixel);
	}

	virtual void mover() {}
};
 