#include "IA3.h"
#include "Tablero.h"


IA3::IA3() {}

IA3::IA3(char colorJugador)
{
	color = colorJugador;
}

void IA3::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	puntosn = 0;
	puntosb = 0;
	int puntos = 0;
	/*int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;*/

	int i, j;
	minimo = -9999;
	maximo = -9999;
	

	//********************** DECISI�N DEL PR�XIMO MOVIMIENTO DE LA IA  ********************//
	
	// evaluacion max 
	// para cada movimiento posible del jugador sobre "tablero"
	for (x_ini = 0; x_ini < 8; x_ini++)
	{
		for (y_ini = 0; y_ini < 8; y_ini++)
		{
			// buscar una pieza para mover ( similar a seleccionar de persona )
			if (Tablero::getCasillaT(x_ini, y_ini)->getOcupada() == TRUE && Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color)
			{
				pieza = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

				// mover la pieza en copia tablero2
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						// se puede realizar el movimiento
						if (pieza->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {
							 
							// realizamos el movimiento
							// si se come alguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) != 0 && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
							{
								piezacomida = Tablero::getPiezasT(x_fin, y_fin);
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									tipomovimiento = 0;
									movimientocontrario(); // hacer  movimiento del jugador contrario7
								}
								// deshacemos el movimiento

								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si hace enroque
							else if (Tablero::getTipoPiezasT(x_ini, y_ini) == 6 && (x_fin == 6 || x_fin == 2) && pieza->getPrimerMovimiento() == false && (Tablero::getTipoPiezasT(7, y_ini) == 2 || Tablero::getTipoPiezasT(0, y_ini) == 2) && (Tablero::getCasillaT(7, y_ini)->getPieza()->getPrimerMovimiento() == false || Tablero::getCasillaT(0, y_ini)->getPieza()->getPrimerMovimiento() == false) && piezaini->getEnroque() == false)
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

								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									tipomovimiento = 1;
									movimientocontrario();// hacer  movimiento del jugador contrario
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

							if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
							{
								tipomovimiento = 2;
								movimientocontrario(); // hacer  movimiento del jugador contrario
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

							if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
							{
								tipomovimiento = 2;
								movimientocontrario(); // hacer  movimiento del jugador contrario
							}
							// deshacer en passant
							Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
							Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(piezacomida);
							Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si no come ninguna pieza
							else if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
							{
							 // copia del tablero y realizar el movimiento si se mueve a una casilla vac�a
							 Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
							 Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

							 if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
							 {
								 tipomovimiento = 3;
								 movimientocontrario(); // hacer  movimiento del jugador contrario
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


	// una vez encontrado el mejor movimiento, lo hacemos

	// ****************   REALIZACI�N DEL MOVIMIENTO DESPU�S DE DECIDIR QUE ES LO QUE QUIERE HACER   *****************//

		// si mueve a una casilla ocupada
		if (tipomovf == 0)
		{
			piezaini = Tablero::getCasillaT(posinix, posiniy)->getPieza();
			piezafin = Tablero::getCasillaT(posfinx, posfiny)->getPieza();
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

			turnoterminado = TRUE;
			return;
		}

		// si hace enroque
		else if (tipomovf == 1)
		{
			piezaini = Tablero::getCasillaT(posinix, posiniy)->getPieza();

			if (color == 'N')
			{
				if (posfinx == 6) // derecha
				{
					piezafin = Tablero::getCasillaT(7, 7)->getPieza();
					Tablero::getCasillaT(7, 7)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(5, 7)->colocarPieza(piezafin);
				}

				if (posfinx == 2) // izquierda
				{
					piezafin = Tablero::getCasillaT(0, 7)->getPieza();
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
					piezafin = Tablero::getCasillaT(7, 0)->getPieza();
					Tablero::getCasillaT(7, 0)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(5, 0)->colocarPieza(piezafin);
				}

				if (posfinx == 2) // izquierda
				{
					piezafin = Tablero::getCasillaT(0, 0)->getPieza();
					Tablero::getCasillaT(0, 0)->colocarPieza(0);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
					Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
					Tablero::getCasillaT(3, 0)->colocarPieza(piezafin);
				}
			}

			piezaini->setEnroque(true);
			turnoterminado = TRUE;
			return;
		}

		// si hace en passant
		else if (tipomovf == 2)
		{
			piezaini = Tablero::getCasillaT(posinix, posiniy)->getPieza();

			if (color == 'N')
			{
				piezafin = Tablero::getCasillaT(posfinx, posfiny + 1)->getPieza();
				Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
				Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
				Tablero::getCasillaT(posfinx, posfiny + 1)->colocarPieza(0);
				Tablero::eliminarPieza(piezafin); //elimina pieza
			}

			if (color == 'B')
			{
				piezafin = Tablero::getCasillaT(posfinx, posfiny - 1)->getPieza();
				Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
				Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
				Tablero::getCasillaT(posfinx, posfiny - 1)->colocarPieza(0);
				Tablero::eliminarPieza(piezafin); //elimina pieza
			}
			turnoterminado = TRUE;
			return;
		}

		// si mueve a una casilla vacia
		else if (tipomovf == 3)
		{
			piezaini = Tablero::getCasillaT(posinix, posiniy)->getPieza();
			Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
			Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

			// mira si es el primer movimiento de la torre o rey
			if ((piezaini->getTipoPieza() == 2 || piezaini->getTipoPieza() == 6) && piezaini->getPrimerMovimiento() == false)
			{
				piezaini->setPrimerMovimiento(true);
			}

			// mira si es el primer movimiento del pe�n
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
			turnoterminado = TRUE;
			return;
		}
}

void IA3::movimientocontrario()
{
	// evaluacion min
	int x_ini2 = 0, y_ini2 = 0, x_fin2 = 0, y_fin2 = 0;
	int i, j;

	// buscamos pieza del color contrario

	for (x_ini2 = 0; x_ini2 < 8; x_ini2++)
	{
		for (y_ini2 = 0; y_ini2 < 8; y_ini2++)
		{
			// buscar una pieza para mover ( similar a seleccionar de persona )
			if (Tablero::getCasillaT(x_ini2, y_ini2)->getOcupada() == TRUE && Tablero::getCasillaT(x_ini2, y_ini2)->getPieza()->getColorPieza() != color)
			{
				pieza2 = Tablero::getCasillaT(x_ini2, y_ini2)->getPieza();

				// mover la pieza en copia tablero3
				for (x_fin2 = 0; x_fin2 < 8; x_fin2++)
				{
					for (y_fin2 = 0; y_fin2 < 8; y_fin2++) {

						// se puede realizar el movimiento
						if (pieza2->movimientoLegal(Tablero::getCasillaT(x_fin2, y_fin2)) == TRUE) {

							//// realizamos el movimiento
							//// si se come alguna pieza
							if (Tablero::getTipoPiezasT(x_fin2, y_fin2) != 0 && Tablero::getCasillaT(x_fin2, y_fin2)->getPieza()->getColorPieza() == color)
							{
								piezacomida2 = Tablero::getPiezasT(x_fin2, y_fin2);
								Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
								Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);

								puntosn = getPuntos('N');
								puntosb = getPuntos('B');

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = puntosn - puntosb; puntospropios = puntosb - puntosn;
								if (color == 'N') puntoscontrario = puntosb - puntosn; puntospropios = puntosn - puntosb;

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									// hemos encontrado el mejor movimiento
									minimo = puntoscontrario;

									// comprobamos si el movimiento es mejor o no
									if (puntospropios >= maximo) {
										maximo = puntospropios; 
										// guardamos datos del movimiento
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										tipomovf = tipomovimiento;
									}
								}

								// DESHACEMOS CAMBIOS
								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(piezacomida2);
								Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
							}

							// si hace enroque
							else if (Tablero::getTipoPiezasT(x_ini2, y_ini2) == 6 && (x_fin2 == 6 || x_fin2 == 2) && pieza2->getPrimerMovimiento() == false && (Tablero::getTipoPiezasT(7, y_ini2) == 2 || Tablero::getTipoPiezasT(0, y_ini2) == 2) && (Tablero::getCasillaT(7, y_ini2)->getPieza()->getPrimerMovimiento() == false || Tablero::getCasillaT(0, y_ini2)->getPieza()->getPrimerMovimiento() == false) && pieza2->getEnroque() == false)
							{
								// hacer enroque
								if (color != 'N')
								{
									if (x_fin2 == 6) // derecha
									{
										piezamovida2 = Tablero::getCasillaT(7, 7)->getPieza(); // torre
										Tablero::getCasillaT(7, 7)->colocarPieza(0);
										Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
										Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
										Tablero::getCasillaT(5, 7)->colocarPieza(piezamovida2);
									}

									if (x_fin2 == 2) // izquierda
									{
										piezamovida2 = Tablero::getCasillaT(0, 7)->getPieza(); // torre
										Tablero::getCasillaT(0, 7)->colocarPieza(0);
										Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
										Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
										Tablero::getCasillaT(3, 7)->colocarPieza(piezamovida2);
									}
								}

								if (color != 'B')
								{
									if (x_fin2 == 6) // derecha
									{
										piezamovida2 = Tablero::getCasillaT(7, 0)->getPieza(); // torre
										Tablero::getCasillaT(7, 0)->colocarPieza(0);
										Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
										Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
										Tablero::getCasillaT(5, 0)->colocarPieza(piezamovida2);
									}

									if (x_fin2 == 2) // izquierda
									{
										piezamovida2 = Tablero::getCasillaT(0, 0)->getPieza(); // torre
										Tablero::getCasillaT(0, 0)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza2);
										Tablero::getCasillaT(3, 0)->colocarPieza(piezamovida2);
									}
								}

								puntosn = getPuntos('N');
								puntosb = getPuntos('B');

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = puntosn - puntosb;
								if (color == 'N') puntoscontrario = puntosb - puntosn;

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									// hemos encontrado el mejor movimiento
									minimo = puntoscontrario;

									// vemos como es la situaci�n de nuestras piezas
									if (color == 'N') puntospropios = puntosn - puntosb;
									if (color == 'B') puntospropios = puntosb - puntosn;

									// comprobamos si el movimiento es mejor o no
									if (puntospropios >= maximo) {
										maximo = puntospropios;
										// guardamos datos del movimiento
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										tipomovf = tipomovimiento;
									}

									// deshacer enroque
									if (color != 'N')
									{
										if (x_fin2 == 6) // derecha
										{
											Tablero::getCasillaT(7, 7)->colocarPieza(piezamovida2);
											Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
											Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
											Tablero::getCasillaT(5, 7)->colocarPieza(0);
										}

										if (x_fin2 == 2) // izquierda
										{
											Tablero::getCasillaT(0, 7)->colocarPieza(piezamovida2);
											Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
											Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
											Tablero::getCasillaT(3, 7)->colocarPieza(0);
										}
									}

									if (color != 'B')
									{
										if (x_fin2 == 6) // derecha
										{
											Tablero::getCasillaT(7, 0)->colocarPieza(piezamovida2);
											Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
											Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
											Tablero::getCasillaT(5, 0)->colocarPieza(0);
										}

										if (x_fin2 == 2) // izquierda
										{
											Tablero::getCasillaT(0, 0)->colocarPieza(piezamovida2);
											Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
											Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
											Tablero::getCasillaT(3, 0)->colocarPieza(0);
										}
									}
								}
							}

							//// si hace en passant
							else if (color != 'B' && Tablero::getTipoPiezasT(x_ini2, y_ini2) == 1 && Tablero::getTipoPiezasT(x_fin2, y_fin2) == 0 && y_fin2 == y_ini2 + 1 && y_fin2 == 5 && (x_fin2 == x_ini2 + 1 || x_fin2 == x_ini2 - 1) && Tablero::getTipoPiezasT(x_fin2, y_fin2 - 1) == 1 && Tablero::getCasillaT(x_fin2, y_fin2 - 1)->getPieza()->getColorPieza() == color && Tablero::getCasillaT(x_fin2, y_fin2 - 1)->getPieza()->getPassant() == true)
							{
							 //hace en passant
							piezacomida2 = Tablero::getCasillaT(x_fin2, y_fin2 - 1)->getPieza();
							Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
							Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
							Tablero::getCasillaT(x_fin2, y_fin2 - 1)->colocarPieza(0);

							puntosn = getPuntos('N');
							puntosb = getPuntos('B');

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = puntosn - puntosb;
								if (color == 'N') puntoscontrario = puntosb - puntosn;

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									// hemos encontrado el mejor movimiento
									minimo = puntoscontrario;

									// vemos como es la situaci�n de nuestras piezas
									if (color == 'N') puntospropios = puntosn - puntosb;
									if (color == 'B') puntospropios = puntosb - puntosn;

									// comprobamos si el movimiento es mejor o no
									if (puntospropios >= maximo) {
										maximo = puntospropios;
										// guardamos datos del movimiento
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										tipomovf = tipomovimiento;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
								Tablero::getCasillaT(x_fin2, y_fin2 - 1)->colocarPieza(piezacomida2);
								Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
							}

							else if (color != 'N' && Tablero::getTipoPiezasT(x_ini2, y_ini2) == 1 && Tablero::getTipoPiezasT(x_fin2, y_fin2) == 0 && y_fin2 == y_ini2 - 1 && y_fin2 == 2 && (x_fin2 == x_ini2 + 1 || x_fin2 == x_ini2 - 1) && Tablero::getTipoPiezasT(x_fin2, y_fin2 + 1) == 1 && Tablero::getCasillaT(x_fin2, y_fin2 + 1)->getPieza()->getColorPieza() == color && Tablero::getCasillaT(x_fin2, y_fin2 + 1)->getPieza()->getPassant() == true)
							{

							// hace en passant
							piezacomida2 = Tablero::getCasillaT(x_fin2, y_fin2 + 1)->getPieza();
							Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
							Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
							Tablero::getCasillaT(x_fin2, y_fin2 + 1)->colocarPieza(0);

							puntosn = getPuntos('N');
							puntosb = getPuntos('B');
								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = puntosn - puntosb;
								if (color == 'N') puntoscontrario = puntosb - puntosn;

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									// hemos encontrado el mejor movimiento
									minimo = puntoscontrario;

									// vemos como es la situaci�n de nuestras piezas
									if (color == 'N') puntospropios = puntosn - puntosb;
									if (color == 'B') puntospropios = puntosb - puntosn;

									// comprobamos si el movimiento es mejor o no
									if (puntospropios >= maximo) {
										maximo = puntospropios;
										// guardamos datos del movimiento
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										tipomovf = tipomovimiento;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
								Tablero::getCasillaT(x_fin2, y_fin2 + 1)->colocarPieza(piezacomida2);
								Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
							}

							// si no come ninguna pieza
							else if (Tablero::getTipoPiezasT(x_fin2, y_fin2) == 0)
							{
							// copia del tablero y realizar el movimiento si se mueve a una casilla vac�a
							Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(pieza2);
							Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(0);
								
						
							puntosn = getPuntos('N');
							puntosb = getPuntos('B');
							
							// mirar puntos negros y blancos
							if (color == 'B') puntoscontrario = puntosn - puntosb;
							if (color == 'N') puntoscontrario = puntosb - puntosn;

							// mirar si es mejor el movimiento o no
							if (puntoscontrario >= minimo) {
								// hemos encontrado el mejor movimiento
								minimo = puntoscontrario;

								// vemos como es la situaci�n de nuestras piezas
								if (color == 'N') puntospropios = puntosn - puntosb;
								if (color == 'B') puntospropios = puntosb - puntosn;

								// comprobamos si el movimiento es mejor o no
								if (puntospropios >= maximo) {
									maximo = puntospropios;
									// guardamos datos del movimiento
									posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
									posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
									tipomovf = tipomovimiento;
								}
							}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin2, y_fin2)->colocarPieza(0);
								Tablero::getCasillaT(x_ini2, y_ini2)->colocarPieza(pieza2);
							}
						}
					}
				}
			}
		}
	}
}