#include "Torre.h"

Torre::Torre()
{
	/*setTipoPieza(2);*/ //funcion de PIEZA
}

Torre::Torre(char colorEquipo)
{
	color = colorEquipo;
	//draw();
}

void Torre::draw()
{
	//switch (color)
	//{
	//	case 'B':
	//		TorreB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
	//		TorreB.draw();
	//		break;
	//	case 'N':
	//		TorreN.setPos(pos.x, pos.x);
	//		TorreN.draw();
	//		break;
	//	default:
	//		break;
 //   }

	if (color == 'B') {
		TorreB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		TorreB.draw();
	}
	else if (color == 'N'){
		TorreN.setPos(pos.x, pos.y);
		TorreN.draw();
	}

}

//bool Torre::movimientoLegal() 
//{
//	int i, x_ini = 0, y_ini = 0; //casilla desde la que empieza la pieza
//	bool obstaculo;
//	int x_legal ; //casilla que queremos comprobar si podemos mover ahí o no
//	int y_casilla_legal;
//	int x_fin ; //posible casilla final en direccion del movimiento que queremos (test)
//	int y_fin;
//
//     //Movimientos DERECHA
//	if (x_ini < 8)
//	{
//		obstaculo = 0;
//		if (y_fin == y_ini) {
//	
//			for (i = x_ini + 1; i < 8 && obstaculo == false; i++)
//			{
//				x_fin = i;
//				//if (/*casillafin.casillaOcupada() */== true) obstaculo = true;
//				if ((obstaculo == false))
//				{
//					if (x_fin == x_legal) return true;
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
//	//	return casilla;
//	/*}*/
//
//	/*return true;*/
//}