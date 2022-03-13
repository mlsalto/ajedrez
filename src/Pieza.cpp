#include "Pieza.h"

Pieza::Pieza() {
	
}

Pieza::~Pieza() {

}

void Pieza::draw() {

	switch (pieza)
	{
	case 0: // NADA
		break;


	case 1: //PEON
		if (getColorPieza() == 0) {
			PeonB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			PeonB.draw();
		}   //BLANCO
		else {
			PeonN.setPos(posini.x, posini.y);
			PeonN.draw();
		}  // NEGRO
		break;


	case 2: //TORRE
		if (getColorPieza() == 0) {
			TorreB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			TorreB.draw();
		}   //BLANCO
		else {
		    TorreN.setPos(posini.x, posini.y);
		    TorreN.draw();
	    }  // NEGRO
		break;


	case 3: //ALFIL
		if (getColorPieza() == 0) {
			AlfilB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			AlfilB.draw();
		}   //BLANCO
		else {
			AlfilN.setPos(posini.x, posini.y);
			AlfilN.draw();
		}  // NEGRO
		break;


	case 4: //CABALLO
		if (getColorPieza() == 0) {
			CaballoB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			CaballoB.draw();
		}   //BLANCO
		else {
			CaballoN.setPos(posini.x, posini.y);
			CaballoN.draw();
		}  // NEGRO
		break;


	case 5: //REINA
		if (getColorPieza() == 0) {
			ReinaB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			ReinaB.draw();
		}   //BLANCO
		else {
			ReinaN.setPos(posini.x, posini.y);
			ReinaN.draw();
		}  // NEGRO
		break;


	case 6: //REY
		if (getColorPieza() == 0) {
			ReyB.setPos(posini.x, posini.y); //este set pos hay que ponerlo siempre para que dibuje el sprite
			ReyB.draw();
		}   //BLANCO
		else {
			ReyN.setPos(posini.x, posini.y);
			ReyN.draw();
		}  // NEGRO
		break;
	}
}

bool Pieza::moverPieza()
{
	return true;
}

void Pieza::setColorPieza(int x)
{
	color = x;
}

void Pieza::setTipoPieza(int x)
{
	pieza = x;
}

void Pieza::setPos(int x, int y)
{
	posini.x = x;
	posini.y = y;
}

int Pieza::getColorPieza()
{
	return color;
}

int Pieza::getTipoPieza()
{
	return pieza;
}

Vector2D Pieza::getPos()
{
	return posini;
}