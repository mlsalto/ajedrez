#include "Rey.h"
#include "Tablero.h"

Rey::Rey()
{
	tipoPieza = 6;
}

Rey::Rey(char colorEquipo) {
	color = colorEquipo;
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
	Tablero tablero;
	int i, j, row, coll;
	Casilla* copia_casillas[8][8];
	bool obstaculo = false;

	////// COPIA DEL TABLERO //////
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			copia_casillas[i][j] = tablero.getCasillaT(i, j);

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll < 7 && row == y_fin)
	{
		for (i = coll + 1; i <= coll + 2 && !obstaculo; i++)
		{
			if (copia_casillas[i][y_fin]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (coll > 0 && row == y_fin)
	{
		for (i = coll - 1; i >= coll - 2 && !obstaculo; i--)
		{
			if (copia_casillas[i][y_fin]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && row < 7)
	{
		for (i = row + 1; i <= row + 2 && !obstaculo; i++)
		{
			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > 0)
	{
		for (i = row - 1; i >= row - 2 && !obstaculo; i--)
		{
			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	//////////************DIAOGONALES************//////////
	///////////       MOVIMIENTO ARRIBA&DERECHA     ///////////
	if (coll < 7 && row < 7)
	{
		for (i = row + 1, j = coll + 1; i <= row + 2 && j <= coll + 2 && !obstaculo; i++, j++)
		{

			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ARRIBA&IZQUIERDA     ///////////
	if (coll < 7 && row > 0)
	{
		for (i = row - 1, j = coll + 1; i >= row - 2 && j <= coll + 2 && !obstaculo; i--, j++)
		{

			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ABAJO&DERECHA     ///////////
	if (coll > 0 && row < 7)
	{
		for (i = row + 1, j = coll - 1; i >= row + 2 && j <= coll - 2 && !obstaculo; i++, j--)
		{

			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ABAJO&IZQUIERDA     ///////////
	if (coll > 0 && row > 0)
	{
		for (i = row - 1, j = coll - 1; i >= row - 2 && j <= coll - 2 && !obstaculo; i--, j--)
		{

			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}
}



