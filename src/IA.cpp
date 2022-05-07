#include "IA.h"
#include "Tablero.h"

IA::IA() {}

IA::IA(char colorJugador)
{
	color = colorJugador;
}


void IA::moverPieza(int button, int state, int x, int y)
{
	int x_ini, x_fin, y_ini, y_fin;
	int puntos = 0;
	int posfinx, posfiny;
	int posinix, posiniy;
	int maximo = 0;

	//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	for (x_ini = 0; x_ini < 8; x_ini++)
	{
		for (y_ini = 0; y_ini < 8; y_ini++) 
		{

			if (Tablero::getCasillaT(x_ini, y_ini)->getTipoPieza() != 0 && Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color)
			{
				pieza = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

				// mover la pieza encontrada
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						// se puede realizar el movimiento
						if (pieza->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {

							// si no come ninguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								// puntos obtenidos
								puntos = getPuntos(color);

								if (puntos > maximo) {
									piezaini = pieza; //guardamos valor pieza
									posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
									posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
									maximo = puntos;
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si se come alguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) != 0)
							{
								piezacomida = Tablero::getPiezasT(x_fin, y_fin);
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								puntos = getPuntos(color);

								if (puntos > maximo) {
									piezaini = pieza; //guardamos valor pieza
									piezafin = piezacomida;
									posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
									posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
									maximo = puntos;
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(piezacomida);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}
						}
					}
				}
			}
		}
	}


	// ****************   REALIZACIÓN DEL MOVIMIENTO DESPUÉS DE DECIDIR QUE ES LO QUE QUIERE HACER   *****************//
   
	// si mueve a una casilla vacia
	if (Tablero::getCasillaT(posfinx, posfiny)->getTipoPieza() == 0)
	{
		Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
		Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
	}

	// si mueve a una casilla ocupada
	if (Tablero::getCasillaT(posfinx, posfiny)->getTipoPieza() != 0)
	{
		Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
		Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
		Tablero::eliminarPieza(piezafin); //elimina pieza
	}

	turnoterminado = TRUE;
}