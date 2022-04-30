#include "Tablero.h"
#include "freeglut.h"

Casilla* Tablero::casillas[8][8];
ListaPiezas Tablero::piezas;

Tablero::Tablero(){}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j] = new Casilla(i, j);

	// torres
	Torre* t1b = new Torre('B');
	Torre* t2b = new Torre('B');
	Torre* t1n = new Torre('N');
	Torre* t2n = new Torre('N');

	// caballos
	Caballo* c1b = new Caballo('B');
	Caballo* c2b = new Caballo('B');
	Caballo* c1n = new Caballo('N');
	Caballo* c2n = new Caballo('N');

	//Peones blancos (1)
	Peon* p1b = new Peon('B');
	Peon* p2b = new Peon('B');
	Peon* p3b = new Peon('B');
	Peon* p4b = new Peon('B');
	Peon* p5b = new Peon('B');
	Peon* p6b = new Peon('B');
	Peon* p7b = new Peon('B');
	Peon* p8b = new Peon('B');

	//Peones negros (1)
	Peon* p1n = new Peon('N');
	Peon* p2n = new Peon('N');
	Peon* p3n = new Peon('N');
	Peon* p4n = new Peon('N');
	Peon* p5n = new Peon('N');
	Peon* p6n = new Peon('N');
	Peon* p7n = new Peon('N');
	Peon* p8n = new Peon('N');

	//rey
	Rey* kb = new Rey('B');
	Rey* kn = new Rey('N');

	//reina
	Reina* qb = new Reina('B');
	Reina* qn = new Reina('N');

	//alfiles
	Alfil* a1n = new Alfil('N');
	Alfil* a2n = new Alfil('N');
	Alfil* a1b = new Alfil('B');
	Alfil* a2b = new Alfil('B');

    //coloca las piezas en cada casilla
	// Torre(t), Caballo(c), Peon (p), Rey(k), Reina(q), Alfil (a)

	// PRIMERA FILA BLANCA
	casillas[0][0]->colocarPieza(t1b);
	casillas[1][0]->colocarPieza(c1b);
	casillas[3][0]->colocarPieza(qb);
	casillas[2][0]->colocarPieza(a1b);
	casillas[3][0]->colocarPieza(qb);
	casillas[4][0]->colocarPieza(kb);
	casillas[5][0]->colocarPieza(a2b);
	casillas[6][0]->colocarPieza(c2b);
	casillas[7][0]->colocarPieza(t2b);

	// SEGUNDA FILA BLANCA
	casillas[0][1]->colocarPieza(p1b);
	casillas[1][1]->colocarPieza(p2b);
	casillas[2][1]->colocarPieza(p3b);
	casillas[3][1]->colocarPieza(p4b);
	casillas[4][1]->colocarPieza(p5b);
	casillas[5][1]->colocarPieza(p6b);
	casillas[6][1]->colocarPieza(p7b);
	casillas[7][1]->colocarPieza(p8b);

	// PRIMERA FILA NEGRA
	casillas[0][7]->colocarPieza(t1n);
	casillas[1][7]->colocarPieza(c1n); 
	casillas[2][7]->colocarPieza(a1n);
	casillas[3][7]->colocarPieza(qn);
	casillas[4][7]->colocarPieza(kn);
	casillas[5][7]->colocarPieza(a2n);
	casillas[6][7]->colocarPieza(c2n);
	casillas[7][7]->colocarPieza(t2n);

	// SEGUNDA FILA NEGRA
	casillas[0][6]->colocarPieza(p1n);
	casillas[1][6]->colocarPieza(p2n);
	casillas[2][6]->colocarPieza(p3n);
	casillas[3][6]->colocarPieza(p4n);
	casillas[4][6]->colocarPieza(p5n);
	casillas[5][6]->colocarPieza(p6n);
	casillas[6][6]->colocarPieza(p7n);
	casillas[7][6]->colocarPieza(p8n);

	/// AGREGAR PIEZAS BLANCAS ///
	piezas.agregar(c1b);
	piezas.agregar(c2b);

	piezas.agregar(kb);
	piezas.agregar(qb);

	piezas.agregar(t1b);
	piezas.agregar(t2b);

	piezas.agregar(a1b);
	piezas.agregar(a2b);

	piezas.agregar(p1b);
	piezas.agregar(p2b);
	piezas.agregar(p3b);
	piezas.agregar(p4b);
	piezas.agregar(p5b);
	piezas.agregar(p6b);
	piezas.agregar(p7b);
	piezas.agregar(p8b);

	/// AGREGAR PIEZAS NEGRAS ///
	piezas.agregar(c1n);
	piezas.agregar(c2n);

	piezas.agregar(kn);
	piezas.agregar(qn);

	piezas.agregar(t1n);
	piezas.agregar(t2n);

	piezas.agregar(a1n);
	piezas.agregar(a2n);

	piezas.agregar(p1n);
	piezas.agregar(p2n);
	piezas.agregar(p3n);
	piezas.agregar(p4n);
	piezas.agregar(p5n);
	piezas.agregar(p6n);
	piezas.agregar(p7n);
	piezas.agregar(p8n);
}

void Tablero::dibuja()
{
	//el tablero tiene que dibujarse el último para dibujarse detrás y que no
	//tape a las figuras
	jugador1->draw(1);
	jugador2->draw(2);

	piezas.draw();

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
	        casillas[i][j]->draw();

	tableroAjedrez.draw();
	marcoTablero.draw();
	letrasTablero.draw();
}

void Tablero::ratonTablero(int button, int state, int x, int y)
{
	if (turno == TRUE)
	{
		jugador1->moverPieza(button, state, x, y);
		if (jugador1->turnoTerminado() == TRUE)
		{
			turno = FALSE;
		}
	}

	if (turno == FALSE)
	{
		jugador2->moverPieza(button, state, x, y);
		if (jugador2->turnoTerminado() == TRUE)
		{
			turno = TRUE;
		}
	}
}

//En tu turno, compruebas si puedes hacer jaque al contrincante
//A la función le pasas el color de las piezas que van a hacer el jaque
bool Tablero::detectar_jaque(char color)
{
	//salida int para comprobar el jaque: 0=no hay jaque; 1=jaque al rey BLANCO; 2=jaque al rey NEGRO

	//bucle anidado para recorrer el tablero y saber en qué casilla se encuentra el rey contrario
	// rey == 6
	bool rey = false;
	int i, j;
	int pos_rey_x, pos_rey_y;

	for (i = 0; i < 8 && rey == false; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (casillas[i][j]->getTipoPieza() == 6 && casillas[i][j]->getPieza()->getColorPieza() == color)
			{
				pos_rey_x = casillas[i][j]->getColumna();
				pos_rey_y = casillas[i][j]->getFila();
				rey = true;
			}
		}
	}

	//bucle anidado para recorrer el tablero y comprobar si alguna pieza puede hacer jaque a la posición actual del rey
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (casillas[i][j]->getOcupada() == true && casillas[i][j]->getPieza()->movimientoLegal(casillas[pos_rey_x][pos_rey_y]) == true)
				return true;
		}
	}
	return false;
}


void Tablero::eliminarPiezaT(int x, int y)
{
	piezas.eliminar(casillas[x][y]->getPieza());
}

void Tablero::setJugador1(Jugador* j)
{
	jugador1 = j;
}

void Tablero::setJugador2(Jugador* j)
{
	jugador2 = j;
}

Pieza* Tablero::getPiezasT(int x, int y)
{
	return casillas[x][y]->getPieza();
}

int Tablero::getTipoPiezasT(int x, int y)
{
	return casillas[x][y]->getTipoPieza();
}

Casilla* Tablero::getCasillaT(int x, int y)
{
	return casillas[x][y];
}

bool Tablero::getCasillaOcupada(int x, int y)
{
	return casillas[x][y]->getOcupada();
}


bool Tablero::getCoronacion(char color)
{
	for (i = 0; i < 8 ; i++)
		for (j = 0; j < 8; j++)	{
			if (casillas[i][j]->getTipoPieza() == 1 && casillas[i][j]->getPieza()->getColorPieza() == color) {
				if (color == 'N')
					if (j == 0) return true;
				if (color == 'B')
					if (j == 7) return true;
		    }
		}

	return false;
}

void Tablero::setCoronacion(int tipoficha)
{
	int pos_peon_x = 0, pos_peon_y = 0;
	char color = 'N';

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			if (casillas[i][j]->getTipoPieza() == 1 && (j == 7 || j == 0)) {
				if (j == 0) {
					color = 'N';
					pos_peon_x = i;
					pos_peon_y = j;
				}
				if (j == 7) {
					color = 'B';
					pos_peon_x = i;
					pos_peon_y = j;
				}
			}
		}

	eliminarPiezaT(pos_peon_x, pos_peon_y);

	if( tipoficha == 2 ) {
		Torre* t = new Torre(color);
		casillas[pos_peon_x][pos_peon_y]->colocarPieza(t);
		piezas.agregar(t);
	}
	if (tipoficha == 3){
		Alfil* a = new Alfil(color);
		casillas[pos_peon_x][pos_peon_y]->colocarPieza(a);
		piezas.agregar(a);
	}

	if (tipoficha == 4) {
		Caballo* c = new Caballo(color);
		casillas[pos_peon_x][pos_peon_y]->colocarPieza(c);
		piezas.agregar(c);
	}

	if (tipoficha == 5) {
		Reina* q = new Reina(color);
		casillas[pos_peon_x][pos_peon_y]->colocarPieza(q);
		piezas.agregar(q);
	}
}