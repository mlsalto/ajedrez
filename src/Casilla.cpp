#include "Casilla.h"
#include "Pieza.h"

Casilla::Casilla()
{

}

Casilla::Casilla(int x ,int y)
{
	columna = x; 
	fila = y;
	ocupada = false;
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
	ocupada = true;
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