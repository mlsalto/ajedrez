#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"

class Coordinador
{
private:

	// PRUEBAS //
	Sprite Jaque{ "recursos/CHECK.png", 0, 0, 150, 90 };
	////////////
	
	// menu inicial gambito dama
	Sprite MenuInicial{ "recursos/menu/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "recursos/menu/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "recursos/menu/M_FreePlay.png", 0, 0, 130, 80 };
	Sprite MenuOpciones{ "recursos/menu/M_Options.png", 0, 0, 130, 80 };

	// menu inicial gambito rey
	Sprite MenuInicial2{ "recursos/menu/Menu2.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode2{ "recursos/menu/M_StoryMode2.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay2{ "recursos/menu/M_FreePlay2.png", 0, 0, 130, 80 };
	Sprite MenuOpciones2{ "recursos/menu/M_Options2.png", 0, 0, 130, 80 };

	// menu opciones
	Sprite QueenGam{ "recursos/menu/M_OpcionesQ.png", 0, 0, 130, 80 };
	Sprite QueenGamH{ "recursos/menu/M_OpcionesQH.png", 0, 0, 130, 80 };
	Sprite QueenGamE{ "recursos/menu/M_OpcionesQE.png", 0, 0, 130, 80 };
	Sprite QueenGamHE{ "recursos/menu/M_OpcionesQHE.png", 0, 0, 130, 80 };
	Sprite KingGam{ "recursos/menu/M_OpcionesK.png", 0, 0, 130, 80 };
	Sprite KingGamH{ "recursos/menu/M_OpcionesKH.png", 0, 0, 130, 80 };
	Sprite KingGamE{ "recursos/menu/M_OpcionesKE.png", 0, 0, 130, 80 };
	Sprite KingGamHE{ "recursos/menu/M_OpcionesKHE.png", 0, 0, 130, 80 };

    // menu Pausa // 
	Sprite PausaM{ "recursos/menu/PAUSE_NS.png", 0, 0, 70, 50 };
	Sprite PausaResume{ "recursos/menu/PAUSE_RESUME.png", 0, 0, 130, 80 };
	Sprite PausaRestart{ "recursos/menu/PAUSE_RESTAR.png", 0, 0, 130, 80 };
	Sprite PausaBack{ "recursos/menu/PAUSE_BACKTO.png", 0, 0, 130, 80 };
	Sprite PausaExit{ "recursos/menu/PAUSE_EXIR.png", 0, 0, 130, 80 };

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
	void mueve(float t);
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
	// variables animacion //
	float posicionx = 100;
	int parada;
	//////////////////////////

	/// variables menu opciones //
	int opciones; // Q(0) K(1) Q+H(2) K+H(3) Q+E(4) K+E(5) Q+H+E(6) K+H+E(7)
	bool ayuda; // ayuda on(1)  ayuda off(0)
	bool tipojuego; // queens(0)  kings(1)
	/////////////////////////////


	enum Estado { INICIO, OPCIONES , JUEGO, AYUDA, FIN}; //editar los estados
	Estado estado;

	enum EstadoJuego { TURNO, TURNO_NEGRAS, JAQUE, PAUSA, CORONAR_BLANCAS, CORONAR_NEGRAS }; // para gestionar Jugadores
	EstadoJuego estadojuego;

	enum Coronar{ C, REINA, TORRE, ALFIL, CABALLO};
	Coronar coronar;

    enum Inicio{I ,FREE_PLAY, STORY_MODE, OPTIONS};
	Inicio menu_inicio;

	enum Juego{ J , HELP, PAUSE,};
	Juego menu_juego;

	/*enum Pausa{P, NEW_GAME , BACK_TO_GAME, BACK_TO_MENU, EXIT};
	Pausa menu_pausa;*/

	enum Ayuda { A, MOVEMENTS, SPECIAL_RULESS, END_GAME };
	Ayuda menu_ayuda;

	enum Movimientos{M , KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
	Movimientos menu_movimientos;
};

