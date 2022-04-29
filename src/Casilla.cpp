#include "Casilla.h"
#include "Pieza.h"

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
		p->setCasilla(this);//esto tengo que mirar a ver que es
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
	if (tipocasilla == 0)
	{
		casilla_seleccionada.setPos(1000, 1000);
		casilla_seleccionada.draw();
	}

	if (tipocasilla == 1)
	{
		casilla_seleccionada.setPos(-28 + (columna* 8), -28 + (fila * 8));
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

void Casilla::setFila(int x)
{
	fila = x;
}

int Casilla::getColumna()
{
	return columna;
}

void Casilla::setColumna(int x)
{
	columna = x;
}

void Casilla::setTipoCasilla(int x)
{
	tipocasilla = x;
}