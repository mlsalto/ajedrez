#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"

class Coordinador
{
private:

	// PRUEBAS //
	SpriteSequence Jaque{ "recursos/CHECK_FRAME1.png", 34, 1, 50, true,0, 0, 150, 90 , 0};
	SpriteSequence Jaque1{ "recursos/CHECK_FRAME1_rojo.png", 34, 1, 50, true,0, 0, 150, 90 , 0 };
	////////////
	
	// menu inicial gambito dama //
	Sprite MenuInicial{ "recursos/menu/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "recursos/menu/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "recursos/menu/M_FreePlay.png", 0, 0, 130, 80 };
	Sprite MenuOpciones{ "recursos/menu/M_Options.png", 0, 0, 130, 80 };

	// menu inicial gambito rey //
	Sprite MenuInicial2{ "recursos/menu/Menu2.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode2{ "recursos/menu/M_StoryMode2.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay2{ "recursos/menu/M_FreePlay2.png", 0, 0, 130, 80 };
	Sprite MenuOpciones2{ "recursos/menu/M_Options2.png", 0, 0, 130, 80 };

	// menu opciones //
	Sprite QueenGam{ "recursos/menu/M_OpcionesQ.png", 0, 0, 130, 80 };
	Sprite QueenGamH{ "recursos/menu/M_OpcionesQH.png", 0, 0, 130, 80 };
	Sprite QueenGamE{ "recursos/menu/M_OpcionesQE.png", 0, 0, 130, 80 };
	Sprite QueenGamHE{ "recursos/menu/M_OpcionesQHE.png", 0, 0, 130, 80 };
	Sprite KingGam{ "recursos/menu/M_OpcionesK.png", 0, 0, 130, 80 };
	Sprite KingGamH{ "recursos/menu/M_OpcionesKH.png", 0, 0, 130, 80 };
	Sprite KingGamE{ "recursos/menu/M_OpcionesKE.png", 0, 0, 130, 80 };
	Sprite KingGamHE{ "recursos/menu/M_OpcionesKHE.png", 0, 0, 130, 80 };

    // menu Pausa // 
	Sprite PausaM{ "recursos/menu/PAUSE_NS.png", 0, 0, 110, 50 };
	Sprite PausaResume{ "recursos/menu/PAUSE_RESUME.png", 0, 0,110, 50 };
	Sprite PausaRestart{ "recursos/menu/PAUSE_RESTAR.png", 0, 0, 110, 50 };
	Sprite PausaBack{ "recursos/menu/PAUSE_BACKTO.png", 0, 0, 110, 50 };
	Sprite PausaExit{ "recursos/menu/PAUSE_EXIR.png", 0, 0, 110, 50 };

	// menu ayuda queen //
	Sprite HelpM{ "recursos/menu/help/HELP_NS.png", 0, 0, 110, 50 };
	Sprite HelpMov{ "recursos/menu/help/HELP_mov.png", 0, 0, 110, 50 };
	Sprite HelpSpeMov{ "recursos/menu/help/HELP_SP.png", 0, 0, 110, 50 };
	Sprite HelpEnd{ "recursos/menu/help/HELP_END.png", 0, 0, 110, 50 };

	// menu ayuda movs queen //
	Sprite HelpMovM{ "recursos/menu/help/HELP_MOV_NS.png", 0, 0, 110, 50 };
	Sprite HelpMovP{ "recursos/menu/help/HELP_MOV_PAWN.png", 0, 0, 110, 50 };
	Sprite HelpMovB{ "recursos/menu/help/HELP_MOV_BISHOP.png", 0, 0, 110, 50 };
	Sprite HelpMovKn{ "recursos/menu/help/HELP_MOV_KNIGHT.png", 0, 0, 110, 50 };
	Sprite HelpMovR{ "recursos/menu/help/HELP_MOV_ROOK.png", 0, 0, 110, 50 };
	Sprite HelpMovQ{ "recursos/menu/help/HELP_MOV_QUEEN.png", 0, 0, 110, 50 };
	Sprite HelpMovK{ "recursos/menu/help/HELP_MOV_KING.png", 0, 0, 110, 50 };

	// menu ayuda mov esp queen //
	Sprite HelpMovEspM{ "recursos/menu/help/HELP_SP_NS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspC{ "recursos/menu/help/HELP_SP_CAS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspE{ "recursos/menu/help/HELP_SP_ENP.png", 0, 0, 110, 50 };
	Sprite HelpMovEspP{ "recursos/menu/help/HELP_SP_PRO.png", 0, 0, 110, 50 };

	// menu ayuda flecha //
	Sprite Flecha{ "recursos/BACKNARROW.png", -45, 17, 8, 4};

	// menu ayuda mucho texto //
	Sprite HelpBish{ "recursos/BISHOP_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpPawn{ "recursos/PAWN_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpRook{ "recursos/ROOK_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKnig{ "recursos/HORSE_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKing{ "recursos/KING_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpQuee{ "recursos/QUEEN_TEXT.png", 0, 0, 110, 50 };

	// coronaciones blancas queen //
	Sprite MenuCoronar_B{"recursos/menu/M_CoronacionB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_B{ "recursos/menu/M_CoronacionReinaB.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_B{ "recursos/menu/M_CoronacionAlfilB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_B{ "recursos/menu/M_CoronacionCaballoB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_B{ "recursos/menu/M_CoronacionTorreB.png", 0 , 0, 40 ,60 };

	// coronaciones blancas king //
	Sprite MenuCoronar_B2{ "recursos/menu/M_CoronacionB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_B2{ "recursos/menu/M_CoronacionReinaB2.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_B2{ "recursos/menu/M_CoronacionAlfilB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_B2{ "recursos/menu/M_CoronacionCaballoB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_B2{ "recursos/menu/M_CoronacionTorreB2.png", 0 , 0, 40 ,60 };

	// coronaciones negras queen //
	Sprite MenuCoronar_N{ "recursos/menu/M_CoronacionN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_N{ "recursos/menu/M_CoronacionReinaN.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_N{ "recursos/menu/M_CoronacionAlfilN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_N{ "recursos/menu/M_CoronacionCaballoN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_N{ "recursos/menu/M_CoronacionTorreN.png", 0 , 0, 40 ,60 };

	// coronaciones negras king //
	Sprite MenuCoronar_N2{ "recursos/menu/M_CoronacionN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_N2{ "recursos/menu/M_CoronacionReinaN2.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_N2{ "recursos/menu/M_CoronacionAlfilN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_N2{ "recursos/menu/M_CoronacionCaballoN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_N2{ "recursos/menu/M_CoronacionTorreN2.png", 0 , 0, 40 ,60 };

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
	void setMenuPausa(int x);
	void setMenuAyuda(int x);
	void setMenuMovs(int x);
	void setMenuMovsEspeciales(int x);
	void setMenuMuchoTexto(int x);
	// getters //
	int getEstado();
	int getModoJuego();
	int getEstadoJuego();

protected:
	Tablero tablero;

	/// variables menu opciones //
	int opciones; // Q(0) K(1) Q+H(2) K+H(3) Q+E(4) K+E(5) Q+H+E(6) K+H+E(7)
	bool ayuda; // ayuda on(1)  ayuda off(0)
	bool tipojuego; // queens(0)  kings(1)
	/////////////////////////////

	// variables menu pausa //
	int pause; //  pausa(0) resume(1) restart(2) backto(3) exit(4)
	///////////////////////
	
	// variables menu help //
	int help; //  ayuda(0) mov(1) special rules(2) finpartida(3)
	int movs; // movs(0) pawn(1) bish(2) knig(3) rook(4) quee(5) king(6)
	int specialmovs; //specialmov(0) cast(1) pass(2) prom(3)
	int muchotexto; // pawn(0) bish(1) knig(2) rook(3) quee(4) king(5) end(6)
	///////////////////////
	
	// variables Jaque //
	int i = 0; 
	//////////////////////////

	enum Estado { INICIO, OPCIONES , JUEGO,  FIN}; //editar los estados
	Estado estado;

	enum EstadoJuego { TURNO, TURNO_NEGRAS, JAQUE, PAUSA, AYUDA, CORONAR_BLANCAS, CORONAR_NEGRAS }; // para gestionar Jugadores
	EstadoJuego estadojuego;

	enum Coronar{ C, REINA, TORRE, ALFIL, CABALLO};
	Coronar coronar;

    enum Inicio{I ,FREE_PLAY, STORY_MODE, OPTIONS};
	Inicio menu_inicio;

	enum HELPS{ H, MOVS, MOVSE, END, TEXT};
	HELPS menu_help;
};

