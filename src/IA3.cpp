#include "IA3.h"

IA3::IA3() {}

IA3::IA3(char colorJugador)
{
	color = colorJugador;
}

void IA3::moverPieza(int button, int state, int x, int y)
{
	turnoterminado = FALSE;
	int x_ini = 0, x_fin = 0, y_ini = 0, y_fin = 0;
	int puntos = 0;
	int posfinx = 0, posfiny = 0;
	int posinix = 0, posiniy = 0;
	int maximo = 0;

}