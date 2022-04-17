#include "Torre.h"
#include "Tablero.h"

Torre::Torre()
{
	tipoPieza = 2;
}

Torre::Torre(char colorEquipo)
{
	color = colorEquipo;
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
	int i, j, row,coll;
	bool obstaculo = false;

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();


	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll < x_fin && row == y_fin)
	{
		for (i = coll + 1; i <= x_fin && !obstaculo; i++)
		{
			if(Tablero::getCasillaOcupada(i, y_fin) == true){
				obstaculo = true; 
				return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (coll > x_fin && row == y_fin)
	{
		for (i = coll - 1; i >= x_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(i, y_fin) == true) {
				obstaculo = true;
				return false;
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
				obstaculo = true;
				return false;
			}
		}
		return true;
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && row > y_fin)
	{
		for (i = row - 1; i >= y_fin && !obstaculo; i--)
		{
			if (Tablero::getCasillaOcupada(x_fin, i) == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}
}
