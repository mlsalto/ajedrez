#pragma once
#include <iostream>
#include "ETSIDI.h"


using namespace ETSIDI;

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

class Pieza
{
private:
	//atributos comunes de todas las piezas, que viene siendo: tipo, color
	//ATENCION: el atributo posicion, se implementará según la casilla
	/*ColorPieza _color;
	TipoPieza _pieza;*/

	int color;
	int pieza;
	Vector2D posini;

	Sprite PeonN{ "recursos/peonN.png", posini.x, posini.y, 8, 8 };
	Sprite PeonB{ "recursos/peonB.png", posini.x, posini.y, 8, 8 };

	Sprite TorreN{ "recursos/torreN.png", posini.x, posini.y, 8, 8 };
	Sprite TorreB{ "recursos/torreB.png", posini.x, posini.y, 8, 8 };

	Sprite AlfilN{ "recursos/alfilN.png", posini.x, posini.y, 8, 8 };
	Sprite AlfilB{ "recursos/alfilB.png", posini.x, posini.y, 8, 8 };

	Sprite CaballoN{"recursos/caballoN.png", posini.x, posini.y, 8, 8};
	Sprite CaballoB{ "recursos/caballoB.png",posini.x, posini.y, 8, 8 };

	Sprite ReinaN{"recursos/reinaN.png", posini.x, posini.y, 8, 8 };
	Sprite ReinaB{ "recursos/reinaB.png",posini.x, posini.y, 8, 8 };

	Sprite ReyN{ "recursos/reyN.png", posini.x, posini.y, 8, 8 };
	Sprite ReyB{ "recursos/reyB.png", posini.x, posini.y, 8, 8 };


public:
	

	Pieza();
	~Pieza();
	
	virtual bool moverPieza();

	/*static*/ void draw(); //debe ser abstracta

	/*virtual*/ void setColorPieza(int x); //asigna el color blanco o negro
	/*virtual*/ void setTipoPieza(int x); //asigna el tipo de pieza (Rey, Reina...)
	void setPos(int x, int y);


	int getColorPieza(); //devuelve el color blanco o negro
	int getTipoPieza(); //devuelve el tipo de pieza (Rey, Reina...)
	Vector2D getPos();
};

