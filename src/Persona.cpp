#include "Persona.h"
#include "Tablero.h"

Persona::Persona() {}

Persona::Persona(char colorJugador)
{
	color = colorJugador;
}

void Persona::draw(int x)
{
	// El modo de juego es queens gambit //
	if (Tablero::getTipoJuego() == TRUE)
	{
		if (x == 1) {
			if (color == 'B') player1.setPos(60, 15);
			if (color == 'N') player1.setPos(-60, 15);
			player1.draw();
		}

		if (x == 2) {
			if (color == 'B')player2.setPos(60, 15);
			if (color == 'N')player2.setPos(-60, 15);
			player2.draw();
		}

		if (x == 3) {
			if (color == 'B')player3.setPos(60, 15);
			if (color == 'N')player3.setPos(-60, 15);
			player3.draw();
		}

		if (x == 4) {
			if (color == 'B')player4.setPos(60, 15);
			if (color == 'N')player4.setPos(-60, 15);
			player4.draw();
		}
	}

	// El modo de juego es kings gambit //
	if (Tablero::getTipoJuego() == FALSE)
	{
		if (x == 1) {
			if (color == 'B') TB.setPos(60, 15);
			if (color == 'N') TB.setPos(-60, 15);
			TB.draw();
		}

		if (x == 2) {
			if (color == 'B') TC.setPos(60, 15);
			if (color == 'N') TC.setPos(-60, 15);
			TC.draw();
		}

		if (x == 3) {
			if (color == 'B') TH.setPos(60, 15);
			if (color == 'N') TH.setPos(-60, 15);
			TH.draw();
		}

		if (x == 4) {
			if (color == 'B') TJ.setPos(60, 15);
			if (color == 'N') TJ.setPos(-60, 15);
			TJ.draw();
		}

		if (x == 5) {
			if (color == 'B') TM.setPos(60, 15);
			if (color == 'N') TM.setPos(-60, 15);
			TM.draw();
		}

		if (x == 6) {
			if (color == 'B') TO.setPos(60, 15);
			if (color == 'N') TO.setPos(-60, 15);
			TO.draw();
		}

		if (x == 7) {
			if (color == 'B') TP.setPos(60, 15);
			if (color == 'N') TP.setPos(-60, 15);
			TP.draw();
		}

		if (x == 8) {
			if (color == 'B') TR.setPos(60, 15);
			if (color == 'N') TR.setPos(-60, 15);
			TR.draw();
		}

		if (x == 9) {
			if (color == 'B') TS.setPos(60, 15);
			if (color == 'N') TS.setPos(-60, 15);
			TS.draw();
		}
	}
}

void Persona::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int i, j;
	int x_cell, y_cell;
	int x_tablero, y_tablero;
	int coorx, coory;

	// cálculo de coordenadas del tablero //
	float ratioy = glutGet(GLUT_WINDOW_HEIGHT) * 1.0 / 768;
	float ratiox = (glutGet(GLUT_WINDOW_HEIGHT) * 1.7786) / 1366;

	float ratio = glutGet(GLUT_WINDOW_WIDTH) * 1.0 / glutGet(GLUT_WINDOW_HEIGHT);

	coorx =  x - (402 * ratiox) - (glutGet(GLUT_WINDOW_WIDTH) - (glutGet(GLUT_WINDOW_HEIGHT) * 1.7786)) / 2;
	coory =  y - (103 * ratioy);

	if (coorx < 0 || coory < 0) return; // tienen que ser coords pos

	x_cell = coorx / int(70 * ratioy);
	y_cell = coory / int(70 * ratioy);

	switch (y_cell)
	{
	case 0:
		y_tablero = 7;
		break;
	case 1:
		y_tablero = 6;
		break;
	case 2:
		y_tablero = 5;
		break;
	case 3:
		y_tablero = 4;
		break;
	case 4:
		y_tablero = 3;
		break;
	case 5:
		y_tablero = 2;
		break;
	case 6:
		y_tablero = 1;
		break;
	case 7:
		y_tablero = 0;
		break;
	default:
		y_tablero = 8;
		break;
	}

	switch (x_cell)
	{
	case 0:
		x_tablero = 0;
		break;
	case 1:
		x_tablero = 1;
		break;
	case 2:
		x_tablero = 2;
		break;
	case 3:
		x_tablero = 3;
		break;
	case 4:
		x_tablero = 4;
		break;
	case 5:
		x_tablero = 5;
		break;
	case 6:
		x_tablero = 6;
		break;
	case 7:
		x_tablero = 7;
		break;
	default:
		x_tablero = 8;
		break;
	}

	if (x_tablero == 8 || y_tablero == 8) return; // si se sale del tablero no hace nada

	////////////////// FUNCION DE SELECCIÓN PIEZAS DEL TABLERO ////////////////////////////

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (turnoterminado == FALSE) {
			
			// primero deshacemos la posibilidad del en passat
			
			if (posibilidad_passant == true)
			{
				EnPassant->setPassant(false);
				posibilidad_passant = false;
			}

			//AUN NO HAY PIEZA SELECCIONADA
			if (seleccionpieza == FALSE) {

				if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == color)
				{
					piezaini = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();
					posinix = x_tablero;	posiniy = y_tablero;

					seleccionpieza = TRUE;
					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);

					// dibujar casillas legales
					if (Tablero::detectar_jaque(color) == true && piezaini->getTipoPieza() == 6)
					{
						piezaini->setPrimerMovimiento(true);
					}

					for (i = 0 ; i < 8; i++ )
						for (j = 0; j < 8; j++) {
							if (piezaini->movimientoLegal(Tablero::getCasillaT(i, j)) == TRUE)
							{
								if(Tablero::getCasillaOcupada(i,j)== true && Tablero::getCasillaT(i,j)->getPieza()->getColorPieza() != color)Tablero::getCasillaT(i, j)->setTipoCasilla(3);
								else Tablero::getCasillaT(i, j)->setTipoCasilla(2);
							}
						}
				}
			}

			//HAY PIEZA SELECCIONADA
			else if (seleccionpieza == TRUE) {

				////////    SELECCIÓN NUEVA PIEZA BLANCA   ////////
				if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == color)
				{

					// codigo que habia antes
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) { Tablero::getCasillaT(i, j)->setTipoCasilla(0); }

					piezaini = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();
					posinix = x_tablero;	posiniy = y_tablero;

					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);

					if (Tablero::detectar_jaque(color) == true && piezaini->getTipoPieza() == 6)
					{
						piezaini->setPrimerMovimiento(true);
					}

					// dibujar casillas legales
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) {
							if (piezaini->movimientoLegal(Tablero::getCasillaT(i, j)) == TRUE)
							{
								if (Tablero::getCasillaOcupada(i, j) == true && Tablero::getCasillaT(i, j)->getPieza()->getColorPieza() != color)Tablero::getCasillaT(i, j)->setTipoCasilla(3);
								else Tablero::getCasillaT(i, j)->setTipoCasilla(2);
							}
						}

				}

				//////// COMER PIEZA NEGRA //////////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() != color && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
					piezafin = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();
					Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini); //colocar pieza seleccionada
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

					if (Tablero::detectar_jaque(color) == true)// si jaque es cierto
					{
						Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
						Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezafin);
						//deshacemos los cambios y salimos de la función
					}

					else if (Tablero::detectar_jaque(color) == false)
					{
						Tablero::eliminarPieza(piezafin); //elimina pieza

						// mira si es el primer movimiento de la torre o rey
						if ((piezaini->getTipoPieza() == 2 || piezaini->getTipoPieza() == 6 || piezaini->getTipoPieza() == 1) && piezaini->getPrimerMovimiento() == false)
						{
							piezaini->setPrimerMovimiento(true);
						}

						if (piezaini->getTipoPieza() == 1)
						{
							piezaini->setPassant(false);
						}
							

						// dibujar casillas legales
						for (i = 0; i < 8; i++)
							for (j = 0; j < 8; j++) {
								Tablero::getCasillaT(i, j)->setTipoCasilla(0);
							}

						seleccionpieza = FALSE;
						turnoterminado = TRUE;
					}
				}

				//////// HACER ENROQUE ///
                else if (Tablero::detectar_jaque(color) == FALSE &&	Tablero::getTipoPiezasT(posinix, posiniy) == 6 && (x_tablero == 6 || x_tablero == 2) && piezaini->getPrimerMovimiento() == false && ( Tablero::getTipoPiezasT(7, posiniy) == 2 || Tablero::getTipoPiezasT(0, posiniy) == 2) && (Tablero::getCasillaT(7, posiniy)->getPieza()->getPrimerMovimiento() == false || Tablero::getCasillaT(0, posiniy)->getPieza()->getPrimerMovimiento() == false )&& piezaini->getEnroque() == false && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{

					if (color == 'N')
					{
						if (x_tablero == 6) // derecha
						{
							piezafin = Tablero::getCasillaT(7, 7)->getPieza(); // torre
							Tablero::getCasillaT(7, 7)->colocarPieza(0);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(5, 7)->colocarPieza(piezafin);
						}

						else if (x_tablero == 2) // izquierda
						{
							piezafin = Tablero::getCasillaT(0, 7)->getPieza(); // torre
							Tablero::getCasillaT(0, 7)->colocarPieza(0);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(3, 7)->colocarPieza(piezafin);
						}
					}

					else if (color == 'B')
					{
						if (x_tablero == 6) // derecha
						{
							piezafin = Tablero::getCasillaT(7, 0)->getPieza(); // torre
							Tablero::getCasillaT(7, 0)->colocarPieza(0);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(5, 0)->colocarPieza(piezafin);
						}

						else if (x_tablero == 2) // izquierda
						{
							piezafin = Tablero::getCasillaT(0, 0)->getPieza(); // torre
							Tablero::getCasillaT(0, 0)->colocarPieza(0);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(3, 0)->colocarPieza(piezafin);
						}
					}

					if (Tablero::detectar_jaque(color) == TRUE)// si jaque es cierto
					{
						//deshacer enroque
						if (color == 'N')
						{
							if (x_tablero == 6) // derecha
							{
								Tablero::getCasillaT(7, 7)->colocarPieza(piezafin);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(5, 7)->colocarPieza(0);
							}

							else if (x_tablero == 2) // izquierda
							{
								Tablero::getCasillaT(0, 7)->colocarPieza(piezafin);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(3, 7)->colocarPieza(0);
							}
						}

						else if (color == 'B')
						{
							if (x_tablero == 6) // derecha
							{
								Tablero::getCasillaT(7, 0)->colocarPieza(piezafin);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(5, 0)->colocarPieza(0);
							}

							else if (x_tablero == 2) // izquierda
							{
								Tablero::getCasillaT(0, 0)->colocarPieza(piezafin);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(3, 0)->colocarPieza(0);
							}
						}
					}

					if (Tablero::detectar_jaque(color) == FALSE)
					{
						piezaini->setEnroque(true);

						for (i = 0; i < 8; i++)
							for (j = 0; j < 8; j++) {
								Tablero::getCasillaT(i, j)->setTipoCasilla(0);
							}

						seleccionpieza = FALSE;
						turnoterminado = TRUE;
					}
					
			    }

				//////// HACER PASsANT ////////
				// passant pieza blanca
				else if (color == 'B' && Tablero::getTipoPiezasT(posinix, posiniy) == 1 && Tablero::getPiezasT(posinix, posiniy)->getColorPieza() == 'B' && Tablero::getTipoPiezasT(x_tablero, y_tablero) == 0 && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE && y_tablero == posiniy + 1 && y_tablero == 5 && (x_tablero == posinix + 1 || x_tablero == posinix - 1) && Tablero::getTipoPiezasT(x_tablero, y_tablero - 1) == 1 && Tablero::getCasillaT(x_tablero, y_tablero - 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_tablero, y_tablero - 1)->getPieza()->getPassant() == true)
				{
				            piezafin = Tablero::getCasillaT(x_tablero, y_tablero - 1)->getPieza();
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero - 1)->colocarPieza(0);

							if (Tablero::detectar_jaque(color) == true)// si jaque es cierto
							{
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero - 1)->colocarPieza(piezafin);
							}

							else if (Tablero::detectar_jaque(color) == false)
							{
								Tablero::eliminarPieza(piezafin);

								// dibujar casillas legales
								for (i = 0; i < 8; i++)
									for (j = 0; j < 8; j++) {
										Tablero::getCasillaT(i, j)->setTipoCasilla(0);
									}

								seleccionpieza = FALSE;
								turnoterminado = TRUE;
							}
			
				}

				// passant pieza negra
				else if (color == 'N' && Tablero::getTipoPiezasT(posinix, posiniy) == 1 && Tablero::getPiezasT(posinix, posiniy)->getColorPieza() == 'N' && Tablero::getTipoPiezasT(x_tablero, y_tablero) == 0 && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE && y_tablero == posiniy - 1 && y_tablero == 2 && (x_tablero == posinix + 1 || x_tablero == posinix - 1) && Tablero::getTipoPiezasT(x_tablero, y_tablero + 1) == 1 && Tablero::getCasillaT(x_tablero, y_tablero + 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_tablero, y_tablero + 1)->getPieza()->getPassant() == true)
				{
							piezafin = Tablero::getCasillaT(x_tablero, y_tablero + 1)->getPieza();
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
							Tablero::getCasillaT(x_tablero, y_tablero + 1)->colocarPieza(0);
					
							if (Tablero::detectar_jaque(color) == true)// si jaque es cierto
							{
								Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
								Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								Tablero::getCasillaT(x_tablero, y_tablero + 1)->colocarPieza(piezafin);
							}

							else if (Tablero::detectar_jaque(color) == false)
							{
								Tablero::eliminarPieza(piezafin);

								// dibujar casillas legales
								for (i = 0; i < 8; i++)
									for (j = 0; j < 8; j++) {
										Tablero::getCasillaT(i, j)->setTipoCasilla(0);
									}

								seleccionpieza = FALSE;
								turnoterminado = TRUE;
							}
                }

				//////// MOVER A CASILLA VACÍA ///////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() == 0 && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
	
						Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
						Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

						if (Tablero::detectar_jaque(color) == true)// si jaque es cierto
						{
							Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
							Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(0);
							//deshacemos los cambios y salimos de la función
						}

						else if (Tablero::detectar_jaque(color) == false)
						{
							
							// mira si es el primer movimiento del peón
							if ((piezaini->getTipoPieza() == 1))
							{
								if (color == 'N')
								{
									if (y_tablero == 4 && posiniy == 6 && piezaini->getPrimerMovimiento() == false) { piezaini->setPassant(true); EnPassant = piezaini; posibilidad_passant = TRUE; }
									else piezaini->setPassant(false);
								}
								if (color == 'B')
								{
									if (y_tablero == 3 && posiniy == 1 && piezaini->getPrimerMovimiento() == false) { piezaini->setPassant(true); EnPassant = piezaini; posibilidad_passant = TRUE; }
									else piezaini->setPassant(false);
								}
							}

							// mira si es el primer movimiento de la torre o rey o peon
							if ((piezaini->getTipoPieza() == 2 || piezaini->getTipoPieza() == 6 || piezaini->getTipoPieza() == 1) && piezaini->getPrimerMovimiento() == false)
							{
								piezaini->setPrimerMovimiento(true);
							}

							// dibujar casillas legales
							for (i = 0; i < 8; i++)
								for (j = 0; j < 8; j++) {
									Tablero::getCasillaT(i, j)->setTipoCasilla(0);
								}

							seleccionpieza = FALSE;
							turnoterminado = TRUE;
						}
				}
			}
		}	
	}
}


