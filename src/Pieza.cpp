#include "Pieza.h"

Pieza::Pieza() {
	color == NEGRO;
	pieza == TORRE;
}

void Pieza::dibujarPieza() {
	switch (pieza)
	{
	case REY:
		break;
	case REINA:
		break;
	case TORRE:
		if (color == NEGRO) { TorreN.draw(); }
		else { TorreB.draw(); }
		break;
	case ALFIL:
		break;
	case CABALLO:
		break;
	case PEON:
		break;
	case VACIO:
		break;
	}
}

void Pieza::setColorPieza(ColorPieza x)
{
	color == x;
}

void Pieza::setTipoPieza(TipoPieza x)
{
	pieza == x;
}

//void Pieza::setCasilla(Vector2D x)
//{
//	casilla = x;
//}


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