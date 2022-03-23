#pragma once
#include <iostream>
#include "ETSIDI.h"
#include "Casilla.h"


using namespace ETSIDI;

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

class Pieza
{
protected:
	Casilla* casilla;
	int pieza;
protected:
	//atributos comunes de todas las piezas, que viene siendo: tipo, color
	//ATENCION: el atributo posicion, se implementar� seg�n la casilla

	char color;

	Vector2D pos;
	Vector2D poscas;

	Sprite PeonN{ "recursos/peonN.png", pos.x, pos.y, 8, 8 };
	Sprite PeonB{ "recursos/peonB.png", pos.x, pos.y, 8, 8 };

	Sprite TorreN{ "recursos/torreN.png", pos.x, pos.y, 8, 8 };
	Sprite TorreB{ "recursos/torreB.png", pos.x, pos.y, 8, 8 };

	Sprite AlfilN{ "recursos/alfilN.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilB{ "recursos/alfilB.png", pos.x, pos.y, 8, 8 };

	Sprite CaballoN{"recursos/caballoN.png", pos.x, pos.y, 8, 8};
	Sprite CaballoB{ "recursos/caballoB.png",pos.x, pos.y, 8, 8 };

	Sprite ReinaN{"recursos/reinaN.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaB{ "recursos/reinaB.png",pos.x, pos.y, 8, 8 };

	Sprite ReyN{ "recursos/reyN.png", pos.x, pos.y, 8, 8 };
	Sprite ReyB{ "recursos/reyB.png", pos.x, pos.y, 8, 8 };


public:
	

	Pieza();
	Pieza(char colorJugador);

	virtual ~Pieza();
	
	virtual bool movimientoLegal(Casilla* x, Casilla* y);

	virtual void draw(); //debe ser abstracta

    ///asigna el color blanco o negro
	/*virtual*/ void setTipoPieza(int x); //asigna el tipo de pieza (Rey, Reina...)
	void setPos(int x, int y);
	void setCasilla(Casilla* c);


	char getColorPieza(); //devuelve el color blanco o negro
	Casilla* getCasilla();
};

