#include "IA.h"
#include "Tablero.h"

IA::IA() {}

IA::IA(char colorJugador)
{
	color = colorJugador;
}


void IA::moverPieza(int button, int state, int x, int y)
{
	int i, j;
	int x_ini, x_fin, y_ini, y_fin;
	int a, b;
	int puntos;
	Pieza* piezaini; // pieza que movemos
	Pieza* piezafin; // pieza que comemos
	int posfinx, posfiny;
	int posinix, posiniy;
	int maximo = 0;


	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	for (x_ini = 0; x_ini < 8; x_ini++)
			for (y_ini = 0; y_ini < 8; y_ini++) {

				// encontrar pieza para mover
				if (Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color) { //color de la pieza es igual que la nuestra
					posinix = x_ini;
					posiniy = y_ini;
					piezaini = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

					// mover la pieza encontrada
					for (x_fin = 0; x_fin < 8; x_fin++) 
						for (y_fin = 0; y_fin < 8; y_fin++) {
							
							// se puede realizar el movimiento
							if (piezaini->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {

								// si no come ninguna pieza
								if (Tablero::getTipoPiezasT(x_fin, y_fin) != 0)
								{
									// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
									Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezaini);
									Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

									// puntos obtenidos
									for (a = 0; a < 8; a++)
										for (b = 0; b < 8; b++) {
											puntos = getPuntos(color);

											if (puntos > maximo) {
												piezafin = piezaini; //guardamos valor pieza
												posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
												posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
												maximo = puntos;
											}
										}

									// deshacemos el movimiento
									Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
									Tablero::getCasillaT(posinix, posiniy)->colocarPieza(piezaini);
								}

								// si se come alguna pieza
								if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
								{
									// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
									Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezaini);
									Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

									// puntos obtenidos

									for (a = 0; a < 8; a++)
										for (b = 0; b < 8; b++) {
											puntos = getPuntos(color);

											if (puntos > maximo) {
												piezafin = piezaini; //guardamos valor pieza
												 // guardar valor posicion inicio pieza
												 // guardar valor posicion final pieza
												maximo = puntos;
											}
										}
									// deshacemos el movimiento
								}
							}
						}
				}
			}
}