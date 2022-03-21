#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
public:
	Torre();
	Torre(char colorEquipo);
	//~Torre();

	void draw();
	bool movimientoLegal(Casilla* x, Casilla* y);
};

