#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa() //esta funcion en realidad no hace falta
{
	tablero.nuevoTablero();

}

void Coordinador::tecla(unsigned char key)
{
	/// NO SE SI A�ADIREMOS TECLAS A�N?? ///

	if (estado == INICIO) {
		

	}
}

void Coordinador::raton(int button, int state, int x, int y)
{
	if (estado == INICIO) {
		// RATON QUE FUNIONE EN INICIO
	}

	if (estado == JUEGO) {
		switch (modojuego) {

		case FREE_PLAY:
			//tablero.ratonTablero();
			break;

		case STORY_MODE:
			if (estadojuego == TURNO_BLANCAS) {
				//RATON TABLERO
			}
			else if (estadojuego == TURNO_NEGRAS) {
				// NO DEBER�A FUNCIONAR EL RAT�N
			}
			break;
		}
	}


	tablero.ratonTablero(button,state,x,y);
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {
		/*MenuInicial.setPos(0, 0);
        MenuInicial.draw();*/
	}

	if (estado == JUEGO) {
		switch (modojuego) {

		case FREE_PLAY:
			// dibujar el tablero
			break;

		case STORY_MODE:
			// dibujar el tablero del story mode
			break;
		}
	}

	if (estado == PAUSA) {
		// dibujar el menu de la pausa
	}

	if (estado == FIN) {
		// dibujar seg�n si ganan las negras o blancas
		// ( hay que ver como implementarlo )
	}



	///////////////////////////////
	tablero.dibuja();
	//////////////////////////////
}

void Coordinador::mueve()
{

}

int Coordinador::getEstado()
{
	return estado;
}

int Coordinador::getModoJuego()
{
	return modojuego;
}

int Coordinador::getEstadoJuego()
{
	return estadojuego;
}