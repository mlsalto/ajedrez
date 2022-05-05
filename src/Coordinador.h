#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"

class Coordinador
{
private:

	// jaque //
	SpriteSequence Jaque{ "recursos/CHECK_FRAME1.png", 34, 1, 50, true,0, 0, 150, 90 , 0};
	SpriteSequence Jaque1{ "recursos/CHECK_FRAME1_rojo.png", 34, 1, 50, true,0, 0, 150, 90 , 0 };
	
	// jaque mate //
	SpriteSequence JaqueMate{ "recursos/CHECKMATE__animation.png", 47, 1, 50, true,0, 0, 150, 90 , 0 };
	SpriteSequence JaqueMate1{ "recursos/CHECKMATE__animation_rojo.png", 47, 1, 50, true,0, 0, 150, 90 , 0 };
	
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

	// menu ayuda king //
	Sprite HelpM2{ "recursos/menu/help/HELP_NS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMov2{ "recursos/menu/help/HELP_mov_rojo.png", 0, 0, 110, 50 };
	Sprite HelpSpeMov2{ "recursos/menu/help/HELP_SP_rojo.png", 0, 0, 110, 50 };
	Sprite HelpEnd2{ "recursos/menu/help/HELP_END.png", 0, 0, 110, 50 };

	// menu ayuda movs king //
	Sprite HelpMovM2{ "recursos/menu/help/HELP_MOV_NS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovP2{ "recursos/menu/help/HELP_MOV_PAWN_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovB2{ "recursos/menu/help/HELP_MOV_BISHOP_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovKn2{ "recursos/menu/help/HELP_MOV_KNIGHT_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovR2{ "recursos/menu/help/HELP_MOV_ROOK_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovQ2{ "recursos/menu/help/HELP_MOV_QUEEN_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovK2{ "recursos/menu/help/HELP_MOV_KING_rojo.png", 0, 0, 110, 50 };

	// menu ayuda mov esp king //
	Sprite HelpMovEspM2{ "recursos/menu/help/HELP_SP_NS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspC2{ "recursos/menu/help/HELP_SP_CAS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspE2{ "recursos/menu/help/HELP_SP_ENP.png", 0, 0, 110, 50 };
	Sprite HelpMovEspP2{ "recursos/menu/help/HELP_SP_PRO.png", 0, 0, 110, 50 };

	// menu flecha //
	Sprite Flecha{ "recursos/BACKNARROW.png", -45, 17, 8, 4};
	Sprite Flecha1{ "recursos/BACKNARROW1.png", -45, 17, 8, 4 };

	// menu ayuda mucho texto //
	Sprite HelpBish{ "recursos/menu/muchotexto/BISHOP_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpPawn{ "recursos/menu/muchotexto/PAWN_MUCHOTEXTO.png", 0, 0, 110, 50 };
	Sprite HelpRook{ "recursos/menu/muchotexto/ROOK_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKnig{ "recursos/menu/muchotexto/HORSE_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKing{ "recursos/menu/muchotexto/KING_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpQuee{ "recursos/menu/muchotexto/QUEEN_TEXT.png", 0, 0, 110, 50 };

	// menu botones help y pause //
	Sprite BotonHP_azul{ "recursos/help_pause_azul.png", 60 , -35 , 16 , 8};
	Sprite BotonHP_rojo{ "recursos/help_pause_rojo.png", 60 , -35 , 16 , 8};

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

	// menu ganador blanco //
	Sprite MenuGanadorB{ "recursos/menu/WHITE_WINS_NS.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReB{ "recursos/menu/WHITE_WINS_REMATCH.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaB{ "recursos/menu/WHITE_WINS_BACKTOMENU.png", 0, 0, 110, 50 };

	// menu ganador negro //
	Sprite MenuGanadorN{ "recursos/menu/BLACK_WINS_NS.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReN{ "recursos/menu/BLACK_WINS_REMATCH.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaN{ "recursos/menu/BLACK_WINS_BACKTOMENU.png", 0, 0, 110, 50 };

	// menu personaje blanco kings //
	Sprite PerBK{ "recursos/menu/personajes/PLAYER1_VACIO_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TB{ "recursos/menu/personajes/PLAYER1_TB_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TC{ "recursos/menu/personajes/PLAYER1_TC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TH{ "recursos/menu/personajes/PLAYER1_TH_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TJ{ "recursos/menu/personajes/PLAYER1_TJC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TM{ "recursos/menu/personajes/PLAYER1_TM_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TO{ "recursos/menu/personajes/PLAYER1_TOJ_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TP{ "recursos/menu/personajes/PLAYER1_TP_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TR{ "recursos/menu/personajes/PLAYER1_TR_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TS{ "recursos/menu/personajes/PLAYER1_TS_ROJO.png", 0, 0, 130, 80 };

	// menu personaje negro kings //
	Sprite PerNK{ "recursos/menu/personajes/PLAYER2_VACIO_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TB{ "recursos/menu/personajes/PLAYER2_TB_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TC{ "recursos/menu/personajes/PLAYER2_TC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TH{ "recursos/menu/personajes/PLAYER2_TH_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TJ{ "recursos/menu/personajes/PLAYER2_TJC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TM{ "recursos/menu/personajes/PLAYER2_TM_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TO{ "recursos/menu/personajes/PLAYER2_TOJ_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TP{ "recursos/menu/personajes/PLAYER2_TP_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TR{ "recursos/menu/personajes/PLAYER2_TR_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TS{ "recursos/menu/personajes/PLAYER2_TS_ROJO.png", 0, 0, 130, 80 };

public:
	Coordinador();
	virtual ~Coordinador();

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
	void setMenuFinal(int x);
	void setPersonajeB(int x);
	void setPersonajeN(int x);

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
	
	// variables Jaque y Jaque Mate//
	int i = 0; 
	//////////////////////////

	// variables Jaque y Jaque Mate//
	int ganador; // blancas(0) negras (1)
	int final; // final (0) rematch (1) back to(2)
	//////////////////////////

	// variables menu personajes //
	int personajeB;
	int personajeN;
	//////////////////////////////

	enum Estado { INICIO, OPCIONES , S_PER_BLANCO, S_PER_NEGRO, JUEGO,  FIN}; //editar los estados
	Estado estado;

	enum EstadoJuego { TURNO, TURNO_NEGRAS, JAQUE, JAQUE_MATE, PAUSA, AYUDA, CORONAR_BLANCAS, CORONAR_NEGRAS }; // para gestionar Jugadores
	EstadoJuego estadojuego;

	enum Coronar{ C, REINA, TORRE, ALFIL, CABALLO};
	Coronar coronar;

    enum Inicio{I ,FREE_PLAY, STORY_MODE, OPTIONS};
	Inicio menu_inicio;

	enum HELPS{ H, MOVS, MOVSE, END, TEXT};
	HELPS menu_help;
};

