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
	Pieza* piezaini;
	int posinix, posiniy;

	// copia tablero //
	Casilla* copia_tablero[8][8];
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			copia_tablero[i][j] = Tablero::getCasillaT(i, j);

	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	for (x_ini = 0; x_ini < 8; x_ini++)
			for (y_ini = 0; y_ini < 8; y_ini++) {
				if (Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color) { //color de la pieza es igual que la nuestra
					posinix = x_ini;
					posiniy = y_ini;
					piezaini = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

					for (x_fin = 0; x_fin < 8; x_fin++) //movimiento final en el tablero de la pieza que hemos encontrado
						for (y_fin = 0; y_fin < 8; y_fin++) {
							if (piezaini->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {
									//hacer una copia del tablero y realizar el movimiento
									//evaluamos los puntos obtenidos
									//lo comparamos los puntos obtenidos con lo máximos if(puntos > maximo) maximo = puntos;
									// guardamos los valores de la pieza que se mueve y a donde se mueve
							}
						}
				}
			}
	
}