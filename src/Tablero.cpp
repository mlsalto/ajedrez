#include "Tablero.h"

Tablero::Tablero()
{
    //casilla;
}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{
	// posiciona i, j segun el [][]
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j].setPos(i, j);

    //colocar casillas de iniciacion (color y piezas) 
	
	// PIEZAS BLANCAS
	for (i = 0; i < 8; i++)
	{
		casillas[i][1].setPieza(1); casillas[i][1].setColor(0); //peones
		casillas[i][0].setColor(0); //todas blancas

		casillas[0][0].setPieza(2); //torre 1
		casillas[1][0].setPieza(4); //caballo 1
		casillas[2][0].setPieza(3); //alfil 1
		casillas[3][0].setPieza(5); //reina
		casillas[4][0].setPieza(6); //rey 
		casillas[5][0].setPieza(3); //alfil 2
		casillas[6][0].setPieza(4); //caballo 2
		casillas[7][0].setPieza(2); //torre 2
	}

	// PIEZAS NEGRAS
	for (i = 0; i < 8; i++)
	{
		casillas[i][6].setPieza(1); casillas[i][6].setColor(1); //peones
		casillas[i][7].setColor(1); //todas negras

		casillas[0][7].setPieza(2); //torre 1
		casillas[1][7].setPieza(4); //caballo 1
		casillas[2][7].setPieza(3); //alfil 1
		casillas[3][7].setPieza(5); //reina
		casillas[4][7].setPieza(6); //rey 
		casillas[5][7].setPieza(3); //alfil 2
		casillas[6][7].setPieza(4); //caballo 2
		casillas[7][7].setPieza(2); //torre 2
	}
}

void Tablero::dibuja()
{
	//dibuja todas las casillas
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j].draw();

	//el tablero tiene que dibujarse el último para dibujarse detrás y que no
	//tape a las figuras
	tableroAjedrez.draw();
	//casilla.draw();
}


//Casilla Tablero::getCasilla(int _columna, int _fila)
//{
//	return casilla[0][0];
//}