#pragma once
#include <iostream>
#include "ETSIDI.h"



using namespace ETSIDI;

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

class Pieza
{
protected:
	//atributos comunes de todas las piezas, que viene siendo: tipo, color
	//ATENCION: el atributo posicion, se implementará según la casilla
	/*ColorPieza _color;
	TipoPieza _pieza;*/
	
	char color;

	int pieza;

	Vector2D pos;

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

	~Pieza();
	
	virtual bool moverPieza();

	virtual void draw(); //debe ser abstracta

	/*virtual*//* void setColorPieza(int x); *///asigna el color blanco o negro
	/*virtual*/ void setTipoPieza(int x); //asigna el tipo de pieza (Rey, Reina...)
	void setPos(int x, int y);
	

	char getColorPieza(); //devuelve el color blanco o negro
	/*int getTipoPieza(); *///devuelve el tipo de pieza (Rey, Reina...)
	/*Vector2D getPos();*/
};

