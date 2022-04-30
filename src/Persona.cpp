#include "Persona.h"
#include "Tablero.h"

Persona::Persona() {}

Persona::Persona(char colorJugador)
{
	color = colorJugador;
	//tipoJugador = 0;
}

void Persona::draw(int x)
{
	if (x == 1) {
		if(color == 'B') player1.setPos(60, 0); 
		if(color == 'N') player1.setPos(-60, 0);
		player1.draw();
	}
	
	if (x == 2) {
		if (color == 'B')player2.setPos(60, 0); 
		if (color == 'N')player2.setPos(-60, 0); 
		player2.draw();
	}

	if (x == 3) {
		if (color == 'B')player3.setPos(60, 0);
		if (color == 'N')player3.setPos(-60, 0);
		player3.draw();
	}
}

void Persona::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int i, j;
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

	if (x_tablero == 8 || y_tablero == 8) return; // si se sale del tablero no hace nada

	////////////////// FUNCION DE SELECCIÓN PIEZAS DEL TABLERO ////////////////////////////

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (turnoterminado == FALSE) {
			//AUN NO HAY PIEZA SELECCIONADA
			if (seleccionpieza == FALSE) {

				if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == color)
				{
					piezaini = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();
					posinix = x_tablero;	posiniy = y_tablero;

					seleccionpieza = TRUE;
					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);

					// dibujar casillas legales
					for (i = 0 ; i < 8; i++ )
						for (j = 0; j < 8; j++) {
							if (piezaini->movimientoLegal(Tablero::getCasillaT(i, j)) == TRUE)
							{
								if(Tablero::getCasillaOcupada(i,j)== true && Tablero::getCasillaT(i,j)->getPieza()->getColorPieza() != color)Tablero::getCasillaT(i, j)->setTipoCasilla(3);
								else Tablero::getCasillaT(i, j)->setTipoCasilla(2);
							}
						}
				}
			}

			//HAY PIEZA SELECCIONADA
			else if (seleccionpieza == TRUE) {

				////////    SELECCIÓN NUEVA PIEZA BLANCA    ////////
				if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == color)
				{
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) {Tablero::getCasillaT(i, j)->setTipoCasilla(0);}

					piezaini = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();
					posinix = x_tablero;	posiniy = y_tablero;

					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);

					// dibujar casillas legales
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) {
							if (piezaini->movimientoLegal(Tablero::getCasillaT(i, j)) == TRUE)
							{
								if (Tablero::getCasillaOcupada(i, j) == true && Tablero::getCasillaT(i, j)->getPieza()->getColorPieza() != color)Tablero::getCasillaT(i, j)->setTipoCasilla(3);
								else Tablero::getCasillaT(i, j)->setTipoCasilla(2);
							}
						}
				}

				//////// COMER PIEZA NEGRA //////////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() != color && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
					Tablero::eliminarPiezaT(x_tablero, y_tablero); //elimina pieza
					Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini); //colocar pieza seleccionada
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

					// dibujar casillas legales
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) {
								Tablero::getCasillaT(i, j)->setTipoCasilla(0);
						}

					seleccionpieza = FALSE;
					turnoterminado = TRUE;
				}

				//////// MOVER A CASILLA VACÍA ///////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() == 0 && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
					Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);
					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

			       // dibujar casillas legales
					for (i = 0; i < 8; i++)
						for (j = 0; j < 8; j++) {
							Tablero::getCasillaT(i, j)->setTipoCasilla(0);
						}

					seleccionpieza = FALSE;
					turnoterminado = TRUE;
				}
			}
		}
		
	}
}

void Persona::funciondejaqueturno()
{
	int i, j;
	Casilla* copia_tablero[8][8];
	int pos_pieza_x, pos_pieza_y;
	int posinix, posiniy;
	Pieza* pieza_prueba;

	int i, j, pos_rey_x, pos_rey_y, posiciones = 0;

	for (i = 0; i < 8 ; i++)
		for (j = 0; j < 8; j++)
			copia_tablero[i][j] = Tablero::getCasillaT(i, j);
	
	copia_tablero[pos_pieza_x][pos_pieza_y]->colocarPieza(pieza_prueba);
	copia_tablero[posinix][posiniy]->colocarPieza(0);

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if()
}