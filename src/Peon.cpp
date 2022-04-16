#include "Peon.h"
#include "Tablero.h"

Peon::Peon()
{
}

Peon::Peon(char colorEquipo)
{
	color = colorEquipo;
}

void Peon::draw()
{
	if (color == 'B') {
		PeonB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		PeonB.draw();
	}
	else if (color == 'N') {
		PeonN.setPos(pos.x, pos.y);
		PeonN.draw();
	}
}

bool Peon::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	Tablero tablero;
	int i, j, row, coll;
	Casilla* copia_casillas[8][8];
	bool obstaculo = false;

	////// COPIA DEL TABLERO //////
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			copia_casillas[i][j] = tablero.getCasillaT(i, j);

	////// FILA Y COLUMNA ACTUAL DE LA PIEZA //////
	row = (pos.x + 28) / 8;
	coll = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA QUE INTRODUCE EL USUARIO//////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	switch (color)
	{
		// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha/izquierda en caso de haber una pieza negra
	case 'B':
		if (coll == 1)
		{
			////// PRIMER MOVIMIENTO A ESCOGER ENTRE 1-2 CASILLAS HACIA ARRIBA //////
			if (y_fin <= coll + 2)
			{
				// Si hay una pieza en la casilla donde se quiere desplazar y no hay nada
				if (copia_casillas[row][y_fin]->getOcupada() == false) {
					obstaculo = true;
					return false;
				}
				return true;
			}
		}
		else
		{
			////// RESTO DE MOVIMIENTOS 1 CASILLA HACIA ARRIBA /////
			if (y_fin = coll + 1)
			{
				// Si hay una pieza en la casilla donde se quiere desplazar y no hay nada
				if (copia_casillas[row][y_fin]->getOcupada() == false) {
					obstaculo = true;
					return false;
				}
				return true;
			}
		}

		////// MOVIMIENTO DIAGONAL ARRIBA (IZQUIERDA Y DERECHA) - 1 CASILLA /////
		if ((y_fin = (coll + 1)) && ((x_fin = (row + 1)) || (x_fin = (row - 1))))
		{
			if (copia_casillas[x_fin][y_fin]->getOcupada() == false) { //No sé cómo hacer para que no se coman entre sí las piezas blancas :v
				obstaculo = true;
				return false;
			}
			return true;
		}
		break;
	//Los peones negros solo se mueven hacia abajo y diagonales de abajo derecha/izquierda
	case 'N':
		if (y_fin == 6)
		{
			////// PRIMER MOVIMIENTO A ESCOGER ENTRE 1-2 CASILLAS HACIA ARRIBA //////
			if (y_fin <= coll - 2)
			{
				// Si hay una pieza en la casilla donde se quiere desplazar y no hay nada
				if (copia_casillas[row][y_fin]->getOcupada() == false) {
					obstaculo = true;
					return false;
				}
				return true;
			}
		}
		else
		{
			////// RESTO DE MOVIMIENTOS 1 CASILLA HACIA ARRIBA /////
			if (y_fin = coll - 1)
			{
				// Si hay una pieza en la casilla donde se quiere desplazar y no hay nada
				if (copia_casillas[row][y_fin]->getOcupada() == false) {
					obstaculo = true;
					return false;
				}
				return true;
			}
		}

		////// MOVIMIENTO DIAGONAL ARRIBA (IZQUIERDA Y DERECHA) - 1 CASILLA /////
		if ((y_fin = (coll - 1)) && ((x_fin = (row + 1)) || (row = (row - 1))))
		{
			if (copia_casillas[x_fin][y_fin]->getOcupada() == false) { //No sé cómo hacer para que no se coman entre sí las piezas blancas :v
				obstaculo = true;
				return false;
			}
			return true;
		}
		break;
	}

	return false;
}
