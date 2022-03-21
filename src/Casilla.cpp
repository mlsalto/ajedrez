#include "Casilla.h"
#include "Pieza.h"

Casilla::Casilla()
{

}

Casilla::Casilla(int x ,int y)
{
	setPos(x, y);
}

void Casilla::draw()
{
	//pieza->draw();
	//cout << "uwu" << endl;
}

void Casilla::colocarPieza(Pieza* p)
{
	p->setPos(-28 + (8 * columna), -28 + (8 * fila));
	/*p->setCasilla(this);*/ //esto tengo que mirar a ver que es
	pieza = p;
}

void Casilla::setColorPieza(char x)
{
	colorPieza = x;
}

void Casilla::setPos(int x, int y)
{
	columna = x;
	fila = y;
}

Pieza* Casilla::getTipoPieza()
{
	return pieza;
}

char Casilla::getColorPieza()
{
	return colorPieza;
}
