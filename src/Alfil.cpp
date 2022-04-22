#include "Alfil.h"
#include "Tablero.h"
#include <math.h>

Alfil::Alfil() {

}

Alfil::Alfil(char colorEquipo) {

	color = colorEquipo;
	tipoPieza = 3;
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
	int i, j, row, coll;
	bool obstaculo = false;

	////// FILA Y COLUMNA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();


	///////////       MOVIMIENTO DERECHA/ARRIBA     ///////////
	if (coll < 7 && row < 7)
	{
		for (i = row + 1, j = coll + 1; i <= x_fin && j <= y_fin && !obstaculo; i++, j++)
		{

			if (Tablero::getCasillaOcupada(i, j) == true || fabs(x_fin - i) != fabs(y_fin - j)) {
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

			if (Tablero::getCasillaOcupada(i, j) == true || fabs(x_fin - i) != fabs(y_fin - j)) {
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
			if (Tablero::getCasillaOcupada(i, j) == true || fabs(x_fin - i) != fabs(y_fin - j)) {
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
			if (Tablero::getCasillaOcupada(i, j) == true || fabs(x_fin - i) != fabs(y_fin - j)) {
				obstaculo = true;
				return false;
			}
			return true;
		}
	}

}