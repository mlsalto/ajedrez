#include "IA3.h"
#include "Tablero.h"

Casilla* IA3::tablero2[8][8];
Casilla* IA3::tablero3[8][8];

IA3::IA3() {}

IA3::IA3(char colorJugador)
{
	color = colorJugador;
}

void IA3::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	int puntos = 0;
	int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;
	int i, j;
	

	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	
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

				// hacer copia del tablero sobre tablero2
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						tablero2[i][j] = Tablero::getCasillaT(i, j); // copia tablero en tablero2
					}
				}

				// mover la pieza en copia tablero2
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						// se puede realizar el movimiento
						if (pieza->movimientoLegal(tablero2[x_fin][y_fin]) == TRUE) {
							 
							// realizamos el movimiento
							// si se come alguna pieza
							if (tablero2[x_fin][y_fin]->getTipoPieza() != 0 && tablero2[x_fin][y_fin]->getPieza()->getColorPieza() != color)
							{
								piezacomida = tablero2[x_fin][y_fin]->getPieza();
								tablero2[x_fin][y_fin]->colocarPieza(pieza);
								tablero2[x_ini][y_ini]->colocarPieza(0);

								movimientocontrario(); // hacer  movimiento del jugador contrario

								// calculamos si a nosotros nos viene bien

								tipomovimiento = 0;
							}

							// si hace enroque
							else if (tablero2[x_ini][y_ini]->getTipoPieza() == 6 && (x_fin == 6 || x_fin == 2) && pieza->getPrimerMovimiento() == false && (tablero2[7][y_ini]->getTipoPieza() == 2 || tablero2[0][y_ini]->getTipoPieza() == 2) && (tablero2[7][y_ini]->getPieza()->getPrimerMovimiento() == false || tablero2[0][y_ini]->getPieza()->getPrimerMovimiento() == false) && piezaini->getEnroque() == false)
							{
								// hacer enroque
								if (color == 'N')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = tablero2[7][7]->getPieza(); // torre
										tablero2[7][7]->colocarPieza(0);
										tablero2[x_ini][y_ini]->colocarPieza(0);
										tablero2[x_fin][y_fin]->colocarPieza(pieza);
										tablero2[5][7]->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = tablero2[0][7]->getPieza(); // torre
										tablero2[0][7]->colocarPieza(0);
										tablero2[x_ini][y_ini]->colocarPieza(0);
										tablero2[x_fin][y_fin]->colocarPieza(pieza);
										tablero2[3][7]->colocarPieza(piezamovida);
									}
								}

								if (color == 'B')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = tablero2[7][0]->getPieza(); // torre
										tablero2[7][0]->colocarPieza(0);
										tablero2[x_ini][y_ini]->colocarPieza(0);
										tablero2[x_fin][y_fin]->colocarPieza(pieza);
										tablero2[5][0]->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = tablero2[0][0]->getPieza(); // torre
										tablero2[0][0]->colocarPieza(0);
										tablero2[x_ini][y_ini]->colocarPieza(0);
										tablero2[x_fin][y_fin]->colocarPieza(pieza);
										tablero2[3][0]->colocarPieza(piezamovida);
									}
								}

								movimientocontrario(); // hacer  movimiento del jugador contrario

								tipomovimiento = 1;
							}

							// si hace en passant
							else if (color == 'B' && tablero2[x_ini][y_ini]->getTipoPieza() == 1 && tablero2[x_fin][y_fin]->getTipoPieza() == 0 && y_fin == y_ini + 1 && y_fin == 5 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && tablero2[x_fin][y_fin - 1]->getTipoPieza() == 1 && tablero2[x_fin][y_fin - 1]->getPieza()->getColorPieza() != color && tablero2[x_fin][y_fin - 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = tablero2[x_fin][y_fin - 1]->getPieza();
								tablero2[x_fin][y_fin]->colocarPieza(pieza);
								tablero2[x_ini][y_ini]->colocarPieza(0);
								tablero2[x_fin][y_fin - 1]->colocarPieza(0);

								movimientocontrario();// hacer  movimiento del jugador contrario

								tipomovimiento = 2;

							}

							else if (color == 'N' && tablero2[x_ini][y_ini]->getTipoPieza() == 1 && tablero2[x_fin][y_fin]->getTipoPieza() == 0 && y_fin == y_ini - 1 && y_fin == 2 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && tablero2[x_fin][y_fin + 1]->getTipoPieza() == 1 && tablero2[x_fin][y_fin + 1]->getPieza()->getColorPieza() != color && tablero2[x_fin][y_fin + 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = tablero2[x_fin][y_fin + 1]->getPieza();
								tablero2[x_fin][y_fin]->colocarPieza(pieza);
								tablero2[x_ini][y_ini]->colocarPieza(0);
								tablero2[x_fin][y_fin + 1]->colocarPieza(0);

								movimientocontrario();// hacer  movimiento del jugador contrario

								tipomovimiento = 2;

							}

							// si no come ninguna pieza
							else if (tablero2[x_fin][y_fin]->getTipoPieza() == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
								tablero2[x_fin][y_fin]->colocarPieza(pieza);
								tablero2[x_ini][y_ini]->colocarPieza(0);

								movimientocontrario(); // hacer  movimiento del jugador contrario

								tipomovimiento = 3;
							}
						}
					}
				}
			}
		}
	}
}

void IA3::movimientocontrario()
{
	// evaluacion min
	int x_ini, y_ini, x_fin, y_fin;
	int i, j;

	// buscamos pieza del color contrario

	for (x_ini = 0; x_ini < 8; x_ini++)
	{
		for (y_ini = 0; y_ini < 8; y_ini++)
		{
			// buscar una pieza para mover ( similar a seleccionar de persona )
			if (tablero2[x_ini][y_ini]->getOcupada() == TRUE && tablero2[x_ini][y_ini]->getPieza()->getColorPieza() != color)
			{
				pieza = tablero2[x_ini][y_ini]->getPieza();

				// hacer copia del tablero2 sobre tablero3
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						tablero3[i][j] = tablero2[i][j]; // copia tablero en tablero2
					}
				}

				// mover la pieza en copia tablero3
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						// se puede realizar el movimiento
						if (pieza->movimientoLegal(tablero3[x_fin][y_fin]) == TRUE) {

							// realizamos el movimiento
							// si se come alguna pieza
							if (tablero3[x_fin][y_fin]->getTipoPieza() != 0 && tablero3[x_fin][y_fin]->getPieza()->getColorPieza() == color)
							{
								piezacomida = tablero3[x_fin][y_fin]->getPieza();
								tablero3[x_fin][y_fin]->colocarPieza(pieza);
								tablero3[x_ini][y_ini]->colocarPieza(0);


								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = getPuntos('N') - getPuntos('B');
								if (color == 'N') puntoscontrario = getPuntos('B') - getPuntos('N');

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									minimo = puntoscontrario;
								}
							}

							// si hace enroque
							else if (tablero3[x_ini][y_ini]->getTipoPieza() == 6 && (x_fin == 6 || x_fin == 2) && pieza->getPrimerMovimiento() == false && (tablero3[7][y_ini]->getTipoPieza() == 2 || tablero3[0][y_ini]->getTipoPieza() == 2) && (tablero3[7][y_ini]->getPieza()->getPrimerMovimiento() == false || tablero3[0][y_ini]->getPieza()->getPrimerMovimiento() == false) && piezaini->getEnroque() == false)
							{
								// hacer enroque
								if (!color == 'N')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = tablero3[7][7]->getPieza(); // torre
										tablero3[7][7]->colocarPieza(0);
										tablero3[x_ini][y_ini]->colocarPieza(0);
										tablero3[x_fin][y_fin]->colocarPieza(pieza);
										tablero3[5][7]->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = tablero3[0][7]->getPieza(); // torre
										tablero3[0][7]->colocarPieza(0);
										tablero3[x_ini][y_ini]->colocarPieza(0);
										tablero3[x_fin][y_fin]->colocarPieza(pieza);
										tablero3[3][7]->colocarPieza(piezamovida);
									}
								}

								if (!color == 'B')
								{
									if (x_fin == 6) // derecha
									{
										piezamovida = tablero3[7][0]->getPieza(); // torre
										tablero3[7][0]->colocarPieza(0);
										tablero3[x_ini][y_ini]->colocarPieza(0);
										tablero3[x_fin][y_fin]->colocarPieza(pieza);
										tablero3[5][0]->colocarPieza(piezamovida);
									}

									if (x_fin == 2) // izquierda
									{
										piezamovida = tablero3[0][0]->getPieza(); // torre
										tablero3[0][0]->colocarPieza(0);
										tablero3[x_ini][y_ini]->colocarPieza(0);
										tablero3[x_fin][y_fin]->colocarPieza(pieza);
										tablero3[3][0]->colocarPieza(piezamovida);
									}
								}

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = getPuntos('N') - getPuntos('B');
								if (color == 'N') puntoscontrario = getPuntos('B') - getPuntos('N');

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									minimo = puntoscontrario;
								}
							}

							// si hace en passant
							else if (!color == 'B' && tablero3[x_ini][y_ini]->getTipoPieza() == 1 && tablero3[x_fin][y_fin]->getTipoPieza() == 0 && y_fin == y_ini + 1 && y_fin == 5 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && tablero3[x_fin][y_fin - 1]->getTipoPieza() == 1 && tablero3[x_fin][y_fin - 1]->getPieza()->getColorPieza() != color && tablero3[x_fin][y_fin - 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = tablero3[x_fin][y_fin - 1]->getPieza();
								tablero3[x_fin][y_fin]->colocarPieza(pieza);
								tablero3[x_ini][y_ini]->colocarPieza(0);
								tablero3[x_fin][y_fin - 1]->colocarPieza(0);

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = getPuntos('N') - getPuntos('B');
								if (color == 'N') puntoscontrario = getPuntos('B') - getPuntos('N');

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									minimo = puntoscontrario;
								}
							}

							else if (!color == 'N' && tablero3[x_ini][y_ini]->getTipoPieza() == 1 && tablero3[x_fin][y_fin]->getTipoPieza() == 0 && y_fin == y_ini - 1 && y_fin == 2 && (x_fin == x_ini + 1 || x_fin == x_ini - 1) && tablero3[x_fin][y_fin + 1]->getTipoPieza() == 1 && tablero3[x_fin][y_fin + 1]->getPieza()->getColorPieza() != color && tablero3[x_fin][y_fin + 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								piezacomida = tablero3[x_fin][y_fin + 1]->getPieza();
								tablero3[x_fin][y_fin]->colocarPieza(pieza);
								tablero3[x_ini][y_ini]->colocarPieza(0);
								tablero3[x_fin][y_fin + 1]->colocarPieza(0);

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = getPuntos('N') - getPuntos('B');
								if (color == 'N') puntoscontrario = getPuntos('B') - getPuntos('N');

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									minimo = puntoscontrario;
								}
							}

							// si no come ninguna pieza
							else if (tablero3[x_fin][y_fin]->getTipoPieza() == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
								tablero3[x_fin][y_fin]->colocarPieza(pieza);
								tablero3[x_ini][y_ini]->colocarPieza(0);

								// mirar puntos negros y blancos
								if (color == 'B') puntoscontrario = getPuntos('N') - getPuntos('B');
								if (color == 'N') puntoscontrario = getPuntos('B') - getPuntos('N');

								// mirar si es mejor el movimiento o no
								if (puntoscontrario >= minimo) {
									minimo = puntoscontrario;
								}
							}
						}
					}
				}
			}
		}
	}
}