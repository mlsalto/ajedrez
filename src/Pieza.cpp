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

bool Pieza::movimientoLegal( Casilla* y)
{
	return true;
}

void Pieza::setPos(int x, int y) //sirve a la hora de dibujar la posicion
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
