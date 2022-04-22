#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = JUEGO;
}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa() //esta funcion en realidad no hace falta
{
	tablero.nuevoTablero(0);

}

void Coordinador::tecla(unsigned char key)
{
	/// NO SE SI AÑADIREMOS TECLAS AÚN?? ///

	if (estado == INICIO) {
		

	}

	if (estado == JUEGO) {


	}
}

void Coordinador::raton(int button, int state, int x, int y)
{
	if (estado == INICIO) {
		// RATON QUE FUNIONE EN INICIO

		// si se hace click en lo que sea se hace estado == Juego y
		// el modo de juego se cambia (a lo que sea)
	}

	if (estado == JUEGO) {
		switch (modojuego)
		{
		case FREE_PLAY:
			//tablero.ratonTablero();
			break;

		case STORY_MODE:
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

		tablero.dibuja();
	}

	if (estado == PAUSA) {
		// dibujar el menu de la pausa
	}

	if (estado == FIN) {
		// dibujar según si ganan las negras o blancas
		// ( hay que ver como implementarlo )
	}
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