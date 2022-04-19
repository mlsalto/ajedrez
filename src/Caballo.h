#pragma once
#include "Pieza.h"

class Caballo: public Pieza
{
public:
	Caballo();
	Caballo(char colorEquipo);
	//~Caballo();

	void draw();
	bool movimientoLegal(Casilla* fin);
};

