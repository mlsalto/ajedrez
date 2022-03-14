#include "Tablero.h"
#include "freeglut.h"

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

void Tablero::ratonTablero(int button, int state, int x, int y)
{
	int x_cell, y_cell;
	int x_tablero, y_tablero;
	x_cell = x / 76;
	y_cell = y / 77;

	switch (y_cell)
	{
	case 1:
		y_tablero = 7;
		break;
	case 2:
		y_tablero = 6;
		break;
	case 3:
		y_tablero = 5;
		break;
	case 4:
		y_tablero = 4;
		break;
	case 5:
		y_tablero = 3;
		break;
	case 6:
		y_tablero = 2;
		break;
	case 7:
		y_tablero = 1;
		break;
	case 8:
		y_tablero = 0;
		break;
	default:
		y_tablero = 8;
		break;
	}

	switch (x_cell)
	{
	case 5:
		x_tablero = 0;
		break;
	case 6:
		x_tablero = 1;
		break;
	case 7:
		x_tablero = 2;
		break;
	case 8:
		x_tablero = 3;
		break;
	case 9:
		x_tablero = 4;
		break;
	case 10:
		x_tablero = 5;
		break;
	case 11:
		x_tablero = 6;
		break;
	case 12:
		x_tablero = 7;
		break;
	default:
		x_tablero = 8;
		//y_tablero = 0;
		break;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (seleccionpieza == FALSE) { //AUN NO HAY PIEZA SELECCIONADA
	
			if (casillas[x_tablero][y_tablero].getPieza() != 0)
			{
				piezaini = casillas[x_tablero][y_tablero].getPieza();
				colorini = casillas[x_tablero][y_tablero].getColor();
				posinix = x_tablero;	posiniy = y_tablero;

				cout << "(" << x_tablero << "," << y_tablero << "," << piezaini << "," << colorini << ")" << endl;
				seleccionpieza = TRUE;
		
			}
				//casilla_iluminada->setPos(-36 + (x_tablero * 8), -36 + (y_tablero * 8)); //funcion para dibujar casilla iluminada en función del ratón
		}

		else if (seleccionpieza == TRUE) { //HAY PIEZA SELECCIONADA

			casillas[x_tablero][y_tablero].setPieza(piezaini);
			casillas[x_tablero][y_tablero].setColor(colorini);
			casillas[posinix][posiniy].setPieza(0);

			seleccionpieza = FALSE;
		}
	}
}

//Casilla Tablero::getCasilla(int _columna, int _fila)
//{
//	return casilla[0][0];
//}