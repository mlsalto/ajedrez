// ajedrez.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "freeglut.h"
#include "Coordinador.h"

Coordinador coordinador;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void Mouse(int x, int y);
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
	glutPassiveMotionFunc(Mouse);
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);

	// codigo
	coordinador.inicializa();

	glutMainLoop();

	return 0;
}

void Mouse(int x, int y)
{
	cout << x << ',' << y << endl; //pruebas
	//coordinador.PassiveMouse(x, y);

	if (x > 557 || x < 246 || y < 448 || y > 557) {
		coordinador.setModoJuego(0);
	}

	else if (x < 557 && x > 246 && y < 557 && y > 510) {
		coordinador.setModoJuego(1);
	}

	else if (x < 557 && x > 246 && y < 490 && y > 448) {
		coordinador.setModoJuego(2);
	}


	OnDraw();

	glutPostRedisplay;
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
	//coordinador.PassiveMouse(x, y);
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int x, int y) //arreglar el defaulta ya que en el primer switch no lo 
{
	coordinador.raton(button,state,x,y);
	glutPostRedisplay;
}


void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado	
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
}
