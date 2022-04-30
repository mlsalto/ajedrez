#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"

class Coordinador
{
private:
	// menu inicial gambito dama
	Sprite MenuInicial{ "recursos/menu/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "recursos/menu/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "recursos/menu/M_FreePlay.png", 0, 0, 130, 80 };
	Sprite MenuOpciones{ "recursos/menu/M_Options.png", 0, 0, 130, 80 };
	// menu opciones
	//Sprite Reina{};
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
	bool tiempo(char color);

	// setters //
	void setMenuInicio(int x);
	void setMenuCoronacion(int x);
	void setOpciones(int x);

	// getters //
	int getEstado();
	int getModoJuego();
	int getEstadoJuego();

protected:
	Tablero tablero;

	int tipoJuego; // queensgambit(0), kingsgambit(1)

	int opciones; // Q(0) K(1) Q+H(3) K+H(4) Q+E(5) K+E(6) Q+H+E(7) K+H+E(8)

	enum Estado { INICIO, OPCIONES , JUEGO, PAUSA, AYUDA, FIN}; //editar los estados
	Estado estado;

	enum EstadoJuego{TURNO, TURNO_NEGRAS, CORONAR_BLANCAS, CORONAR_NEGRAS}; // para gestionar Jugadores
	EstadoJuego estadojuego;

	enum Coronar{ C, REINA, TORRE, ALFIL, CABALLO};
	Coronar coronar;

    enum Inicio{I ,FREE_PLAY, STORY_MODE, OPTIONS};
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

