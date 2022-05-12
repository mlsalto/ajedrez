#pragma once
#include "Pieza.h"

class Torre : public Pieza
{
public:
	Torre(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

