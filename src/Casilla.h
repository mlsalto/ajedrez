#pragma once
#define MAX_PIEZAS 32
#include "ETSIDI.h"
#include "Pieza.h"
//
//class Pieza;

using namespace ETSIDI;

class Casilla
{
// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)
private:
	int fila;   //a lo mejor hay que cambiar fila/ columna, ir viendo
	int columna;
	Vector2D pos;
	char colorPieza;

public:
	Casilla(); // filas y columnas
	Pieza* pieza; //ver como implementar con la clase !!!!!!
	void draw();

	void colocarPieza(Pieza* pieza);
	void setColorPieza(char x);
	void setPos(int x, int y);

	Pieza* getTipoPieza();
	char getColorPieza();

};

