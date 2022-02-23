#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
private:
	Vector2D _posini; //posición desde la que parte la torre

	Casilla& casillafin;
public:
	TipoPieza getTipoPieza();
	bool movimientoLegal(Casilla& n_casilla);
};

