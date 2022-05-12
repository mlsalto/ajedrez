#include "Pieza.h"

Pieza::Pieza() {}

Pieza::Pieza(char colorJugador)
{
	color = colorJugador;
}

Pieza::~Pieza() {}

void Pieza::draw() {}

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

void Pieza::setEnroque(bool x)
{
	enroque = true;
}

void Pieza::setPassant(bool x)
{
	passant = x;
}

void Pieza::setPrimerMovimiento(bool x)
{
	primermovimiento = x;
}

int Pieza::getTipoPieza()
{
	return tipoPieza;
}

char Pieza::getColorPieza()
{
	return color;
}

Casilla* Pieza::getCasilla()
{
	return casilla;
}

bool Pieza::getEnroque()
{
	return enroque;
}

bool Pieza::getPassant()
{
	return passant;
}

bool Pieza::getPrimerMovimiento()
{
	return primermovimiento;
}