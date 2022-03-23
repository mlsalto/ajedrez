#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero()
{/*
	Torre* t1 = new Torre('B');*/
	
    //casilla;
}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{

	Torre* t1b = new Torre('B');
	Torre* t2b = new Torre('B');

	Torre* t1n = new Torre('N');
	Torre* t2n = new Torre('N');

	// posiciona i, j segun el [][]
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			  casillas[i][j] = new Casilla(i, j);

	//coloca las piezas en cada casilla
	casillas[0][0]->colocarPieza(t1b); t1b->setCasilla(casillas[0][0]);
	casillas[7][0]->colocarPieza(t2b);

	casillas[0][7]->colocarPieza(t1n);
    casillas[7][7]->colocarPieza(t2n);


	//agregar listas 
	piezas.agregar(t1b);
    piezas.agregar(t2b);
    piezas.agregar(t1n);
    piezas.agregar(t2n);
	
}



void Tablero::dibuja()
{
	//el tablero tiene que dibujarse el último para dibujarse detrás y que no
	//tape a las figuras


	piezas.draw();

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
	
			if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0)
			{
				piezaini = casillas[x_tablero][y_tablero]->getTipoPieza();
				colorini = casillas[x_tablero][y_tablero]->getColorPieza();
				posinix = x_tablero;	posiniy = y_tablero;

				cout << "(" << x_tablero << "," << y_tablero << "," << piezaini << "," << colorini << ")" << endl;
				seleccionpieza = TRUE;
		
			}
				//casilla_iluminada->setPos(-36 + (x_tablero * 8), -36 + (y_tablero * 8)); //funcion para dibujar casilla iluminada en función del ratón
		}

		else if (seleccionpieza == TRUE) { //HAY PIEZA SELECCIONADA
			if (piezaini->movimientoLegal(casillas[posinix][posiniy],casillas[x_tablero][y_tablero]) == true)
			{
				casillas[x_tablero][y_tablero]->colocarPieza(piezaini);
				piezaini->setCasilla(casillas[x_tablero][y_tablero]);

				seleccionpieza = FALSE;
			}
		}
	}
}

void movimientoVertical()  //indica si hasta donde se puede mover en vertical
{

}

bool Tablero::movimientoDerechaLibre(Casilla * ini, Casilla* fin)
{
	int x_ini = ini->getColumna();
	int y_ini = ini->getFila();

	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	bool obstaculo = false;

	if (x_ini < 7 && y_ini == y_fin)
    {
	for (i = x_ini + 1; i <= x_fin && !obstaculo; i++)
	  {
		if (casillas[x_fin][y_fin]->getTipoPieza() != NULL) {
			obstaculo = true;
			return false;
		}
		return true;
	  }
    }
}

Pieza* Tablero::getPiezasT(int x, int y)
{
	return casillas[x][y]->getTipoPieza();
}

Casilla* Tablero::getCasillaT(int x, int y)
{
	return casillas[x][y];
}