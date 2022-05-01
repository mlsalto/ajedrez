#include "Rey.h"
#include "Tablero.h"
#include <math.h>

Rey::Rey(){}

Rey::Rey(char colorEquipo) 
{
	color = colorEquipo;
	tipoPieza = 6;
}

void Rey::draw() {
	if (color == 'B')
	{
		ReyB.setPos(pos.x, pos.y);
		ReyB.draw();
	}
	else if (color == 'N')
	{
		ReyN.setPos(pos.x, pos.y);
		ReyN.draw();
	}
}

bool Rey::movimientoLegal(Casilla* fin) {
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row, coll;
	bool obstaculo = false;

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	///////////       MOVIMIENTO DERECHA      ///////////
	if (x_fin == coll+1 && y_fin==row && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
			return true;
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (x_fin==coll-1 && y_fin == row && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
			return true;
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && y_fin == row + 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
			return true;
	}


	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && y_fin == row-1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
			return true;
	}

	//////////************DIAOGONALES************//////////
	///////////       MOVIMIENTO ARRIBA&DERECHA     ///////////
	if (x_fin==coll+1 && y_fin==row+1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
		return true;
	}

	///////////       MOVIMIENTO ARRIBA&IZQUIERDA     ///////////
	if (x_fin == coll - 1 && y_fin == row + 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
		return true;
	}
	
	///////////       MOVIMIENTO ABAJO&DERECHA     ///////////
	if (x_fin == coll + 1 && y_fin == row - 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
		return true;
	}

	///////////       MOVIMIENTO ABAJO&IZQUIERDA     ///////////
	if (x_fin == coll - 1 && y_fin == row - 1 && Tablero::getCasillaOcupada(x_fin, y_fin) == false)
	{
		return true;
	}
	//ENROQUES
//////////// Enroques rey/torre negros ///////
//enroque corto (a la derecha)
	if (Tablero::getTipoPiezasT(7, 7) == 2 && Tablero::getTipoPiezasT(4, 7) == 6 && Tablero::getCasillaT(7, 7)->getPieza()->getColorPieza() == color)
	{
		for (i = coll + 1; i <= x_fin - 1 && Tablero::getCasillaOcupada(i, y_fin) == false; i++)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
			{
				return false;
			}
			return true;
		}
	}
	//enroque largo (a la izquierda)
	if (Tablero::getTipoPiezasT(0, 7) == 2 && Tablero::getTipoPiezasT(4, 7) == 6 && Tablero::getCasillaT(0, 7)->getPieza()->getColorPieza() == color)
	{
		for (i = coll - 1; i <= x_fin + 1 && Tablero::getCasillaOcupada(i, y_fin) == false; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
			{
				return false;
			}
			return true;
		}
	}

	//////////// Enroques rey/torre blancos ///////
	//enroque corto
	if (Tablero::getTipoPiezasT(7, 0) == 2 && Tablero::getTipoPiezasT(4, 0) == 6 && Tablero::getCasillaT(7, 0)->getPieza()->getColorPieza() == color)
	{
		for (i = coll + 1; i <= x_fin - 1 && Tablero::getCasillaOcupada(i, y_fin) == false; i++)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
			{
				return false;
			}
			return true;
		}
	}
	//enroque largo (a la izquierda)
	if (Tablero::getTipoPiezasT(0, 0) == 2 && Tablero::getTipoPiezasT(4, 0) == 6 && Tablero::getCasillaT(0, 0)->getPieza()->getColorPieza() == color)
	{
		for (i = coll - 1; i <= x_fin + 1 && Tablero::getCasillaOcupada(i, y_fin) == false; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true)
			{
				return false;
			}
			return true;
		}
	}
	else {
		return false;
	}
}
 



