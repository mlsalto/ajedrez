#pragma once
#include "Jugador.h"

class IA1 : public Jugador
{
private:
	Pieza* piezaini; // pieza que movemos
	Pieza* pieza; // pieza que movemos
	Pieza* piezacomida; // pieza que comemos
	Pieza* piezafin;
	Pieza* piezamovida;

	Pieza* EnPassant;
	bool posibilidad_passant = false;

	bool movimientoposible;
	int tipomovimiento; // comer pieza (0), enroque (1), passant (2), mover a casilla vacia (3)
public:
	IA1();
	IA1(char colorJugador);

	void draw(int x);
	void moverPieza(int button, int state, int x, int y);
};

