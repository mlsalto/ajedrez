#include "Peon.h"
#include "Tablero.h"

Peon::Peon()
{
}

Peon::Peon(char colorEquipo)
{
	color = colorEquipo;
}

void Peon::draw()
{
	if (color == 'B') {
		PeonB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		PeonB.draw();
	}
	else if (color == 'N') {
		PeonN.setPos(pos.x, pos.y);
		PeonN.draw();
	}
}

bool Peon::movimientoLegal(Casilla* fin)
{
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

	switch (color)
	{
	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha/izquierda
	case 'B':
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
		break;
	//Los peones negros solo se mueven hacia abajo y diagonales de abajo derecha/izquierda
	case 'N':
		///////////       MOVIMIENTO ABAJO      ///////////
		if (row == x_fin && coll > 0)
		{
			for (i = coll - 1; i >= y_fin && !obstaculo; i--)
			{
				if (copia_casillas[x_fin][i]->getOcupada() == true) {
					obstaculo = true;
					return false;
				}
				return true;
			}
		}
		break;
	}

	return false;
}
