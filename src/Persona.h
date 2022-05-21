#pragma once
#include "Jugador.h"


class Persona :public Jugador
{
private:
	// variables ayuda de seleccion de piezas por teclado //
	bool seleccionpieza = FALSE;
	Pieza* piezaini;
	Pieza* piezafin;
	Pieza* EnPassant;
	Pieza* rey;
	bool posibilidad_passant = false;
	int posinix, posiniy;
	bool eleccionrey;
	bool primermovrey;

public:
	Persona();
	Persona(char colorJugador);

	void draw(int x);
	void moverPieza(int button, int state, int x, int y);
};

