#pragma once
#include "Pieza.h"

#define MAX_PIEZAS 32

class ListaPiezas
{
private:
	Pieza* lista[MAX_PIEZAS];
	int numero;

public:
	ListaPiezas();

	bool agregar(Pieza* p);
	void draw();
	void movimientoValido(Casilla* c, Casilla* d);

	void destruirContenido();

	void eliminar(int index);
	void eliminar(Pieza* p);

	//virtual ~ListaPiezas();
};

