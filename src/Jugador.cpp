#include "Jugador.h"

Jugador::Jugador(){}

Jugador::Jugador(char colorJugador)
{
	color = colorJugador;
}

////////// PARA LOS PUNTOS DE CADA PERSONA /////////
/* Valores matemáticos para la evaluación de la función

 peon.
   - Por cada peon +100 puntos
   - Por cada peon en el centro del tablero +12 puntos
   - Por cada casilla que un peon avanza +2 puntos

 caballo.
   - Por cada caballo +315 puntos
   - Si está cerca o lejos del centro del tablero +-0-15 puntos

 alfil.
   - Por cada alfil +330 puntos
   - Añadir un punto por cada casilla a la que se pueda mover el alfil

 torre.
   - Por cada torre +500 puntos
   - Añadir un punto por cada casilla a la que se pueda mover la torre

 dama.
   - Por cada dama +940 puntos
   - Si está cerca o lejos del centro del tablero +-0-10 puntos

*/


void Jugador::moverPieza(int button, int state, int x, int y)
{

}

bool Jugador::turnoTerminado()
{
	return turnoterminado;
}