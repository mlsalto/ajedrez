#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Rey : public Pieza
{
	Rey();
	Rey(char colorEquipo);
	//~Rey();

	void draw();
	bool movimientoLegal(Casilla* fin);
};

