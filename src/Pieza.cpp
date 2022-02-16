#include "Pieza.h"

void Pieza::setColorPieza(ColorPieza x)
{
	color = x;
}

void Pieza::setTipoPieza(TipoPieza x)
{
	pieza = x;
}

ColorPieza Pieza::getColorPieza()
{
	return color;
}

TipoPieza Pieza::getTipoPieza()
{
	return pieza;
}

