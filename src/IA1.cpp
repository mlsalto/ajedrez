#include "IA1.h"
#include "Tablero.h"

IA1::IA1() {}

IA1::IA1(char colorJugador)
{
	color = colorJugador;
}


void IA1::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	int puntos = 0;
	int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;
	int maximo = 0;

	
		//********************** DECISI�N DEL PR�XIMO MOVIMIENTO DE LA IA  ********************//
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

						/// HAY QUE HACER VARIAS COSAS ///

						// si no come ninguna pieza //
						// si come alguna pieza //
						// si en passant blanco //
						// si en passant negro //
						// si coronacion //
						// si haces enroque //
						// quizas hacer int que sea TIPOMOVIMIENTO, as� despues se pone un if al final y es m�s facil
						
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
									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 0;
									}
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si hace enroque
							else if (Tablero::getTipoPiezasT(x_ini, y_ini) == 6 && (x_fin == 6 || x_fin == 2) && pieza->getPrimerMovimiento() == false && Tablero::getTipoPiezasT(x_fin, y_ini) == 2 && Tablero::getCasillaT(x_fin, y_ini)->getPieza()->getPrimerMovimiento() == false && piezaini->getEnroque() == false)
							{
								// hacer enroque
								if (color == 'N')
								{
									if (x_fin == 6) // derecha
									{
										piezafin = Tablero::getCasillaT(7, 7)->getPieza(); // torre
										Tablero::getCasillaT(7, 7)->colocarPieza(0);
										Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);
										Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
										Tablero::getCasillaT(5, 7)->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezafin = Tablero::getCasillaT(0, 7)->getPieza(); // torre
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
									puntos = getPuntos(color);

									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezamovida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 1;
									}
								}

								// deshacer enroque
							}

							// si hace en passant
							else if (color == 'B' && Tablero::getTipoPiezasT(x_ini, y_ini) == 1 && Tablero::getTipoPiezasT(x_fin, y_fin) == 0 && y_fin == y_ini + 1 && y_fin == 5 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && Tablero::getTipoPiezasT(x_fin, y_fin - 1) == 1 && Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza()->getPassant() == true)
							{
								// hace en passant
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								piezacomida = Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza();
								//Tablero::eliminarPieza(Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza());
								Tablero::getCasillaT(x_fin, y_fin - 1)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									puntos = getPuntos(color);

									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 2;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin, y_fin - 1)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							else if (color == 'N' && Tablero::getTipoPiezasT(x_ini, y_ini) == 1 && Tablero::getTipoPiezasT(x_fin, y_fin) == 0  && y_fin == y_ini - 1 && y_fin == 2 && (x_fin == x_ini + 1 || x_fin== x_ini - 1) && Tablero::getTipoPiezasT(x_fin, y_fin + 1) == 1 && Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza()->getColorPieza() != color && Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza()->getPassant() == true)
							{
								// hace en passant
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								piezacomida = Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza();
								//Tablero::eliminarPieza(Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza());
								Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									puntos = getPuntos(color);

									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
										tipomovimiento = 2;
									}
								}

								// deshacer en passant
								Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si no come ninguna pieza
							else if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vac�a
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								// calcular puntos
								if (Tablero::detectar_jaque(color) == FALSE) 
								{
									puntos = getPuntos(color);

									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
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

		// ****************   REALIZACI�N DEL MOVIMIENTO DESPU�S DE DECIDIR QUE ES LO QUE QUIERE HACER   *****************//


		// si mueve a una casilla ocupada
		if (tipomovimiento == 0 )
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
		else if (tipomovimiento == 3 )
		{
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
		}

		turnoterminado = TRUE;
}