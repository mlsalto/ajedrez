#include "Reina.h"
#include "Tablero.h"
#include <math.h>

Reina::Reina() {}

Reina::Reina(char colorEquipo)
{
	color = colorEquipo;
	tipoPieza = 5;
}

void Reina::draw()
{
	if (Tablero::getTipoJuego() == true) {
		if (color == 'B')
		{
			ReinaB.setPos(pos.x, pos.y); //se debe poner siempre para que dibuje el sprite
			ReinaB.draw();
		}
		else if (color == 'N')
		{
			ReinaA.setPos(pos.x, pos.y);
			ReinaA.draw();
		}
	}
	if (Tablero::getTipoJuego() == false) {
		if (color == 'B')
		{
			ReinaR.setPos(pos.x, pos.y); 
			ReinaR.draw();
		}
		else if (color == 'N')
		{
			ReinaN.setPos(pos.x, pos.y);
			ReinaN.draw();
		}
	}
}

bool Reina::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row, coll;
	bool obstaculo = false;

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();


	//////////////**************    VERTICAL & HORIZONTAL    **************///////////

	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll < x_fin && row == y_fin)
	{
		for (i = coll + 1; i <= x_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true) {
				if (i == x_fin) 
				{
					if (Tablero::getCasillaT(i, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(i, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (coll > x_fin && row == y_fin)
	{
		for (i = coll - 1; i >= x_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true) 
			{
				if (i == x_fin) {
					if (Tablero::getCasillaT(i, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(i, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && row < y_fin)
	{
		for (i = row + 1; i <= y_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				if (i == y_fin) 
				{
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	/////////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > y_fin)
	{
		for (i = row - 1; i >= y_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				if (i == y_fin) {
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	//////////////**************     DIAGONAL     **************///////////

	if (abs(x_fin - coll) != abs(y_fin - row)) return false; //no es diagonal

	///////////       MOVIMIENTO DERECHA/ARRIBA     ///////////
	if (coll < x_fin && row < y_fin)
	{
		for (i = coll + 1, j = row + 1; i <= x_fin && j <= y_fin && !obstaculo; i++, j++)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) 
			{
				if (i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA/ARRIBA       ///////////
	if (coll > x_fin && row < y_fin)
	{
		for (i = coll - 1, j = row + 1; i >= x_fin && j <= y_fin && !obstaculo; i--, j++)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) 
			{
				if (i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO DERECHA/ABAJO       ///////////
	if (coll < x_fin && row > y_fin)
	{
		for (i = coll + 1, j = row - 1; i <= x_fin && j >= y_fin && !obstaculo; i++, j--)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) 
			{
				if (i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA/ABAJO      ///////////
	if (coll > x_fin && row > y_fin)
	{
		for (i = coll - 1, j = row - 1; i >= x_fin && j >= y_fin && !obstaculo; i--, j--)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) 
			{
				if (i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}
	else return false;
}