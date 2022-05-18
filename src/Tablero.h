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
#include "Jugador.h"
#include "IA1.h"
#include "IA2.h"
#include "IA3.h"
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
	bool turno; // blancas(1)   negras(0)
	bool turnoterminado;
	bool finturnob;
	bool finturnon;

	
	///////// ELEMENTOS DE DIBUJO //////////
	Sprite tableroAjedrez{ "recursos/tablero.png", 0, 0, 64, 64 };
	Sprite marcoTablero{ "recursos/Marco.png", 0, 0, 72, 72 };
	Sprite tableroAjedrez2{ "recursos/tablero2.png", 0, 0, 64, 64 };
	Sprite marcoTablero2{ "recursos/Marco2.png", 0, 0, 72, 72 };
	Sprite letrasTablero{ "recursos/numeros_y_letras.png", 0, 0, 90, 90 };
	Sprite marcoTurno{ "recursos/turno.png", 0, 0, 28, 41 };
	Sprite blancasq{ "recursos/piezas/peonB.png", 0, 0, 10, 10 };
	Sprite negrasq{ "recursos/piezas/peonA.png", 0, 0, 10, 10 };
	Sprite blancask{ "recursos/piezas/peonR.png", 0, 0, 10, 10 };
	Sprite negrask{ "recursos/piezas/peonM.png", 0, 0, 10, 10};

	///// JUGADORES ////
	Jugador* jugador1;
	Jugador* jugador2;
	int personaje1; // indica el personaje
	int personaje2;

	///// MODO JUEGO ////
	static bool tipojuego; // queens(false)  kings(true)
	static bool movimientos; // encendidos(true) apagados(false)


public:
	Tablero();

	void dibuja();
	void nuevoTablero(); //similar a un inicializa

	void ratonTablero(int button, int state, int x, int y);

	static void eliminarPiezaT(int x, int y);
	static void eliminarPieza(Pieza* pieza);
	static void eliminarTablero();
	
	// setters
	void setJugador1(Jugador* j );
	void setJugador2(Jugador* j);

	void setPersonaje1(int x);
	void setPersonaje2(int x);

	void setTipoJuego(bool x);
	void setMovimientos(bool x);

	// getters //
	static Pieza* getPiezasT(int x, int y);
	static int getTipoPiezasT(int x, int y);
	static Casilla* getCasillaT(int x, int y);
	static bool getCasillaOcupada(int x, int y);
	static bool getTipoJuego();
	static bool getMovimientos();
	bool getTurnoAcabadoN();
	bool getTurnoAcabadoB();

	// jaque y jaque mate //
	static bool detectar_jaque(char color);
	static bool detectar_jaque_mate(char color);

	// coronacion //
	bool getCoronacion(char color);
	void setCoronacion(int tipoficha);
};

