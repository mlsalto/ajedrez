#include "Pieza.h"

Pieza::Pieza() {
	
}

Pieza::Pieza(char colorJugador)
{
	color = colorJugador;
}

Pieza::~Pieza() {

}

void Pieza::draw() {

}

bool Pieza::movimientoLegal(Casilla* x, Casilla* y)
{
	return true;
}


void Pieza::setTipoPieza(int x)
{
	//pieza = x;
}

void Pieza::setPos(int x, int y) 
{
	pos.x = x;
	pos.y = y;
}


void Pieza::setCasilla(Casilla* c)
{
	casilla = c;
}


char Pieza::getColorPieza()
{
	return color;
}

Casilla* Pieza::getCasilla()
{
	return casilla;
}
