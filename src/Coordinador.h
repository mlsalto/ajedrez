#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"
class Coordinador
{
private:
	Sprite MenuInicial{ "recursos/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "recursos/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "recursos/M_FreePlay.png", 0, 0, 130, 80 };

public:
	Coordinador();
	virtual ~Coordinador();

	void inicializa();
	void tecla(unsigned char key);
	void raton(int button, int state, int x, int y);
	void musica();
	void mueve();
	void dibuja();

	// setters //
	void setModoJuego(int x);
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

    enum ModoJuego{NONE = 0,FREE_PLAY, STORY_MODE};
	ModoJuego modojuego;
};

