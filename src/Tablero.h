#pragma once
#include "Casilla.h"
#include "ETSIDI.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"


using namespace ETSIDI;

class Tablero
{
private: 
	ListaPiezas piezas;

	Sprite tableroAjedrez{ "recursos/tablero.png", 0, 0, 64, 64 };
   
	int i, j;
	bool seleccionpieza = FALSE;
	char colorini;
	Pieza* piezaini;
	int posinix, posiniy;
	int turno;

public:
	Casilla* casillas[8][8]; //esto no se si está bien??????

	Tablero();


	void dibuja();
	void nuevoTablero(); //similar a un inicializa???

	void ratonTablero(int button, int state, int x, int y);
  
	Pieza* getPiezasT(int x, int y);
	Casilla* getCasillaT(int x, int y);

};

