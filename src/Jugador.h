#pragma once
#include "freeglut.h"
#include "Pieza.h"

class Jugador
{
protected:
	char color;
	//int tipoJugador; // 0 es persona 1 es IA

	bool turnoterminado = FALSE;

public:
	Jugador();
	Jugador(char colorJugador);

	void draw();
	// mas cositas

	int getPuntos(char colorJugador, Casilla* c);
	virtual void moverPieza(int button, int state, int x, int y); // el int x de momento, ya se irá cambiando
	bool turnoTerminado();
};

