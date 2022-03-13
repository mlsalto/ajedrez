// ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "freeglut.h"
#include "Coordinador.h"

Coordinador coordinador;

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

	// codigo
	coordinador.inicializa();

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

	coordinador.dibuja();
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
		//casilla_iluminada->setPos(-36 + (x_tablero * 8), -36 + (y_tablero * 8)); //funcion para dibujar casilla iluminada en función del ratón
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
