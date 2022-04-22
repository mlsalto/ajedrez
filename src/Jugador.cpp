#include "Jugador.h"

Jugador::Jugador(){}

Jugador::Jugador(char colorJugador)
{
	color = colorJugador;
}

void Jugador::moverPieza(int button, int state, int x, int y)
{

}

bool Jugador::turnoTerminado()
{
	return turnoterminado;
}