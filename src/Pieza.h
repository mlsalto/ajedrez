#pragma once

enum class TipoPieza { REY, REINA, TORRE, ALFIL, CABALLO, PEON, VACIO};
enum class ColorPieza { BLANCO, NEGRO };

class Pieza
{
private:
	ColorPieza color;
	TipoPieza pieza;

public:

	void setColorPieza(ColorPieza x); //asigna el color blanco o negro
	void setTipoPieza(TipoPieza x); //asigna el tipo de pieza (Rey, Reina...)

	ColorPieza getColorPieza(); //devuelve el color blanco o negro
	TipoPieza getTipoPieza(); //devuelve el tipo de pieza (Rey, Reina...)

};

