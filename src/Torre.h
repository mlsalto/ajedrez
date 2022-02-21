#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
private:
	Sprite TorreN{ "recursos/torreN.png",0,-8,8,8};
	Sprite TorreB{ "recursos/torreB.png",0,24,8,8};
public:
	Torre();
	//bool movimiento 
};

