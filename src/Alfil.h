#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Alfil: public Pieza
{
public:
	Alfil();
	Alfil(char colorEquipo);
	//~Alfil();

	void draw();
	bool movimientoLegal(Casilla* fin);

};

