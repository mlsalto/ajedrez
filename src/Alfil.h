#pragma once
#include "Pieza.h"

class Alfil: public Pieza
{
public:
	Alfil(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

