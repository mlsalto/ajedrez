#include "Caballo.h"
#include "Tablero.h"

Caballo::Caballo()
{

}

Caballo::Caballo(char colorEquipo)
{
	color = colorEquipo;
	tipoPieza = 4;
}

void Caballo::draw()
{
	if (color == 'B') {
		CaballoB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		CaballoB.draw();
	}
	else if (color == 'N') {
		CaballoN.setPos(pos.x, pos.y);
		CaballoN.draw();
	}
}

bool Caballo::movimientoLegal(Casilla* fin)
{
	////// DEFINICIÓN DE VARIABLES DE AYUDA //////
	int i, j, row, coll;

	////// FILA Y COLUMNA //////
	coll = (pos.x + 28) / 8;
	row = (pos.y + 28) / 8;

	////// ALMACENAMIENTO DATOS DE ENTRADA //////
	int x_fin = fin->getColumna();
	int y_fin = fin->getFila();

	///////// EL CABALLO SE MUEVE EN L, 3 posiciones y despues 2 /////////

	// para que funcione dependiendo del color
	if (Tablero::getCasillaOcupada(x_fin, y_fin) == true && Tablero::getCasillaT(x_fin, y_fin)->getPieza()->getColorPieza() == color) return false;

	///////////       MOVIMIENTO DERECHA      ///////////
	if (coll + 2 == x_fin )
	{
		// movimiento arriba
		if (row + 1 == y_fin)return true;
		// movimiento abajo
		if (row - 1 == y_fin)return true;
	}

	///////////     MOVIMIENTO IZQUIERDA     ///////////
	if (coll - 2 == x_fin)
	{
		// movimiento arriba
		if (row + 1 == y_fin)return true;
		// movimiento abajo
		if (row - 1 == y_fin)return true;
	}

	///////////       MOVIMIENTO ARRIBA     ///////////
	if (row + 2 == y_fin)
	{
		// movimiento derecha
		if (coll + 1 == x_fin)return true;
		// movimiento izquierda
		if (coll - 1 == x_fin)return true;
	}

	///////////       MOVIMIENTO ABAJO    ///////////
	if (row - 2 == y_fin)
	{
		// movimiento derecha
		if (coll + 1 == x_fin)return true;
		// movimiento izquierda
		if (coll - 1 == x_fin)return true;
	}

	return false;
}