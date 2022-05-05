#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina();
	Reina(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

