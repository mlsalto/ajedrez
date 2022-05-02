#include "Coordinador.h"
#include <ctime>
#include <iostream>

Coordinador::Coordinador()
{
	estado = INICIO; 
	estadojuego == JAQUE;
	menu_inicio = I;

	// opciones
	opciones = 2;
	tipojuego = 0;
	tablero.setTipoJuego(true);
	//////////////

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
		if (x > 557 || x < 246 || y < 448 || y > 610) { setMenuInicio(0); /*no hay modo juego*/}
		else if (x < 557 && x > 246 && y < 557 && y > 510) { setMenuInicio(1); /*freeplay*/}
		else if (x < 557 && x > 246 && y < 490 && y > 448) { setMenuInicio(2); /*storymode*/}
		else if (x < 557 && x > 246 && y < 610 && y > 570) { setMenuInicio(3); /*opciones*/ }
	}

	if (estado == OPCIONES) {
		if (x > 378 || x < 287 || y < 601 || y > 642) {  /*no hay modo opciones*/ 
			if (opciones == 4)setOpciones(0);
			if (opciones == 5)setOpciones(1);
			if (opciones == 6)setOpciones(2);
			if (opciones == 7)setOpciones(3);
		}
		else if (x < 378 && x > 287 && y < 642 && y > 601) { /*exit*/
			if (opciones == 0)setOpciones(4);
			if (opciones == 1)setOpciones(5);
			if (opciones == 2)setOpciones(6);
			if (opciones == 3)setOpciones(7);
		}
	}

	if (estadojuego == PAUSA) {
		if (x > 737 || x < 498 || y < 329 || y > 539) { setMenuAyuda(0); /*no hay modo ayuda*/ }
		else if (x < 643 && x > 498 && y < 370 && y > 329) { setMenuAyuda(1); /*resume*/ }
		else if (x < 643 && x > 498 && y < 452 && y > 380) { setMenuAyuda(2); /*restart*/ }
		else if (x < 737 && x > 498 && y < 481 && y > 462) { setMenuAyuda(3); /*back to*/ }
		else if (x < 524 && x > 498 && y < 539 && y > 507) { setMenuAyuda(4); /*exit*/ }
	}

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
		if (key == 'p' || key == 'P') { estadojuego = PAUSA; }
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

			else if (x < 557 && x > 246 && y < 490 && y > 448) {
				// no hace nada de mometo, debería iniciar juego modo IA
			}

			else if (x < 557 && x > 246 && y < 610 && y > 570){
				estado = OPCIONES;
			}
		}
	}

	if (estado == OPCIONES) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (x > 730 || x < 287 || y < 191 || y > 642) {  /*no hay modo opciones*/ }
			else if (x < 730 && x > 377 && y < 231 && y > 191) { /*queens*/ 
				if (opciones == 1)setOpciones(0); 
				if (opciones == 3)setOpciones(2);
				if (opciones == 5)setOpciones(4); 
				if (opciones == 7)setOpciones(6);
			}
			else if (x < 730 && x > 377 && y < 307 && y > 264) { /*kings*/ 
				if (opciones == 0)setOpciones(1);
				if (opciones == 2)setOpciones(3);
				if (opciones == 4)setOpciones(5);
				if (opciones == 6)setOpciones(7);
			}
			else if (x < 440 && x > 377 && y < 480 && y > 452) { /*on*/
				if (opciones == 0)setOpciones(2);
				if (opciones == 1)setOpciones(3);
				if (opciones == 4)setOpciones(6);
				if (opciones == 5)setOpciones(7);
			}
			else if (x < 440 && x > 377 && y < 531 && y > 496) { /*off*/
				if (opciones == 2)setOpciones(0);
				if (opciones == 3)setOpciones(1);
				if (opciones == 6)setOpciones(4);
				if (opciones == 7)setOpciones(5);
			}
			else if (x < 378 && x > 287 && y < 642 && y > 601) { /*exit*/
				estado = INICIO;
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

			if (estadojuego == PAUSA) {
				if (x > 737 || x < 498 || y < 329 || y > 539) {  /*no hay modo ayuda*/ }
				else if (x < 643 && x > 498 && y < 370 && y > 329) { estadojuego = TURNO; /*resume*/ }
				else if (x < 643 && x > 498 && y < 452 && y > 380) { tablero.eliminarTablero(); tablero.nuevoTablero(); estadojuego = TURNO;/*restart*/ } 
				else if (x < 737 && x > 498 && y < 481 && y > 462) { tablero.eliminarTablero(); estado = INICIO; estadojuego = TURNO;/*back to*/ } 
				else if (x < 524 && x > 498 && y < 539 && y > 507) { exit(0);/*exit*/ }
			}

			if (estadojuego == TURNO) {
				if (tablero.getTurnoAcabado() == true)
				{
					if (Tablero::detectar_jaque('N') == true || Tablero::detectar_jaque('B') == true)
					{
						estadojuego = JAQUE;
					}
				}

				if (tablero.getCoronacion('B') == TRUE) estadojuego = CORONAR_BLANCAS;
				else if (tablero.getCoronacion('N') == TRUE) estadojuego = CORONAR_NEGRAS;
			}
		}
	}

	if (estado == PAUSA) {

	}
}

void Coordinador::dibuja()
{
	if (estado == INICIO) {

		if (tipojuego == 0) {
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

			case OPTIONS:
				MenuOpciones.setPos(0, 0);
				MenuOpciones.draw();
			}
		}

		if (tipojuego == 1) {
			switch (menu_inicio)
			{
			case INICIO:
				MenuInicial2.setPos(0, 0);
				MenuInicial2.draw();

			case FREE_PLAY:
				MenuFreePlay2.setPos(0, 0);
				MenuFreePlay2.draw();

			case STORY_MODE:
				MenuStoryMode2.setPos(0, 0);
				MenuStoryMode2.draw();

			case OPTIONS:
				MenuOpciones2.setPos(0, 0);
				MenuOpciones2.draw();
			}
		}

		// para la carga de sprite sequences //
		Jaque.draw();
		Jaque1.draw();
	}

	if (estado == OPCIONES) {

		switch (opciones) {
		case 0:
			QueenGam.setPos(0, 0);
			QueenGam.draw();

		case 1:
			KingGam.setPos(0, 0);
			KingGam.draw();

		case 2:
			QueenGamH.setPos(0, 0);
			QueenGamH.draw();

		case 3:
			KingGamH.setPos(0, 0);
			KingGamH.draw();

		case 4:
			QueenGamE.setPos(0, 0);
			QueenGamE.draw();

		case 5:
			KingGamE.setPos(0, 0);
			KingGamE.draw();

		case 6:
			QueenGamHE.setPos(0, 0);
			QueenGamHE.draw();

		case 7:
			KingGamHE.setPos(0, 0);
			KingGamHE.draw();
		}
	}

	if (estado == JUEGO) {

		if (estadojuego == TURNO)  { 
			tablero.dibuja();
		}

		if (estadojuego == PAUSA) {
			switch (help) 
			{
			case 0:
				PausaM.setPos(0, 0);
				PausaM.draw();
			case 1:
				PausaResume.setPos(0, 0);
				PausaResume.draw();
			case 2:
				PausaRestart.setPos(0, 0);
				PausaRestart.draw();
			case 3:
				PausaBack.setPos(0, 0);
				PausaBack.draw();
			case 4:
				PausaExit.setPos(0, 0);
				PausaExit.draw();
			}
			tablero.dibuja();
		}

		if (estadojuego == JAQUE) {
			if (tipojuego == 0) {
				Jaque.draw();
			}
			if (tipojuego == 1) {
				Jaque1.draw();
			}
			tablero.dibuja();
		}
		
		if (estadojuego == CORONAR_BLANCAS) {
			if (tipojuego == 0) {
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

			if (tipojuego == 1) {
				switch (coronar)
				{
					// HAY QUE PONERLO SEGÚN EL COLOR DEL JUGADOR
				case C:
					MenuCoronar_B2.setPos(0, 0);
					MenuCoronar_B2.draw();

				case REINA:
					MenuCoronarReina_B2.setPos(0, 0);
					MenuCoronarReina_B2.draw();

				case TORRE:
					MenuCoronarTorre_B2.setPos(0, 0);
					MenuCoronarTorre_B2.draw();

				case ALFIL:
					MenuCoronarAlfil_B2.setPos(0, 0);
					MenuCoronarAlfil_B2.draw();

				case CABALLO:
					MenuCoronarCaballo_B2.setPos(0, 0);
					MenuCoronarCaballo_B2.draw();

				}
			}
			
			tablero.dibuja();
		}

		if (estadojuego == CORONAR_NEGRAS) {
			if (tipojuego == 0) {
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

			if (tipojuego == 1) {
				switch (coronar)
				{
					// HAY QUE PONERLO SEGÚN EL COLOR DEL JUGADOR
				case C:
					MenuCoronar_N2.setPos(0, 0);
					MenuCoronar_N2.draw();

				case REINA:
					MenuCoronarReina_N2.setPos(0, 0);
					MenuCoronarReina_N2.draw();

				case TORRE:
					MenuCoronarTorre_N2.setPos(0, 0);
					MenuCoronarTorre_N2.draw();

				case ALFIL:
					MenuCoronarAlfil_N2.setPos(0, 0);
					MenuCoronarAlfil_N2.draw();

				case CABALLO:
					MenuCoronarCaballo_N2.setPos(0, 0);
					MenuCoronarCaballo_N2.draw();
				}
			}
			
		}
		tablero.dibuja();
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

void Coordinador::mueve(float t)
{

	if (estadojuego == JAQUE)
	{
		if (tipojuego == 0) {
			if (i < 34) {
				Jaque.setState(i);
				i++;
			}
			else if (i >= 34) {
				i = 0;
				estadojuego = TURNO;
			}
		}

		if (tipojuego == 1) {
			if (i < 34) {
				Jaque1.setState(i);
				i++;
			}
			else if (i >= 34) {
				i = 0;
				estadojuego = TURNO;
			}
		}
	}
}

void Coordinador::setMenuInicio( int x)
{
	if (x == 0) menu_inicio = I;
	if (x == 1) menu_inicio = FREE_PLAY;
	if (x == 2) menu_inicio = STORY_MODE;
	if (x == 3) menu_inicio = OPTIONS;
}

void Coordinador::setMenuCoronacion(int x)
{
	if (x == 0) coronar = C;
	if (x == 1) coronar = REINA;
	if (x == 2) coronar = TORRE;
	if (x == 3) coronar = ALFIL;
	if (x == 4) coronar = CABALLO;
}

void Coordinador::setOpciones(int x)
{
	opciones = x;

	if (x == 0) { tipojuego = 0; tablero.setTipoJuego(true); }
	if (x == 1) { tipojuego = 1; tablero.setTipoJuego(false); }
	if (x == 2) { tipojuego = 0; tablero.setTipoJuego(true); }
	if (x == 3) { tipojuego = 1; tablero.setTipoJuego(false); }
	if (x == 4) { tipojuego = 0; tablero.setTipoJuego(true); }
	if (x == 5) { tipojuego = 1; tablero.setTipoJuego(false); }
	if (x == 6) { tipojuego = 0; tablero.setTipoJuego(true); }
	if (x == 7) { tipojuego = 1; tablero.setTipoJuego(false); }
}

void Coordinador::setMenuAyuda(int x)
{
	help = x;
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

