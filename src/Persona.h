#pragma once
#include "Jugador.h"


class Persona :public Jugador
{
private:
	bool seleccionpieza = FALSE;
	Pieza* piezaini;
	int posinix, posiniy;

public:
	Persona();
	Persona(char colorJugador);

	// mas cositas
	void moverPieza(int button, int state, int x, int y);
};

