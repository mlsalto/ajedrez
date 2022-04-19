#include "Jugador.h"


Jugador::Jugador(char colorJugador)
{
	color = colorJugador;
}

bool Jugador::movimientoRealizado()
{
	/// hay que poner funcion que realice movimiento
	return true;
}

int Jugador::puntos() //cuenta los puntos sobre el tablero del jugador
{
	int i, j;
	Pieza* p;
	int puntos_pieza, tipoPieza = 0; // según el tipo de pieza que sea
	bool color_pieza;
	bool movimiento_legal;
	// HAY QUE PONERLO EN FUNCIÓN DEL COLOR //




	//************************* LECTURA DE PUNTOS SOBRE EL TABLERO  *********************//
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			tipoPieza = Tablero::getTipoPiezasT(i, j); // hay que hacer la funcion con get tipo

			//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

			switch (tipoPieza)
			{
			case 0: //no pieza
				break;

			case 1: //peon
				puntos_totales = puntos_totales + 100;
				//if(a)
				break;

			case 2: //torre
				puntos_totales = puntos_totales + 500;
				break;

			case 3: //alfil
				puntos_totales = puntos_totales + 330;
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
	return puntos_totales;
}

