#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero()
{
	// posiciona i, j segun el [][]
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j] = new Casilla(i, j);

	Torre* t1b = new Torre('B');
	Torre* t2b = new Torre('B');

	Torre* t1n = new Torre('N');
	Torre* t2n = new Torre('N');

	//Peones blancos (1)
	Peon* p1b = new Peon('B');
	Peon* p2b = new Peon('B');
	Peon* p3b = new Peon('B');
	Peon* p4b = new Peon('B');
	Peon* p5b = new Peon('B');
	Peon* p6b = new Peon('B');
	Peon* p7b = new Peon('B');
	Peon* p8b = new Peon('B');

	//Peones negros (1)
	Peon* p1n = new Peon('N');
	Peon* p2n = new Peon('N');
	Peon* p3n = new Peon('N');
	Peon* p4n = new Peon('N');
	Peon* p5n = new Peon('N');
	Peon* p6n = new Peon('N');
	Peon* p7n = new Peon('N');
	Peon* p8n = new Peon('N');

	//coloca las piezas en cada casilla
	//TORRES BLANCAS
	casillas[0][0]->colocarPieza(t1b); // t1b->setCasilla(casillas[0][0]);
	casillas[7][0]->colocarPieza(t2b);

	//PEONES BLANCOS
	casillas[0][1]->colocarPieza(p1b);
	casillas[1][1]->colocarPieza(p2b);
	casillas[2][1]->colocarPieza(p3b);
	casillas[3][1]->colocarPieza(p4b);
	casillas[4][1]->colocarPieza(p5b);
	casillas[5][1]->colocarPieza(p6b);
	casillas[6][1]->colocarPieza(p7b);
	casillas[7][1]->colocarPieza(p8b);

	//TORRES NEGRAS
	casillas[0][7]->colocarPieza(t1n);
	casillas[7][7]->colocarPieza(t2n);

	//PEONES NEGROS
	casillas[0][6]->colocarPieza(p1n);
	casillas[1][6]->colocarPieza(p2n);
	casillas[2][6]->colocarPieza(p3n);
	casillas[3][6]->colocarPieza(p4n);
	casillas[4][6]->colocarPieza(p5n);
	casillas[5][6]->colocarPieza(p6n);
	casillas[6][6]->colocarPieza(p7n);
	casillas[7][6]->colocarPieza(p8n);

	//
	piezas.agregar(t1b);
	piezas.agregar(t2b);

	piezas.agregar(p1b);
	piezas.agregar(p2b);
	piezas.agregar(p3b);
	piezas.agregar(p4b);
	piezas.agregar(p5b);
	piezas.agregar(p6b);
	piezas.agregar(p7b);
	piezas.agregar(p8b);

	piezas.agregar(t1n);
	piezas.agregar(t2n);
	
	piezas.agregar(p1n);
	piezas.agregar(p2n);
	piezas.agregar(p3n);
	piezas.agregar(p4n);
	piezas.agregar(p5n);
	piezas.agregar(p6n);
	piezas.agregar(p7n);
	piezas.agregar(p8n);
}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{

}



void Tablero::dibuja()
{
	//el tablero tiene que dibujarse el último para dibujarse detrás y que no
	//tape a las figuras


	piezas.draw();

	casilla_seleccionada.draw();

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

	////////////////// FUNCION DE SELECCIÓN PIEZAS DEL TABLERO ////////////////////////////

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (turno == TRUE) //TURNO BLANCAS
		{
			//AUN NO HAY PIEZA SELECCIONADA
			if (seleccionpieza == FALSE) {

				if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'B')
				{
					piezaini = casillas[x_tablero][y_tablero]->getTipoPieza();

					posinix = x_tablero;	posiniy = y_tablero;

					cout << "(" << x_tablero << "," << y_tablero << "," << piezaini << "," << colorini << ")" << endl;
					seleccionpieza = TRUE;

					casilla_seleccionada.setPos(-28 + (posinix * 8), -28 + (posiniy * 8));
					casilla_seleccionada.draw();

				}
			}

			//HAY PIEZA SELECCIONADA
			else if (seleccionpieza == TRUE) {
				 
				////////    SELECCIÓN NUEVA PIEZA BLANCA    ////////
				if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'B')
				{
					piezaini = casillas[x_tablero][y_tablero]->getTipoPieza();

					posinix = x_tablero;	posiniy = y_tablero;

					casilla_seleccionada.setPos(-28 + (posinix * 8), -28 + (posiniy * 8));
					casilla_seleccionada.draw();
				}

				//////// COMER PIEZA NEGRA //////////
				else if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'N' && piezaini->movimientoLegal(casillas[x_tablero][y_tablero]) == TRUE)
				{
					piezas.eliminar(casillas[x_tablero][y_tablero]->getTipoPieza()); //elimina pieza

					casillas[x_tablero][y_tablero]->colocarPieza(piezaini); //colocar pieza seleccionada
					piezaini->setCasilla(casillas[x_tablero][y_tablero]);

					casillas[posinix][posiniy]->colocarPieza(0);

					casilla_seleccionada.setPos(1000, 1000);
					casilla_seleccionada.draw();

					seleccionpieza = FALSE;
					turno = FALSE;
				}

				//////// MOVER A CASILLA VACÍA ///////
				else if (casillas[x_tablero][y_tablero]->getTipoPieza() == 0 && piezaini->movimientoLegal(casillas[x_tablero][y_tablero]) == TRUE)
				{
					casillas[x_tablero][y_tablero]->colocarPieza(piezaini);
					piezaini->setCasilla(casillas[x_tablero][y_tablero]);

					casillas[posinix][posiniy]->colocarPieza(0);

					casilla_seleccionada.setPos(1000, 1000);
					casilla_seleccionada.draw();

					seleccionpieza = FALSE;
					turno = FALSE;
				}
			}
		}



		if (turno == FALSE) //TURNO NEGRAS
		{
			//AUN NO HAY PIEZA SELECCIONADA
			if (seleccionpieza == FALSE) {

				if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'N')
				{
					piezaini = casillas[x_tablero][y_tablero]->getTipoPieza();

					posinix = x_tablero;	posiniy = y_tablero;

					cout << "(" << x_tablero << "," << y_tablero << "," << piezaini << "," << colorini << ")" << endl;
					seleccionpieza = TRUE;

					casilla_seleccionada.setPos(-28 + (posinix * 8), -28 + (posiniy * 8));
					casilla_seleccionada.draw();

				}
			}

			//HAY PIEZA SELECCIONADA
			else if (seleccionpieza == TRUE) {

				////////    SELECCIÓN NUEVA PIEZA NEGRA   ////////
				if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'N')
				{
					piezaini = casillas[x_tablero][y_tablero]->getTipoPieza();

					posinix = x_tablero;	posiniy = y_tablero;

					casilla_seleccionada.setPos(-28 + (posinix * 8), -28 + (posiniy * 8));
					casilla_seleccionada.draw();
				}

				//////// COMER PIEZA BLANCA//////////
				else if (casillas[x_tablero][y_tablero]->getTipoPieza() != 0 && casillas[x_tablero][y_tablero]->getTipoPieza()->getColorPieza() == 'B' && piezaini->movimientoLegal(casillas[x_tablero][y_tablero]) == TRUE)
				{
					piezas.eliminar(casillas[x_tablero][y_tablero]->getTipoPieza()); //elimina pieza

					casillas[x_tablero][y_tablero]->colocarPieza(piezaini); //colocar pieza seleccionada
					piezaini->setCasilla(casillas[x_tablero][y_tablero]);

					casillas[posinix][posiniy]->colocarPieza(0);

					casilla_seleccionada.setPos(1000, 1000);
					casilla_seleccionada.draw();

					seleccionpieza = FALSE;
					turno = TRUE;
				}

				//////// MOVER A CASILLA VACÍA ///////
				else if (casillas[x_tablero][y_tablero]->getTipoPieza() == 0 && piezaini->movimientoLegal(casillas[x_tablero][y_tablero]) == TRUE)
				{
					casillas[x_tablero][y_tablero]->colocarPieza(piezaini);
					piezaini->setCasilla(casillas[x_tablero][y_tablero]);

					casillas[posinix][posiniy]->colocarPieza(0);

					casilla_seleccionada.setPos(1000, 1000);
					casilla_seleccionada.draw();

					seleccionpieza = FALSE;
					turno = TRUE;
				}
			}
		}
	}
}

Pieza* Tablero::getPiezasT(int x, int y)
{
	casillas[x][y]->getTipoPieza();
	return 0;

}

Casilla* Tablero::getCasillaT(int x, int y)
{
	return casillas[x][y];
}