#include "IA.h"

IA::IA() {

}

IA::IA(char colorJugador)
{
	color = colorJugador;
}

bool IA::movimientoRealizado()
{
	//movimientos realizados seg�n la mec�nica de la IA
	return true;
}


////// PRUEBAS PARA REALIZACI�N DE UNA IA SENCILLA ////////

/* Valores matem�ticos para la evaluaci�n de la funci�n

 peon.
   - Por cada peon +100 puntos
   - Por cada peon en el centro del tablero +12 puntos
   - Por cada casilla que un peon avanza +2 puntos

 caballo.
   - Por cada caballo +315 puntos
   - Si est� cerca o lejos del centro del tablero +-0-15 puntos

 alfil.
   - Por cada alfil +330 puntos
   - A�adir un punto por cada casilla a la que se pueda mover el alfil

 torre.
   - Por cada torre +500 puntos
   - A�adir un punto por cada casilla a la que se pueda mover la torre

 dama.
   - Por cada dama +940 puntos
   - Si est� cerca o lejos del centro del tablero +-0-10 puntos

*/



int IA::funcionIA()
{
	int i, j;
	Pieza* p;
	int puntos_pieza, tipoPieza = 0; // seg�n el tipo de pieza que sea
	int puntos_totales = 0; //inicializa los puntos totales
	bool color_pieza = 0;
	bool movimiento_legal = 0;
	// HAY QUE PONERLO EN FUNCI�N DEL COLOR //

	// ESTO DEBE SER UNA FUNCI�N APARTE
	//********************** DECISI�N DEL PR�XIMO MOVIMIENTO DE LA IA  ********************//

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (color_pieza == 0) { //color de la pieza es igual que la nuestra

				for (i = 0; i < 8; i++) //movimiento final en el tablero de la pieza que hemos encontrado
					for (j = 0; j < 8; j++) {
						if (/* movimiento es legal a i,j*/ movimiento_legal == true) {
							//hacer una copia del tablero y realizar el movimiento
							//evaluamos los puntos obtenidos
							//lo comparamos los puntos obtenidos con lo m�ximos if(puntos > maximo) maximo = puntos;
							// guardamos los valores de la pieza que se mueve y a donde se mueve
						}
					}
			}
		}

	return 0;
}