#include "Torre.h"
#include "Tablero.h"

Torre::Torre()
{
	//pieza = 2; //funcion de PIEZA
}

Torre::Torre(char colorEquipo)
{
	color = colorEquipo;
	//draw();
}

void Torre::draw()
{
	if (color == 'B') {
		TorreB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		TorreB.draw();
	}
	else if (color == 'N'){
		TorreN.setPos(pos.x, pos.y);
		TorreN.draw();
	}
}

bool Torre::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	Tablero tablero;
	int i, j, row,coll;
	Casilla* copia_casillas[8][8];
	bool obstaculo = false;

	////// COPIA DEL TABLERO //////
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			copia_casillas[i][j] = tablero.getCasillaT(i, j);

	////// FILA Y COLUMNA //////
	row = (pos.x + 28) / 8;
	coll = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	

	///////////       MOVIMIENTO DERECHA      ///////////
	if (row < 7 && coll == y_fin)
	{
		for (i = row + 1; i <= x_fin && !obstaculo; i++)
		{
			if (copia_casillas[i][y_fin]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (row > 0 && coll == y_fin)
	{
		for (i = row - 1; i >= x_fin && !obstaculo; i--)
		{
			if (copia_casillas[i][y_fin]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (row == x_fin && coll < 7)
	{
		for (i = coll + 1; i <= y_fin && !obstaculo; i++)
		{
			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (row == x_fin && coll > 0)
	{
		for (i = coll -1; i >= y_fin && !obstaculo; i--)
		{
			if (copia_casillas[x_fin][i]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

}
