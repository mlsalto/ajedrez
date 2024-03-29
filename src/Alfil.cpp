#include "Alfil.h"
#include "Tablero.h"
#include <math.h>

Alfil::Alfil(char colorEquipo) 
{
	color = colorEquipo;
	tipoPieza = 3;
}

void Alfil::draw()
{
	// El modo de juego es queens gambit
	if (Tablero::getTipoJuego() == true) {
		if (color == 'B') {
			AlfilB.setPos(pos.x, pos.y); 
			AlfilB.draw();
		}
		else if (color == 'N') {
			AlfilA.setPos(pos.x, pos.y);
			AlfilA.draw();
		}
	}

	// El modo de juego es kings gambit
	if (Tablero::getTipoJuego() == false) {
		if (color == 'B') {
			AlfilR.setPos(pos.x, pos.y); 
			AlfilR.draw();
		}
		else if (color == 'N') {
			AlfilN.setPos(pos.x, pos.y);
			AlfilN.draw();
		}
	}
}

bool Alfil::movimientoLegal(Casilla* fin) {

	////// DEFINICI�N DE VARIABLES DE AYUDA //////
	int i, j, row, coll;

	////// FILA Y COLUMNA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	////// SI NO EST� EN LA DIAGONAL //////
	if (fabs(x_fin - coll) != fabs(y_fin - row)) return false;

	///////////       MOVIMIENTO DERECHA/ARRIBA     ///////////
	if (coll < x_fin && row < y_fin)
	{
		for (i = coll + 1, j = row + 1; i <= x_fin && j <= y_fin ; i++, j++)
		{
			if (Tablero::getCasillaOcupada(i, j) == true ) {
				if (i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA/ARRIBA    ///////////
	if (coll > x_fin && row < y_fin)
	{
		for (i = coll - 1, j = row + 1; i >= x_fin && j <= y_fin ; i--, j++)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) {
				if(i == x_fin && j == y_fin) {
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color) { return true; }
				}
			else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO DERECHA/ABAJO    ///////////
	if (coll < x_fin && row > y_fin)
	{
		for (i = coll + 1, j = row - 1; i <= x_fin && j >= y_fin ; i++, j--)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) {
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
		for (i = coll - 1, j = row - 1; i >= x_fin && j >= y_fin ; i--, j--)
		{
			if (Tablero::getCasillaOcupada(i, j) == true) {
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