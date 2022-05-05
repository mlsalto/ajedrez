#pragma once
#include "Pieza.h"

class Peon: public Pieza
{
public:
	Peon();
	Peon(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

