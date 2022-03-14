#pragma once
#define MAX_PIEZAS 32
#include "ETSIDI.h"
#include "Pieza.h"


using namespace ETSIDI;

class Casilla
{
// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)
protected:
	Pieza pieza; //ver como implementar con la clase !!!!!!
	int fila;   //a lo mejor hay que cambiar fila/ columna, ir viendo
	int columna;
	Vector2D pos;

public:

	Casilla(); // filas y columnas

	void draw();

	void setPieza(int x);
	void setColor(int x);
	void setFila(int x);
	void setColumna(int x); 
	void setPos(int x, int y);

	int getPieza();
	int getColor();
	int getFila();
	int getColumna();
	Vector2D getPos();


	///void dibujarTablero();

};

