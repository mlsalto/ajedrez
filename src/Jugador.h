#pragma once
#include "freeglut.h"
#include "Pieza.h"

class Jugador
{
protected:
	char color;

	bool turnoterminado = FALSE;

	// Sprites personajes modo queens gambit //
	Sprite player1{ "recursos/jugadores/queens/beth.png", 0, 0, 28,40 };
	Sprite player2{ "recursos/jugadores/queens/benny.png", 0, 0, 28,40 };
	Sprite player3{ "recursos/jugadores/queens/Capa_2.png", 0, 0, 28,40 };

	// Sprites personajes modo kings gambit //
	Sprite TB{ "recursos/jugadores/kings/thebandit.png", 0, 0, 28,40 };
	Sprite TC{ "recursos/jugadores/kings/theconsumed.png", 0, 0, 28,40 };
	Sprite TH{ "recursos/jugadores/kings/thehunter.png", 0, 0, 28,40 };
	Sprite TJ{ "recursos/jugadores/kings/thejesterchampion.png", 0, 0, 28,40 };
	Sprite TM{ "recursos/jugadores/kings/themediciner.png", 0, 0, 28,40 };
	Sprite TO{ "recursos/jugadores/kings/theowljester.png", 0, 0, 28,40 };
	Sprite TP{ "recursos/jugadores/kings/theproxy.png", 0, 0, 28,40 };
	Sprite TR{ "recursos/jugadores/kings/theringmaster.png", 0, 0, 28,40 };
	Sprite TS{ "recursos/jugadores/kings/theshrike.png", 0, 0, 28,40 };

public:
	Jugador();
	Jugador(char colorJugador);

	virtual void draw(int x);

	int getPuntos(char colorJugador);
	virtual void moverPieza(int button, int state, int x, int y); 
    bool turnoTerminado();
};

