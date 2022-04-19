#include "Jugador.h"


////// PRUEBAS PARA REALIZACIÓN DE UNA IA SENCILLA ////////

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



int Jugador::funcionIA()
{
	int i, j;
	Pieza* p;
	int puntos_pieza, tipoPieza = 0; // según el tipo de pieza que sea
	int puntos_totales = 0; //inicializa los puntos totales
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


	// ESTO DEBE SER UNA FUNCIÓN APARTE
	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (color_pieza == 0) { //color de la pieza es igual que la nuestra

				for (i = 0; i < 8; i++) //movimiento final en el tablero de la pieza que hemos encontrado
					for (j = 0; j < 8; j++) {
						if (/* movimiento es legal a i,j*/ movimiento_legal == true) {
							//hacer una copia del tablero y realizar el movimiento
							//evaluamos los puntos obtenidos
							//lo comparamos los puntos obtenidos con lo máximos if(puntos > maximo) maximo = puntos;
							// guardamos los valores de la pieza que se mueve y a donde se mueve
						}
					}
			}
		}
}