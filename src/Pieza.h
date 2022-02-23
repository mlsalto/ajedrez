#pragma once
#include "ETSIDI.h"
#include "Casilla.h"

using namespace ETSIDI;

enum TipoPieza { REY, REINA, TORRE, ALFIL, CABALLO, PEON, VACIO};
enum ColorPieza { BLANCO, NEGRO };

class Pieza
{
private:
	ColorPieza _color;
	TipoPieza _pieza;
	//Casilla* _ncasilla; //lo que viene siendo la posicion
	//prueba
	
	Sprite TorreN{ "recursos/torreN.png",0,-8,8,8 };
	Sprite TorreB{ "recursos/torreB.png",0,24,8,8 };

	friend class ajedrez;

public:

	Pieza(void);
	

	virtual void dibujarPieza(); //debe ser abstracta

	//bool movimientoLegal(Casilla* x);//permite ver o saber que moviientos se pueden hacer (implementado tambien en Rey, Reina...)
	//bool mover(Casilla* x /*,añadir jugador*/); //movimiento que realiza el jugador

	virtual void setColorPieza(ColorPieza x); //asigna el color blanco o negro
	virtual void setTipoPieza(TipoPieza x); //asigna el tipo de pieza (Rey, Reina...)
	//void setCasilla(Casilla* x); //asigna en la casilla que se encuentra la pieza

	ColorPieza getColorPieza(); //devuelve el color blanco o negro
	TipoPieza getTipoPieza(); //devuelve el tipo de pieza (Rey, Reina...)
	//Casilla* getCasilla(); //devuelve la casilla en la que está la pieza

};

