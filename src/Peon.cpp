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
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA QUE INTRODUCE EL USUARIO//////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha/izquierda en caso de haber una pieza negra
	if (color == 'B')
	{		
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 1 && y_fin == row + 2 && x_fin == coll)
		{
			// Bucle para que el programa compruebe que el peón no se salta ninguna pieza
			for (i = row + 1; y_fin <= row + 2 && obstaculo == false; i++)
			{
				// En caso de que la casilla esté ocupada, el movimiento NO es legal				
				if (Tablero::getCasillaOcupada(i, y_fin) == true) {
					obstaculo = true; // Para que el bucle no se siga ejecutando
					return false;
				}
				
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		else if (y_fin == row + 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
				return false;
			return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		else if (y_fin == row + 1 && x_fin == coll + 1)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
				return false;
			return true;
		}
		else if (y_fin == row + 1 && x_fin == coll - 1)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
				return false;
			return true;
		}

		return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal
	}

	//Los peones negros solo se mueven hacia abajo y diagonales de abajo derecha/izquierda
	if (color == 'N')
	{
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 6 && y_fin == row - 2 && x_fin == coll)
		{
			return true;
			// Bucle para que el programa compruebe que el peón no se salta ninguna pieza
			/*
			for (i=row+1; y_fin <= row + 2 && obstaculo==false;i++)
			{
				// En caso de que la casilla esté ocupada, el movimiento NO es legal
				if (copia_casillas[i][y_fin]->getOcupada() == true) {
					obstaculo = true;
					return false;
				}

			}
			*/
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		else if (y_fin == row - 1 && x_fin == coll)
		{
			return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		else if (y_fin == row - 1 && x_fin == coll + 1)
		{
			return true;
		}
		else if (y_fin == row - 1 && x_fin == coll - 1)
		{
			return true;
		}


		return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal
	}
}
