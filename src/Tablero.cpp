#include "Tablero.h"
#include "freeglut.h"

Casilla* Tablero::casillas[8][8];
ListaPiezas Tablero::piezas;
bool Tablero::tipojuego;
bool Tablero::movimientos;

Tablero::Tablero(){}

// 0 blanco, 1 negro // 
//  VACIO(0) PEON(1) TORRE(2) ALFIL(3) CABALLO(4) REINA(5) REY(6)

void Tablero::nuevoTablero()
{
	// inicializacion valores //
	turno = TRUE; // blancas(1)   negras(0)
	turnoterminado = FALSE;
	finturnon = false;
	finturnob = false;

	// lista piezas
	piezas.inicializa();

	// casillas
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
	if (turno == TRUE) marcoTurno.setPos(60, 15);
	else if (turno == FALSE) marcoTurno.setPos(-60, 15);
	marcoTurno.draw();
	
	if (tipojuego == TRUE) {
		blancasq.setPos(70 , 30);
		blancasq.draw();
		negrasq.setPos(-70, 30);
		negrasq.draw();
	}

	else if (tipojuego == FALSE) {
		blancask.setPos(70, 30);
		blancask.draw();
		negrask.setPos(-70, 30);
		negrask.draw();
	}

	jugador1->draw(personaje1); // blancas
	jugador2->draw(personaje2); // negras

	piezas.drawEliminadas();

	piezas.draw();

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			casillas[i][j]->draw();
	

	if (tipojuego == TRUE) {
		tableroAjedrez.draw();
		marcoTablero.draw();
	}
	
	else if (tipojuego == FALSE) {
		tableroAjedrez2.draw();
		marcoTablero2.draw();
	}

	letrasTablero.draw();
}

void Tablero::ratonTablero(int button, int state, int x, int y)
{
	finturnon = false;
	finturnob = false;

	if (turno == TRUE)
	{
		jugador1->moverPieza(button, state, x, y);
		if (jugador1->turnoTerminado() == TRUE)
		{
			finturnob = true;
			finturnon = false;
			turno = FALSE;
			return;
		}
	}

	if (turno == FALSE)
	{
		jugador2->moverPieza(button, state, x, y);
		if (jugador2->turnoTerminado() == TRUE)
		{
			finturnon = true;
			finturnob = false;
			turno = TRUE;
			return;
		}
	}
}

//En tu turno, compruebas si puedes hacer jaque al contrincante
bool Tablero::detectar_jaque(char color) {
	// este jaque solo depende del color
	int i, j;
	int pos_rey_x = 0, pos_rey_y = 0;
	//bucle anidado para recorrer el tablero y comprobar si alguna pieza puede hacer jaque a la posición actual del rey
	bool rey = false;

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


	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (casillas[i][j]->getOcupada() == true && casillas[i][j]->getPieza()->getColorPieza() != color && casillas[i][j]->getPieza()->movimientoLegal(casillas[pos_rey_x][pos_rey_y]) == true)
			{
				return true;
			}
		}
	}

	return false;
}

bool Tablero::detectar_jaque_mate(char color) {

	int i, j;
	int a, b;

	// variables de ayuda para realizar los movimientos virtuales //
	Pieza* piezaini = 0;
	int piezaini_ini_x, piezaini_ini_y;

	Pieza* piezacomida;
	Pieza* piezamovida = 0;

	// si no hay jaque no puede haber jaque mate //
	if (detectar_jaque(color) == false) return false;

	
	// comprobar para todos los movimientos de todas las piezas jaque == true //
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++) {
			// encontrar pieza 
			if (casillas[i][j]->getTipoPieza() != 0 && casillas[i][j]->getPieza()->getColorPieza() == color)
			{
				piezaini = casillas[i][j]->getPieza(); // guardar dato pieza
				piezaini_ini_x = i; piezaini_ini_y = j; // guardar dato posicion inicial

				for (a = 0; a < 8; a++)
				{
					for (b = 0; b < 8; b++)
					{
						// realizar mov legal de la pieza 
						if (piezaini->movimientoLegal(casillas[a][b]) == true) {


							// si se come alguna pieza 
							if (casillas[a][b]->getTipoPieza() != 0 && casillas[a][b]->getPieza()->getColorPieza() != color)
							{
								piezacomida = casillas[a][b]->getPieza();
								casillas[a][b]->colocarPieza(piezaini);
								casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);

								// comprobamos si hay jaque con la nueva disposición
								// no hay jaque
								if (detectar_jaque(color) == false)
								{
									casillas[a][b]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);

									return false;
								}

								// hay jaque
								if (detectar_jaque(color) == true)
								{
									casillas[a][b]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
								}
							}


							// si se hace enroque
							else if (casillas[piezaini_ini_x][piezaini_ini_y]->getTipoPieza() == 6 && (a == 6 || a == 2) && piezaini->getPrimerMovimiento() == false && (casillas[7][piezaini_ini_y]->getTipoPieza() == 2 || casillas[0][piezaini_ini_y]->getTipoPieza() == 2) && (casillas[7][piezaini_ini_y]->getPieza()->getPrimerMovimiento() == false || casillas[0][piezaini_ini_y]->getPieza()->getPrimerMovimiento() == false) && piezaini->getEnroque() == false)
							{
								// hacer enroque
								if (color == 'N')
								{
									if (a == 6) // derecha
									{
										piezamovida = casillas[7][7]->getPieza(); // torre
										casillas[7][7]->colocarPieza(0);
										casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);
										casillas[a][b]->colocarPieza(piezaini);
										casillas[5][7]->colocarPieza(piezamovida);
									}

									if (a == 2) // izquierda
									{
										piezamovida = casillas[0][7]->getPieza(); // torre
										casillas[0][7]->colocarPieza(0);
										casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);
										casillas[a][b]->colocarPieza(piezaini);
										casillas[3][7]->colocarPieza(piezamovida);
									}
								}

								if (color == 'B')
								{
									if (a == 6) // derecha
									{
										piezamovida = casillas[7][0]->getPieza(); // torre
										casillas[7][0]->colocarPieza(0);
										casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);
										casillas[a][b]->colocarPieza(piezaini);
										casillas[5][0]->colocarPieza(piezamovida);
									}

									if (a == 2) // izquierda
									{
										piezamovida = casillas[0][0]->getPieza(); // torre
										casillas[0][0]->colocarPieza(0);
										casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);
										casillas[a][b]->colocarPieza(piezaini);
										casillas[3][0]->colocarPieza(piezamovida);
									}
								}


								// si no hay jaque
								if (detectar_jaque(color) == false)
								{
									// deshacer enroque
									if (color == 'N')
									{
										if (a == 6) // derecha
										{
											casillas[7][7]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[5][7]->colocarPieza(0);
										}

										if (a == 2) // izquierda
										{
											casillas[0][7]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[3][7]->colocarPieza(0);
										}
									}
									if (color == 'B')
									{
										if (a == 6) // derecha
										{
											casillas[7][0]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[5][0]->colocarPieza(0);
										}

										if (a == 2) // izquierda
										{
											casillas[0][0]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[3][0]->colocarPieza(0);
										}
									}
									return false;
								}

								// si hay jaque
								if (detectar_jaque(color) == true)
								{
									// deshacer enroque
									if (color == 'N')
									{
										if (a == 6) // derecha
										{
											casillas[7][7]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[5][7]->colocarPieza(0);
										}

										if (a == 2) // izquierda
										{
											casillas[0][7]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[3][7]->colocarPieza(0);
										}
									}

									if (color == 'B')
									{
										if (a == 6) // derecha
										{
											casillas[7][0]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[5][0]->colocarPieza(0);
										}

										if (a == 2) // izquierda
										{
											casillas[0][0]->colocarPieza(piezamovida);
											casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
											casillas[a][b]->colocarPieza(0);
											casillas[3][0]->colocarPieza(0);
										}
									}
								}
							}


							// si hace en passant
							else if (color == 'B' && casillas[piezaini_ini_x][piezaini_ini_y]->getTipoPieza() == 1 && casillas[a][b]->getTipoPieza() == 0 && b == piezaini_ini_y + 1 && b == 5 && (a == piezaini_ini_x + 1 || a == piezaini_ini_x - 1) && casillas[a][b - 1]->getTipoPieza() == 1 && casillas[a][b - 1]->getPieza()->getColorPieza() != color && casillas[a][b - 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								casillas[a][b]->colocarPieza(piezaini);
								piezacomida = casillas[a][b - 1]->getPieza();
								casillas[a][b - 1]->colocarPieza(0);

								if (detectar_jaque(color) == false)
								{
									// deshacer en passant
									casillas[a][b - 1]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y ]->colocarPieza(piezaini);

									return false;
								}

								if (detectar_jaque(color) == true)
								{
									// deshacer en passant
									casillas[a][b - 1]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
								}

							}

							else if (color == 'N' && casillas[piezaini_ini_x][piezaini_ini_y]->getTipoPieza() == 1 && casillas[a][b]->getTipoPieza() == 0 && b == piezaini_ini_y - 1 && b == 5 && (a == piezaini_ini_x + 1 || a == piezaini_ini_x + 1) && casillas[a][b + 1]->getTipoPieza() == 1 && casillas[a][b + 1]->getPieza()->getColorPieza() != color && casillas[a][b + 1]->getPieza()->getPassant() == true)
							{
								// hace en passant
								casillas[a][b]->colocarPieza(piezaini);
								piezacomida = casillas[a][b + 1]->getPieza();
								casillas[a][b - 1]->colocarPieza(0);

								if (detectar_jaque(color) == false)
								{
									// deshacer en passant
									casillas[a][b + 1]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);

									return false;
								}

								if (detectar_jaque(color) == true)
								{
									// deshacer en passant
									casillas[a][b + 1]->colocarPieza(piezacomida);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
								}
							}


							// si no come ninguna pieza 
							else if (casillas[a][b]->getTipoPieza() == 0)
							{
								casillas[a][b]->colocarPieza(piezaini);
								casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(0);

								// comprobamos si hay jaque con la nueva disposición
								// no hay jaque
								if (detectar_jaque(color) == false)
								{
									casillas[a][b]->colocarPieza(0);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);

									return false;
								}

								// hay jaque
								if (detectar_jaque(color) == true)
								{
									casillas[a][b]->colocarPieza(0);
									casillas[piezaini_ini_x][piezaini_ini_y]->colocarPieza(piezaini);
								}

							}
						}
					}
				}
			}
		}
	}
	return true;
}

void Tablero::eliminarPiezaT(int x, int y)
{
	piezas.eliminar(casillas[x][y]->getPieza());
}

void Tablero::eliminarPieza(Pieza * pieza)
{
	piezas.eliminar(pieza);
}

void Tablero::eliminarTablero()
{
	int i , j;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			piezas.eliminar(casillas[i][j]->getPieza());
}

void Tablero::setJugador1(Jugador* j)
{
	jugador1 = j;
}

void Tablero::setJugador2(Jugador* j)
{
	jugador2 = j;
}

void Tablero::setPersonaje1(int x)
{
	personaje1 = x;
}

void Tablero::setPersonaje2(int x)
{
	personaje2 = x;
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

bool Tablero::getTipoJuego()
{
	return tipojuego;
}

bool Tablero::getMovimientos()
{
	return movimientos;
}

bool Tablero::getTurnoAcabadoN()
{
	return finturnon;
}

bool Tablero::getTurnoAcabadoB()
{
	return finturnob;
}

void Tablero::setTipoJuego(bool x)
{
	 tipojuego = x;
}

void Tablero::setMovimientos(bool x)
{
	movimientos = x;
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