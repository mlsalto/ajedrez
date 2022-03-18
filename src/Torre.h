#pragma once
#include "Pieza.h"
using namespace ETSIDI;

class Torre : public Pieza
{
private:
	Vector2D pos; //posición desde la que parte la torre

	//Sprite TorreN{ "recursos/torreN.png",0,-8,8,8 };
	//Sprite TorreB{ "recursos/torreB.png",0,24,8,8 };

	/*Sprite TorreN{ "recursos/torreN.png", pos.x, pos.y, 8, 8 };
	Sprite TorreB{ "recursos/torreB.png", pos.x, pos.y, 8, 8 };*/

	/*Casilla& casillafin;*/
public:
	Torre();
	Torre(int x, int y);
	~Torre();

	void draw();
	bool movimientoLegal();

};

