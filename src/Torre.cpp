#include "Torre.h"

Torre::Torre()
{
	setTipoPieza(2); //funcion de PIEZA
}

Torre::Torre(int x, int y)
{
	pos.x = x; 
	pos.y = y;
	setPos(x, y); //entra a las funciones de PIEZA
}

void Torre::draw()
{
	draw();
	//if (getColorPieza() == 0) { TorreB.draw(); }   //BLANCO
	//else(TorreN);  // NEGRO
}

//bool Torre::movimientoLegal(Casilla& n_casilla) 
//{
//	int i, x_casilla_ini = 0, y_casilla_ini = 0; //casilla desde la que empieza la pieza
//	bool obstaculo;
//	int x_casilla_legal = n_casilla.getColumna(); //casilla que queremos comprobar si podemos mover ahí o no
//	int y_casilla_legal = n_casilla.getFila();
//	int x_casilla_fin = casillafin.getColumna(); //posible casilla final en direccion del movimiento que queremos (test)
//	int y_casilla_fin = casillafin.getFila();
//
//    // Movimientos DERECHA
//	if (x_casilla_ini < 7)
//	{
//		obstaculo = 0;
//		if (y_casilla_fin == y_casilla_legal) {
//	
//			for (i = x_casilla_ini + 1; i < 8 && obstaculo == false; i++)
//			{
//				x_casilla_fin = i;
//				if (casillafin.casillaOcupada() == true) obstaculo = true;
//				if ((obstaculo == false))
//				{
//					if (x_casilla_fin == x_casilla_legal)return true;
//					else { return false; }
//				}
//			}
//		}
//		else { return false; }
//	}
//
//	//// Movimientos IZQUIERDA
//	//if (posini.y > 0)
//	//{
//	//	obstaculo = 0;
//	//	posfin.x = posini.x;
//	//	for (i = posini.y - 1; i >= 0 && !obstaculo; i--)
//	//	{
//	//		posfin.y = i;
//	//		if (tablero[posfin].ficha != VACIO) obstaculo = 1;
//	//		if ((obstaculo == 0))
//	//		{
//	//				casillasTablero[*n_casilla] = posfin;
//	//				*n_casilla = *n_casilla + 1;
//	//		}
//	//	}
//	//}
//
//	//	// Movimientos ARRIBA
//	//if (posini.x < 7)
//	//{
//	//	obstaculo = 0;
//	//	posfin.y = posfin.y;
//	//	for (i = posini.x + 1; i < 8 && !obstaculo; i++)
//	//	{
//	//		posfin.x = i;
//	//		if (tablero[posfin].ficha != VACIO) obstaculo = 1;
//	//		if ((obstaculo == 0))
//	//		{
//	//			casillasTablero[*n_casilla] = posfin;
//	//			*n_casilla = *n_casilla + 1;
//	//		}
//	//	}
//	//}
//
//	//	// Movimientos ABAJO
//	//if (posini.x > 0)
//	//{
//	//	obstaculo = 0;
//	//	posfin.y = posfin.y;
//	//	for (i = posini.x - 1; i >= 0 && !obstaculo; i--)
//	//	{
//	//		posfin.x = i;
//	//		if (tablero[posfin].ficha != VACIO) obstaculo = 1;
//	//		if ((obstaculo == 0))
//	//		{
//	//			casillasTablero[*n_casilla] = posfin;
//	//			*n_casilla = *n_casilla + 1;
//	//		}
//	//	}
//	//}
//
//
//
//	//if (*n_casilla != 0) {
//	//	casilla = (int**)malloc(*n_casilla * sizeof(int*));//printf("\n");
//	//	for (i = 0; i < *n_casilla; i++)
//	//	{
//	//		casilla[i] = casillasTablero[i];
//	//	}
//	//}
//		//return casilla;
//	/*}*/
//
//	/*return true;*/
//}