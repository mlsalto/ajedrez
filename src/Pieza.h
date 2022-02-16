#pragma once

enum TipoPieza { REY, REINA, TORRE, ALFIL, CABALLO, PEON };
enum ColorPieza { BLANCO, NEGRO };

class Pieza
{
private:
	ColorPieza color;
	TipoPieza pieza;

public:

	void setColorPieza(ColorPieza x); //asigna el color blanco o negro
	void setTipoPieza(TipoPieza x);

	ColorPieza getColorPieza();
	TipoPieza getTipoPieza();

};

