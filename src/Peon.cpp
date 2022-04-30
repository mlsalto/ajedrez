#include "Peon.h"
#include "Tablero.h"

Peon::Peon()
{
}

Peon::Peon(char colorEquipo)
{
	color = colorEquipo;
	tipoPieza = 1;
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
	////// DEFINICI�N DE VARIABLES DE AYUDA //////
	int i, j, row, coll;
	bool obstaculo = false;
	bool coronacion = false;

	////// FILA Y COLUMNA ACTUAL DE LA PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA QUE INTRODUCE EL USUARIO POR RAT�N //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha / izquierda en caso de haber una pieza negra
	if (color == 'B')
	{
		////// MOVIMIENTO 1: m�ximo 2 casillas hacia delante //////
		if (row == 1 && (y_fin == row + 1 || y_fin == row + 2) && x_fin == coll)
		{
			for (i = row + 1; i <= y_fin && !obstaculo; i++)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		if (y_fin == row + 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			else return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 �nico desplazamiento //////
		if (y_fin == row + 1 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
		{
			return true;
		}
		else return false;  // No se cumple ninguno de los movimientos legalesde los peones y por tanto, NO es un movimiento legal - la pieza no se	mueve -
	}

	//Los peones negros solo se mueven hacia abajo y diagonales de abaj derecha / izquierda
	else if (color == 'N')
	{
		////// MOVIMIENTO 1: m�ximo 2 casillas hacia delante //////
		if (row == 6 && (y_fin == row - 1 || y_fin == row - 2) && x_fin == coll)
		{
			//bucle para comprobar que el pe�n no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
			for (i = row - 1; i >= y_fin && !obstaculo; i--)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		if (y_fin == row - 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			else return true;
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 �nico desplazamiento //////
		if (y_fin == row - 1 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
		{
			return true;
		}

		else return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal
	}

	//////// CORONACI�N DEL PE�N ///////
	// Como el pe�n solo se mueve avanza hacia delante, y su casilla de inicio NO es la del final del tablero, se pueden hacer ambos colores a la vez:
	if ((y_fin == 0 || y_fin == 7) && (x_fin == coll || ((x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true)))
	{
		coronacion = true;
		return true;
	}
}
