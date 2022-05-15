#pragma once
#include "Tablero.h"
#include "Persona.h"
#include "Jugador.h"
#include "IA1.h"
#include "IA2.h"

class Coordinador
{
private:

	// jaque //
	SpriteSequence Jaque{ "bin/recursos/CHECK_FRAME1.png", 34, 1, 50, true,0, 0, 150, 90 , 0};
	SpriteSequence Jaque1{ "bin/recursos/CHECK_FRAME1_rojo.png", 34, 1, 50, true,0, 0, 150, 90 , 0 };
	
	// jaque mate //
	SpriteSequence JaqueMate{ "bin/recursos/CHECKMATE_ANIMATION.png", 34, 1, 50, true,0, 0, 150, 90 , 0 };
	SpriteSequence JaqueMate1{ "bin/recursos/CHECKMATE_ANIMATION_rojo.png", 34, 1, 50, true,0, 0, 150, 90 , 0 };
	
	// menu inicial gambito dama //
	Sprite MenuInicial{ "bin/recursos/menu/inicio/Menu.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode{ "bin/recursos/menu/inicio/M_StoryMode.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay{ "bin/recursos/menu/inicio/M_FreePlay.png", 0, 0, 130, 80 };
	Sprite MenuOpciones{ "bin/recursos/menu/inicio/M_Options.png", 0, 0, 130, 80 };

	// menu inicial gambito rey //
	Sprite MenuInicial2{ "bin/recursos/menu/inicio/Menu2.png", 0, 0, 130, 80 };
	Sprite MenuStoryMode2{ "bin/recursos/menu/inicio/M_StoryMode2.png", 0, 0, 130, 80 };
	Sprite MenuFreePlay2{ "bin/recursos/menu/inicio/M_FreePlay2.png", 0, 0, 130, 80 };
	Sprite MenuOpciones2{ "bin/recursos/menu/inicio/M_Options2.png", 0, 0, 130, 80 };

	// menu opciones //
	Sprite QueenGam{ "bin/recursos/menu/opciones/M_OpcionesQ.png", 0, 0, 130, 80 };
	Sprite QueenGamH{ "bin/recursos/menu/opciones/M_OpcionesQH.png", 0, 0, 130, 80 };
	Sprite QueenGamE{ "bin/recursos/menu/opciones/M_OpcionesQE.png", 0, 0, 130, 80 };
	Sprite QueenGamHE{ "bin/recursos/menu/opciones/M_OpcionesQHE.png", 0, 0, 130, 80 };
	Sprite KingGam{ "bin/recursos/menu/opciones/M_OpcionesK.png", 0, 0, 130, 80 };
	Sprite KingGamH{ "bin/recursos/menu/opciones/M_OpcionesKH.png", 0, 0, 130, 80 };
	Sprite KingGamE{ "bin/recursos/menu/opciones/M_OpcionesKE.png", 0, 0, 130, 80 };
	Sprite KingGamHE{ "bin/recursos/menu/opciones/M_OpcionesKHE.png", 0, 0, 130, 80 };

    // menu Pausa queen // 
	Sprite PausaM{ "bin/recursos/menu/pausa/PAUSE_NS.png", 0, 0, 110, 50 };
	Sprite PausaResume{ "bin/recursos/menu/pausa/PAUSE_RESUME.png", 0, 0,110, 50 };
	Sprite PausaRestart{ "bin/recursos/menu/pausa/PAUSE_RESTAR.png", 0, 0, 110, 50 };
	Sprite PausaBack{ "bin/recursos/menu/pausa/PAUSE_BACKTO.png", 0, 0, 110, 50 };
	Sprite PausaExit{ "bin/recursos/menu/pausa/PAUSE_EXIR.png", 0, 0, 110, 50 };

	// menu Pausa king // 
	Sprite PausaM2{ "bin/recursos/menu/pausa/PAUSA_NS_rojo.png", 0, 0, 110, 50 };
	Sprite PausaResume2{ "bin/recursos/menu/pausa/PAUSE_RESUME_rojo.png", 0, 0,110, 50 };
	Sprite PausaRestart2{ "bin/recursos/menu/pausa/PAUSE_RESTART_rojo.png", 0, 0, 110, 50 };
	Sprite PausaBack2{ "bin/recursos/menu/pausa/PAUSE_BACKTO_rojo.png", 0, 0, 110, 50 };
	Sprite PausaExit2{ "bin/recursos/menu/pausa/PAUSE_EXIT_rojo.png", 0, 0, 110, 50 };

	// menu ayuda queen //
	Sprite HelpM{ "bin/recursos/menu/help/HELP_NS.png", 0, 0, 110, 50 };
	Sprite HelpMov{ "bin/recursos/menu/help/HELP_mov.png", 0, 0, 110, 50 };
	Sprite HelpSpeMov{ "bin/recursos/menu/help/HELP_SP.png", 0, 0, 110, 50 };
	Sprite HelpEnd{ "bin/recursos/menu/help/HELP_END.png", 0, 0, 110, 50 };

	// menu ayuda movs queen //
	Sprite HelpMovM{ "bin/recursos/menu/help/HELP_MOV_NS.png", 0, 0, 110, 50 };
	Sprite HelpMovP{ "bin/recursos/menu/help/HELP_MOV_PAWN.png", 0, 0, 110, 50 };
	Sprite HelpMovB{ "bin/recursos/menu/help/HELP_MOV_BISHOP.png", 0, 0, 110, 50 };
	Sprite HelpMovKn{ "bin/recursos/menu/help/HELP_MOV_KNIGHT.png", 0, 0, 110, 50 };
	Sprite HelpMovR{ "bin/recursos/menu/help/HELP_MOV_ROOK.png", 0, 0, 110, 50 };
	Sprite HelpMovQ{ "bin/recursos/menu/help/HELP_MOV_QUEEN.png", 0, 0, 110, 50 };
	Sprite HelpMovK{ "bin/recursos/menu/help/HELP_MOV_KING.png", 0, 0, 110, 50 };

	// menu ayuda mov esp queen //
	Sprite HelpMovEspM{ "bin/recursos/menu/help/HELP_SP_NS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspC{ "bin/recursos/menu/help/HELP_SP_CAS.png", 0, 0, 110, 50 };
	Sprite HelpMovEspE{ "bin/recursos/menu/help/HELP_SP_ENP.png", 0, 0, 110, 50 };
	Sprite HelpMovEspP{ "bin/recursos/menu/help/HELP_SP_PRO.png", 0, 0, 110, 50 };

	// menu ayuda king //
	Sprite HelpM2{ "bin/recursos/menu/help/HELP_NS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMov2{ "bin/recursos/menu/help/HELP_mov_rojo.png", 0, 0, 110, 50 };
	Sprite HelpSpeMov2{ "bin/recursos/menu/help/HELP_SP_rojo.png", 0, 0, 110, 50 };
	Sprite HelpEnd2{ "bin/recursos/menu/help/HELP_END_rojo.png", 0, 0, 110, 50 };

	// menu ayuda movs king //
	Sprite HelpMovM2{ "bin/recursos/menu/help/HELP_MOV_NS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovP2{ "bin/recursos/menu/help/HELP_MOV_PAWN_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovB2{ "bin/recursos/menu/help/HELP_MOV_BISHOP_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovKn2{ "bin/recursos/menu/help/HELP_MOV_KNIGHT_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovR2{ "bin/recursos/menu/help/HELP_MOV_ROOK_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovQ2{ "bin/recursos/menu/help/HELP_MOV_QUEEN_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovK2{ "bin/recursos/menu/help/HELP_MOV_KING_rojo.png", 0, 0, 110, 50 };

	// menu ayuda mov esp king //
	Sprite HelpMovEspM2{ "bin/recursos/menu/help/HELP_SP_NS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovEspC2{ "bin/recursos/menu/help/HELP_SP_CAS_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovEspE2{ "bin/recursos/menu/help/HELP_SP_ENP_rojo.png", 0, 0, 110, 50 };
	Sprite HelpMovEspP2{ "bin/recursos/menu/help/HELP_SP_PRO_rojo.png", 0, 0, 110, 50 };

	// menu flecha //
	Sprite Flecha{ "bin/recursos/BACKNARROW.png", -45, 17, 8, 4};
	Sprite Flecha1{ "bin/recursos/BACKNARROW1.png", -45, 17, 8, 4 };

	// menu ayuda mucho texto //
	Sprite HelpBish{ "bin/recursos/menu/muchotexto/BISHOP_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpPawn{ "bin/recursos/menu/muchotexto/PAWN_MUCHOTEXTO.png", 0, 0, 110, 50 };
	Sprite HelpRook{ "bin/recursos/menu/muchotexto/ROOK_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKnig{ "bin/recursos/menu/muchotexto/HORSE_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpKing{ "bin/recursos/menu/muchotexto/KING_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpQuee{ "bin/recursos/menu/muchotexto/QUEEN_TEXT.png", 0, 0, 110, 50 };
	Sprite HelpCast{ "bin/recursos/menu/muchotexto/CASTLINH_MUCHO_TEXTO.png", 0, 0, 110, 50 };
	Sprite HelpPass{ "bin/recursos/menu/muchotexto/ENPASSANT_MUCHOTEXTO.png", 0, 0, 110, 50 };
	Sprite HelpProm{ "bin/recursos/menu/muchotexto/promotion_MUCHOTEXTOAAA.png", 0, 0, 110, 50 };
	Sprite HelpEndg{ "bin/recursos/menu/muchotexto/ENDGAME_MUCHOTEXTO.png", 0, 0, 110, 50 };

	// menu botones help y pause //
	Sprite BotonHP_azul{ "bin/recursos/help_pause_azul.png", 60 , -35 , 16 , 8};
	Sprite BotonHP_rojo{ "bin/recursos/help_pause_rojo.png", 60 , -35 , 16 , 8};

	// coronaciones blancas queen //
	Sprite MenuCoronar_B{"bin/recursos/menu/coronacion/M_CoronacionB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_B{ "bin/recursos/menu/coronacion/M_CoronacionReinaB.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_B{ "bin/recursos/menu/coronacion/M_CoronacionAlfilB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_B{ "bin/recursos/menu/coronacion/M_CoronacionCaballoB.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_B{ "bin/recursos/menu/coronacion/M_CoronacionTorreB.png", 0 , 0, 40 ,60 };

	// coronaciones blancas king //
	Sprite MenuCoronar_B2{ "bin/recursos/menu/coronacion/M_CoronacionB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_B2{ "bin/recursos/menu/coronacion/M_CoronacionReinaB2.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_B2{ "bin/recursos/menu/coronacion/M_CoronacionAlfilB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_B2{ "bin/recursos/menu/coronacion/M_CoronacionCaballoB2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_B2{ "bin/recursos/menu/coronacion/M_CoronacionTorreB2.png", 0 , 0, 40 ,60 };

	// coronaciones negras queen //
	Sprite MenuCoronar_N{ "bin/recursos/menu/coronacion/M_CoronacionN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_N{ "bin/recursos/menu/coronacion/M_CoronacionReinaN.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_N{ "bin/recursos/menu/coronacion/M_CoronacionAlfilN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_N{ "bin/recursos/menu/coronacion/M_CoronacionCaballoN.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_N{ "bin/recursos/menu/coronacion/M_CoronacionTorreN.png", 0 , 0, 40 ,60 };

	// coronaciones negras king //
	Sprite MenuCoronar_N2{ "bin/recursos/menu/coronacion/M_CoronacionN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarReina_N2{ "bin/recursos/menu/coronacion/M_CoronacionReinaN2.png", 0 , 0,40 ,60 };
	Sprite MenuCoronarAlfil_N2{ "bin/recursos/menu/coronacion/M_CoronacionAlfilN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarCaballo_N2{ "bin/recursos/menu/coronacion/M_CoronacionCaballoN2.png", 0 , 0, 40 ,60 };
	Sprite MenuCoronarTorre_N2{ "bin/recursos/menu/coronacion/M_CoronacionTorreN2.png", 0 , 0, 40 ,60 };

	// menu ganador blanco queen //
	Sprite MenuGanadorB{ "bin/recursos/menu/ganador/WHITE_WINS_NS.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReB{ "bin/recursos/menu/ganador/WHITE_WINS_REMATCH.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaB{ "bin/recursos/menu/ganador/WHITE_WINS_BACKTOMENU.png", 0, 0, 110, 50 };

	// menu ganador negro queen//
	Sprite MenuGanadorN{ "bin/recursos/menu/ganador/BLACK_WINS_NS.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReN{ "bin/recursos/menu/ganador/BLACK_WINS_REMATCH.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaN{ "bin/recursos/menu/ganador/BLACK_WINS_BACKTOMENU.png", 0, 0, 110, 50 };

	// menu ganador blanco king //
	Sprite MenuGanadorB2{ "bin/recursos/menu/ganador/WHITE_WINS_NS_rojo.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReB2{ "bin/recursos/menu/ganador/WHITE_WINS_REMATCH_rojo.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaB2{ "bin/recursos/menu/ganador/WHITE_WINS_BACKTOMENU_rojo.png", 0, 0, 110, 50 };

	// menu ganador negro king //
	Sprite MenuGanadorN2{ "bin/recursos/menu/ganador/BLACK_WINS_NS_rojo.png", 0, 0, 110, 50 };
	Sprite MenuGanadorReN2{ "bin/recursos/menu/ganador/BLACK_WINS_REMATCH_rojo.png", 0, 0, 110, 50 };
	Sprite MenuGanadorBaN2{ "bin/recursos/menu/ganador/BLACK_WINS_BACKTOMENU_rojo.png", 0, 0, 110, 50 };

	// menu personaje blanco queens //
	Sprite PerBQ{ "bin/recursos/menu/personajes/PLAYER1_VACIO_AZUL.png", 0, 0, 130, 80 };
	Sprite PerBQ_BT{ "bin/recursos/menu/personajes/PLAYER1_BETH_AZUL.png", 0, 0, 130, 80 };
	Sprite PerBQ_MS{ "bin/recursos/menu/personajes/PLAYER1_MRSHEIBEL_AZUL.png", 0, 0, 130, 80 };
	Sprite PerBQ_BE{ "bin/recursos/menu/personajes/PLAYER1_BENNY_AZUL.png", 0, 0, 130, 80 };
	Sprite PerBQ_BB{ "bin/recursos/menu/personajes/PLAYER1_BABYBETH_AZUL.png", 0, 0, 130, 80 };
	
	// menu personaje negro queens //
	Sprite PerNQ{ "bin/recursos/menu/personajes/PLAYER2_VACIO_AZUL.png", 0, 0, 130, 80 };
	Sprite PerNQ_BT{ "bin/recursos/menu/personajes/PLAYER2_BETH_AZUL.png", 0, 0, 130, 80 };
	Sprite PerNQ_MS{ "bin/recursos/menu/personajes/PLAYER2_MRSHEIBEL_AZUL.png", 0, 0, 130, 80 };
	Sprite PerNQ_BE{ "bin/recursos/menu/personajes/PLAYER2_BENNY_AZUL.png", 0, 0, 130, 80 };
	Sprite PerNQ_BB{ "bin/recursos/menu/personajes/PLAYER2_BABYBETH_AZUL.png", 0, 0, 130, 80 };

	// menu personaje blanco kings //
	Sprite PerBK{ "bin/recursos/menu/personajes/PLAYER1_VACIO_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TB{ "bin/recursos/menu/personajes/PLAYER1_TB_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TC{ "bin/recursos/menu/personajes/PLAYER1_TC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TH{ "bin/recursos/menu/personajes/PLAYER1_TH_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TJ{ "bin/recursos/menu/personajes/PLAYER1_TJC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TM{ "bin/recursos/menu/personajes/PLAYER1_TM_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TO{ "bin/recursos/menu/personajes/PLAYER1_TOJ_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TP{ "bin/recursos/menu/personajes/PLAYER1_TP_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TR{ "bin/recursos/menu/personajes/PLAYER1_TR_ROJO.png", 0, 0, 130, 80 };
	Sprite PerBK_TS{ "bin/recursos/menu/personajes/PLAYER1_TS_ROJO.png", 0, 0, 130, 80 };

	// menu personaje negro kings //
	Sprite PerNK{ "bin/recursos/menu/personajes/PLAYER2_VACIO_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TB{ "bin/recursos/menu/personajes/PLAYER2_TB_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TC{ "bin/recursos/menu/personajes/PLAYER2_TC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TH{ "bin/recursos/menu/personajes/PLAYER2_TH_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TJ{ "bin/recursos/menu/personajes/PLAYER2_TJC_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TM{ "bin/recursos/menu/personajes/PLAYER2_TM_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TO{ "bin/recursos/menu/personajes/PLAYER2_TOJ_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TP{ "bin/recursos/menu/personajes/PLAYER2_TP_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TR{ "bin/recursos/menu/personajes/PLAYER2_TR_ROJO.png", 0, 0, 130, 80 };
	Sprite PerNK_TS{ "bin/recursos/menu/personajes/PLAYER2_TS_ROJO.png", 0, 0, 130, 80 };

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

	//variable de musica//
	bool musicajaque;
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

