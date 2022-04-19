#pragma once
#include "Tablero.h"
#include "Jugador.h"

class Coordinador
{
private:
	Sprite MenuInicial{ "recursos/MENU.png", 0, 0, 130, 80 };
public:
	Coordinador();
	virtual ~Coordinador();
	void inicializa();
	void tecla(unsigned char key);
	void raton(int button, int state, int x, int y);
	void mueve();
	void dibuja();
	int getEstado();

protected:
	Tablero tablero;
	enum Estado { INICIO = 1, JUEGO, GAMEOVER, PAUSA, TIENDA, FIN, JEFE }; //editar los estados
	Estado estado;

	enum EstadoJuego{TURNO_BLANCAS, TURNO_NEGRAS}; // para gestionar Jugadores
};

