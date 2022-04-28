#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO; 
	estadojuego = TURNO_BLANCAS;
	modojuego = NONE;

	musica(); // para que suene al inicio la música
}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa() //esta funcion en realidad no hace falta
{
//	tablero.nuevoTablero();
}

void Coordinador::tecla(unsigned char key)
{
	/// NO SE SI AÑADIREMOS TECLAS AÚN?? ///

	if (estado == INICIO) {
		

	}

	if (estado == JUEGO) {

		// tecla H (help)
		// tecla P (pause)
		//

	}
}

void Coordinador::raton(int button, int state, int x, int y)
{
	if (estado == INICIO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (x < 557 && x > 246 && y < 557 && y > 510) {

				Persona* Jugador1 = new Persona('B');
				Persona* Jugador2 = new Persona('N');

				tablero.setJugador1(Jugador1);
				tablero.setJugador2(Jugador2);

				estado = JUEGO;

				tablero.nuevoTablero(); // inicializamos nuevo tablero
				musica(); // para actualziar musica
			}

			if (x < 557 && x > 246 && y < 490 && y > 448) {
				// no hace nada de mometo, debería iniciar juego modo IA
			}
		}
	}


	if (estado == JUEGO) {
		tablero.ratonTablero(button, state, x, y);
	}
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {

		switch (modojuego) 
		{
		case NONE:
			MenuInicial.setPos(0, 0);
			MenuInicial.draw();

		case FREE_PLAY:
			MenuFreePlay.setPos(0, 0);
			MenuFreePlay.draw();

		case STORY_MODE:
			MenuStoryMode.setPos(0, 0);
			MenuStoryMode.draw();
		}
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

void Coordinador::musica()
{
	if (estado == INICIO) playMusica("recursos/menu.mp3");
	if (estado == JUEGO) playMusica("recursos/juego.mp3", true);
	
}

void Coordinador::mueve(){}

void Coordinador::setModoJuego( int x)
{
	if (x == 0) modojuego = NONE;
	if (x == 1) modojuego = FREE_PLAY;
	if (x == 2) modojuego = STORY_MODE;
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