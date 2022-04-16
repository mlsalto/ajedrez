#include "Casilla.h"
#include "Pieza.h"

Casilla::Casilla(int x ,int y)
{
	columna = x; 
	fila = y;
	ocupada = false;
	pieza = NULL;
}

void Casilla::colocarPieza(Pieza* p)
{
	if (p != NULL) {
		p->setPos(-28 + (8 * columna), -28 + (8 * fila));
		p->setCasilla(this);//esto tengo que mirar a ver que es
		pieza = p;
		ocupada = true;
	}

	else if (p == NULL)
	{
		pieza = NULL;
		ocupada = false;
	}
}

bool Casilla::getOcupada()
{
	return ocupada;
}

Pieza* Casilla::getTipoPieza()
{
	return pieza;
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