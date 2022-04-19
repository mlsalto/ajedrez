#include "Reina.h"
#include "Tablero.h"

Reina::Reina() 
{
	tipoPieza = 5;
}

Reina::Reina(char colorEquipo)
{
	color = colorEquipo;
}

void Reina::draw()
{
	if (color == 'B') 
	{
		ReinaB.setPos(pos.x, pos.y); //se debe poner siempre para que dibuje el sprite
		ReinaB.draw();
	}
	else if (color == 'N')
	{
		ReinaN.setPos(pos.x, pos.y);
		ReinaN.draw();
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
	if (coll < 7 && row == y_fin)
	{
		for (i = coll + 1; i <= x_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (coll > 0 && row == y_fin)
	{
		for (i = coll - 1; i >= x_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && row < 7)
	{
		for (i = row + 1; i <= y_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(x_fin,i) == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > 0)
	{
		for (i = row - 1; i >= y_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}



	//////////////**************    DIAGONAL?    **************///////////
	
	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll < 7 && row == y_fin)
	{
		for (i = coll + 1; i <= x_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == false)
			{
				obstaculo = true;
				return false;
			}
		}
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (coll > 0 && row == y_fin)
	{
		for (i = coll - 1; i >= x_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == false)
			{
				obstaculo = true;
				return false;
			}
		}
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && row < 7)
	{
		for (i = row + 1; i <= y_fin && !obstaculo; i++)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == false)
			{
				obstaculo = true;
				return false;
			}
		}
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > 0)
	{
		for (i = row - 1; i >= y_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == false)
			{
				obstaculo = true;
				return false;
			}
		}
	}

	return true;
}