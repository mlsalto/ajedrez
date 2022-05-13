#include "IA1.h"
#include "Tablero.h"

IA1::IA1() {}

IA1::IA1(char colorJugador)
{
	color = colorJugador;
}


void IA1::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	int puntos = 0;
	int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;
	int maximo = 0;

	
		//********************** DECISIÓN DEL PRÓXIMO MOVIMIENTO DE LA IA  ********************//
	for (x_ini = 0; x_ini < 8; x_ini++)
	{
		for (y_ini = 0; y_ini < 8; y_ini++)
		{
			// buscar una pieza para mover ( similar a seleccionar de persona )
			if (Tablero::getCasillaT(x_ini, y_ini)->getOcupada() == TRUE && Tablero::getCasillaT(x_ini, y_ini)->getPieza()->getColorPieza() == color)
			{
				pieza = Tablero::getCasillaT(x_ini, y_ini)->getPieza();

				// mover la pieza encontrada (similar a la pieza ya seleccionada de pieza)
				for (x_fin = 0; x_fin < 8; x_fin++)
				{
					for (y_fin = 0; y_fin < 8; y_fin++) {

						/// HAY QUE HACER VARIAS COSAS ///

						// si no come ninguna pieza //
						// si come alguna pieza //
						// si en passant blanco //
						// si en passant negro //
						// si coronacion //
						// si haces enroque //
						// quizas hacer int que sea TIPOMOVIMIENTO, así despues se pone un if al final y es más facil
						
						// se puede realizar el movimiento
						if (pieza->movimientoLegal(Tablero::getCasillaT(x_fin, y_fin)) == TRUE) {
							
							// si no come ninguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) == 0)
							{
								// copia del tablero y realizar el movimiento si se mueve a una casilla vacía
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									puntos = getPuntos(color);

									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
									}
								}

								// deshacemos el movimiento
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(0);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(pieza);
							}

							// si se come alguna pieza
							if (Tablero::getTipoPiezasT(x_fin, y_fin) != 0 && Tablero::getTipoPiezasT(x_fin, y_fin) != 6)
							{
								piezacomida = Tablero::getPiezasT(x_fin, y_fin);
								Tablero::getCasillaT(x_fin, y_fin)->colocarPieza(pieza);
								Tablero::getCasillaT(x_ini, y_ini)->colocarPieza(0);

								if (Tablero::detectar_jaque(color) == FALSE) // comprobar que no haya jaque
								{
									if (puntos > maximo) {
										piezaini = pieza; //guardamos valor pieza
										piezafin = piezacomida;
										posinix = x_ini; posiniy = y_ini;// guardar valor posicion inicio pieza
										posfinx = x_fin; posfiny = y_fin; // guardar valor posicion final pieza
										maximo = puntos;
									}
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
		if (Tablero::getCasillaT(posfinx, posfiny)->getTipoPieza() != 0 && Tablero::getCasillaT(posfinx, posfiny)->getTipoPieza() != 6)
		{
			Tablero::getCasillaT(posfinx, posfiny)->colocarPieza(piezaini);
			Tablero::getCasillaT(posinix, posiniy)->colocarPieza(0);
			Tablero::eliminarPieza(piezafin); //elimina pieza
		}

		turnoterminado = TRUE;
	
}