#include "Torre.h"
#include "Tablero.h"

Torre::Torre(){}

Torre::Torre(char colorEquipo)
{
	color = colorEquipo;
	tipoPieza = 2;
}

void Torre::draw()
{
	if (Tablero::getTipoJuego() == true) {
		if (color == 'B') {
			TorreB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			TorreB.draw();
		}
		else if (color == 'N') {
			TorreA.setPos(pos.x, pos.y);
			TorreA.draw();
		}
	}
	if (Tablero::getTipoJuego() == false) {
		if (color == 'B') {
			TorreR.setPos(pos.x, pos.y);
			TorreR.draw();
		}
		else if (color == 'N') {
			TorreN.setPos(pos.x, pos.y);
			TorreN.draw();
		}
	}
}

bool Torre::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row,coll;

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();


	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll < x_fin && row == y_fin)
	{
		for (i = coll + 1; i <= x_fin; i++)
		{
			if(Tablero::getCasillaOcupada(i, y_fin) == true ){
				if (i == x_fin) {
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
		for (i = coll - 1; i >= x_fin ; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true ) {
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
		for (i = row + 1; i <= y_fin ; i++)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				if (i == y_fin) {
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() == color) { return false; }
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() != color ){ return true; }
				}
				else return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > y_fin)
	{
		for (i = row - 1; i >= y_fin ; i--)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				if (i == y_fin) {
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() == color) {return false;}
					if (Tablero::getCasillaT(x_fin, i)->getPieza()->getColorPieza() != color) {return true;}
				}
				else return false;
			}
		}
		return true;
	}

	else return false;
}
