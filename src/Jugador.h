#pragma once
#include "Pieza.h"
#include "Tablero.h"



class Jugador
{
protected:
	char color;
	int puntos_totales;
public:
	Jugador();
	Jugador(char colorJugador);
	//~Jugador();

	bool movimientoRealizado();
	int puntos();

	int funcionIA();
};

