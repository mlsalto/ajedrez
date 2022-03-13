#include "Coordinador.h"

Coordinador::Coordinador()
{

}

Coordinador::~Coordinador()
{

}

void Coordinador::inicializa()
{
	tablero.nuevoTablero();
}

void Coordinador::tecla(unsigned char key)
{

}

void Coordinador::mueve()
{

}

void Coordinador::dibuja()
{
	tablero.dibuja();
}

int Coordinador::getEstado()
{
	return 1;
}