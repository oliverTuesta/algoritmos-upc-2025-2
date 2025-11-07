#pragma once

using namespace System::Drawing;
using namespace System::Windows::Forms;

class Character {

private:
	int x, y;
	int ancho, alto;
	int idx, idy;
	int dx, dy;
	int pasos;
	double zoom;

public:
	Character(int x, int y, int ancho, int height, double zoom);
	~Character();
	void mover(Keys tecla, Graphics^ graficos);
	void dibujar(Graphics^ graficos, Bitmap^ bmp);
};

Character::Character(int x, int y, int ancho, int alto, double zoom) {
	this->ancho = ancho;
	this->alto = alto;
	this->zoom = zoom;
	this->x = x;
	this->y = y;
	idx = 0;
	idy = 0;
	dx = dy = 0;
	pasos = 5;
}

Character::~Character() {

}

void Character::mover(Keys tecla, Graphics^ graficos){
	int anchoPanel = graficos->VisibleClipBounds.Width;
	int altoPanel = graficos->VisibleClipBounds.Height;
	bool teclaValida = false;
	switch (tecla) {
	case Keys::W:
	case Keys::Up:
		idy = 3;
		dy = -1;
		teclaValida = true;
		break;
	case Keys::S:
	case Keys::Down:
		idy = 0;
		dy = +1;
		teclaValida = true;
		break;
	case Keys::A:
	case Keys::Left:
		idy = 1;
		dx = -1;
		teclaValida = true;
		break;
	case Keys::D:
	case Keys::Right:
		idy = 2;
		dx = +1;
		teclaValida = true;
		break;
	}
	if (teclaValida == false) return;
	idx++;
	idx = idx % 4;
	int nuevoX = x + dx * pasos;
	int nuevoY = y + dy * pasos;
	if (nuevoX >= 0 && nuevoX + ancho * zoom < anchoPanel) {
		x += dx * pasos;
	}
	if (nuevoY >= 0 && nuevoY + alto * zoom < altoPanel) {
		y += dy * pasos;
	}
	dx = 0;
	dy = 0;
}

void Character::dibujar(Graphics^ graficos, Bitmap^ bmp) {
	Rectangle section = Rectangle(idx * ancho, idy * alto, ancho, alto);
	Rectangle mostrar = Rectangle(x,y,ancho* zoom, alto * zoom);
	graficos->DrawImage(bmp, mostrar, section, GraphicsUnit::Pixel);
}