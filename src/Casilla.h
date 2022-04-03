#pragma once
#define MAX_PIEZAS 32
#include "ETSIDI.h"
//#include "Pieza.h"

class Pieza;

using namespace ETSIDI;

class Casilla
{
// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)
private:
	int fila;   
	int columna;

	bool ocupada;

	Pieza* pieza; 

public:
	Casilla(); // filas y columnas
	Casilla(int x, int y);
	//~Casilla(); //destructor

	void draw();

	void colocarPieza(Pieza* pieza); //coloca una pieza en una casilla

	bool getOcupada();  // devuelve si la casilla está ocupada o no

	Pieza* getTipoPieza();   //devuelve la pieza que está en la casilla

	int getFila();
	void setFila(int x);

	int getColumna();
	void setColumna(int x);

};

