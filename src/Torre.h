#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
private:
	Vector2D _posini; //posición desde la que parte la torre
public:
	TipoPieza getTipoPieza();
	bool movimientoLegal(Casilla& x, Vector2D y);
};

