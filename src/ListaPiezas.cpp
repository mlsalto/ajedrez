#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	numero = 0;

	for (int i = 0; i < MAX_PIEZAS; i++)
		lista[i] = 0;
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
			eliminar(i);
			return;
		}
}