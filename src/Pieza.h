#pragma once
#include <iostream>
#include "ETSIDI.h"
#include "Casilla.h"


class Pieza
{
protected:
	//atributos comunes de todas las piezas, que viene siendo: tipo, color
	Vector2D pos;
	Casilla* casilla;

	char color;  // 0 blanco, 1 negro // 
	int tipoPieza; //  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

	bool enroque = false;
	bool passant = false;

	// Sprites de los peones //
	Sprite PeonN{ "recursos/piezas/peonN.png", pos.x, pos.y, 8, 8 };
	Sprite PeonB{ "recursos/piezas/peonB.png", pos.x, pos.y, 8, 8 };
	Sprite PeonA{ "recursos/piezas/peonA.png", pos.x, pos.y, 8, 8 };
	Sprite PeonR{ "recursos/piezas/peonR.png", pos.x, pos.y, 8, 8 };

	// Sprites de las torres //
	Sprite TorreN{ "recursos/piezas/torreN.png", pos.x, pos.y, 8, 8 };
	Sprite TorreB{ "recursos/piezas/torreB.png", pos.x, pos.y, 8, 8 };
	Sprite TorreA{ "recursos/piezas/torreA.png", pos.x, pos.y, 8, 8 };
	Sprite TorreR{ "recursos/piezas/torreR.png", pos.x, pos.y, 8, 8 };

	// Sprites de los alfiles //
	Sprite AlfilN{ "recursos/piezas/alfilN.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilB{ "recursos/piezas/alfilB.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilA{ "recursos/piezas/alfilA.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilR{ "recursos/piezas/alfilR.png", pos.x, pos.y, 8, 8 };

	// Sprites de los caballos //
	Sprite CaballoN{ "recursos/piezas/caballoN.png", pos.x, pos.y, 8, 8};
	Sprite CaballoB{ "recursos/piezas/caballoB.png",pos.x, pos.y, 8, 8 };
	Sprite CaballoA{ "recursos/piezas/caballoA.png", pos.x, pos.y, 8, 8 };
	Sprite CaballoR{ "recursos/piezas/caballoR.png",pos.x, pos.y, 8, 8 };

	// Sprites de las reinas //
	Sprite ReinaN{ "recursos/piezas/reinaN.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaB{ "recursos/piezas/reinaB.png",pos.x, pos.y, 8, 8 };
	Sprite ReinaA{ "recursos/piezas/reinaA.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaR{ "recursos/piezas/reinaR.png",pos.x, pos.y, 8, 8 };

    // Sprite de los reyes //
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

	// setters //
	void setPos(int x, int y);
	void setCasilla(Casilla* c);
	void setEnroque(bool x);
	void setPassant(bool x);
	
	// getters //
	int getTipoPieza();
	char getColorPieza(); //devuelve el color blanco o negro
	Casilla* getCasilla();
	bool getEnroque();
	bool getPassant();
};

