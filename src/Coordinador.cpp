#include "Coordinador.h"

Coordinador::Coordinador()
{

}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa() //esta funcion en realidad no hace falta
{
	tablero.nuevoTablero();
	
	Persona* Jugador1 = new Persona('B');
	Persona* Jugador1 = new Persona('N');
}

void Coordinador::tecla(unsigned char key)
{

}

void Coordinador::raton(int button, int state, int x, int y)
{
	tablero.ratonTablero(button,state,x,y);
}

void Coordinador::mueve()
{

}

void Coordinador::dibuja()
{
	/*MenuInicial.setPos(0, 0);
	MenuInicial.draw();*/
	tablero.dibuja();
}

int Coordinador::getEstado()
{
	return 1;
}