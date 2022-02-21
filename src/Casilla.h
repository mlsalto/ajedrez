#pragma once
#define MAX_PIEZAS 32
#include "ETSIDI.h"
#include "Pieza.h"

using namespace ETSIDI;

class Casilla
{
private:
	int _fila;
	int _columna;
	//Pieza* lista[MAX_PIEZAS];
public:
	Casilla(int x, int y);
	
	bool casillaOcupada();

	int getFila();
	int getColumna();
	//Pieza* getPieza();
	//void setPieza(Pieza* x);
};

