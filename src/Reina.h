#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Reina : public Pieza
{
public:
	Reina();
	Reina(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
};

