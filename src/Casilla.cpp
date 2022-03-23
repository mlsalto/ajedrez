#include "Casilla.h"
#include "Pieza.h"

Casilla::Casilla()
{

}

Casilla::Casilla(int x ,int y)
{
	setPos(x, y);
	setOcupada(false);

}

void Casilla::draw()
{
	//pieza->draw();
	//cout << "uwu" << endl;
}

void Casilla::colocarPieza(Pieza* p)
{
	p->setPos(-28 + (8 * columna), -28 + (8 * fila));
	//p->getColorPieza();
	//p->setCasilla(this);
	/*p->setCasilla(this);*/ //esto tengo que mirar a ver que es
	pieza = p;
	setOcupada(true);
}


void Casilla::setColorPieza(Pieza* p)
{
	colorPieza = p->getColorPieza();
}

void Casilla::setPos(int x, int y)
{
	columna = x;
	fila = y;
}

void Casilla::setOcupada(bool x)
{
	ocupada = x;
}

bool Casilla::getOcupada()
{
	return ocupada;
}

Pieza* Casilla::getTipoPieza()
{
	return pieza;
}

char Casilla::getColorPieza()
{
	return colorPieza;
}

int Casilla::getFila()
{
	return fila;
}

int Casilla::getColumna()
{
	return columna;
}