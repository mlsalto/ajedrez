#include "Peon.h"
#include "Tablero.h"

Peon::Peon(char colorEquipo)
{
	color = colorEquipo;
	tipoPieza = 1;
}

void Peon::draw()
{
	if (Tablero::getTipoJuego() == true) {
		if (color == 'B') {
			PeonB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			PeonB.draw();
		}
		else if (color == 'N') {
			PeonA.setPos(pos.x, pos.y);
			PeonA.draw();
		}
	}
	if (Tablero::getTipoJuego() == false) {
		if (color == 'B') {
			PeonR.setPos(pos.x, pos.y); 
			PeonR.draw();
		}
		else if (color == 'N') {
			PeonN.setPos(pos.x, pos.y);
			PeonN.draw();
		}
	}
}

bool Peon::getPass()
{
	return pass;
}

bool Peon::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row, coll;
	bool obstaculo = false;
	bool coronacion = false;
	bool pass = false;

	////// FILA Y COLUMNA ACTUAL DE LA PIEZA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA QUE INTRODUCE EL USUARIO POR RATÓN //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	// los peones blancos solo se mueven hacia arriba y diagonales de arriba derecha / izquierda en caso de haber una pieza negra
	if (color == 'B')
	{
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 1 && (y_fin == row + 1 || y_fin == row + 2) && x_fin == coll)
		{
			for (i = row + 1; i <= y_fin && !obstaculo; i++)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		if (y_fin == row + 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			else
			{
				if (y_fin == 7)
					coronacion = true;
				return true;
			}
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		if (y_fin == row + 1 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
		{
			return true;
		}

		////// PASSANT /////
		// 1 peon N solo puede comer 1 peon B si el peon negro se posiciona al lado de 1 peon B dando 2 pasos -NO 1 SOLO!!-
		// Solo puede comerse el peon B si es el movimiento siguiente al movimiento del peon B
		if (y_fin == row + 1 && y_fin == 5 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == false && Tablero::getCasillaT(x_fin, y_fin - 1)->getTipoPieza() == 1 && Tablero::getCasillaT(x_fin, y_fin - 1)->getPieza()->getColorPieza() != color && Tablero::getPiezasT(x_fin, y_fin - 1)->getPassant() == true)
		{
			pass = true;
			Tablero::getCasillaT(x_fin, y_fin - 1)->colocarPieza(0);
			return true;
		}

		else return false;  // No se cumple ninguno de los movimientos legalesde los peones y por tanto, NO es un movimiento legal - la pieza no se	mueve -
	}

	//Los peones negros solo se mueven hacia abajo y diagonales de abaj derecha / izquierda
	else if (color == 'N')
	{
		////// MOVIMIENTO 1: máximo 2 casillas hacia delante //////
		if (row == 6 && (y_fin == row - 1 || y_fin == row - 2) && x_fin == coll)
		{
			//bucle para comprobar que el peón no se salta ninguna pieza - cuando se mueve 2 casillas hacia delante
			for (i = row - 1; i >= y_fin && !obstaculo; i--)
			{
				if (Tablero::getCasillaOcupada(x_fin, i) == true)
					return false;
			}
			return true;
		}

		////// SIGUIENTES MOVIMIENTOS: 1 CASILLA POR TURNO //////
		if (y_fin == row - 1 && x_fin == coll)
		{
			if (Tablero::getCasillaOcupada(x_fin, y_fin) == true)
				return false;
			else
			{
				if (y_fin == 0)
					coronacion = true;
				return true;
			}
		}

		////// COMER PIEZAS NEGRAS: en diagonal 1 único desplazamiento //////
		if (y_fin == row - 1 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == true && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() != color)
		{
			return true;
		}

		////// PASSANT /////
		// 1 peon N solo puede comer 1 peon B si el peon negro se posiciona al lado de 1 peon B dando 2 pasos -NO 1 SOLO!!-
		// Solo puede comerse el peon B si es el movimiento siguiente al movimiento del peon B
		if (y_fin == row - 1 && y_fin == 2 && (x_fin == coll + 1 || x_fin == coll - 1) && Tablero::getCasillaOcupada(x_fin, y_fin) == false && Tablero::getCasillaT(x_fin, y_fin + 1)->getTipoPieza() == 1 && Tablero::getCasillaT(x_fin, y_fin + 1)->getPieza()->getColorPieza() != color && Tablero::getPiezasT(x_fin, y_fin + 1)->getPassant() == true)
		{

			pass = true;
			Tablero::getCasillaT(x_fin, y_fin + 1)->colocarPieza(0);
			return true;
		}

		else return false;  // No se cumple ninguno de los movimientos legales de los peones y por tanto, NO es un movimiento legal
	}
}