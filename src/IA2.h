#pragma once
#include "Jugador.h"

class IA2 :  public Jugador
{
private:
	Pieza* piezaini; // pieza que movemos
	Pieza* pieza; // pieza que movemos
	Pieza* piezacomida; // pieza que comemos
	Pieza* piezafin;
	Pieza* piezamovida;

	bool movimientoposible;
	int tipomovimiento; // comer pieza (0), enroque (1), passant (2), mover a casilla vacia (3)
public:
	IA2();
	IA2(char colorJugador);

	void moverPieza(int button, int state, int x, int y);
};

