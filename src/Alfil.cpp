#include "Alfil.h"
#include "Tablero.h"
#include <math.h>

Alfil::Alfil() {

	//pieza= 2;
}

Alfil::Alfil(char colorEquipo) {

	color = colorEquipo;
	//draw();
}

void Alfil::draw()
{
	if (color == 'B') {
		AlfilB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		AlfilB.draw();
	}
	else if (color == 'N') {
		AlfilN.setPos(pos.x, pos.y);
		AlfilN.draw();
	}
}

bool Alfil::movimientoLegal(Casilla* fin) {

	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	Tablero tablero;
	int i, j, row, coll;
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


	///////////       MOVIMIENTO DERECHA/ARRIBA     ///////////
	if (coll < 7 && row < 7)
	{
		for (i = row + 1, j = coll + 1; i <= x_fin && j <= y_fin && !obstaculo; i++, j++)
		{

			if (copia_casillas[i][j]->getOcupada() == true || fabs(x_fin - i) != fabs(y_fin - j)) {
				obstaculo = true;
				return false;
			}

			return true;
		}

	}

	///////////       MOVIMIENTO IZQUIERDA/ARRIBA    ///////////
	if (coll < 7 && row > 0)
	{
		for (i = row - 1, j = coll + 1; i >= x_fin && j <= y_fin && !obstaculo; i--, j++)
		{

			if (copia_casillas[i][j]->getOcupada() == true || fabs(x_fin - i) != fabs(y_fin - j)) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO DERECHA/ABAJO    ///////////
	if (coll > 0 && row < 7)
	{
		for (i = row + 1, j = coll - 1; i <= x_fin && j >= y_fin && !obstaculo; i++, j--)
		{
			if (copia_casillas[i][j]->getOcupada() == true || fabs(x_fin - i) != fabs(y_fin - j)) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

	///////////       MOVIMIENTO IZQUIERDA/ABAJO      ///////////
	if (coll > 0 && row > 0)
	{
		for (i = row - 1, j = coll - 1; i >= x_fin && j >= y_fin && !obstaculo; i--, j--)
		{
			if (copia_casillas[i][j]->getOcupada() == true || fabs(x_fin - i) != fabs(y_fin - j)) {
				obstaculo = true;
				return false;
			}

			return true;
		}
	}

}