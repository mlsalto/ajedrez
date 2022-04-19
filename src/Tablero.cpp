#include "Tablero.h"
#include "freeglut.h"

Casilla* Tablero::casillas[8][8];

Tablero::Tablero()
{
	
}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j] = new Casilla(i, j);

	Torre* t1b = new Torre('B');
	Torre* t2b = new Torre('B');

	Caballo* c1b = new Caballo('B');
	Caballo* c2b = new Caballo('B');

	Torre* t1n = new Torre('N');
	Torre* t2n = new Torre('N');

	Caballo* c1n = new Caballo('N');
	Caballo* c2n = new Caballo('N');

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

	//rey
	Rey* kb = new Rey('B');
	Rey* kn = new Rey('N');

	//reina
	Reina* qb = new Reina('B');
	Reina* qn = new Reina('N');

	//alfiles
	Alfil* a1n = new Alfil('N');
	Alfil* a2n = new Alfil('N');

	Alfil* a1b = new Alfil('B');
	Alfil* a2b = new Alfil('B');


    //coloca las piezas en cada casilla
	// Torre(t), Caballo(c), Peon (p), Rey(k), Reina(q), Alfil (a)

	// PRIMERA FILA BLANCA
	casillas[0][0]->colocarPieza(t1b);
	casillas[1][0]->colocarPieza(c1b);
<<<<<<< HEAD
	casillas[3][0]->colocarPieza(qb);
=======
	casillas[2][0]->colocarPieza(a1b);
	casillas[3][0]->colocarPieza(qb);
	casillas[4][0]->colocarPieza(kb);
	casillas[5][0]->colocarPieza(a2b);
>>>>>>> master
	casillas[6][0]->colocarPieza(c2b);
	casillas[7][0]->colocarPieza(t2b);

	// SEGUNDA FILA BLANCA
	casillas[0][1]->colocarPieza(p1b);
	casillas[1][1]->colocarPieza(p2b);
	casillas[2][1]->colocarPieza(p3b);
	casillas[3][1]->colocarPieza(p4b);
	casillas[4][1]->colocarPieza(p5b);
	casillas[5][1]->colocarPieza(p6b);
	casillas[6][1]->colocarPieza(p7b);
	casillas[7][1]->colocarPieza(p8b);

	// PRIMERA FILA NEGRA
	casillas[0][7]->colocarPieza(t1n);
	casillas[1][7]->colocarPieza(c1n);
<<<<<<< HEAD
	casillas[3][7]->colocarPieza(qn);
	casillas[6][7]->colocarPieza(c2n);
	casillas[7][7]->colocarPieza(t2n); 
=======
	casillas[2][7]->colocarPieza(a1n);
	casillas[3][7]->colocarPieza(qn);
	casillas[4][7]->colocarPieza(kn);
	casillas[5][7]->colocarPieza(a2n);
	casillas[6][7]->colocarPieza(c2n);
	casillas[7][7]->colocarPieza(t2n);
>>>>>>> master

	// SEGUNDA FILA NEGRA
	casillas[0][6]->colocarPieza(p1n);
	casillas[1][6]->colocarPieza(p2n);
	casillas[2][6]->colocarPieza(p3n);
	casillas[3][6]->colocarPieza(p4n);
	casillas[4][6]->colocarPieza(p5n);
	casillas[5][6]->colocarPieza(p6n);
	casillas[6][6]->colocarPieza(p7n);
	casillas[7][6]->colocarPieza(p8n);

	/// AGREGAR PIEZAS BLANCAS ///
	piezas.agregar(c1b);
	piezas.agregar(c2b);

<<<<<<< HEAD
=======
	piezas.agregar(kb);

>>>>>>> master
	piezas.agregar(qb);

	piezas.agregar(t1b);
	piezas.agregar(t2b);

	piezas.agregar(a1b);
	piezas.agregar(a2b);

	piezas.agregar(p1b);
	piezas.agregar(p2b);
	piezas.agregar(p3b);
	piezas.agregar(p4b);
	piezas.agregar(p5b);
	piezas.agregar(p6b);
	piezas.agregar(p7b);
	piezas.agregar(p8b);

	/// AGREGAR PIEZAS NEGRAS ///
	piezas.agregar(c1n);
	piezas.agregar(c2n);

<<<<<<< HEAD
=======
	piezas.agregar(kn);

>>>>>>> master
	piezas.agregar(qn);

	piezas.agregar(t1n);
	piezas.agregar(t2n);

<<<<<<< HEAD
=======
	piezas.agregar(a1n);
	piezas.agregar(a2n);

>>>>>>> master
	piezas.agregar(p1n);
	piezas.agregar(p2n);
	piezas.agregar(p3n);
	piezas.agregar(p4n);
	piezas.agregar(p5n);
	piezas.agregar(p6n);
	piezas.agregar(p7n);
	piezas.agregar(p8n);
}

void Tablero::dibuja()
{
	//el tablero tiene que dibujarse el último para dibujarse detrás y que no
	//tape a las figuras

	piezas.draw();

	casilla_seleccionada.draw();

	tableroAjedrez.draw();
	marcoTablero.draw();
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
	return casillas[x][y]->getTipoPieza();
}

Casilla* Tablero::getCasillaT(int x, int y)
{
	return casillas[x][y];
}

bool Tablero::getCasillaOcupada(int x, int y)
{
	return casillas[x][y]->getOcupada();
}



////// PRUEBAS PARA REALIZACIÓN DE UNA IA SENCILLA ////////

/* Valores matemáticos para la evaluación de la función

 peon.
   - Por cada peon +100 puntos
   - Por cada peon en el centro del tablero +12 puntos
   - Por cada casilla que un peon avanza +2 puntos

 caballo.
   - Por cada caballo +315 puntos
   - Si está cerca o lejos del centro del tablero +-0-15 puntos

 alfil.
   - Por cada alfil +330 puntos
   - Añadir un punto por cada casilla a la que se pueda mover el alfil 

 torre.
   - Por cada torre +500 puntos
   - Añadir un punto por cada casilla a la que se pueda mover la torre

 dama.  
   - Por cada dama +940 puntos
   - Si está cerca o lejos del centro del tablero +-0-10 puntos

*/



int Tablero::funcionIA()
{
	int i, j;
	Pieza* p;
	int puntos_pieza, tipoPieza; // según el tipo de pieza que sea
	int puntos_totales = 0; //inicializa los puntos totales
	bool color_pieza;
	bool movimiento_legal;
	// HAY QUE PONERLO EN FUNCIÓN DEL COLOR //




	//************************* LECTURA DE PUNTOS SOBRE EL TABLERO  *********************//
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			p = getPiezasT(i, j); // hay que hacer la funcion con get tipo

			//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

			switch (tipoPieza)
			{
			case 0: //no pieza
				break;

			case 1: //peon
				puntos_totales = puntos_totales + 100;
				//if(a)
				break;

			case 2: //torre
				puntos_totales = puntos_totales + 500;
				break;

			case 3: //alfil
				puntos_totales = puntos_totales + 330;
				break;

			case 4: //caballo
				puntos_totales = puntos_totales + 315;
				break;

			case 5: //reina
				puntos_totales = puntos_totales + 940;
				break;

			case 6: //rey
				break;
			}
		}
	return puntos_totales;


	// ESTO DEBE SER UNA FUNCIÓN APARTE
	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (color_pieza == 0) { //color de la pieza es igual que la nuestra

				for (i = 0; i < 8; i++) //movimiento final en el tablero de la pieza que hemos encontrado
					for (j = 0; j < 8; j++) {
						if (/* movimiento es legal a i,j*/ movimiento_legal == true) {
							//hacer una copia del tablero y realizar el movimiento
							//evaluamos los puntos obtenidos
							//lo comparamos los puntos obtenidos con lo máximos if(puntos > maximo) maximo = puntos;
							// guardamos los valores de la pieza que se mueve y a donde se mueve
						}
					}
			}
		}
}


