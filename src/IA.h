#pragma once
#include "Jugador.h"

class IA : public Jugador
{
public:
	IA();
	IA(char colorJugador);

	void moverPieza(int button, int state, int x, int y);
};

