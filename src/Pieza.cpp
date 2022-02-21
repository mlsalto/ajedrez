#include "Pieza.h"

Pieza::Pieza() {
	_color == NEGRO;
	_pieza == TORRE;
}

void Pieza::dibujarPieza() {
	switch (_pieza)
	{
	case REY:
		break;
	case REINA:
		break;
	case TORRE:
		if (_color == NEGRO) { TorreN.draw(); }
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
	_color = x;
}

void Pieza::setTipoPieza(TipoPieza x)
{
	_pieza = x;
}

//void Pieza::setCasilla(Casilla* x)
//{
//	_ncasilla = x;
//}


ColorPieza Pieza::getColorPieza()
{
	return _color;
}

TipoPieza Pieza::getTipoPieza()
{
	return _pieza;
}

//Casilla* Pieza::getCasilla()
//{
//	return _ncasilla;
//}