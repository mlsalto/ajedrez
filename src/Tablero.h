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
	Casilla *casillas[8][8]; //esto no se si está bien??????
	//en principio la idea es crear una matriz 8x8 de casillas

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


	Pieza* prueba;
public:

	Tablero();
	//Tablero(int _filas, int _columnas);

	void dibuja();
	void nuevoTablero(); //similar a un inicializa???

	bool movimientoDerechaLibre(Casilla* ini, Casilla* fin);

	void ratonTablero(int button, int state, int x, int y);
   /* Casilla getCasilla(int _columna, int _fila); *///dos punteros porque es vector de vectores (matriz) de casillas
	Pieza* getPiezasT(int x, int y);
	Casilla* getCasillaT(int x, int y);

};

