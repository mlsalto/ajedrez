#pragma once
#include "Pieza.h"

using namespace ETSIDI;

class Peon: public Pieza
{
public:
	Peon();
	Peon(char colorEquipo);

	//~Torre();
	void draw();
	bool movimientoLegal(Casilla* fin);
};

