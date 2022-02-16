#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;

enum class TipoPieza { REY, REINA, TORRE, ALFIL, CABALLO, PEON, VACIO};
enum class ColorPieza { BLANCO, NEGRO };

class Pieza
{
private:
	ColorPieza color;
	TipoPieza pieza;

	Vector2D casilla;

public:

	void setColorPieza(ColorPieza x); //asigna el color blanco o negro
	void setTipoPieza(TipoPieza x); //asigna el tipo de pieza (Rey, Reina...)
	void setCasilla(Vector2D x); //asigna en la casilla que se encuentra la pieza

	ColorPieza getColorPieza(); //devuelve el color blanco o negro
	TipoPieza getTipoPieza(); //devuelve el tipo de pieza (Rey, Reina...)
	Vector2D getCasilla(); //devuelve la casilla en la que está la pieza
};

