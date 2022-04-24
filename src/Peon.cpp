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
	int i, j, row, coll;
	bool obstaculo = false;

	////// FILA Y COLUMNA ACTUAL DE LA PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA QUE INTRODUCE EL USUARIO POR RATÓN //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha/izquierda en caso de haber una pieza negra
	if (color == 'B')
	{
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 1 && (y_fin == row + 1 || y_fin <= row + 2) && x_fin == coll)
		{
			for (i = row + 1; i <= y_fin && !obstaculo; i++)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		else if (y_fin == row + 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		else if (y_fin == row + 1 && x_fin == coll + 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == true)
		{
			return true;
		}
		else if (y_fin == row + 1 && x_fin == coll - 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == true)
		{
			return true;
		}

		return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal -la pieza no se mueve-
	}

	//Los peones negros solo se mueven hacia abajo y diagonales de abajo derecha/izquierda
	if (color == 'N')
	{
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 6 && (y_fin == row - 1 || y_fin == row - 2) && x_fin == coll)
		{
			//bucle para comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
			for (i = row - 1; i >= y_fin && !obstaculo; i--)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		else if (y_fin == row - 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		else if (y_fin == row - 1 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true)
		{
			//el movimiento es legal si la casilla indicada por el usuario está en la 1º diagonal con la casilla donde se encuentra en ese momento el peón
			return true;
		}

		return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal
	}
}