#include "IA2.h"
#include "Tablero.h"
#include <ctime>
#include <time.h>

IA2::IA2() {}

IA2::IA2(char colorJugador)
{
	color = colorJugador;
}

void IA2::draw(int x)
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
	}
}

void IA2::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	movimientoposible = FALSE;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	int puntos = 0;
	int puntosn = 0, puntosb = 0;
	int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;
	int maximo = -9999;
	
	// temporizador para que tarde un rato en hacer el movimiento
	unsigned tiempo_ini, tiempo_fin;
	double tiempopasado = 0;
	tiempo_ini = clock();

	do
	{
		tiempo_fin = clock();
		tiempopasado = (double(tiempo_fin - tiempo_ini)/ CLOCKS_PER_SEC);
	} while (tiempopasado < 3);

	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	for (x_ini = 0; x_ini < 8; x_ini++)
	{
		for (y_ini = 0; y_ini < 8; y_ini++)
		{	
			// buscar una pieza para mover ( similar a seleccionar de persona )
			if (Tablero::getCasillaT(x_ini, y_ini)->getOcupada() == TRUE && Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color)
			{
				pieza = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

				// mover la pieza encontrada (similar a la pieza ya seleccionada de pieza)
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						// se puede realizar el movimiento
						if (pieza->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {

							// si se come alguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) != 0 && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
							{
								piezacomida = Tablero::getPiezasT(x_fin, y_fin);
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									// mirar puntos negros y blancos
									puntosn = getPuntos('N');
									puntosb = getPuntos('B');

									if (color == 'N') puntos = puntosn - puntosb;
									if (color == 'B') puntos = puntosb - puntosn;

									// mirar si es mejor el movimiento o no
									if (puntos >= maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 0;
										movimientoposible = TRUE;
									}
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si hace enroque
							else if (Tablero::getTipoPiezasT(x_ini, y_ini) == 6 && (x_fin == 6 || x_fin == 2) && pieza->getPrimerMovimiento() == false && (Tablero::getTipoPiezasT(7, y_ini) == 2 || Tablero::getTipoPiezasT(0, y_ini) == 2) && (Tablero::getCasillaT(7, y_ini)->getPieza()->getPrimerMovimiento() == false || Tablero::getCasillaT(0, y_ini)->getPieza()->getPrimerMovimiento() == false) && pieza->getEnroque() == false)
							{
								// hacer enroque
								if (color == 'N')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = Tablero::getCasillaT(7, 7)->getPieza(); // torre
										Tablero::getCasillaT(7, 7)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
										Tablero::getCasillaT(5, 7)->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = Tablero::getCasillaT(0, 7)->getPieza(); // torre
										Tablero::getCasillaT(0, 7)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
										Tablero::getCasillaT(3, 7)->colocarPieza(piezamovida);
									}
								}

								if (color == 'B')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = Tablero::getCasillaT(7, 0)->getPieza(); // torre
										Tablero::getCasillaT(7, 0)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
										Tablero::getCasillaT(5, 0)->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = Tablero::getCasillaT(0, 0)->getPieza(); // torre
										Tablero::getCasillaT(0, 0)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
										Tablero::getCasillaT(3, 0)->colocarPieza(piezamovida);
									}
								}

								// comprobar puntos
								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									// mirar puntos negros y blancos
									puntosn = getPuntos('N');
									puntosb = getPuntos('B');

									if (color == 'N') puntos = puntosn - puntosb;
									if (color == 'B') puntos = puntosb - puntosn;

									// mirar si es mejor el movimiento o no
									if (puntos >= maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezamovida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 1;
										movimientoposible = TRUE;
									}
								}

								// deshacer enroque
								if (color == 'N')
								{
									if (x_fin == 6) // derecha
									{
										Tablero::getCasillaT(7, 7)->colocarPieza(piezamovida);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
										Tablero::getCasillaT(5, 7)->colocarPieza(0);
									}

									if (x_fin == 2) // izquierda
									{
										Tablero::getCasillaT(0, 7)->colocarPieza(piezamovida);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
										Tablero::getCasillaT(3, 7)->colocarPieza(0);
									}
								}

								if (color == 'B')
								{
									if (x_fin == 6) // derecha
									{
										Tablero::getCasillaT(7, 0)->colocarPieza(piezamovida);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
										Tablero::getCasillaT(5, 0)->colocarPieza(0);
									}

									if (x_fin == 2) // izquierda
									{
										Tablero::getCasillaT(0, 0)->colocarPieza(piezamovida);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
										Tablero::getCasillaT(3, 0)->colocarPieza(0);
									}
								}
							}

							// si hace en passant
							else if (color == 'B' && Tablero::getTipoPiezasT(x_ini, y_ini) == 1 && Tablero::getTipoPiezasT(x_fin, y_fin) == 0 && y_fin == y_ini + 1 && y_fin == 5 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && Tablero::getTipoPiezasT(x_fin, y_fin - 1) == 1 && Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza();
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
								Tablero::getCasillaT(x_fin, y_fin - 1)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									// mirar puntos negros y blancos
									puntosn = getPuntos('N');
									puntosb = getPuntos('B');

									if (color == 'N') puntos = puntosn - puntosb;
									if (color == 'B') puntos = puntosb - puntosn;

									// mirar si es mejor el movimiento o no
									if (puntos >= maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 2;
										movimientoposible = TRUE;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
								Tablero::getCasillaT(x_fin, y_fin - 1)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							else if (color == 'N' && Tablero::getTipoPiezasT(x_ini, y_ini) == 1 && Tablero::getTipoPiezasT(x_fin, y_fin) == 0 && y_fin == y_ini - 1 && y_fin == 2 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && Tablero::getTipoPiezasT(x_fin, y_fin + 1) == 1 && Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza();
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
								Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									// mirar puntos negros y blancos
									puntosn = getPuntos('N');
									puntosb = getPuntos('B');

									if (color == 'N') puntos = puntosn - puntosb;
									if (color == 'B') puntos = puntosb - puntosn;

									// mirar si es mejor el movimiento o no
									if (puntos >= maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 2;
										movimientoposible = TRUE;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
								Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si no come ninguna pieza
							else if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE)
								{
									// mirar puntos negros y blancos
									puntosn = getPuntos('N');
									puntosb = getPuntos('B');

									if (color == 'N') puntos = puntosn - puntosb;
									if (color == 'B') puntos = puntosb - puntosn;

									// mirar si es mejor el movimiento o no
									if (puntos >= maximo) {
										piezaini = pieza; //guardamos valor pieza
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 3;
										movimientoposible = TRUE;
									}
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}
						}
					}
				}
			}
		}
	}

	// ****************   REALIZACIÓN DEL MOVIMIENTO DESPUÉS DE DECIDIR QUE ES LO QUE QUIERE HACER   *****************//

	if (movimientoposible == TRUE)
	{
		// si mueve a una casilla ocupada
		if (tipomovimiento == 0)
		{
			Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
			Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
			Tablero::eliminarPieza(piezafin); //elimina pieza

			// mira si es el primer movimiento de la torre o rey
			if ((piezaini->getTipoPieza() == 2 || piezaini->getTipoPieza() == 6) && piezaini->getPrimerMovimiento() == false)
			{
				piezaini->setPrimerMovimiento(true);
			}

			if (piezaini->getTipoPieza() == 1)
			{
				piezaini->setPassant(false);
			}
		}

		// si hace enroque
		else if (tipomovimiento == 1)
		{
			if (color == 'N')
			{
				if (posfinx == 6) // derecha
				{
					Tablero::getCasillaT(7, 7)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(5, 7)->colocarPieza(piezafin);
				}

				if (posfinx == 2) // izquierda
				{
					Tablero::getCasillaT(0, 7)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(3, 7)->colocarPieza(piezafin);
				}
			}

			if (color == 'B')
			{
				if (posfinx == 6) // derecha
				{
					Tablero::getCasillaT(7, 0)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(5, 0)->colocarPieza(piezafin);
				}

				if (posfinx == 2) // izquierda
				{
					Tablero::getCasillaT(0, 0)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(3, 0)->colocarPieza(piezafin);
				}
			}

			piezaini->setEnroque(true);
		}

		// si hace en passant
		else if (tipomovimiento == 2)
		{
			if (color == 'N')
			{
				Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
				Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
				Tablero::getCasillaT(posfinx, posfiny + 1)->colocarPieza(0);
				Tablero::eliminarPieza(piezafin); //elimina pieza
			}

			if (color == 'B')
			{
				Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
				Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
				Tablero::getCasillaT(posfinx, posfiny - 1)->colocarPieza(0);
				Tablero::eliminarPieza(piezafin); //elimina pieza
			}
		}

		// si mueve a una casilla vacia
		else if (tipomovimiento == 3)
		{
			Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
			Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

			// mira si es el primer movimiento de la torre o rey
			if ((piezaini->getTipoPieza() == 2 || piezaini->getTipoPieza() == 6) && piezaini->getPrimerMovimiento() == false)
			{
				piezaini->setPrimerMovimiento(true);
			}

			// mira si es el primer movimiento del peón
			if ((piezaini->getTipoPieza() == 1))
			{
				if (color == 'N')
				{
					if (posfiny == 4 && posiniy == 6) piezaini->setPassant(true);
					else piezaini->setPassant(false);
				}
				if (color == 'B')
				{
					if (posfiny == 3 && posiniy == 1) piezaini->setPassant(true);
					else piezaini->setPassant(false);
				}
			}
		}
	}
	turnoterminado = TRUE;
}

