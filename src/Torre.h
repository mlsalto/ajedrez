#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre();
	Torre(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

