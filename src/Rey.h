#pragma once
#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

