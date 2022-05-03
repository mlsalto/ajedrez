#pragma once
#include "Jugador.h"


class Persona :public Jugador
{
private:
	bool seleccionpieza = FALSE;
	Pieza* piezaini;
	Pieza* piezafin;
	int posinix, posiniy;

public:
	Persona();
	Persona(char colorJugador);

	void draw(int x);
	// mas cositas
	void moverPieza(int button, int state, int x, int y);


	void funciondejaqueturno();
};

