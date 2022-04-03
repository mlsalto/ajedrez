#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
private:
	Casilla* casilla_prueba;

public:
	Torre();
	Torre(char colorEquipo);
	//~Torre();

	void draw();
	bool movimientoLegal(Casilla* fin);
};

