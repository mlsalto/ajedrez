#include "ListaPiezas.h"

ListaPiezas::ListaPiezas()
{
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		lista[i] = 0;
}

ListaPiezas::~ListaPiezas()
{
}

bool ListaPiezas::agregar(Pieza* b)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i] == b) return false;
	}

	if (numero < MAX_PIEZAS) {
		lista[numero++] = b; // ¨²ltimo puesto sin rellenar
	}
	else {
		return false;
	}// capacidad m¨¢xima alcanzada
	return true;
}

//void ListaPiezas::dibujar(TipoPieza t) ///NO SE SI ESTÁ BIEN?????
//{
//	pieza = t;
//	switch (pieza) {
//	case REY:
//		break;
//	case 1:
//		break;
//	case 2:
//		break;
//	case 3:
//		break;
//	case 4:
//		break;
//	case 5:
//		break;
//	case 6:
//		break;
//	case 7:
//		break;
//	}	
//}