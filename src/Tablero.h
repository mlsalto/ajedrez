#pragma once
#include "Casilla.h"
#include "ETSIDI.h"
#include "Pieza.h"
#include "Torre.h"
#include "Reina.h"
#include "ListaPiezas.h"


using namespace ETSIDI;

class Tablero
{
private: 
	/////// ELEMENTOS PARA CREAR TABLERO INICIAL  ///////
	ListaPiezas piezas;
	Casilla* casillas[8][8]; 
	int i, j;

	/////// ELEMENTOS DE AYUDA PARA GESTIONAR  RATON CON EL TURNO ////////
	bool seleccionpieza = FALSE;
	char colorini;
	Pieza* piezaini;
	int posinix, posiniy;
	bool turno = TRUE; // blancas(1)   negras(0)

	///////// ELEMENTOS DE DIBUJO //////////
	Sprite tableroAjedrez{ "recursos/tablero.png", 0, 0, 64, 64 };
	Sprite casilla_seleccionada{ "recursos/casilla_iluminada.png",1000, 1000,8,8 };

public:

	Tablero();


	void dibuja();
	void nuevoTablero(); //similar a un inicializa???

	void ratonTablero(int button, int state, int x, int y);
  
	Pieza* getPiezasT(int x, int y);
	Casilla* getCasillaT(int x, int y);

};

