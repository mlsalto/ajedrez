#include "Coordinador.h"
#include <ctime>
#include <iostream>

Coordinador::Coordinador()
{
	// INICIALIZADORES BIEN //

	estado = INICIO;
	menu_inicio = I;
	coronar = C;
	menu_help = H;

	tipojuego = 0;
	opciones = 2;
	ayuda = TRUE;
	tablero.setTipoJuego(true);
	tablero.setMovimientos(true);

	// resto de variables //
	movs = 0;
	specialmovs = 0;
	muchotexto = 0;
	pause = 0;
	help = 0;

	// musica //
	musica(); // para que suene al inicio la música
}

Coordinador::~Coordinador() {}


void Coordinador::mouse(int x, int y)
{
	//cout << x << ',' << y << endl; //pruebas
	if (estado == INICIO) {
		if (x > reshx * 557 || x < reshx * 246 || y < reshy * 448 || y > reshy * 610) { setMenuInicio(0); /*no hay modo juego*/ }
		else if (x < reshx * 557 && x > reshx * 246 && y < reshy * 557 && y > reshy * 510) { setMenuInicio(1);/*freeplay*/ }
		else if (x < reshx * 557 && x > reshx * 246 && y < reshy * 490 && y > reshy * 448) { setMenuInicio(2); /*storymode*/ }
		else if (x < reshx * 557 && x > reshx * 246 && y < reshy * 610 && y > reshy * 570) { setMenuInicio(3); /*opciones*/ }
	}

	if (estado == OPCIONES) {
		if (x > reshx * 378 || x < reshx * 287 || y < reshy * 601 || y > reshy * 642) {  /*no hay modo opciones*/
			if (opciones == 4)setOpciones(0);
			if (opciones == 5)setOpciones(1);
			if (opciones == 6)setOpciones(2);
			if (opciones == 7)setOpciones(3);
		}
		else if (x < reshx * 378 && x >  reshx * 287 && y < reshy * 642 && y > reshy * 601) { /*exit*/
			if (opciones == 0)setOpciones(4);
			if (opciones == 1)setOpciones(5);
			if (opciones == 2)setOpciones(6);
			if (opciones == 3)setOpciones(7);
		}
	}

	if (estado == JUEGO) {

		if (estadojuego == PAUSA) {
			if (x > reshx * 737 || x < reshx * 498 || y < reshy * 329 || y > reshy * 539) { pause = 0; /*no hay modo pausa*/ }
			else if (x < reshx * 643 && x > reshx * 498 && y < reshy * 370 && y > reshy * 329) { pause = 1;  /*resume*/ }
			else if (x < reshx * 643 && x > reshx * 498 && y < reshy * 452 && y > reshy * 380) { pause = 2; /*restart*/ }
			else if (x < reshx * 737 && x > reshx * 498 && y < reshy * 481 && y > reshy * 462) { pause = 3; /*back to*/ }
			else if (x < reshx * 524 && x > reshx * 498 && y < reshy * 539 && y > reshy * 507) { pause = 4; /*exit*/ }
		}

		if (estadojuego == AYUDA) {
			if (menu_help == H) {
				if (x > reshx * 742 || x < reshx * 509 || y < reshy * 345 || y > reshy * 540) { help = 0; /*no hay modo ayuda*/ }
				else if (x < reshx * 742 && x >  reshx * 509 && y < reshy * 374 && y > reshy * 345) { help = 1; /*movimientos*/ }
				else if (x < reshx * 716 && x >  reshx * 509 && y < reshy * 463 && y > reshy * 423) { help = 2; /*movimientos especiales*/ }
				else if (x < reshx * 665 && x >  reshx * 509 && y < reshy * 540 && y > reshy * 514) { help = 3; /*fin juego*/ }
			}

			if (menu_help == MOVS) {
				if (x > reshx * 628 || x < reshx * 537 || y < reshy * 300 || y > reshy * 568) { movs = 0; /*no hay modo movs*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 332 && y > reshy * 300) { movs = 1; /*pawn*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 382 && y > reshy * 332) { movs = 2; /*bishop*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 424 && y > reshy * 382) { movs = 3; /*knight*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 474 && y > reshy * 424) { movs = 4; /*rook*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 522 && y > reshy * 474) { movs = 5; /*queen*/ }
				else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 568 && y > reshy * 522) { movs = 6; /*king*/ }
			}

			if (menu_help == MOVSE) {
				if (x > reshx * 688 || x < reshx * 505 || y < reshy * 347 || y > reshy * 506) { specialmovs = 0; /*no hay modo ayuda*/ }
				else if (x < reshx * 643 && x > reshx * 505 && y < reshy * 383 && y > reshy * 347) { specialmovs = 1; /*movimientos*/ }
				else if (x < reshx * 688 && x > reshx * 505 && y < reshy * 441 && y > reshy * 414) { specialmovs = 2; /*movimientos especiales*/ }
				else if (x < reshx * 670 && x > reshx * 505 && y < reshy * 506 && y > reshy * 471) { specialmovs = 3; /*fin juego*/ }
			}
		}

		if (estadojuego == CORONAR_NEGRAS || estadojuego == CORONAR_BLANCAS) {
			if (x > reshx * 760 || x < reshx * 600 || y < reshy * 254 || y > reshy * 593) { setMenuCoronacion(0); /*no hay modo coronar*/ }
			else if (x < reshx * 760 && x >  reshx * 600 && y < reshy * 289 && y > reshy * 254) { setMenuCoronacion(3); /*ALFIL*/ }
			else if (x < reshx * 760 && x >  reshx * 600 && y < reshy * 391 && y > reshy * 353) { setMenuCoronacion(4); /*CABALLO*/ }
			else if (x < reshx * 760 && x >  reshx * 600 && y < reshy * 494 && y > reshy * 455) { setMenuCoronacion(2); /*TORRE*/ }
			else if (x < reshx * 760 && x >  reshx * 600 && y < reshy * 593 && y > reshy * 553) { setMenuCoronacion(1); /*REINA*/ }
		}
	}

	if (estado == FIN) {
		if (x > reshx * 708 || x < reshx * 470 || y < reshy * 423 || y > reshy * 521) { final = 0; /*no hay final*/ }
		else if (x < reshx * 624 && x > reshx * 470 && y < reshy * 462 && y > reshy * 423) { final = 1; /*rematch*/ }
		else if (x < reshx * 708 && x > reshx * 470 && y < reshy * 521 && y > reshy * 496) { final = 2; /*back to*/ }
	}
}

void Coordinador::tecla(unsigned char key)
{
	if (estado == JUEGO) {
		if (estadojuego == TURNO) {
			if (key == 'p' || key == 'P') {  estadojuego = PAUSA; stopMusica(); playMusica("recursos/sonidos/Characterselection.mp3"); }
			if (key == 'h' || key == 'H') {estadojuego = AYUDA;  menu_help == H; stopMusica(); playMusica("recursos/sonidos/Characterselection.mp3");}
		}
	}
}

void Coordinador::raton(int button, int state, int x, int y)
{
	if (estado == INICIO) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (x < reshx * 557 && x > reshx * 246 && y < reshy * 557 && y > reshy * 510) {

				stopMusica();

				playMusica("recursos/sonidos/Gamemodeselect.mp3");

				Persona* Jugador1 = new Persona('B');
				Persona* Jugador2 = new Persona('N');

				tablero.setJugador1(Jugador1);
				tablero.setJugador2(Jugador2);

				tablero.setPersonaje1(0);
				tablero.setPersonaje2(0);

				estado = S_PER_BLANCO;
				modojuego = TRUE;
				personajeB = 0;

				timeBlack = 5400;
				timeWhite = 5400;

				tablero.nuevoTablero(); // inicializamos nuevo tablero
				return;
			}

			else if (x < reshx * 557 && x > reshx * 246 && y < reshy * 490 && y > reshy * 448) {

		
				Persona* Jugador1 = new Persona('B');
				IA1* Jugador2 = new IA1('N'); //ESTO HAY QUE CAMBIARLA A LA 1 QUE NO SE OLVIDE

				tablero.setJugador1(Jugador1);
				tablero.setJugador2(Jugador2);

				tablero.setPersonaje1(4); // personaje de la persona
				tablero.setPersonaje2(2); // personaje de la IA

				nivel = 1;
				modojuego = FALSE;

				timeBlack = 5400;
				timeWhite = 5400;

				estado = PANTALLA;
				musica();
				tablero.nuevoTablero(); // inicializamos nuevo tablero
			}

			else if (x < reshx * 557 && x > reshx * 246 && y < reshy * 610 && y > reshy * 570) {
				estado = OPCIONES;
				return;
			}
		}
	}

	if (estado == S_PER_BLANCO)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (tipojuego == 0) {
				if (x < reshx * 1158 && x > reshx * 1086 && y < reshy * 135 && y > reshy * 102 && personajeB != 0) { estado = S_PER_NEGRO; personajeN = 0; playMusica("recursos/sonidos/Pokeselect.mp3"); return; }
				else if (x > reshx * 682 || x < reshx * 275 || y < reshy * 292 || y > reshy * 471) { personajeB = 0; tablero.setPersonaje1(0); return;/*no hay personaje seleecionado*/ }
				else if (x < reshx * 556 && x > reshx * 275 && y < reshy * 324 && y > reshy * 292) { personajeB = 1; tablero.setPersonaje1(1); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 513 && x > reshx * 275 && y < reshy * 370 && y > reshy * 344) { personajeB = 2; tablero.setPersonaje1(2); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 556 && x > reshx * 275 && y < reshy * 423 && y > reshy * 392) { personajeB = 3; tablero.setPersonaje1(3); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 682 && x > reshx * 275 && y < reshy * 471 && y > reshy * 441) { personajeB = 4; tablero.setPersonaje1(4); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
			}

			if (tipojuego == 1) {
				if (x < reshx * 1158 && x > reshx * 1086 && y < reshy * 135 && y > reshy * 102 && personajeB != 0) { estado = S_PER_NEGRO; personajeN = 0; playMusica("recursos/sonidos/Pokeselect.mp3");  return; }
				else if (x > reshx * 713 || x < reshx * 264 || y < reshy * 229 || y > reshy * 654) { personajeB = 0; tablero.setPersonaje1(0); return; /*no hay personaje seleecionado*/ }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 258 && y > reshy * 229) { personajeB = 1; tablero.setPersonaje1(1); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 568 && x > reshx * 264 && y < reshy * 307 && y > reshy * 278) { personajeB = 2; tablero.setPersonaje1(2); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 360 && y > reshy * 332) { personajeB = 3; tablero.setPersonaje1(3); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 713 && x > reshx * 264 && y < reshy * 408 && y > reshy * 377) { personajeB = 4; tablero.setPersonaje1(4); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 568 && x > reshx * 264 && y < reshy * 455 && y > reshy * 424) { personajeB = 5; tablero.setPersonaje1(5); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 586 && x > reshx * 264 && y < reshy * 504 && y > reshy * 478) { personajeB = 6; tablero.setPersonaje1(6); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 555 && y > reshy * 526) { personajeB = 7; tablero.setPersonaje1(7); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 619 && x > reshx * 264 && y < reshy * 605 && y > reshy * 575) { personajeB = 8; tablero.setPersonaje1(8); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 654 && y > reshy * 628) { personajeB = 9; tablero.setPersonaje1(9); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
			}
		}
	}

	if (estado == S_PER_NEGRO)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (tipojuego == 0) {
				if (x < reshx * 1158 && x > reshx * 1086 && y < reshy * 135 && y > reshy * 102 && personajeN != 0) { estado = JUEGO; estadojuego = TURNO;  playMusica("recursos/sonidos/Pokeselect.mp3"); musica(); return; }
				else if (x > reshx * 682 || x < reshx * 275 || y < reshy * 292 || y > reshy * 471) { personajeN = 0; tablero.setPersonaje2(0);  return;/*no hay personaje seleecionado*/ }
				else if (x < reshx * 556 && x > reshx * 275 && y < reshy * 324 && y > reshy * 292) { personajeN = 1; tablero.setPersonaje2(1); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 513 && x > reshx * 275 && y < reshy * 370 && y > reshy * 344) { personajeN = 2; tablero.setPersonaje2(2); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 556 && x > reshx * 275 && y < reshy * 423 && y > reshy * 392) { personajeN = 3; tablero.setPersonaje2(3); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 682 && x > reshx * 275 && y < reshy * 471 && y > reshy * 441) { personajeN = 4; tablero.setPersonaje2(4); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
			}

			if (tipojuego == 1) {
				if (x < reshx * 1158 && x > reshx * 1086 && y < reshy * 135 && y > reshy * 102 && personajeN != 0) { estado = JUEGO; estadojuego = TURNO; musica(); return; }
				else if (x > reshx * 713 || x < reshx * 264 || y < reshy * 229 || y > reshy * 654) { personajeN = 0; tablero.setPersonaje2(0);  return;/*no hay personaje seleecionado*/ }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 258 && y > reshy * 229) { personajeN = 1; tablero.setPersonaje2(1); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 568 && x > reshx * 264 && y < reshy * 307 && y > reshy * 278) { personajeN = 2; tablero.setPersonaje2(2); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 360 && y > reshy * 332) { personajeN = 3; tablero.setPersonaje2(3); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 713 && x > reshx * 264 && y < reshy * 408 && y > reshy * 377) { personajeN = 4; tablero.setPersonaje2(4); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 568 && x > reshx * 264 && y < reshy * 455 && y > reshy * 424) { personajeN = 5; tablero.setPersonaje2(5); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 586 && x > reshx * 264 && y < reshy * 504 && y > reshy * 478) { personajeN = 6; tablero.setPersonaje2(6); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 555 && y > reshy * 526) { personajeN = 7; tablero.setPersonaje2(7); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 619 && x > reshx * 264 && y < reshy * 605 && y > reshy * 575) { personajeN = 8; tablero.setPersonaje2(8); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
				else if (x < reshx * 493 && x > reshx * 264 && y < reshy * 654 && y > reshy * 628) { personajeN = 9; tablero.setPersonaje2(9); playMusica("recursos/sonidos/Characterselection.mp3"); return; }
			}
		}
	}

	if (estado == OPCIONES) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if (x > reshx * 730 || x < reshx * 287 || y < reshy * 191 || y > reshy * 642) {  /*no hay modo opciones*/ }
			else if (x < reshx * 730 && x > reshx * 377 && y < reshy * 231 && y > reshy * 191) { /*queens*/
				if (opciones == 1)setOpciones(0);
				if (opciones == 3)setOpciones(2);
				if (opciones == 5)setOpciones(4);
				if (opciones == 7)setOpciones(6);
				return;
			}
			else if (x < reshx * 730 && x > reshx * 377 && y < reshy * 307 && y > reshy * 264) { /*kings*/
				if (opciones == 0)setOpciones(1);
				if (opciones == 2)setOpciones(3);
				if (opciones == 4)setOpciones(5);
				if (opciones == 6)setOpciones(7);
				return;
			}
			else if (x < reshx * 440 && x > reshx * 377 && y < reshy * 480 && y > reshy * 452) { /*on*/
				if (opciones == 0)setOpciones(2);
				if (opciones == 1)setOpciones(3);
				if (opciones == 4)setOpciones(6);
				if (opciones == 5)setOpciones(7);
				return;
			}
			else if (x < reshx * 440 && x > reshx * 377 && y < reshy * 531 && y > reshy * 496) { /*off*/
				if (opciones == 2)setOpciones(0);
				if (opciones == 3)setOpciones(1);
				if (opciones == 6)setOpciones(4);
				if (opciones == 7)setOpciones(5);
				return;
			}
			else if (x < reshx * 378 && x > reshx * 287 && y < reshy * 642 && y > reshy * 601) { /*exit*/
				estado = INICIO; return;
			}
		}
	}

	if (estado == JUEGO) {

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (estadojuego == TURNO) {

					tablero.ratonTablero(button, state, x, y);
					// SI SE AABA ALGUNO DE LOS TIEMPOS
					if (timeWhite == 0) { ganador = 0; ganar = FALSE; }
					if (timeBlack == 0) { ganador = 1; ganar = TRUE; }

					// si termina el turno de las negras
					if (tablero.getTurnoAcabadoN() == true)
					{
						if (musicajaque == true) {
							musica();
							musicajaque = false;
						}

						if (Tablero::detectar_jaque('N') == true || Tablero::detectar_jaque_mate('B') == true)
						{
							musicajaque = false;
							if (Tablero::detectar_jaque('N') == true) { ganador = 1; ganar = TRUE; }
							else if (Tablero::detectar_jaque_mate('B') == true) { ganador = 0; ganar = FALSE; }
							i = 0;
							estadojuego = JAQUE_MATE;
							musica();
							return;
						}

						else if (Tablero::detectar_jaque('B') == true)
						{
							musicajaque = true;
							estadojuego = JAQUE;
							i = 0;
							musica();
							return;
						}

						if (Tablero::detectar_ahogado('N') || Tablero::detectar_ahogado('B') || Tablero::detectar_tablas_muertas('N') || Tablero::detectar_tablas_muertas('B'))
						{
							playMusica("recursos/sonidos/Draw.mp3");
							estado = FIN;
							ganador = 2;
							return;
						}
					}

					// si termina el turno de las blancas
					if (tablero.getTurnoAcabadoB() == true)
					{
						turnotime = 1;
						if (musicajaque == true) {
							musica();
							musicajaque = false;
						}

						if (Tablero::detectar_jaque('B') == true || Tablero::detectar_jaque_mate('N') == true)
						{
							musicajaque = false;
							if (Tablero::detectar_jaque_mate('N') == true) { ganador = 1; ganar = TRUE; }
							else if (Tablero::detectar_jaque('B') == true) { ganador = 0; ganar = FALSE; }
							i = 0;
							estadojuego = JAQUE_MATE;
							musica();
							return;
						}

						else if (Tablero::detectar_jaque('N') == true)
						{
							musicajaque = true;
							estadojuego = JAQUE;
							musica();
							i = 0;
							return;
						}

						if (Tablero::detectar_ahogado('N') || Tablero::detectar_ahogado('B') || Tablero::detectar_tablas_muertas('N') || Tablero::detectar_tablas_muertas('B'))
						{
							playMusica("recursos/sonidos/Draw.mp3");
							estado = FIN;
							ganador = 2;
							return;
						}
					}

					if (modojuego == TRUE)
					{
						if (tablero.getCoronacion('B') == TRUE) { estadojuego = CORONAR_BLANCAS; }
						else if (tablero.getCoronacion('N') == TRUE) { estadojuego = CORONAR_NEGRAS; }

					}

					if(modojuego == FALSE)
					{
					// hay que meter cosas //
					if (tablero.getCoronacion('B') == TRUE) { estadojuego = CORONAR_BLANCAS; }
					else if (tablero.getCoronacion('N') == TRUE) { tablero.setCoronacion(5); }
				    }
			}

			if (estadojuego == CORONAR_NEGRAS || estadojuego == CORONAR_BLANCAS) {
				if (x > reshx * 760 || x < reshx * 600 || y < reshy * 254 || y > reshy * 593) { return; /*no hay modo coronar*/ }
				else if (x < reshx * 760 && x > reshx * 600 && y < reshy * 289 && y > reshy * 254) { tablero.setCoronacion(3); estadojuego = TURNO; return;/*ALFIL*/ }
				else if (x < reshx * 760 && x > reshx * 600 && y < reshy * 391 && y > reshy * 353) { tablero.setCoronacion(4); estadojuego = TURNO; return; /*CABALLO*/ }
				else if (x < reshx * 760 && x > reshx * 600 && y < reshy * 494 && y > reshy * 455) { tablero.setCoronacion(2); estadojuego = TURNO; return;/*TORRE*/ }
				else if (x < reshx * 760 && x > reshx * 600 && y < reshy * 593 && y > reshy * 553) { tablero.setCoronacion(5); estadojuego = TURNO; return;/*REINA*/ }
			}

			if (estadojuego == PAUSA) {
				if (x > reshx * 737 || x < reshx * 498 || y < reshy * 329 || y > reshy * 539) { return; /*no hay modo pausa*/ }
				else if (x < reshx * 643 && x > reshx * 498 && y < reshy * 370 && y > reshy * 329) { estadojuego = TURNO; playMusica("recursos/sonidos/Pokeselect.mp3"); musica(); return;/*resume*/ }
				else if (x < reshx * 643 && x > reshx * 498 && y < reshy * 452 && y > reshy * 380) { tablero.eliminarTablero(); tablero.nuevoTablero(); timeBlack = 5400;
				timeWhite = 5400; estadojuego = TURNO; playMusica("recursos/sonidos/Pokeselect.mp3"); musica(); return;/*restart*/ }
				else if (x < reshx * 737 && x > reshx * 498 && y < reshy * 481 && y > reshy * 462) { tablero.eliminarTablero(); estado = INICIO; musica(); estadojuego = TURNO; return;/*back to*/ }
				else if (x < reshx * 524 && x > reshx * 498 && y < reshy * 539 && y > reshy * 507) { exit(0);/*exit*/ }
			}

			if (estadojuego == AYUDA) {
				turnotime = 2;
				if (menu_help == H) {
					if (x < reshx * 319 && x > reshx * 252 && y < reshy * 233 && y > reshy * 200) { estadojuego = TURNO; musica(); return; }
					else if (x > reshx * 742 || x < reshx * 509 || y < reshy * 345 || y > reshy * 540) { return; /*no hay modo ayuda*/ }
					else if (x < reshx * 742 && x > reshx * 509 && y < reshy * 374 && y > reshy * 345) { menu_help = MOVS; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*movimientos*/ }
					else if (x < reshx * 716 && x > reshx * 509 && y < reshy * 463 && y > reshy * 423) { menu_help = MOVSE; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*movimientos especiales*/ }
					else if (x < reshx * 665 && x > reshx * 509 && y < reshy * 540 && y > reshy * 514) { menu_help = END; playMusica("recursos/sonidos/Pokeselect.mp3"); return;/*fin juego*/ }
				}

				if (menu_help == MOVS) {
					if (x < reshx * 319 && x > reshx * 252 && y < reshy * 233 && y > reshy * 200) { help = 0; menu_help = H; return; }
					else if (x > reshx * 628 || x < reshx * 537 || y < reshy * 300 || y > reshy * 568) { return; /*no hay modo movs*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 332 && y > reshy * 300) { muchotexto = 0; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*pawn*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 382 && y > reshy * 332) { muchotexto = 1; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*bishop*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 424 && y > reshy * 382) { muchotexto = 2; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*knight*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 474 && y > reshy * 424) { muchotexto = 3; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*rook*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 522 && y > reshy * 474) { muchotexto = 4; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*queen*/ }
					else if (x < reshx * 628 && x > reshx * 537 && y < reshy * 568 && y > reshy * 522) { muchotexto = 5; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*king*/ }
				}

				if (menu_help == MOVSE) {
					if (x < reshx * 319 && x >  reshx * 252 && y < reshy * 233 && y > reshy * 200) { help = 0; menu_help = H; playMusica("recursos/sonidos/Pokeselect.mp3"); return; }
					else if (x > reshx * 688 || x < reshx * 505 || y < reshy * 347 || y > reshy * 506) { return; /*no hay modo movse*/ }
					else if (x < reshx * 643 && x > reshx * 505 && y < reshy * 383 && y > reshy * 347) { muchotexto = 6; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*castling*/ }
					else if (x < reshx * 688 && x > reshx * 505 && y < reshy * 441 && y > reshy * 414) { muchotexto = 7; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*passant*/ }
					else if (x < reshx * 670 && x > reshx * 505 && y < reshy * 506 && y > reshy * 471) { muchotexto = 8; menu_help = TEXT; playMusica("recursos/sonidos/Pokeselect.mp3"); return; /*promotion*/ }
				}

				if (menu_help == END) {
					if (x < reshx * 319 && x > reshx * 252 && y < reshy * 233 && y > reshy * 200) { help = 0; menu_help = H; playMusica("recursos/sonidos/Pokeselect.mp3"); return; }
				}

				if (menu_help == TEXT) {
					if (x < reshx * 319 && x > reshx * 252 && y < reshy * 233 && y > reshy * 200 && (muchotexto == 0 || muchotexto == 1 || muchotexto == 2 || muchotexto == 3 || muchotexto == 4 || muchotexto == 5))
					{
						movs = 0; menu_help = MOVS; playMusica("recursos/sonidos/Pokeselect.mp3"); return;
					}

					if (x < reshx * 319 && x > reshx * 252 && y < reshy * 233 && y > reshy * 200 && (muchotexto == 6 || muchotexto == 7 || muchotexto == 8))
					{
						specialmovs = 0; menu_help = MOVSE; playMusica("recursos/sonidos/Pokeselect.mp3"); return;
					}
				}
			}
		}
	}

	if (estado == FIN) {
		turnotime = 2;

		if (modojuego == TRUE) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
				if (x > reshx * 708 || x < reshx * 470 || y < reshy * 423 || y > reshy * 521) { ; /*no hay final*/ }
				else if (x < reshx * 624 && x > reshx * 470 && y < reshy * 462 && y > reshy * 423) {
					tablero.eliminarTablero();
					tablero.nuevoTablero(); 
					estado = JUEGO;
					timeBlack = 5400;
					timeWhite = 5400;  
					estadojuego = TURNO; 
					i = 0;
					musica(); playMusica("recursos/sonidos/Pokeselect.mp3");/*rematch*/ }

				else if (x < reshx * 708 && x > reshx * 470 && y < reshy * 521 && y > reshy * 496) { 
					tablero.eliminarTablero();
					estado = INICIO; 
					estadojuego = TURNO;
					playMusica("recursos/sonidos/menu.mp3");
					i = 0;  /*back to*/ }
			}
		}

		if (modojuego == FALSE)
		{
			// DEPENDIENDO DE SI SE GANA O SE PIERDE
			
			// si se gana //
			if (ganar == TRUE) {
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
					if (x > reshx * 708 || x < reshx * 470 || y < reshy * 423 || y > reshy * 521) { ; /*no hay final*/ }
					else if (x < reshx * 624 && x > reshx * 470 && y < reshy * 462 && y > reshy * 423) 
					{
						nivel++;

						tablero.eliminarTablero(); 

						if (nivel == 2) {
							Persona* Jugador1 = new Persona('B');
							IA2* Jugador2 = new IA2('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(1); // personaje de la persona
							tablero.setPersonaje2(5); // personaje de la IA
						}

						if (nivel == 3) {
							Persona* Jugador1 = new Persona('B');
							IA3* Jugador2 = new IA3('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(1); // personaje de la persona
							tablero.setPersonaje2(3); // personaje de la IA
						}

						if (nivel > 3)
						{
							Persona* Jugador1 = new Persona('B');
							IA1* Jugador2 = new IA1('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(4); // personaje de la persona
							tablero.setPersonaje2(2); // personaje de la IA

							nivel = 1;
						}

						timeBlack = 5400;
						timeWhite = 5400;

						estado = PANTALLA; 
						i = 0; 
						musica(); 
						tablero.nuevoTablero();
						return;
						/*rematch*/ 
					}

					else if (x < reshx * 708 && x > reshx * 470 && y < reshy * 521 && y > reshy * 496) { tablero.eliminarTablero(); estado = INICIO; playMusica("recursos/sonidos/menu.mp3");  estadojuego = TURNO; i = 0; /*back to*/ }
				}
			}

			// si se pierde //
			if (ganar == FALSE) {
				if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
					if (x > reshx * 708 || x < reshx * 470 || y < reshy * 423 || y > reshy * 521) { ; /*no hay final*/ }
					else if (x < reshx * 624 && x > reshx * 470 && y < reshy * 462 && y > reshy * 423)
					{
						tablero.eliminarTablero();

						if (nivel == 1) {
							Persona* Jugador1 = new Persona('B');
							IA1* Jugador2 = new IA1('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(4); // personaje de la persona
							tablero.setPersonaje2(2); // personaje de la IA
						}

						if (nivel == 2) {
							Persona* Jugador1 = new Persona('B');
							IA2* Jugador2 = new IA2('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(1); // personaje de la persona
							tablero.setPersonaje2(2); // personaje de la IA
						}

						if (nivel == 3)
						{
							Persona* Jugador1 = new Persona('B');
							IA3* Jugador2 = new IA3('N');

							tablero.setJugador1(Jugador1);
							tablero.setJugador2(Jugador2);

							tablero.setPersonaje1(1); // personaje de la persona
							tablero.setPersonaje2(3); // personaje de la IA
						}

						timeBlack = 5400;
						timeWhite = 5400;

						estado = PANTALLA;
						i = 0; musica();
						tablero.nuevoTablero();
						return;
						/*rematch*/
					}

					else if (x < reshx * 708 && x > reshx * 470 && y < reshy * 521 && y > reshy * 496) { tablero.eliminarTablero(); 
					estado = INICIO;
					playMusica("recursos/sonidos/menu.mp3");  
					estadojuego = TURNO; 
					i = 0;  /*back to*/ }
				}
			}
		}
	}

}

void Coordinador::dibuja()
{
	///////// INICIO ///////////
	if (estado == INICIO) {

		if (tipojuego == 0) {
			switch (menu_inicio)
			{
			case INICIO:
				MenuInicial.draw();
			case FREE_PLAY:
				MenuFreePlay.draw();
			case STORY_MODE:
				MenuStoryMode.draw();
			case OPTIONS:
				MenuOpciones.draw();
			}
		}

		if (tipojuego == 1) {
			switch (menu_inicio)
			{
			case INICIO:
				MenuInicial2.draw();
			case FREE_PLAY:
				MenuFreePlay2.draw();
			case STORY_MODE:
				MenuStoryMode2.draw();
			case OPTIONS:
				MenuOpciones2.draw();
			}
		}

		// para la carga de sprite sequences //
		Jaque.setPos(1000, 1000);
		Jaque.draw();
		Jaque1.setPos(1000, 1000);
		Jaque1.draw();
		JaqueMate.setPos(1000, 1000);
		JaqueMate.draw();
		JaqueMate1.setPos(1000, 1000);
		JaqueMate1.draw();
	}


		/////////   SELECCION PERSONAJE WHITE  //////////
		if (estado == S_PER_BLANCO)
		{
			Flecha1.setPos(50, 30);
			Flecha1.draw();

			if (tipojuego == 0) {
				switch (personajeB) {
				case 0:
					PerBQ.draw();
				case 1:
					PerBQ_BT.draw();
				case 2:
					PerBQ_MS.draw();
				case 3:
					PerBQ_BE.draw();
				case 4:
					PerBQ_BB.draw();
				}
			}

			if (tipojuego == 1) {
				switch (personajeB) {
				case 0:
					PerBK.draw();
				case 1:
					PerBK_TB.draw();
				case 2:
					PerBK_TC.draw();
				case 3:
					PerBK_TH.draw();
				case 4:
					PerBK_TJ.draw();
				case 5:
					PerBK_TM.draw();
				case 6:
					PerBK_TO.draw();
				case 7:
					PerBK_TP.draw();
				case 8:
					PerBK_TR.draw();
				case 9:
					PerBK_TS.draw();
				}
			}
		}

		/////////   SELECCION PERSONAJE BLACK   //////////
		if (estado == S_PER_NEGRO)
		{
			Flecha1.setPos(50, 30);
			Flecha1.draw();

			if (tipojuego == 0) {
				switch (personajeN) {
				case 0:
					PerNQ.draw();
				case 1:
					PerNQ_BT.draw();
				case 2:
					PerNQ_MS.draw();
				case 3:
					PerNQ_BE.draw();
				case 4:
					PerNQ_BB.draw();
				}
			}

			if (tipojuego == 1) {
				switch (personajeN) {
				case 0:
					PerNK.draw();
				case 1:
					PerNK_TB.draw();
				case 2:
					PerNK_TC.draw();
				case 3:
					PerNK_TH.draw();
				case 4:
					PerNK_TJ.draw();
				case 5:
					PerNK_TM.draw();
				case 6:
					PerNK_TO.draw();
				case 7:
					PerNK_TP.draw();
				case 8:
					PerNK_TR.draw();
				case 9:
					PerNK_TS.draw();
				}
			}
		}

		//////// OPCIONES /////////
		if (estado == OPCIONES) {

			switch (opciones) {
			case 0:
				QueenGam.draw();
			case 1:
				KingGam.draw();
			case 2:
				QueenGamH.draw();
			case 3:
				KingGamH.draw();
			case 4:
				QueenGamE.draw();
			case 5:
				KingGamE.draw();
			case 6:
				QueenGamHE.draw();
			case 7:
				KingGamHE.draw();
			}
		}

		if (estado == PANTALLA)
		{
			if (tipojuego == 0)
			{
				switch (nivel)
				{
				case 1:
					Level1.draw();
				case 2:
					Level2.draw();
				case 3:
					Level3.draw();
				}
			}

			if (tipojuego == 1)
			{
				switch (nivel)
				{
				case 1:
					Level1k.draw();
				case 2:
					Level2k.draw();
				case 3:
					Level3k.draw();
				}
			}
		}

		////////   JUEGO   /////////
		if (estado == JUEGO) {

			ETSIDI::setFont("recursos/8bitOperatorPlus-Regular.ttf", reshy*20);
			ETSIDI::printxy("Time left:",  48,  37);
			dibujarTempWhite(1);
			dibujarTempWhite(2);
			ETSIDI::printxy(":",  69,  37);
			dibujarTempWhite(3);
			dibujarTempWhite(4);

			ETSIDI::printxy("Time left:", -72, 37);
			dibujarTempBlack(1);
			dibujarTempBlack(2);
			ETSIDI::printxy(":",  -51, 37);
			dibujarTempBlack(3);
			dibujarTempBlack(4);

			// turno //
			if (estadojuego == TURNO) {
				if (tipojuego == 0) { BotonHP_azul.draw(); }
				if (tipojuego == 1) { BotonHP_rojo.draw(); }
			}

			// pausa //
			if (estadojuego == PAUSA) {
				if (tipojuego == 0)
				{
					switch (pause)
					{
					case 0:
						PausaM.draw();
					case 1:
						PausaResume.draw();
					case 2:
						PausaRestart.draw();
					case 3:
						PausaBack.draw();
					case 4:
						PausaExit.draw();
					}
				}

				if (tipojuego == 1)
				{
					switch (pause)
					{
					case 0:
						PausaM2.draw();
					case 1:
						PausaResume2.draw();
					case 2:
						PausaRestart2.draw();
					case 3:
						PausaBack2.draw();
					case 4:
						PausaExit2.draw();
					}
				}
				tablero.dibuja();
			}

			// ayuda //
			if (estadojuego == AYUDA) {
				Flecha.setPos(-45, 19);
				Flecha.draw();

				if (tipojuego == 0) {
					if (menu_help == H) {
						switch (help)
						{
						case 0:
							HelpM.draw();
						case 1:
							HelpMov.draw();
						case 2:
							HelpSpeMov.draw();
						case 3:
							HelpEnd.draw();
						}
					}

					if (menu_help == MOVS) {
						switch (movs)
						{
						case 0:
							HelpMovM.draw();
						case 1:
							HelpMovP.draw();
						case 2:
							HelpMovB.draw();
						case 3:
							HelpMovKn.draw();
						case 4:
							HelpMovR.draw();
						case 5:
							HelpMovQ.draw();
						case 6:
							HelpMovK.draw();
						}
					}

					if (menu_help == MOVSE) {
						switch (specialmovs)
						{
						case 0:
							HelpMovEspM.draw();
						case 1:
							HelpMovEspC.draw();
						case 2:
							HelpMovEspE.draw();
						case 3:
							HelpMovEspP.draw();
						}
					}
				}

				if (tipojuego == 1) {
					if (menu_help == H) {
						switch (help)
						{
						case 0:
							HelpM2.draw();
						case 1:
							HelpMov2.draw();
						case 2:
							HelpSpeMov2.draw();
						case 3:
							HelpEnd2.draw();
						}
					}

					if (menu_help == MOVS) {
						switch (movs)
						{
						case 0:
							HelpMovM2.draw();
						case 1:
							HelpMovP2.draw();
						case 2:
							HelpMovB2.draw();
						case 3:
							HelpMovKn2.draw();
						case 4:
							HelpMovR2.draw();
						case 5:
							HelpMovQ2.draw();
						case 6:
							HelpMovK2.draw();
						}
					}

					if (menu_help == MOVSE) {
						switch (specialmovs)
						{
						case 0:
							HelpMovEspM2.draw();
						case 1:
							HelpMovEspC2.draw();
						case 2:
							HelpMovEspE2.draw();
						case 3:
							HelpMovEspP2.draw();
						}
					}
				}

				if (menu_help == END) {
					HelpEndg.draw();
				}

				if (menu_help == TEXT) {
					switch (muchotexto)
					{
					case 0:
						HelpPawn.draw();
					case 1:
						HelpBish.draw();
					case 2:
						HelpKnig.draw();
					case 3:
						HelpRook.draw();
					case 4:
						HelpQuee.draw();
					case 5:
						HelpKing.draw();
					case 6:
						HelpCast.draw();
					case 7:
						HelpPass.draw();
					case 8:
						HelpProm.draw();
					}
				}
			}

			// jaque //
			if (estadojuego == JAQUE) {
				if (tipojuego == 0) {
					Jaque.setPos(0, 0);
					Jaque.draw();
					
				}
				if (tipojuego == 1) {
					Jaque1.setPos(0, 0);
					Jaque1.draw();
				
				}
			}

			// jaque mate //
			if (estadojuego == JAQUE_MATE) {
				if (tipojuego == 0) {
					JaqueMate.setPos(0, 0);
					JaqueMate.draw();
				}
				if (tipojuego == 1) {
					JaqueMate1.setPos(0, 0);
					JaqueMate1.draw();
				}
			}

			// coronacion blancas //
			if (estadojuego == CORONAR_BLANCAS) {
				if (tipojuego == 0) {
					switch (coronar)
					{
					case C:
						MenuCoronar_B.draw();
					case REINA:
						MenuCoronarReina_B.draw();
					case TORRE:
						MenuCoronarTorre_B.draw();
					case ALFIL:
						MenuCoronarAlfil_B.draw();
					case CABALLO:
						MenuCoronarCaballo_B.draw();
					}
				}

				if (tipojuego == 1) {
					switch (coronar)
					{
					case C:
						MenuCoronar_B2.draw();
					case REINA:
						MenuCoronarReina_B2.draw();
					case TORRE:
						MenuCoronarTorre_B2.draw();
					case ALFIL:
						MenuCoronarAlfil_B2.draw();
					case CABALLO:
						MenuCoronarCaballo_B2.draw();
					}
				}
			}

			// coronacion negra //
			if (estadojuego == CORONAR_NEGRAS) {
				if (tipojuego == 0) {
					switch (coronar)
					{
					case C:
						MenuCoronar_N.draw();
					case REINA:
						MenuCoronarReina_N.draw();
					case TORRE:
						MenuCoronarTorre_N.draw();
					case ALFIL:
						MenuCoronarAlfil_N.draw();
					case CABALLO:
						MenuCoronarCaballo_N.draw();
					}
				}

				if (tipojuego == 1) {
					switch (coronar)
					{
					case C:
						MenuCoronar_N2.draw();
					case REINA:
						MenuCoronarReina_N2.draw();
					case TORRE:
						MenuCoronarTorre_N2.draw();
					case ALFIL:
						MenuCoronarAlfil_N2.draw();
					case CABALLO:
						MenuCoronarCaballo_N2.draw();
					}
				}
			}
			tablero.dibuja();
		}

		//////////   FIN DE JUEGO   ///////////
		if (estado == FIN) {
			if (modojuego == TRUE)
			{
				if (tipojuego == 0)
				{

					if (ganador == 1)
					{
						switch (final)
						{
						case 0:
							MenuGanadorB.draw();
						case 1:
							MenuGanadorReB.draw();
						case 2:
							MenuGanadorBaB.draw();
						}
					}

					if (ganador == 0)
					{
						switch (final)
						{
						case 0:
							MenuGanadorN.draw();
						case 1:
							MenuGanadorReN.draw();
						case 2:
							MenuGanadorBaN.draw();
						}
					}

					if (ganador == 2)
					{
						switch (final)
						{
						case 0:
							Tablas.draw();
						case 1:
							TablasRe.draw();
						case 2:
							TablasBa.draw();
						}
					}
				}

				if (tipojuego == 1)
				{
					if (ganador == 1)
					{
						switch (final)
						{
						case 0:
							MenuGanadorB2.draw();
						case 1:
							MenuGanadorReB2.draw();
						case 2:
							MenuGanadorBaB2.draw();
						}
					}

					if (ganador == 0)
					{
						switch (final)
						{
						case 0:
							MenuGanadorN2.draw();
						case 1:
							MenuGanadorReN2.draw();
						case 2:
							MenuGanadorBaN2.draw();
						}
					}

					if (ganador == 2)
					{
						switch (final)
						{
						case 0:
							Tablas2.draw();
						case 1:
							TablasRe2.draw();
						case 2:
							TablasBa2.draw();
						}
					}
				}
				tablero.dibuja();
			}

			if (modojuego == FALSE)
			{
				if (nivel == 3) // si es el último nivel
				{
					if (tipojuego == 0)
					{
						if (ganador == 1) // si gana blancos ( persona )
						{
							switch (final)
							{
							case 0:
								IaSC.draw();
							case 1:
								IaSCRe.draw();
							case 2:
								IaSCBa.draw();
							}
						}

						if (ganador == 0) // si gana negros (IA)
						{
							switch (final)
							{
							case 0:
								IaLF.draw();
							case 1:
								IaLFRe.draw();
							case 2:
								IaLFBa.draw();
							}
						}

						if (ganador == 2)
						{
							switch (final)
							{
							case 0:
								Tablas.draw();
							case 1:
								TablasRe.draw();
							case 2:
								TablasBa.draw();
							}
						}
					}

					if (tipojuego == 1)
					{
						if (ganador == 1) // si gana blancos ( persona )
						{
							switch (final)
							{
							case 0:
								IaSC2.draw();
							case 1:
								IaSCRe2.draw();
							case 2:
								IaSCBa2.draw();
							}
						}

						if (ganador == 0)
						{
							switch (final) // si gana negros (IA)
							{
							case 0:
								IaLF2.draw();
							case 1:
								IaLFRe2.draw();
							case 2:
								IaLFBa2.draw();
							}
						}

						if (ganador == 2)
						{
							switch (final)
							{
							case 0:
								Tablas2.draw();
							case 1:
								TablasRe2.draw();
							case 2:
								TablasBa2.draw();
							}
						}
					}
					tablero.dibuja();
				}

				if (nivel == 1 || nivel == 2) // si es de los dos primeros niveles
				{
					if (tipojuego == 0)
					{
						if (ganador == 1) // si gana blancos ( persona )
						{
							switch (final)
							{
							case 0:
								IaLC.draw();
							case 1:
								IaLCNx.draw();
							case 2:
								IaLCBa.draw();
							}
						}

						if (ganador == 0) // si gana negros (IA)
						{
							switch (final)
							{
							case 0:
								IaLF.draw();
							case 1:
								IaLFRe.draw();
							case 2:
								IaLFBa.draw();
							}
						}

						if (ganador == 2)
						{
							switch (final)
							{
							case 0:
								Tablas.draw();
							case 1:
								TablasRe.draw();
							case 2:
								TablasBa.draw();
							}
						}
					}

					if (tipojuego == 1)
					{
						if (ganador == 1) // si gana blancos ( persona )
						{
							switch (final)
							{
							case 0:
								IaLC2.draw();
							case 1:
								IaLCNx2.draw();
							case 2:
								IaLCBa2.draw();
							}
						}

						if (ganador == 0)
						{
							switch (final) // si gana negros (IA)
							{
							case 0:
								IaLF2.draw();
							case 1:
								IaLFRe2.draw();
							case 2:
								IaLFBa2.draw();
							}
						}

						if (ganador == 2)
						{
							switch (final)
							{
							case 0:
								Tablas2.draw();
							case 1:
								TablasRe2.draw();
							case 2:
								TablasBa2.draw();
							}
						}
					}
					tablero.dibuja();
				}
			}
		}
}

void Coordinador::musica()
{
	if (estado == INICIO || estado == OPCIONES) playMusica("recursos/sonidos/menu.mp3");
	if (estado == JUEGO) {
		if (estadojuego==TURNO)
			playMusica("recursos/sonidos/juego.mp3", true);

	    else if (estadojuego==JAQUE)
			playMusica("recursos/sonidos/JaqueTheme.mp3", true);
	}
	if (estado == FIN || estadojuego == JAQUE_MATE) {
		if (modojuego == FALSE) {
			if(ganar==TRUE) playMusica("recursos/sonidos/VictoryTheme.mp3");
			if(ganar==FALSE) playMusica("recursos/sonidos/defeat.mp3");
		}
		else playMusica("recursos/sonidos/VictoryTheme.mp3");

	}

	if(estado==PANTALLA) playMusica("recursos/sonidos/intro.mp3");
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

	if (estadojuego == JAQUE_MATE)
	{
		if (tipojuego == 0) {
			if (i < 34) {
				JaqueMate.setState(i);
				i++;
			}
			else if (i >= 34) {
				i = 0;
				estado = FIN;
			}
		}

		if (tipojuego == 1) {
			if (i < 34) {
				JaqueMate1.setState(i);
				i++;
			}
			else if (i >= 34) {
				i = 0;
				estado = FIN;
			}
		}
	}

	if (estado == PANTALLA)
	{
		j++;
		if (j == 30)
		{
			estado = JUEGO;
			estadojuego = TURNO;
			musica();
			turnotime = 0;
			j = 0;
		}
	}

	if (estado == JUEGO)
	{
		if (estadojuego == TURNO)
		{
			if (modojuego == TRUE)
			{
				if (tablero.getTurno() == TRUE)
				{
					j++;
					if (j == 10)
					{
						timeWhite = timeWhite - 1;
						dibuja();
						j = 0;
					}
				}

				if (tablero.getTurno() == FALSE)
				{
					j++;
					if (j == 10)
					{
						timeBlack = timeBlack - 1;
						dibuja();
						j = 0;
					}
				}
			}

			if (modojuego == FALSE) 
			{
				if (tablero.getTurno() == TRUE)
				{
					j++;
					if (j == 10)
					{
						timeWhite = timeWhite - 1;
						dibuja();
						j = 0;
						
					}

					pasada = FALSE;
				}

				if (tablero.getTurno() == FALSE)
				{
					j++;
					k++;

					if (j == 10)
					{
						timeBlack = timeBlack - 1;
						dibuja();
						j = 0;
					}

					if (pasada == FALSE)
					{
						if (k > 20)
						{
							raton(GLUT_LEFT_BUTTON, GLUT_DOWN, 0, 0);
							pasada = TRUE;
							k = 0;
						}
					}
				}
			}
		}
	}
}

void Coordinador::setMenuInicio(int x)
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

	if (x == 0) { tipojuego = 0; tablero.setTipoJuego(true); tablero.setMovimientos(false); }
	if (x == 1) { tipojuego = 1; tablero.setTipoJuego(false); tablero.setMovimientos(false); }
	if (x == 2) { tipojuego = 0; tablero.setTipoJuego(true); tablero.setMovimientos(true); }
	if (x == 3) { tipojuego = 1; tablero.setTipoJuego(false); tablero.setMovimientos(true); }
	if (x == 4) { tipojuego = 0; tablero.setTipoJuego(true); tablero.setMovimientos(false); }
	if (x == 5) { tipojuego = 1; tablero.setTipoJuego(false); tablero.setMovimientos(false); }
	if (x == 6) { tipojuego = 0; tablero.setTipoJuego(true); tablero.setMovimientos(true); }
	if (x == 7) { tipojuego = 1; tablero.setTipoJuego(false); tablero.setMovimientos(true); }
}

void Coordinador::setReshape(float x, float y)
{
	reshx = x;
	reshy = y;
}

int Coordinador::getEstado()
{
	return estado;
}

int Coordinador::getMenuJuego()
{
	return menu_inicio;
}

int Coordinador::getEstadoJuego()
{
	return estadojuego;
}

void Coordinador::dibujarTempWhite(int digito)
{
	int timemin, timesecs, numero;
	timemin = timeWhite / 60;
	timesecs = timeWhite % 60;
	int posx, posy;

	if (digito == 1) { posx = 65; posy = 37; numero = timemin / 10; }
	if (digito == 2) { posx = 67; posy = 37; numero = timemin % 10; }
	if (digito == 3) { posx = 70; posy = 37; numero = timesecs / 10; }
	if (digito == 4) { posx = 72; posy = 37; numero = timesecs % 10; }

	ETSIDI::setFont("recursos/8bitOperatorPlus-Regular.ttf", reshy * 20);
	if(numero == 0)ETSIDI::printxy("0",  posx,  posy);
	else if (numero == 1)ETSIDI::printxy("1",  posx,  posy);
	else if (numero == 2)ETSIDI::printxy("2",  posx,  posy);
	else if (numero == 3)ETSIDI::printxy("3",  posx,  posy);
	else if (numero == 4)ETSIDI::printxy("4",  posx,  posy);
	else if (numero == 5)ETSIDI::printxy("5",  posx,  posy);
	else if (numero == 6)ETSIDI::printxy("6",  posx,  posy);
	else if (numero == 7)ETSIDI::printxy("7",  posx,  posy);
	else if (numero == 8)ETSIDI::printxy("8",  posx,  posy);
	else if (numero == 9)ETSIDI::printxy("9",  posx,  posy);
}


void Coordinador::dibujarTempBlack(int digito)
{
	int timemin, timesecs, numero;
	timemin = timeBlack / 60;
	timesecs = timeBlack % 60;
	int posx, posy;

	// -72 48
	if (digito == 1) { posx = -55; posy = 37; numero = timemin / 10; }
	if (digito == 2) { posx = -53; posy = 37; numero = timemin % 10; }
	if (digito == 3) { posx = -50; posy = 37; numero = timesecs / 10; }
	if (digito == 4) { posx = -48; posy = 37; numero = timesecs % 10; }

	ETSIDI::setFont("recursos/8bitOperatorPlus-Regular.ttf", reshy * 20);
	if (numero == 0)ETSIDI::printxy("0",  posx,  posy);
	else if (numero == 1)ETSIDI::printxy("1", posx,  posy);
	else if (numero == 2)ETSIDI::printxy("2", posx,  posy);
	else if (numero == 3)ETSIDI::printxy("3", posx,  posy);
	else if (numero == 4)ETSIDI::printxy("4", posx,  posy);
	else if (numero == 5)ETSIDI::printxy("5", posx,  posy);
	else if (numero == 6)ETSIDI::printxy("6", posx,  posy);
	else if (numero == 7)ETSIDI::printxy("7", posx,  posy);
	else if (numero == 8)ETSIDI::printxy("8", posx,  posy);
	else if (numero == 9)ETSIDI::printxy("9", posx,  posy);
}