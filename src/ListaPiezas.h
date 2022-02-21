#pragma once

#define MAX_PIEZAS 16
#include "Pieza.h"

class ListaPiezas :public Pieza
{
private:

	Pieza* lista[MAX_PIEZAS];
	int numero;

public:
	ListaPiezas();
	/*virtual ~ListaPiezas();*/
	/*bool agregar(Pieza* b);*/

	void dibujar(ColorPieza t);

	/*void dibujaPeon();
	void dibujaRey();
	void dibujaReina();
	void dibujaCaballo();
	void dibujaAlfil();
	void dibujaTorre();

	void muevePeon();
	void mueveRey();
	void mueveReina();
	void mueveCaballo();
	void mueveAlfil();
	void mueveTorre();

	void eliminar(int index);
	void destruirContenido();
	void eliminar(Pieza* b);
	int getnumero() { return numero; }
	Pieza* operator[](int i);*/
};
