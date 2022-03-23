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

bool Torre::movimientoLegal(Casilla* ini, Casilla* fin)
{
	/*if (x->getColumna() == y->getColumna() || x->getFila() == y->getFila()) return true;
	else return false;*/
	int i, j;

	Tablero tablero;
	//Casilla* copia_tablero[8][8];
	//
	//for (i = 0; i < 8; i++)
	//	for (j = 0; j < 8; j++)
	//		copia_tablero[i][j]->colocarPieza(tablero.getPiezasT(i, j));

	//return tablero.movimientoDerechaLibre(x,y);

	return true;

	//int x_ini = ini->getColumna();
	//int y_ini = ini->getFila();

	//int x_fin = fin->getColumna();
	//int y_fin = fin->getFila();

	//bool obstaculo = false;

	///// MOVIMIENTO A DERECHA /////

	//if (x_ini < 7 && y_ini == y_fin)
	//{
	//	for (i = x_ini + 1; i <= x_fin && !obstaculo; i++)
	//	{
	//		if (tablero.getPiezasT(i, y_fin) != 0) {
	//			obstaculo = true;
	//			return false;
	//		}
	//	}
	//	return true;
	//}

}
