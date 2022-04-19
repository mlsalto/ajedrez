#pragma once
#include "Pieza.h"
#include "Tablero.h"



class Jugador
{
private:
	char color;
	int puntos_totales;
public:
	Jugador(char colorJugador);
	~Jugador();

	bool movimientoRealizado();
	int puntos();

	int funcionIA();
};

