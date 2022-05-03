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
	help = 0;

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
		if (x > 737 || x < 498 || y < 329 || y > 539) { setMenuPausa(0); /*no hay modo pausa*/ }
		else if (x < 643 && x > 498 && y < 370 && y > 329) { setMenuPausa(1); /*resume*/ }
		else if (x < 643 && x > 498 && y < 452 && y > 380) { setMenuPausa(2); /*restart*/ }
		else if (x < 737 && x > 498 && y < 481 && y > 462) { setMenuPausa(3); /*back to*/ }
		else if (x < 524 && x > 498 && y < 539 && y > 507) { setMenuPausa(4); /*exit*/ }
	}

	if (estadojuego == AYUDA) {
		if (menu_help == H) {
			if (x > 742 || x < 509 || y < 345 || y > 540) { setMenuAyuda(0); /*no hay modo ayuda*/ }
			else if (x < 742 && x > 509 && y < 374 && y > 345) { setMenuAyuda(1); /*movimientos*/ }
			else if (x < 716 && x > 509 && y < 463 && y > 423) { setMenuAyuda(2); /*movimientos especiales*/ }
			else if (x < 665 && x > 509 && y < 540 && y > 514) { setMenuAyuda(3); /*fin juego*/ }
		}

		if (menu_help == MOVS) {
			if (x > 628 || x < 537 || y < 300 || y > 568) { setMenuMovs(0); /*no hay modo movs*/ }
			else if (x < 628 && x > 537 && y < 332 && y > 300) { setMenuMovs(1); /*pawn*/ }
			else if (x < 628 && x > 537 && y < 382 && y > 332) { setMenuMovs(2); /*bishop*/ }
			else if (x < 628 && x > 537 && y < 424 && y > 382) { setMenuMovs(3); /*knight*/ }
			else if (x < 628 && x > 537 && y < 474 && y > 424) { setMenuMovs(4); /*rook*/ }
			else if (x < 628 && x > 537 && y < 522 && y > 474) { setMenuMovs(5); /*queen*/ }
			else if (x < 628 && x > 537 && y < 568 && y > 522) { setMenuMovs(6); /*king*/ }
		}

		if (menu_help == MOVSE) {
			if (x > 688 || x < 505 || y < 347 || y > 506) { setMenuMovsEspeciales(0); /*no hay modo ayuda*/ }
			else if (x < 643 && x > 505 && y < 383 && y > 347) { setMenuMovsEspeciales(1); /*movimientos*/ }
			else if (x < 688 && x > 505 && y < 441 && y > 414) { setMenuMovsEspeciales(2); /*movimientos especiales*/ }
			else if (x < 670 && x > 505 && y < 506 && y > 471) { setMenuMovsEspeciales(3); /*fin juego*/ }
		}

		if (menu_help == END) {

		}
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
		if (estadojuego == TURNO) {
			if (key == 'p' || key == 'P') { estadojuego = PAUSA; }
			if (key == 'h' || key == 'H') { estadojuego = AYUDA;  menu_help == H; }
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
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

			if (estadojuego == TURNO) {
				tablero.ratonTablero(button, state, x, y);
				if (tablero.getTurnoAcabado() == true)
				{
					if (Tablero::detectar_jaque('N') == true || Tablero::detectar_jaque('B') == true)
					{
						estadojuego = JAQUE;
					}

					if(Tablero::detectar_jaque_mate('N') == true || Tablero::detectar_jaque_mate('B') == true)
					{
						estadojuego = JAQUE_MATE;
					}
				}

				if (tablero.getCoronacion('B') == TRUE) estadojuego = CORONAR_BLANCAS;
				else if (tablero.getCoronacion('N') == TRUE) estadojuego = CORONAR_NEGRAS;
			}

			if (estadojuego == CORONAR_NEGRAS || estadojuego == CORONAR_BLANCAS) {
				if (x > 760 || x < 600 || y < 254 || y > 593) {  /*no hay modo coronar*/ }
				else if (x < 760 && x > 600 && y < 289 && y > 254) { tablero.setCoronacion(3); estadojuego = TURNO;/*ALFIL*/ }
				else if (x < 760 && x > 600 && y < 391 && y > 353) { tablero.setCoronacion(4); estadojuego = TURNO; /*CABALLO*/ }
				else if (x < 760 && x > 600 && y < 494 && y > 455) { tablero.setCoronacion(2); estadojuego = TURNO;/*TORRE*/ }
				else if (x < 760 && x > 600 && y < 593 && y > 553) { tablero.setCoronacion(5); estadojuego = TURNO;/*REINA*/ }
			}

			if (estadojuego == PAUSA) {
				if (x > 737 || x < 498 || y < 329 || y > 539) {  /*no hay modo pausa*/ }
				else if (x < 643 && x > 498 && y < 370 && y > 329) { estadojuego = TURNO; /*resume*/ }
				else if (x < 643 && x > 498 && y < 452 && y > 380) { tablero.eliminarTablero(); tablero.nuevoTablero(); estadojuego = TURNO;/*restart*/ } 
				else if (x < 737 && x > 498 && y < 481 && y > 462) { tablero.eliminarTablero(); estado = INICIO; estadojuego = TURNO;/*back to*/ } 
				else if (x < 524 && x > 498 && y < 539 && y > 507) { exit(0);/*exit*/ }
			}

			if (estadojuego == AYUDA) {

				if (menu_help == H) {
					if (x < 323 && x > 255 && y < 250 && y > 218) { estadojuego = TURNO; }
					else if (x > 742 || x < 509 || y < 345 || y > 540) {  /*no hay modo ayuda*/ }
					else if (x < 742 && x > 509 && y < 374 && y > 345) { menu_help = MOVS; /*movimientos*/ }
					else if (x < 716 && x > 509 && y < 463 && y > 423) { menu_help = MOVSE; /*movimientos especiales*/ }
					else if (x < 665 && x > 509 && y < 540 && y > 514) { menu_help = END; /*fin juego*/ }
				}

				if (menu_help == MOVS) {
					if (x < 323 && x > 255 && y < 250 && y > 218) { setMenuAyuda(0); menu_help = H; }
					else if (x > 628 || x < 537 || y < 300 || y > 568) { ; /*no hay modo movs*/ }
					else if (x < 628 && x > 537 && y < 332 && y > 300) { setMenuMuchoTexto(0); menu_help = TEXT; /*pawn*/ }
					else if (x < 628 && x > 537 && y < 382 && y > 332) { setMenuMuchoTexto(1); menu_help = TEXT; /*bishop*/ }
					else if (x < 628 && x > 537 && y < 424 && y > 382) { setMenuMuchoTexto(2); menu_help = TEXT; /*knight*/ }
					else if (x < 628 && x > 537 && y < 474 && y > 424) { setMenuMuchoTexto(3); menu_help = TEXT; /*rook*/ }
					else if (x < 628 && x > 537 && y < 522 && y > 474) { setMenuMuchoTexto(4); menu_help = TEXT; /*queen*/ }
					else if (x < 628 && x > 537 && y < 568 && y > 522) { setMenuMuchoTexto(5); menu_help = TEXT; /*king*/ }
				}

				if (menu_help == MOVSE) {
					if (x < 323 && x > 255 && y < 250 && y > 218) { setMenuAyuda(0); menu_help = H; }
					else if (x > 688 || x < 505 || y < 347 || y > 506) { ; /*no hay modo movse*/ }
					else if (x < 643 && x > 505 && y < 383 && y > 347) { ; /*castling*/ }
					else if (x < 688 && x > 505 && y < 441 && y > 414) { ; /*passant*/ }
					else if (x < 670 && x > 505 && y < 506 && y > 471) { ; /*promotion*/ }
				}

				if (menu_help == END) {
					if (x < 323 && x > 255 && y < 250 && y > 218) { setMenuAyuda(0); menu_help = H; }
				}

				if (menu_help == TEXT) {
					if (x < 323 && x > 255 && y < 250 && y > 218) { setMenuMovs(0); menu_help = MOVS; }
				}
			}
		}
	}
}

void Coordinador::dibuja()
{
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
		Jaque.draw();
		Jaque1.draw();
		JaqueMate.draw();
		JaqueMate1.draw();
	}

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

	if (estado == JUEGO) {

		if (estadojuego == TURNO)  { 
			tablero.dibuja();
		}

		if (estadojuego == PAUSA) {
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
			tablero.dibuja();
		}

		if (estadojuego == AYUDA) {
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
				}
			}

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

		if (estadojuego == JAQUE_MATE) {
			if (tipojuego == 0) {
				JaqueMate.draw();
			}
			if (tipojuego == 1) {
				JaqueMate1.draw();
			}
			tablero.dibuja();
		}
		
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
			tablero.dibuja();
		}

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

	if (estadojuego == JAQUE_MATE)
	{
		if (tipojuego == 0) {
			if (i < 47) {
				JaqueMate.setState(i);
				i++;
			}
			else if (i >= 47) {
				i = 0;
				estadojuego = TURNO;
			}
		}

		if (tipojuego == 1) {
			if (i < 47) {
				JaqueMate1.setState(i);
				i++;
			}
			else if (i >= 47) {
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

void Coordinador::setMenuPausa(int x)
{
	pause = x;
}

void Coordinador::setMenuAyuda(int x)
{
	help = x;
}

void Coordinador::setMenuMovs(int x)
{
	movs = x;
}

void Coordinador::setMenuMovsEspeciales(int x)
{
	specialmovs = x;
}

void Coordinador::setMenuMuchoTexto(int x)
{
	muchotexto = x;
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

