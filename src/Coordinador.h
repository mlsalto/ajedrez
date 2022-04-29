#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"
class Coordinador
{
private:
	Sprite MenuInicial{ "recursos/menu/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "recursos/menu/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "recursos/menu/M_FreePlay.png", 0, 0, 130, 80 };

	// coronaciones blancas //
	Sprite MenuCoronar_B{"recursos/menu/M_CoronacionB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_B{ "recursos/menu/M_CoronacionReinaB.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_B{ "recursos/menu/M_CoronacionAlfilB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_B{ "recursos/menu/M_CoronacionCaballoB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_B{ "recursos/menu/M_CoronacionTorreB.png", 0 , 0, 40 ,60 };

	// coronaciones negras //
	Sprite MenuCoronar_N{ "recursos/menu/M_CoronacionN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_N{ "recursos/menu/M_CoronacionReinaN.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_N{ "recursos/menu/M_CoronacionAlfilN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_N{ "recursos/menu/M_CoronacionCaballoN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_N{ "recursos/menu/M_CoronacionTorreN.png", 0 , 0, 40 ,60 };

public:
	Coordinador();
	virtual ~Coordinador();

	void inicializa();
	void mouse(int x, int y);
	void tecla(unsigned char key);
	void raton(int button, int state, int x, int y);
	void musica();
	void mueve();
	void dibuja();

	// setters //
	void setMenuInicio(int x);
	void setMenuCoronacion(int x);
	// getters //
	int getEstado();
	int getModoJuego();
	int getEstadoJuego();

protected:
	Tablero tablero;

	enum Estado { INICIO , JUEGO, PAUSA, AYUDA, FIN}; //editar los estados
	Estado estado;

	enum EstadoJuego{TURNO_BLANCAS , TURNO_NEGRAS, CORONAR, CORONAR_NEGRAS}; // para gestionar Jugadores
	EstadoJuego estadojuego;

	enum Coronar{ C, REINA, TORRE, ALFIL, CABALLO};
	Coronar coronar;

    enum Inicio{I ,FREE_PLAY, STORY_MODE, OPCIONES};
	Inicio menu_inicio;

	enum Juego{ J , HELP, PAUSE,};
	Juego menu_juego;

	enum Pausa{P, NEW_GAME , BACK_TO_GAME, BACK_TO_MENU, EXIT};
	Pausa menu_pausa;

	enum Ayuda { A, MOVEMENTS, SPECIAL_RULESS, END_GAME };
	Ayuda menu_ayuda;

	enum Movimientos{M , KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
	Movimientos menu_movimientos;
};

