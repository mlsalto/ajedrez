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
	if (color == 'B') {
		TorreB.setPos(pos.x, pos.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
		TorreB.draw();
	}
	else if (color == 'N'){
		TorreN.setPos(pos.x, pos.y);
		TorreN.draw();
	}
}

bool Torre::movimientoLegal(Casilla* x, Casilla* y)
{
	if (x->getColumna() == y->getColumna() || x->getFila() == y->getFila()) return true;
	else return false;


	bool obstaculo = false;
	int i;

	int x_ini = x->getColumna();
	int y_ini = x->getFila();

	int x_fin = y->getColumna();
	int y_fin = y->getFila();


}
