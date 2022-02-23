#include "Casilla.h"

Casilla::Casilla(int x, int y)
{

}

bool Casilla :: casillaOcupada()
{
	return true;
}

int Casilla::getFila()
{
	return _fila;
}

int Casilla::getColumna()
{
	return _columna;
}

//Pieza* Casilla::getPieza()
//{
//	return lista[MAX_PIEZAS];
//}
//
//void Casilla::setPieza(Pieza* x)
//{
//	lista[MAX_PIEZAS] = x;
//}