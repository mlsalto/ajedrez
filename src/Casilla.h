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
protected:
	int fila;   
	int columna;
	bool ocupada;
	int tipoPieza;
	Pieza* pieza; 
	int tipocasilla; //base(0), seleccionada(1), legal(2), atacada (3)

	Sprite casilla_seleccionada{ "recursos/casilla_seleccionada.png",1000, 1000,8,8 };
	Sprite casilla_legal{ "recursos/Celda_sombreada.png",1000, 1000,8,8 };
	Sprite casilla_atacada{ "recursos/casilla_atacada.png",1000, 1000,8,8 };

public:

	Casilla(int x, int y);
	//~Casilla(); //destructor

	void colocarPieza(Pieza* pieza); //coloca una pieza en una casilla

	void draw();

	bool getOcupada();  // devuelve si la casilla está ocupada o no

	Pieza* getPieza();   //devuelve la pieza que está en la casilla
	int getTipoPieza();

	int getFila();
	int getColumna();

	void setFila(int x);
	void setColumna(int x);
	void setTipoCasilla(int x);
};

