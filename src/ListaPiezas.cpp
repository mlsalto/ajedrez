#include "ListaPiezas.h"
#include "Tablero.h"

ListaPiezas::ListaPiezas()
{
	numero = 0;
	eliminada = 0;
    numeroeliminadasN = 0;
	numeroeliminadasB = 0;

	for (int i = 0; i < MAX_PIEZAS; i++)
		lista[i] = 0;
}

bool ListaPiezas::agregar(Pieza* p)
{
	if (numero < MAX_PIEZAS)
		lista[numero++] = p; // �ltimo puesto sin rellenar
	else
		return false; // capacidad m�xima alcanzada
	return true;
}

void ListaPiezas::draw()
{
	for (int i = 0; i < numero; i++)
		lista[i]->draw();
}


void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaPiezas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaPiezas::eliminar(Pieza* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
		{
			// que tipo de pieza est� siendo eliminada //
			eliminada = p->getTipoPieza();

			// que numero de pieza eliminada es ( seg�n si es blanca o negra )
			if (eliminada != 1 && ((p->getCasilla()->getFila() != 1 && p->getColorPieza() != 'N') || (p->getCasilla()->getFila() != 6 && p->getColorPieza() != 'B')))
			{
				if (p->getColorPieza() == 'N') {
					numeroeliminadasN++;
					coloreliminada = 'N';
				}

				if (p->getColorPieza() == 'B') {
					numeroeliminadasB++;
					coloreliminada = 'B';
				}
			}

			drawEliminadasN();
			drawEliminadasB();

			eliminar(i);
			return;
		}
}

void ListaPiezas::drawEliminadasN()
{
	if (coloreliminada = 'N')
	{
		if (numeroeliminadasN == 1) eliminadaN1 = eliminada;
		if (numeroeliminadasN == 2) eliminadaN2 = eliminada;
		if (numeroeliminadasN == 3) eliminadaN3 = eliminada;
		if (numeroeliminadasN == 4) eliminadaN4 = eliminada;
		if (numeroeliminadasN == 5) eliminadaN5 = eliminada;
		if (numeroeliminadasN == 6) eliminadaN6 = eliminada;
		if (numeroeliminadasN == 7) eliminadaN7 = eliminada;
		if (numeroeliminadasN == 8) eliminadaN8 = eliminada;
		if (numeroeliminadasN == 9) eliminadaN9 = eliminada;
		if (numeroeliminadasN == 10) eliminadaN10 = eliminada;
		if (numeroeliminadasN == 11) eliminadaN11 = eliminada;
		if (numeroeliminadasN == 12) eliminadaN12 = eliminada;
		if (numeroeliminadasN == 13) eliminadaN13 = eliminada;
		if (numeroeliminadasN == 14) eliminadaN14 = eliminada;
		if (numeroeliminadasN == 15) eliminadaN15 = eliminada;
	}
		dibujarPiezas(eliminadaN1, 1, 1);
		dibujarPiezas(eliminadaN2, 2, 1);
		dibujarPiezas(eliminadaN3, 3, 1);
		dibujarPiezas(eliminadaN4, 4, 1);
		dibujarPiezas(eliminadaN5, 5, 1);
		dibujarPiezas(eliminadaN6, 1, 2);
		dibujarPiezas(eliminadaN7, 2, 2);
		dibujarPiezas(eliminadaN8, 3, 2);
		dibujarPiezas(eliminadaN9, 4, 2);
		dibujarPiezas(eliminadaN10, 5, 2);
		dibujarPiezas(eliminadaN11, 1, 3);
		dibujarPiezas(eliminadaN12, 2, 3);
		dibujarPiezas(eliminadaN13, 3, 3);
		dibujarPiezas(eliminadaN14, 4, 3);
		dibujarPiezas(eliminadaN15, 5, 3);
	
}

void ListaPiezas::drawEliminadasB()
{
	if (coloreliminada = 'B')
	{
		if (numeroeliminadasB == 1) eliminadaB1 = eliminada;
		if (numeroeliminadasB == 2) eliminadaB2 = eliminada;
		if (numeroeliminadasB == 3) eliminadaB3 = eliminada;
		if (numeroeliminadasB == 4) eliminadaB4 = eliminada;
		if (numeroeliminadasB == 5) eliminadaB5 = eliminada;
		if (numeroeliminadasB == 6) eliminadaB6 = eliminada;
		if (numeroeliminadasB == 7) eliminadaB7 = eliminada;
		if (numeroeliminadasB == 8) eliminadaB8 = eliminada;
		if (numeroeliminadasB == 9) eliminadaB9 = eliminada;
		if (numeroeliminadasB == 10) eliminadaB10 = eliminada;
		if (numeroeliminadasB == 11) eliminadaB11 = eliminada;
		if (numeroeliminadasB == 12) eliminadaB12 = eliminada;
		if (numeroeliminadasB == 13) eliminadaB13 = eliminada;
		if (numeroeliminadasB == 14) eliminadaB14 = eliminada;
		if (numeroeliminadasB == 15) eliminadaB15 = eliminada;
	}

	dibujarPiezas(eliminadaB1, 1, 1);
	dibujarPiezas(eliminadaB2, 2, 1);
	dibujarPiezas(eliminadaB3, 3, 1);
	dibujarPiezas(eliminadaB4, 4, 1);
	dibujarPiezas(eliminadaB5, 5, 1);
	dibujarPiezas(eliminadaB6, 1, 2);
	dibujarPiezas(eliminadaB7, 2, 2);
	dibujarPiezas(eliminadaB8, 3, 2);
	dibujarPiezas(eliminadaB9, 4, 2);
	dibujarPiezas(eliminadaB10, 5, 2);
	dibujarPiezas(eliminadaB11, 1, 3);
	dibujarPiezas(eliminadaB12, 2, 3);
	dibujarPiezas(eliminadaB13, 3, 3);
	dibujarPiezas(eliminadaB14, 4, 3);
	dibujarPiezas(eliminadaB15, 5, 3);
}


void ListaPiezas::dibujarPiezas(int x, int y , int z)
{
	if (coloreliminada == 'N')
	{
		if (Tablero::getTipoJuego() == TRUE)
		{
			if (x == 1) { PeonA.setPos(45 + 5 * y, -3 - 7 * z); PeonA.draw(); }
			if (x == 2) { TorreA.setPos(45 + 5 * y, -3 - 7 * z); TorreA.draw(); }
			if (x == 3) { AlfilA.setPos(45 + 5 * y, -3 - 7 * z); AlfilA.draw(); }
			if (x == 4) { CaballoA.setPos(45 + 5 * y, -3 - 7 * z); CaballoA.draw(); }
			if (x == 5) { ReinaA.setPos(45 + 5 * y, -3 - 7 * z); ReinaA.draw(); }
		}

		if (Tablero::getTipoJuego() == FALSE)
		{
			if (x == 1) { PeonN.setPos(45 + 5 * y, -3 - 7 * z); PeonN.draw(); }
			if (x == 2) { TorreN.setPos(45 + 5 * y, -3 - 7 * z); TorreN.draw(); }
			if (x == 3) { AlfilN.setPos(45 + 5 * y, -3 - 7 * z); AlfilN.draw(); }
			if (x == 4) { CaballoN.setPos(45 + 5 * y, -3 - 7 * z); CaballoN.draw(); }
			if (x == 5) { ReinaN.setPos(45 + 5 * y, -3 - 7 * z); ReinaN.draw(); }
		}
	}

	if (coloreliminada == 'B')
	{
		if (Tablero::getTipoJuego() == TRUE)
		{
			if (x == 1) { PeonB.setPos(-75 + 5 * y, -3 - 7 * z); PeonB.draw(); }
			if (x == 2) { TorreB.setPos(-75 + 5 * y, -3 - 7 * z); TorreB.draw(); }
			if (x == 3) { AlfilB.setPos(-75 + 5 * y, -3 - 7 * z); AlfilB.draw(); }
			if (x == 4) { CaballoB.setPos(-75 + 5 * y, -3 - 7 * z); CaballoB.draw(); }
			if (x == 5) { ReinaB.setPos(-75 + 5 * y, -3 - 7 * z); ReinaB.draw(); }
		}

		if (Tablero::getTipoJuego() == FALSE)
		{
			if (x == 1) { PeonR.setPos(-75 + 5 * y, -3 - 7 * z); PeonR.draw(); }
			if (x == 2) { TorreR.setPos(-75 + 5 * y, -3 - 7 * z); TorreR.draw(); }
			if (x == 3) { AlfilR.setPos(-75 + 5 * y, -3 - 7 * z); AlfilR.draw(); }
			if (x == 4) { CaballoR.setPos(-75 + 5 * y, -3 - 7 * z); CaballoR.draw(); }
			if (x == 5) { ReinaR.setPos(-75 + 5 * y, -3 - 7 * z); ReinaR.draw(); }
		}
	}
}
