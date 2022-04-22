#pragma once
#include "Tablero.h"

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

	// getters //
	int getEstado();
	int getModoJuego();
	int getEstadoJuego();

protected:
	Tablero tablero;

	enum Estado { INICIO = 1, JUEGO, PAUSA, FIN,}; //editar los estados
	Estado estado;

	enum EstadoJuego{TURNO_BLANCAS = 0, TURNO_NEGRAS}; // para gestionar Jugadores
	EstadoJuego estadojuego;

    enum ModoJuego{FREE_PLAY, STORY_MODE};
	ModoJuego modojuego;
};

