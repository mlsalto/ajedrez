#pragma once
#include "Casilla.h"
#include "ETSIDI.h"
#include "Pieza.h"
#include "Torre.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"
#include "Caballo.h"
#include "Alfil.h"
#include "ListaPiezas.h"
 
////// pruebas //////
#include "Jugador.h"
#include "Persona.h"

using namespace ETSIDI;

class Tablero
{
private: 
	static Casilla* casillas[8][8];

	/////// ELEMENTOS PARA CREAR TABLERO INICIAL  ///////
	static ListaPiezas piezas;
	int i, j;

	/////// ELEMENTOS DE AYUDA PARA GESTIONAR  RATON CON EL TURNO ////////;
	bool turno = TRUE; // blancas(1)   negras(0)
	bool turnoterminado = FALSE;
	bool finturno = false;
	//int pasada = 0;
	
	///////// ELEMENTOS DE DIBUJO //////////
	Sprite tableroAjedrez{ "recursos/tablero.png", 0, 0, 64, 64 };
	Sprite marcoTablero{ "recursos/Marco.png", 0, 0, 72, 72 };
	Sprite letrasTablero{ "recursos/numeros_y_letras.png", 0, 0, 90, 90 };

	///// JUGADORES ////
	Jugador* jugador1;
	Jugador* jugador2;


public:
	Tablero();

	void dibuja();
	void nuevoTablero(); //similar a un inicializa???

	void ratonTablero(int button, int state, int x, int y);

	static void eliminarPiezaT(int x, int y);
	static void eliminarPieza(Pieza* pieza);

	//////// PRUEBAS /////////
	void setJugador1(Jugador* j );
	void setJugador2(Jugador* j);
	//////////////////////////
	void mueve(float t);

	// getters //
	static Pieza* getPiezasT(int x, int y);
	static int getTipoPiezasT(int x, int y);
	static Casilla* getCasillaT(int x, int y);
	static bool getCasillaOcupada(int x, int y);

	bool getTurnoAcabado();

	static bool detectar_jaque(char color);
	bool detectar_jaque_mate(char color);

	bool getCoronacion(char color);
	void setCoronacion(int tipoficha);
};

