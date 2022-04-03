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

	Tablero tablero;
<<<<<<< HEAD
	int i, j, row,coll;
	Casilla* copia_casillas[8][8];


	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			copia_casillas[i][j] = tablero.getCasillaT(i, j);

	row = (pos.x + 28) / 8;
	coll = (pos.y + 28) / 8;

	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	bool obstaculo = false;

	//return tablero.CasillaOcupada(fin);

	/// MOVIMIENTO A DERECHA /////

	if (row < 7 && coll == y_fin)
	{
		for (i = row + 1; i <= x_fin && !obstaculo; i++)
		{
			if (copia_casillas[i][y_fin]->getOcupada() == true) {
				obstaculo = true;
				return false;
			}
		}
		return true;
	}


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

=======
	//return tablero.movimientoDerechaLibre(x,y);
	return false;
>>>>>>> cc211856a5f9289cb63ba90dc2345de6d84997ec
}
