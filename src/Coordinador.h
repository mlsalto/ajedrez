#pragma once
#include "Tablero.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void inicializa();
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	int getEstado();
protected:
	Tablero tablero;
	enum Estado { INICIO = 1, JUEGO, GAMEOVER, PAUSA, TIENDA, FIN, JEFE }; //editar los estados
	Estado estado;
};

