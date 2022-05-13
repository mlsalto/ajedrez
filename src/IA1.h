#pragma once
#include "Jugador.h"

class IA1 : public Jugador
{
private:
	Pieza* piezaini; // pieza que movemos
	Pieza* pieza; // pieza que movemos
	Pieza* piezacomida; // pieza que comemos
	Pieza* piezafin;
public:
	IA1();
	IA1(char colorJugador);

	void moverPieza(int button, int state, int x, int y);
};

