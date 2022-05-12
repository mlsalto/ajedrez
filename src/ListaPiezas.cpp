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

	eliminadaN1 = 0; eliminadaN2 = 0; eliminadaN3 = 0; eliminadaN4 = 0; eliminadaN5 = 0; eliminadaN6 = 0; eliminadaN7 = 0; eliminadaN8 = 0; eliminadaN9 = 0; eliminadaN10 = 0; eliminadaN11 = 0; eliminadaN12 = 0; eliminadaN13 = 0; eliminadaN14 = 0; eliminadaN15 = 0;
	eliminadaB1 = 0; eliminadaB2 = 0; eliminadaB3 = 0; eliminadaB4 = 0; eliminadaB5 = 0; eliminadaB6 = 0; eliminadaB7 = 0; eliminadaB8 = 0; eliminadaB9 = 0; eliminadaB10 = 0; eliminadaB11 = 0; eliminadaB12 = 0; eliminadaB13 = 0; eliminadaB14 = 0; eliminadaB15 = 0;
}

bool ListaPiezas::agregar(Pieza* p)
{
	if (numero < MAX_PIEZAS)
		lista[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaPiezas::draw()
{
	for (int i = 0; i < numero; i++)
		lista[i]->draw();
}

void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
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
			// que tipo de pieza está siendo eliminada //
			eliminada = p->getTipoPieza();

			// que numero de pieza eliminada es ( según si es blanca o negra )
			if (eliminada != 1 || (eliminada == 1 && ((p->getColorPieza() == 'B' && p->getCasilla()->getFila() != 7) || (p->getCasilla()->getFila() != 0 && p->getColorPieza() == 'N'))))
			{
				if (p->getColorPieza() == 'N') {
					numeroeliminadasN = numeroeliminadasN + 1;
					coloreliminada = 'N';
				}

				else if (p->getColorPieza() == 'B') {
					numeroeliminadasB = numeroeliminadasB + 1;
					coloreliminada = 'B';
				}
			}

			eliminar(i);
			return;
		}
}

void ListaPiezas::drawEliminadas()
{
	if (coloreliminada == 'N')
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

	if (coloreliminada == 'B')
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

		dibujarPiezas(eliminadaN1, 1, 1, 'N');
		dibujarPiezas(eliminadaN2, 2, 1, 'N');
		dibujarPiezas(eliminadaN3, 3, 1, 'N');
		dibujarPiezas(eliminadaN4, 4, 1, 'N');
		dibujarPiezas(eliminadaN5, 5, 1, 'N');
		dibujarPiezas(eliminadaN6, 1, 2, 'N');
		dibujarPiezas(eliminadaN7, 2, 2, 'N');
		dibujarPiezas(eliminadaN8, 3, 2, 'N');
		dibujarPiezas(eliminadaN9, 4, 2, 'N');
		dibujarPiezas(eliminadaN10, 5, 2, 'N');
		dibujarPiezas(eliminadaN11, 1, 3, 'N');
		dibujarPiezas(eliminadaN12, 2, 3, 'N');
		dibujarPiezas(eliminadaN13, 3, 3, 'N');
		dibujarPiezas(eliminadaN14, 4, 3, 'N');
		dibujarPiezas(eliminadaN15, 5, 3, 'N');
	
		dibujarPiezas(eliminadaB1, 1, 1, 'B');
		dibujarPiezas(eliminadaB2, 2, 1, 'B');
		dibujarPiezas(eliminadaB3, 3, 1, 'B');
		dibujarPiezas(eliminadaB4, 4, 1, 'B');
		dibujarPiezas(eliminadaB5, 5, 1, 'B');
		dibujarPiezas(eliminadaB6, 1, 2, 'B');
		dibujarPiezas(eliminadaB7, 2, 2, 'B');
		dibujarPiezas(eliminadaB8, 3, 2, 'B');
		dibujarPiezas(eliminadaB9, 4, 2, 'B');
		dibujarPiezas(eliminadaB10, 5, 2, 'B');
		dibujarPiezas(eliminadaB11, 1, 3, 'B');
		dibujarPiezas(eliminadaB12, 2, 3, 'B');
		dibujarPiezas(eliminadaB13, 3, 3, 'B');
		dibujarPiezas(eliminadaB14, 4, 3, 'B');
		dibujarPiezas(eliminadaB15, 5, 3, 'B');
}

void ListaPiezas::dibujarPiezas(int x, int y , int z, char a)
{
	if (a == 'N')
	{
		if (Tablero::getTipoJuego() == TRUE)
		{
			if (x == 1) { PeonA.setPos(45 + 5 * y, -3 - 7 * z); PeonA.draw(); }
			else if (x == 2) { TorreA.setPos(45 + 5 * y, -3 - 7 * z); TorreA.draw(); }
			else if (x == 3) { AlfilA.setPos(45 + 5 * y, -3 - 7 * z); AlfilA.draw(); }
			else if (x == 4) { CaballoA.setPos(45 + 5 * y, -3 - 7 * z); CaballoA.draw(); }
			else if (x == 5) { ReinaA.setPos(45 + 5 * y, -3 - 7 * z); ReinaA.draw(); }
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

	if (a == 'B')
	{
		if (Tablero::getTipoJuego() == TRUE)
		{
			if (x == 1) { PeonB.setPos(-75 + 5 * y, -3 - 7 * z); PeonB.draw(); }
			else if (x == 2) { TorreB.setPos(-75 + 5 * y, -3 - 7 * z); TorreB.draw(); }
			else if (x == 3) { AlfilB.setPos(-75 + 5 * y, -3 - 7 * z); AlfilB.draw(); }
			else if (x == 4) { CaballoB.setPos(-75 + 5 * y, -3 - 7 * z); CaballoB.draw(); }
			else if (x == 5) { ReinaB.setPos(-75 + 5 * y, -3 - 7 * z); ReinaB.draw(); }
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
