#pragma once
#include "Pieza.h"

#define MAX_PIEZAS 32

class ListaPiezas
{
private:
	Pieza* lista[MAX_PIEZAS];
	int numero;
	int eliminada;

	int numeroeliminadasN;
	int numeroeliminadasB;
	int eliminadaN1, eliminadaN2, eliminadaN3, eliminadaN4, eliminadaN5, eliminadaN6, eliminadaN7, eliminadaN8, eliminadaN9, eliminadaN10, eliminadaN11, eliminadaN12, eliminadaN13, eliminadaN14, eliminadaN15;
	int eliminadaB1, eliminadaB2, eliminadaB3, eliminadaB4, eliminadaB5, eliminadaB6, eliminadaB7, eliminadaB8, eliminadaB9, eliminadaB10, eliminadaB11, eliminadaB12, eliminadaB13, eliminadaB14, eliminadaB15;
	char coloreliminada;

	// Sprites de los peones //
	Sprite PeonN{ "recursos/piezas/peonN.png", 0, 0, 7, 7 };
	Sprite PeonB{ "recursos/piezas/peonB.png", 0, 0, 7, 7 };
	Sprite PeonA{ "recursos/piezas/peonA.png", 0, 0, 7, 7 };
	Sprite PeonR{ "recursos/piezas/peonR.png", 0, 0, 7, 7 };

	// Sprites de las torres //
	Sprite TorreN{ "recursos/piezas/torreN.png", 0, 0, 7, 7 };
	Sprite TorreB{ "recursos/piezas/torreB.png", 0, 0, 7, 7 };
	Sprite TorreA{ "recursos/piezas/torreA.png", 0, 0, 7, 7 };
	Sprite TorreR{ "recursos/piezas/torreR.png", 0, 0, 7, 7 };

	// Sprites de los alfiles //
	Sprite AlfilN{ "recursos/piezas/alfilN.png", 0, 0, 7, 7 };
	Sprite AlfilB{ "recursos/piezas/alfilB.png", 0, 0, 7, 7 };
	Sprite AlfilA{ "recursos/piezas/alfilA.png", 0, 0, 7, 7 };
	Sprite AlfilR{ "recursos/piezas/alfilR.png", 0, 0, 7, 7 };

	// Sprites de los caballos //
	Sprite CaballoN{ "recursos/piezas/caballoN.png", 0, 0, 7, 7 };
	Sprite CaballoB{ "recursos/piezas/caballoB.png", 0, 0, 7, 7 };
	Sprite CaballoA{ "recursos/piezas/caballoA.png", 0, 0, 7, 7 };
	Sprite CaballoR{ "recursos/piezas/caballoR.png", 0, 0, 7, 7 };

	// Sprites de las reinas //
	Sprite ReinaN{ "recursos/piezas/reinaN.png", 0, 0, 7, 7 };
	Sprite ReinaB{ "recursos/piezas/reinaB.png", 0, 0, 7, 7 };
	Sprite ReinaA{ "recursos/piezas/reinaA.png", 0, 0, 7, 7 };
	Sprite ReinaR{ "recursos/piezas/reinaR.png", 0, 0, 7, 7 };


public:
	ListaPiezas();

	bool agregar(Pieza* p);
	void draw();
	void drawEliminadas();

	void destruirContenido();

	void eliminar(int index);
	void eliminar(Pieza* p);

	void dibujarPiezas(int x, int y, int z, char a);
};

