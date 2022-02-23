#pragma once
#include "Casilla.h"
#include "ETSIDI.h"

using namespace ETSIDI;

class Tablero
{
private:
	Casilla **casillas[8][8]; //esto no se si está bien??????

public:
	Tablero();
	Tablero(int _filas, int _columnas);

	virtual ~Tablero(); //destructor

	void dibujar();

    Casilla** getCasilla(int _columna, int _fila); //dos punteros porque es vector de vectores (matriz) de casillas
};

