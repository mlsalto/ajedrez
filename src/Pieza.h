#pragma once
#include "ETSIDI.h"

using namespace ETSIDI;

enum TipoPieza { REY, REINA, TORRE, ALFIL, CABALLO, PEON, VACIO};
enum ColorPieza { BLANCO, NEGRO };

class Pieza
{
private:
	ColorPieza color;
	TipoPieza pieza;
	Vector2D casilla; //lo que viene siendo la posicion
	//prueba

	Sprite TorreB{ "recursos/torreB.png", 0, 24, 8, 8 };
	
	friend class ajedrez;

public:

	Pieza(void);
	//~Pieza();

	void dibujarPieza();

	void setColorPieza(ColorPieza x); //asigna el color blanco o negro
	void setTipoPieza(TipoPieza x); //asigna el tipo de pieza (Rey, Reina...)
	/*void setCasilla(Vector2D x);*/ //asigna en la casilla que se encuentra la pieza

	ColorPieza getColorPieza(); //devuelve el color blanco o negro
	TipoPieza getTipoPieza(); //devuelve el tipo de pieza (Rey, Reina...)
	Vector2D getCasilla(); //devuelve la casilla en la que está la pieza


};

