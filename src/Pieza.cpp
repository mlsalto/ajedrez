#include "Pieza.h"

void Pieza::setColorPieza(ColorPieza x)
{
	color = x;
}

void Pieza::setTipoPieza(TipoPieza x)
{
	pieza = x;
}

void Pieza::setCasilla(Vector2D x)
{
	casilla = x;
}


ColorPieza Pieza::getColorPieza()
{
	return color;
}

TipoPieza Pieza::getTipoPieza()
{
	return pieza;
}

Vector2D Pieza::getCasilla()
{
	return casilla;
}