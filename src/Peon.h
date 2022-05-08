#pragma once
#include "Pieza.h"

class Peon: public Pieza
{
private:
	bool pass = false;
public:
	Peon();
	Peon(char colorEquipo);

	void draw();
	bool getPass();
	bool movimientoLegal(Casilla* fin);
};

