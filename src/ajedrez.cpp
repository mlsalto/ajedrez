// ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"

using namespace ETSIDI;
Sprite* sprite1;
Sprite* sprite2;
Sprite* sprite3;
Sprite* sprite4;
Sprite* sprite5;
Sprite* sprite6;
Sprite* sprite7;
Sprite* sprite8;

Sprite* spriteB;
Sprite* spriteC;
Sprite* spriteD;
Sprite* spriteE;
Sprite* spriteF;
Sprite* spriteG;
Sprite* spriteH;



void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
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

	sprite1 = new Sprite("recursos/alfilN.png", -32, -16, 8, 8);
	sprite2 = new Sprite("recursos/alfilB.png", -24, -16, 8, 8);
	sprite3 = new Sprite("recursos/peonB.png", -16, -16, 8, 8);
	sprite4 = new Sprite("recursos/caballoB.png", -8, -16, 8, 8);
	sprite5 = new Sprite("recursos/alfilN.png", 0, -16, 8, 8);
	sprite6 = new Sprite("recursos/reyN.png", 8, -16, 8, 8);
	sprite7 = new Sprite("recursos/reinaN.png", 16, -16, 8, 8);
	sprite8 = new Sprite("recursos/caballoB.png", 24, -16, 8, 8);

	
	spriteB = new Sprite("recursos/torreN.png", 0, -8, 8, 8);
	spriteC = new Sprite("recursos/peonN.png", 0, 0, 8, 8);
	spriteD = new Sprite("recursos/caballoN.png", 0, 8, 8, 8);
	spriteE = new Sprite("recursos/reyB.png", 0, 16, 8, 8);
	spriteF = new Sprite("recursos/torreB.png", 0, 24, 8, 8);
	spriteG = new Sprite("recursos/caballoN.png", 0, 32, 8, 8);
	spriteH = new Sprite("recursos/reinaB.png", 0, 40, 8, 8);


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

	gluLookAt(0, 10, 110, // posicion del ojo
		0, 10, 0.0, // hacia que punto mira (0,0,0)
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


	spriteB->draw();
	spriteC->draw();
	spriteD->draw();
	spriteE->draw();
	spriteF->draw();
	spriteG->draw();
	spriteH->draw();


	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	
}

void OnTimer(int value)
{
	//poner aqui el código de animacion

}
