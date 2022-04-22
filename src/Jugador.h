#pragma once
class Jugador
{
protected:
	char color;


public:
	Jugador();
	Jugador(char colorJugador);

	// mas cositas

	void moverPieza(int x); // el int x de momento, ya se irá cambiando
};

