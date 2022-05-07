#include "Jugador.h"
#include "Tablero.h"

Jugador::Jugador(){}

Jugador::Jugador(char colorJugador)
{
	color = colorJugador;
}

////////// PARA LOS PUNTOS DE CADA PERSONA /////////
/* Valores matemáticos para la evaluación de la función

 peon.
   - Por cada peon +100 puntos
   - Por cada peon en el centro del tablero +12 puntos
   - Por cada casilla que un peon avanza +2 puntos

 caballo.
   - Por cada caballo +315 puntos
   - Si está cerca o lejos del centro del tablero +-0-15 puntos

 alfil.
   - Por cada alfil +330 puntos
   - Añadir un punto por cada casilla a la que se pueda mover el alfil

 torre.
   - Por cada torre +500 puntos
   - Añadir un punto por cada casilla a la que se pueda mover la torre

 dama.
   - Por cada dama +940 puntos
   - Si está cerca o lejos del centro del tablero +-0-10 puntos

*/

void Jugador::draw(int x){}


int Jugador::getPuntos(char colorJugador)
{
	int i, j;
	int puntos_totales = 0;
	int tipoPieza = 0; // según el tipo de pieza que sea
	char colorPieza;
	// HAY QUE PONERLO EN FUNCIÓN DEL COLOR //


	//************************* LECTURA DE PUNTOS SOBRE EL TABLERO  *********************//
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (Tablero::getCasillaOcupada(i, j) == true) // si encuentra pieza
			{
				tipoPieza = Tablero::getCasillaT(i, j)->getTipoPieza(); // hay que hacer la funcion con get tipo
				colorPieza = Tablero::getCasillaT(i, j)->getPieza()->getColorPieza();

				//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

				if (color = colorJugador) {

					switch (tipoPieza)
					{
					case 0: //no pieza
						break;

					case 1: //peon
						puntos_totales = puntos_totales + 100;

						// si esta en el centro del tablero + 12 puntos
						if (j == 3 && i == 3 || j == 3 && i == 4 || j == 4 && i == 3 || j == 4 && i == 4) {
							puntos_totales = puntos_totales + 12;
						}

						// por cada casilla que avanza + 2 puntos
						if (color == 'B') {
							int x;
							x = j - 1;
							puntos_totales = puntos_totales + x * 2;
						}

						if (color == 'N') {
							int x;
							x = 6 - j;
							puntos_totales = puntos_totales + x * 2;
						}
						break;

					case 2: //torre
						puntos_totales = puntos_totales + 500;

						// por cada casilla a la que se pueda mover + 1 puntos
						int a, b;
						for (a = 0; a < 8; a++)
							for (b = 0; b < 8; b++)
								if (Tablero::getCasillaT(i, j)->getPieza()->movimientoLegal(Tablero::getCasillaT(a, b)) == true) {
									puntos_totales = puntos_totales + 1;
								}

						break;

					case 3: //alfil
						puntos_totales = puntos_totales + 330;

						// por cada casilla a la que se pueda mover + 1 puntos
						//int a, b;
						for (a = 0; a < 8; a++)
							for (b = 0; b < 8; b++)
								if (Tablero::getCasillaT(i, j)->getPieza()->movimientoLegal(Tablero::getCasillaT(a, b)) == true) {
									puntos_totales = puntos_totales + 1;
								}

						break;

					case 4: //caballo
						puntos_totales = puntos_totales + 315;
						break;

					case 5: //reina
						puntos_totales = puntos_totales + 940;
						break;

					case 6: //rey
						break;
					}
				}
			}
		}

	return puntos_totales;
}

void Jugador::moverPieza(int button, int state, int x, int y){}

bool Jugador::turnoTerminado()
{
	return turnoterminado;
}