// ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"


using namespace ETSIDI;
Sprite* sprite1;
Sprite* sprite2;
Sprite* sprite3;
Sprite* sprite4;
Sprite* sprite5;
Sprite* sprite6;
Sprite* sprite7;
Sprite* sprite8;

//Sprite* spriteB;
Sprite* spriteC;
Sprite* spriteD;
Sprite* spriteE;
//Sprite* spriteF;
Sprite* spriteG;
Sprite* spriteH;

Sprite* spriteTablero;

Pieza pieza;

Sprite* casilla_iluminada;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void onSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Mi_Juego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 1366 / 768.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	sprite1 = new Sprite("recursos/alfilN.png", -28, -20, 8, 8);
	sprite2 = new Sprite("recursos/alfilB.png", -20, -20, 8, 8);
	sprite3 = new Sprite("recursos/peonB.png", -12, -20, 8, 8);
	sprite4 = new Sprite("recursos/caballoB.png", -4, -20, 8, 8);
	sprite5 = new Sprite("recursos/alfilN.png", 4, -20, 8, 8);
	sprite6 = new Sprite("recursos/reyN.png", 12, -20, 8, 8);
	sprite7 = new Sprite("recursos/reinaN.png", 20, -20, 8, 8);
	sprite8 = new Sprite("recursos/caballoB.png", 28, -20, 8, 8);

	
	//spriteB = new Sprite("recursos/torreN.png", 0, -8, 8, 8);
	spriteC = new Sprite("recursos/peonN.png", 4, -4, 8, 8);
	spriteD = new Sprite("recursos/caballoN.png", 4, 4, 8, 8);
	spriteE = new Sprite("recursos/reyB.png", 4, 12, 8, 8);
	//spriteF = new Sprite("recursos/torreB.png", 0, 20, 8, 8);
	spriteG = new Sprite("recursos/caballoN.png", 4, 28, 8, 8);
	spriteH = new Sprite("recursos/reinaB.png", 4, 20, 8, 8);

	casilla_iluminada = new Sprite("recursos/casilla_iluminada.png", 12, 12, 8, 8);

	spriteTablero= new Sprite("recursos/tablero.png", 0, 0, 64, 64); //CENTRO TABLERO 0,0
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 110, // posicion del ojo
		0, 0, 0, // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)*/


//aqui es donde hay que poner el código de dibujo

	sprite1->draw();
	sprite2->draw();
	sprite3->draw();
	sprite4->draw();
	sprite5->draw();
	sprite6->draw();
	sprite7->draw();
	sprite8->draw();


	//spriteB->draw();
	spriteC->draw();
	spriteD->draw();
	spriteE->draw();
	//spriteF->draw();
	spriteG->draw();
	spriteH->draw();

	//spriteTablero->draw();

	casilla_iluminada->draw();

	spriteTablero->draw();

	/*pieza.dibujar(BLANCO);*/

	pieza.dibujarPieza();
	/*pieza.dibujar(BLANCO);*/
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) //arreglar el defaulta ya que en el primer switch no lo 
{
	int x_cell, y_cell;
	int x_tablero, y_tablero;
	x_cell = x / 76;
	y_cell = y / 77;
	

	switch (y_cell)
	{
	case 1:
		y_tablero = 8;
		break;
	case 2:
		y_tablero = 7;
		break;
	case 3:
		y_tablero = 6;
		break;
	case 4:
		y_tablero = 5;
		break;
	case 5:
		y_tablero = 4;
		break;
	case 6:
		y_tablero = 3;
		break;
	case 7:
		y_tablero = 2;
		break;
	case 8:
		y_tablero = 1;
		break;
	default:
		y_tablero = 0;
		break;
	}

	switch (x_cell)
	{
	case 5:
		x_tablero = 1;
		break;
	case 6:
		x_tablero = 2;
		break;
	case 7:
		x_tablero = 3;
		break;
	case 8:
		x_tablero = 4;
		break;
	case 9:
		x_tablero = 5;
		break;
	case 10:
		x_tablero = 6;
		break;
	case 11:
		x_tablero = 7;
		break;
	case 12:
		x_tablero = 8;
		break;
	default:
	x_tablero = 0;
	//y_tablero = 0;
	break;
	}

	

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ 
		cout << "(" << x_tablero << "," << y_tablero << ")" << endl; 
		casilla_iluminada->setPos(-36 + (x_tablero * 8), -36 + (y_tablero * 8)); //funcion para dibujar casilla iluminada en función del ratón
	}


}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	
}

void OnTimer(int value)
{
	//poner aqui el código de animacion

}
