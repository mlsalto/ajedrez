#include "Casilla.h"
#include "Tablero.h"

Casilla::Casilla(int x ,int y)
{
	columna = x; 
	fila = y;
	ocupada = false;
	tipoPieza = 0;
	pieza = NULL;
}

void Casilla::colocarPieza(Pieza* p)
{
	if (p != NULL) {
		p->setPos(-28 + (8 * columna), -28 + (8 * fila));
		p->setCasilla(this);
		tipoPieza = p->getTipoPieza();
		pieza = p;
		ocupada = true;
	}

	else if (p == NULL)
	{
		tipoPieza = 0;
		pieza = NULL;
		ocupada = false;
	}
}

void Casilla::draw()
{
	// Si el modo de juego es CON AYUDA
	if (Tablero::getMovimientos() == true)
	{
		if (tipocasilla == 0)
		{
			casilla_seleccionada.setPos(1000, 1000);
			casilla_seleccionada.draw();
		}

		if (tipocasilla == 1)
		{
			casilla_seleccionada.setPos(-28 + (columna * 8), -28 + (fila * 8));
			casilla_seleccionada.draw();
		}

		if (tipocasilla == 2)
		{
			casilla_legal.setPos(-28 + (columna * 8), -28 + (fila * 8));
			casilla_legal.draw();
		}

		if (tipocasilla == 3)
		{
			casilla_atacada.setPos(-28 + (columna * 8), -28 + (fila * 8));
			casilla_atacada.draw();
		}
	}

	// si el modo de juego es SIN AYUDA
	if (Tablero::getMovimientos() == false)
	{
		if (tipocasilla == 0)
		{
			casilla_seleccionada.setPos(1000, 1000);
			casilla_seleccionada.draw();
		}

		if (tipocasilla == 1)
		{
			casilla_seleccionada.setPos(-28 + (columna * 8), -28 + (fila * 8));
			casilla_seleccionada.draw();
		}

		if (tipocasilla == 2){}
		if (tipocasilla == 3){}
	}
}

bool Casilla::getOcupada()
{
	return ocupada;
}

Pieza* Casilla::getPieza()
{
	return pieza;
}

int Casilla::getTipoPieza()
{
	return tipoPieza;
}

int Casilla::getFila()
{
	return fila;
}

int Casilla::getColumna()
{
	return columna;
}

void Casilla::setTipoCasilla(int x)
{
	tipocasilla = x;
}