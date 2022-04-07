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
	//atributos comunes de todas las piezas, que viene siendo: tipo, color
	Vector2D pos;
	Casilla* casilla;
	//int pieza;
	char color;

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
	
	virtual bool movimientoLegal( Casilla* y); //debe ser abstracta

	virtual void draw(); //debe ser abstracta

	void setPos(int x, int y);
	void setCasilla(Casilla* c);


	char getColorPieza(); //devuelve el color blanco o negro
	Casilla* getCasilla();
};

