#pragma once
#include "Jugador.h"

class IA3 :public Jugador
{
private:
	Pieza* piezaini; // pieza que movemos
	Pieza* pieza; // pieza que movemos
	Pieza* piezacomida; // pieza que comemos
	Pieza* piezamovida;
	Pieza* piezafin;

	int tipomovimiento; // comer pieza (0), enroque (1), passant (2), mover a casilla vacia (3)

	int puntospropios, puntoscontrario;
	int minimo = -9999, maximo = -9999;

	int posinix, posiniy, posfinx, posfiny;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	
	int tipomovf;
	int puntosn, puntosb;

	static Casilla* tablero2[8][8];
	static Casilla* tablero3[8][8];

public:
	IA3();
	IA3(char colorJugador);

	void moverPieza(int button, int state, int x, int y);
	void movimientocontrario();
};

