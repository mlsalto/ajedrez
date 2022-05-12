#pragma once
#include "Pieza.h"

class Peon: public Pieza
{
private:
	bool pass = false;
public:
	Peon(char colorEquipo);

	void draw();
	bool movimientoLegal(Casilla* fin);
	bool getPass();
};

