#pragma once
#include "Jugador.h"

class Persona:public Jugador
{
private:

public:
	Persona();
	Persona(char colorJugador);
	bool movimientoRealizado();
};

