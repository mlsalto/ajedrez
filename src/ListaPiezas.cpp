#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		lista[i] = 0;
}
//
//ListaPiezas::~ListaPiezas()
//{
//}
//
//bool ListaPiezas::agregar(Pieza* b)
//{
//	for (int i = 0; i < numero; i++)
//	{
//		if (lista[i] == b) return false;
//	}
//
//	if (numero < MAX_PIEZAS) {
//		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
//	}
//	else {
//		return false;
//	}// capacidad m¨¢xima alcanzada
//	return true;
//}

//void ListaPiezas::dibujar(ColorPieza t) ///NO SE SI ESTÁ BIEN?????
//{
//	switch (t) {
//	case NEGRO:
//		break;
//	case BLANCO:
//		lista[numero]->setColorPieza(BLANCO);
//		lista[numero]->setTipoPieza(TORRE);
//		lista[numero]->dibujarPieza(TORRE);
//		break;
//	}
//}
