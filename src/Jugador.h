#pragma once
#include "Pieza.h"
#include "Tablero.h"



class Jugador
{
public:
	Jugador();
	~Jugador();

	bool movimiento();
	int puntos();

	int funcionIA();
};

