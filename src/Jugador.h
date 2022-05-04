#pragma once
#include "freeglut.h"
#include "Pieza.h"

class Jugador
{
protected:
	char color;
	//int tipoJugador; // 0 es persona 1 es IA
	 bool turnoterminado = FALSE;

	Sprite player1{ "recursos/jugadores/queens/beth.png", 0, 0, 28,40 };
	Sprite player2{ "recursos/jugadores/queens/benny.png", 0, 0, 28,40 };
	Sprite player3{ "recursos/jugadores/queens/Capa_2.png", 0, 0, 28,40 };

public:
	Jugador();
	Jugador(char colorJugador);

	virtual void draw(int x);
	// mas cositas

	int getPuntos(char colorJugador, Casilla* c);
	virtual void moverPieza(int button, int state, int x, int y); // el int x de momento, ya se ir� cambiando
    bool turnoTerminado();
};

