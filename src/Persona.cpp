#include "Persona.h"
#include "Tablero.h"

Persona::Persona() {}

Persona::Persona(char colorJugador)
{
	color = colorJugador;
	//tipoJugador = 0;
}

void Persona::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
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

					//cout << "(" << x_tablero << "," << y_tablero << "," << piezaini << "," << colorini << ")" << endl;
					seleccionpieza = TRUE;

					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);

				}
			}

			//HAY PIEZA SELECCIONADA
			else if (seleccionpieza == TRUE) {

				////////    SELECCIÓN NUEVA PIEZA BLANCA    ////////
				if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == color)
				{
					Tablero::getCasillaT(posinix, posiniy)->setTipoCasilla(0);

					piezaini = Tablero::getCasillaT(x_tablero, y_tablero)->getPieza();

					posinix = x_tablero;	posiniy = y_tablero;

					Tablero::getCasillaT(x_tablero, y_tablero)->setTipoCasilla(1);
				}

				//////// COMER PIEZA NEGRA //////////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() != 0 && Tablero::getCasillaT(x_tablero, y_tablero)->getPieza()->getColorPieza() == 'N' && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
					Tablero::eliminarPiezaT(x_tablero, y_tablero); //elimina pieza

					Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini); //colocar pieza seleccionada

					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

					Tablero::getCasillaT(posinix, posiniy)->setTipoCasilla(0);

					seleccionpieza = FALSE;
					turnoterminado = TRUE;
				}

				//////// MOVER A CASILLA VACÍA ///////
				else if (Tablero::getCasillaT(x_tablero, y_tablero)->getTipoPieza() == 0 && piezaini->movimientoLegal(Tablero::getCasillaT(x_tablero, y_tablero)) == TRUE)
				{
					Tablero::getCasillaT(x_tablero, y_tablero)->colocarPieza(piezaini);

					Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);

					Tablero::getCasillaT(posinix, posiniy)->setTipoCasilla(0);

					seleccionpieza = FALSE;
					turnoterminado = TRUE;
				}
			}
		}
		
	}
}