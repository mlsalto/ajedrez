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
	bool primermovimiento = false;

	// Sprites de los peones //
	Sprite PeonN{ "bin/recursos/piezas/peonN.png", pos.x, pos.y, 8, 8 };
	Sprite PeonB{ "bin/recursos/piezas/peonB.png", pos.x, pos.y, 8, 8 };
	Sprite PeonA{ "bin/recursos/piezas/peonA.png", pos.x, pos.y, 8, 8 };
	Sprite PeonR{ "bin/recursos/piezas/peonR.png", pos.x, pos.y, 8, 8 };

	// Sprites de las torres //
	Sprite TorreN{ "bin/recursos/piezas/torreN.png", pos.x, pos.y, 8, 8 };
	Sprite TorreB{ "bin/recursos/piezas/torreB.png", pos.x, pos.y, 8, 8 };
	Sprite TorreA{ "bin/recursos/piezas/torreA.png", pos.x, pos.y, 8, 8 };
	Sprite TorreR{ "bin/recursos/piezas/torreR.png", pos.x, pos.y, 8, 8 };

	// Sprites de los alfiles //
	Sprite AlfilN{ "bin/recursos/piezas/alfilN.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilB{ "bin/recursos/piezas/alfilB.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilA{ "bin/recursos/piezas/alfilA.png", pos.x, pos.y, 8, 8 };
	Sprite AlfilR{ "bin/recursos/piezas/alfilR.png", pos.x, pos.y, 8, 8 };

	// Sprites de los caballos //
	Sprite CaballoN{ "bin/recursos/piezas/caballoN.png", pos.x, pos.y, 8, 8};
	Sprite CaballoB{ "bin/recursos/piezas/caballoB.png",pos.x, pos.y, 8, 8 };
	Sprite CaballoA{ "bin/recursos/piezas/caballoA.png", pos.x, pos.y, 8, 8 };
	Sprite CaballoR{ "bin/recursos/piezas/caballoR.png",pos.x, pos.y, 8, 8 };

	// Sprites de las reinas //
	Sprite ReinaN{ "bin/recursos/piezas/reinaN.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaB{ "bin/recursos/piezas/reinaB.png",pos.x, pos.y, 8, 8 };
	Sprite ReinaA{ "bin/recursos/piezas/reinaA.png", pos.x, pos.y, 8, 8 };
	Sprite ReinaR{ "bin/recursos/piezas/reinaR.png",pos.x, pos.y, 8, 8 };

    // Sprite de los reyes //
	Sprite ReyN{ "bin/recursos/piezas/reyN.png", pos.x, pos.y, 8, 8 };
	Sprite ReyB{ "bin/recursos/piezas/reyB.png", pos.x, pos.y, 8, 8 };
	Sprite ReyA{ "bin/recursos/piezas/reyA.png", pos.x, pos.y, 8, 8 };
	Sprite ReyR{ "bin/recursos/piezas/reyR.png", pos.x, pos.y, 8, 8 };


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
	void setPrimerMovimiento(bool x);
	
	// getters //
	int getTipoPieza();
	char getColorPieza(); //devuelve el color blanco o negro
	Casilla* getCasilla();
	bool getEnroque();
	bool getPassant();
	bool getPrimerMovimiento();
};

