#include "Coordinador.h"
#include <ctime>
#include <iostream>

Coordinador::Coordinador()
{
	estado = INICIO; 
	estadojuego = TURNO;
	menu_inicio = I;

	musica(); // para que suene al inicio la música
}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa() //esta funcion en realidad no hace falta
{
//	tablero.nuevoTablero();
}

void Coordinador::mouse(int x, int y)
{
	//cout << x << ',' << y << endl; //pruebas
	if (estado == INICIO) {
		if (x > 557 || x < 246 || y < 448 || y > 557) { setMenuInicio(0); /*no hay modo juego*/}
		else if (x < 557 && x > 246 && y < 557 && y > 510) { setMenuInicio(1); /*freeplay*/}
		else if (x < 557 && x > 246 && y < 490 && y > 448) {setMenuInicio(2); /*storymode*/}
	}

	if (estado == PAUSA) {}

	if (estadojuego == CORONAR_NEGRAS || estadojuego == CORONAR_BLANCAS) {
		if (x > 760 || x < 600 || y < 254 || y > 593) { setMenuCoronacion(0); /*no hay modo coronar*/ }
		else if (x < 760 && x > 600 && y < 289 && y > 254) { setMenuCoronacion(3); /*ALFIL*/ }
		else if (x < 760 && x > 600 && y < 391 && y > 353) { setMenuCoronacion(4); /*CABALLO*/ }
		else if (x < 760 && x > 600 && y < 494 && y > 455) { setMenuCoronacion(2); /*TORRE*/ }
		else if (x < 760 && x > 600 && y < 593 && y > 553) { setMenuCoronacion(1); /*REINA*/ }
	}
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == JUEGO) {
		switch (key) {
		case 'P':
			estado = PAUSA;
		case 'H':
			estado = AYUDA;
		}
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

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (estadojuego == CORONAR_NEGRAS || estadojuego == CORONAR_BLANCAS) {
				if (x > 760 || x < 600 || y < 254 || y > 593) {  /*no hay modo coronar*/ }
				else if (x < 760 && x > 600 && y < 289 && y > 254) { tablero.setCoronacion(3); estadojuego = TURNO;/*ALFIL*/ }
				else if (x < 760 && x > 600 && y < 391 && y > 353) { tablero.setCoronacion(4); estadojuego = TURNO; /*CABALLO*/ }
				else if (x < 760 && x > 600 && y < 494 && y > 455) { tablero.setCoronacion(2); estadojuego = TURNO;/*TORRE*/ }
				else if (x < 760 && x > 600 && y < 593 && y > 553) { tablero.setCoronacion(5); estadojuego = TURNO;/*REINA*/ }
			}
		}


		if (tablero.getCoronacion('B') == TRUE) estadojuego = CORONAR_BLANCAS;
		else if (tablero.getCoronacion('N') == TRUE) estadojuego = CORONAR_NEGRAS;
	}

	if (estado == PAUSA) {

	}
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {

		switch (menu_inicio)
		{
		case INICIO:
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

		if (estadojuego == TURNO)  { tablero.dibuja(); }

		if (estadojuego == CORONAR_BLANCAS) {

			switch (coronar)
			{
				// HAY QUE PONERLO SEGÚN EL COLOR DEL JUGADOR
			case C:
				MenuCoronar_B.setPos(0, 0);
				MenuCoronar_B.draw();

			case REINA:
				MenuCoronarReina_B.setPos(0, 0);
				MenuCoronarReina_B.draw();

			case TORRE:
				MenuCoronarTorre_B.setPos(0, 0);
				MenuCoronarTorre_B.draw();

			case ALFIL:
				MenuCoronarAlfil_B.setPos(0, 0);
				MenuCoronarAlfil_B.draw();

			case CABALLO:
				MenuCoronarCaballo_B.setPos(0, 0);
				MenuCoronarCaballo_B.draw();

			}
		}

		if (estadojuego == CORONAR_NEGRAS) {

			switch (coronar)
			{
				// HAY QUE PONERLO SEGÚN EL COLOR DEL JUGADOR
			case C:
				MenuCoronar_N.setPos(0, 0);
				MenuCoronar_N.draw();

			case REINA:
				MenuCoronarReina_N.setPos(0, 0);
				MenuCoronarReina_N.draw();

			case TORRE:
				MenuCoronarTorre_N.setPos(0, 0);
				MenuCoronarTorre_N.draw();

			case ALFIL:
				MenuCoronarAlfil_N.setPos(0, 0);
				MenuCoronarAlfil_N.draw();

			case CABALLO:
				MenuCoronarCaballo_N.setPos(0, 0);
				MenuCoronarCaballo_N.draw();
			}
		}
		tablero.dibuja();
	}

	if (estado == PAUSA) {
		// dibujar el menu de la pausa
		
		//switch (menu_pausa)
		//{
		//case P:

		//case NEW_GAME:

		//case BACK_TO_GAME:

		//case BACK_TO_MENU:

		//case EXIT:

		//}

	}

	if (estado == FIN) {
		// dibujar según si ganan las negras o blancas
		// ( hay que ver como implementarlo )
	}
}

bool Coordinador::tiempo(char color)
{
	clock_t tiempo; //inicilizar una variable del tipo clock_t -librería <ctime>
	// siempre va al inicio de cuando queremos empezar a contar el tiempo -cuando empiecen a jugar las blancas o negras en sus respectivos turnos
	tiempo = clock(); //asignar a tiempo el valor de la función clock();

	// clock() -> es el tiempo actual del ordenador

	//AQUÍ VA LA ACCIÓN QUE TIENE QUE TEMPORIZAR

	//Para 'parar' el tiempo: solo resta el tiempo actual con el tiempo que se ha cogido antes del juego
	tiempo = clock() - tiempo; 

	//tiempo NO contiene en sí, la cantidad de segundos que ha pasado, contiene CLOCKS -> conversión
	int tiempo_s = int(tiempo) / CLOCKS_PER_SEC;

	return false;
}

void Coordinador::musica()
{
	/*if (estado == INICIO) playMusica("recursos/menu.mp3");
	if (estado == JUEGO) playMusica("recursos/juego.mp3", true);*/
	
}

void Coordinador::mueve(){}

void Coordinador::setMenuInicio( int x)
{
	if (x == 0) menu_inicio = I;
	if (x == 1) menu_inicio = FREE_PLAY;
	if (x == 2) menu_inicio = STORY_MODE;
}

void Coordinador::setMenuCoronacion(int x)
{
	if (x == 0) coronar = C;
	if (x == 1) coronar = REINA;
	if (x == 2) coronar = TORRE;
	if (x == 3) coronar = ALFIL;
	if (x == 4) coronar = CABALLO;
}

int Coordinador::getEstado()
{
	return estado;
}

int Coordinador::getModoJuego()
{
	return menu_inicio;
}

int Coordinador::getEstadoJuego()
{
	return estadojuego;
}

