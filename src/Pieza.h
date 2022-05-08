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

	char color;

	int tipoPieza;

	bool enroque = false;
	bool passant = false;

	int cont = 0;

	Sprite PeonN{ "recursos/piezas/peonN.png", pos.x, pos.y, 8, 8 };
	Sprite PeonB{ "recursos/piezas/peonB.png", pos.x, pos.y, 8, 8 };
	Sprite PeonA{ "recursos/piezas/peonA.png", pos.x, pos.y, 8, 8 };
	Sprite PeonR{ "recursos/piezas/peonR.png", pos.x, pos.y, 8, 8 };

	Sprite TorreN{ "recursos/piezas/torreN.png", pos.x, pos.y, 8, 8 };
	Sprite TorreB{ "recursos/piezas/torreB.png", pos.x, pos.y, 8, 8 };
	Sprite TorreA{ "recursos/piezas/torreA.png", pos.x, pos.y, 8, 8 };
	Sprite TorreR{ "recursos/piezas/torreR.png", pos.x, pos.y, 8, 8 };

	Sprite AlfilN{ "recursos/piezas/alfilN.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilB{ "recursos/piezas/alfilB.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilA{ "recursos/piezas/alfilA.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilR{ "recursos/piezas/alfilR.png", pos.x, pos.y, 8, 8 };

	Sprite CaballoN{ "recursos/piezas/caballoN.png", pos.x, pos.y, 8, 8};
	Sprite CaballoB{ "recursos/piezas/caballoB.png",pos.x, pos.y, 8, 8 };
	Sprite CaballoA{ "recursos/piezas/caballoA.png", pos.x, pos.y, 8, 8 };
	Sprite CaballoR{ "recursos/piezas/caballoR.png",pos.x, pos.y, 8, 8 };

	Sprite ReinaN{ "recursos/piezas/reinaN.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaB{ "recursos/piezas/reinaB.png",pos.x, pos.y, 8, 8 };
	Sprite ReinaA{ "recursos/piezas/reinaA.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaR{ "recursos/piezas/reinaR.png",pos.x, pos.y, 8, 8 };

	Sprite ReyN{ "recursos/piezas/reyN.png", pos.x, pos.y, 8, 8 };
	Sprite ReyB{ "recursos/piezas/reyB.png", pos.x, pos.y, 8, 8 };
	Sprite ReyA{ "recursos/piezas/reyA.png", pos.x, pos.y, 8, 8 };
	Sprite ReyR{ "recursos/piezas/reyR.png", pos.x, pos.y, 8, 8 };


public:
	

	Pieza();
	Pieza(char colorJugador);

	virtual ~Pieza();
	
	virtual bool movimientoLegal( Casilla* y); //debe ser abstracta

	virtual void draw(); //debe ser abstracta

	void setPos(int x, int y);
	void setCasilla(Casilla* c);
	void setEnroque(bool x);
	void setPassant(bool x);


	int getTipoPieza();
	char getColorPieza(); //devuelve el color blanco o negro
	Casilla* getCasilla();
	bool getEnroque();
	bool getPassant();
};

