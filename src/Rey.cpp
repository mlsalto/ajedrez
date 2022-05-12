#include "Rey.h"
#include "Tablero.h"
#include <math.h>

Rey::Rey(){}

Rey::Rey(char colorEquipo) 
{
	color = colorEquipo;
	tipoPieza = 6;
}

void Rey::draw() {

	// El modo de juego es queens gambit
	if (Tablero::getTipoJuego() == true) {
		if (color == 'B')
		{
			ReyB.setPos(pos.x, pos.y);
			ReyB.draw();
		}
		else if (color == 'N')
		{
			ReyA.setPos(pos.x, pos.y);
			ReyA.draw();
		}
	}

	// El modo de juego es kings gambit
	if (Tablero::getTipoJuego() == false) {
		if (color == 'B')
		{
			ReyR.setPos(pos.x, pos.y);
			ReyR.draw();
		}
		else if (color == 'N')
		{
			ReyN.setPos(pos.x, pos.y);
			ReyN.draw();
		}
	}
}

bool Rey::movimientoLegal(Casilla* fin) {
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row, coll;

	////// FILA Y COLUMNA ACTUAL PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	///////////       MOVIMIENTO DERECHA      ///////////
	if (x_fin == coll + 1 && y_fin == row && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO IZQUIERDA    ///////////
	if (x_fin == coll - 1 && y_fin == row && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO ARRIBA    ///////////
	if (coll == x_fin && y_fin == row + 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO ABAJO      ///////////
	if (coll == x_fin && y_fin == row - 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	//////////************DIAOGONALES************//////////
	///////////       MOVIMIENTO ARRIBA&DERECHA     ///////////
	if (x_fin == coll + 1 && y_fin == row + 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO ARRIBA&IZQUIERDA     ///////////
	if (x_fin == coll - 1 && y_fin == row + 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO ABAJO&DERECHA     ///////////
	if (x_fin == coll + 1 && y_fin == row - 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	///////////       MOVIMIENTO ABAJO&IZQUIERDA     ///////////
	if (x_fin == coll - 1 && y_fin == row - 1 && (Tablero::getCasillaOcupada(x_fin, y_fin) == false || Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color))
	{
		return true;
	}

	//ENROQUES
	////////// Enroques rey/torre negros ///////
	 if(color == 'N' && enroque == false && primermovimiento == false)
	 {
	    //enroque corto (a la derecha)
	    if (row == 7 && coll == 4 && x_fin == 6 && y_fin == 7 && Tablero::getTipoPiezasT(7, 7) == 2 && Tablero::getCasillaT(7, 7)->getPieza()->getColorPieza() == color && Tablero::getPiezasT(7, 7)->getPrimerMovimiento() == false)
	    {
		    for (i = coll + 1; i <= x_fin; i++){
			      if(Tablero::getCasillaOcupada(i, y_fin) == true )	return false;
		    }
	        return true;
	    }
	
	    //enroque largo (a la izquierda)
	   if (row == 7 && coll == 4 && x_fin == 2 && y_fin == 7 && Tablero::getTipoPiezasT(0, 7) == 2 && Tablero::getCasillaT(0, 7)->getPieza()->getColorPieza() == color && Tablero::getPiezasT(0, 7)->getPrimerMovimiento() == false)
	   {
		    for (i = coll - 1; i >= x_fin ; i--){
			      if(Tablero::getCasillaOcupada(i, y_fin) == true )return false;
		    }
            return true;
	   }
	 }
	 
	//////////// Enroques rey/torre blancos ///////
	 if(color == 'B' && enroque == false && primermovimiento == false ) {
	     //enroque corto
		 if (row == 0 && coll == 4 && x_fin == 6 && y_fin == 0 && Tablero::getTipoPiezasT(7, 0) == 2 && Tablero::getCasillaT(7, 0)->getPieza()->getColorPieza() == color && Tablero::getPiezasT(7, 0)->getPrimerMovimiento() == false)
		 {
			 for (i = coll + 1; i < 7; i++) {
				 if (Tablero::getCasillaOcupada(i, y_fin) == true)	return false;
			 }
			 return true;
		 }
	 
	     //enroque largo (a la izquierda)
	     if (row == 0 && coll == 4 && x_fin == 2 && y_fin == 0 && Tablero::getTipoPiezasT(0, 0) == 2 && Tablero::getCasillaT(0, 0)->getPieza()->getColorPieza() == color && Tablero::getPiezasT(0, 0)->getPrimerMovimiento() == false)
		 {
		    for (i = coll - 1; i > 0 ; i--){
			    if(Tablero::getCasillaOcupada(i, y_fin) == true )return false;
		    }
	        return true;
	     }
     }

	return false;
}
 


