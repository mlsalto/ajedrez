#pragma once
#include "Casilla.h"
#include "ETSIDI.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"
//#include "Torre.h"

using namespace ETSIDI;

class Tablero
{
private: 

	Torre torre;

	ListaPiezas piezas;
	//Torre torre;

	Sprite tableroAjedrez{ "recursos/tablero.png", 0, 0, 64, 64 };
    //	Torre TorreN, TorreB;
	int i, j;
	bool seleccionpieza = FALSE;
	char colorini;
	Pieza* piezaini;
	Pieza* piezaT;
	int posinix, posiniy;
	int turno;

public:
	Casilla* casillas[8][8]; //esto no se si está bien??????

	Tablero();
	//Tablero(int _filas, int _columnas);

	void dibuja();
	void nuevoTablero(); //similar a un inicializa???


	void ratonTablero(int button, int state, int x, int y);
   /* Casilla getCasilla(int _columna, int _fila); *///dos punteros porque es vector de vectores (matriz) de casillas
	Pieza* getPiezasT(int x, int y);
	Casilla* getCasillaT(int x, int y);

};

