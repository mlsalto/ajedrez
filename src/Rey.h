#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Rey : public Pieza
{
public:
	Rey();
	Rey(char colorEquipo);
	//~Rey();

	void draw();
	bool movimientoLegal(Casilla* fin);
};

