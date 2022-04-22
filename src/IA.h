#pragma once
#include "Jugador.h"

class IA: public Jugador
{
private:

public:
	IA();
	IA(char colorJugador);
	int funcionIA();
	bool movimientoRealizado();
};

