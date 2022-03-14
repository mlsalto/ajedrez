#include "Casilla.h"

Casilla::Casilla()
{

}

void Casilla::draw()
{
	pieza.draw();
	//cout << "uwu" << endl;
}

void Casilla::setPieza(int x)
{
	pieza.setTipoPieza(x);
}

void Casilla::setColor(int x)
{
	pieza.setColorPieza(x);
}

void Casilla::setFila(int x)
{
	fila = x;
}

void Casilla::setColumna(int x)
{
	columna = x;
}

void Casilla::setPos(int x, int y)
{
	pos.x = -28 + (8 * x);
	pos.y = -28 + (8 * y);
	pieza.setPos(pos.x, pos.y);
}

int Casilla::getPieza()
{
	return pieza.getTipoPieza();
}

int Casilla::getColor()
{
	return pieza.getColorPieza();
}

int Casilla::getFila()
{
	return fila;
}

int Casilla::getColumna()
{
	return columna;
}

Vector2D Casilla::getPos()
{
	return pos;
}
