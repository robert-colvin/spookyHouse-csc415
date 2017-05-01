#ifndef MAIN
#define MAIN

using namespace std;

#include <math.h>
#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <iostream>

#define WINDOW_MAX 800
#define WINDOW_MIN 0
#define VIEWPORT_MAX 700
#define VIEWPORT_MIN 100
#define MAX 100

bool filled = false;
bool drawAxis = false;
bool drawSign = false;
float zoomy = 0.0;
int persp = 1;

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') 
		exit(0);
	if (key == 'r')
	{
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;
		
		Nstep = 100000;
		t = 0.0;
		theta = 0.0;
		omega = 1.5;
	}
	if (key == 's' || key == 'S')
	{
		yDeltaSpin = 0.0;
		xDeltaSpin = 0.0;
		zDeltaSpin = 0.0;

		go = !go;
	}
	if (key == 'R')
	{
		filled = false;
		drawAxis = false;
		drawSign = false;
		zoomy = 0.0;
		yspin = 0.0; yDeltaSpin = 0.0;
		xspin = 0.0; xDeltaSpin = 0.0;
		zspin = 0.0; zDeltaSpin = 0.0;

	}
	if (key == 'x' || key == 'X') 
	{	
		xDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'y' || key == 'Y') 
	{	
		yDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'z' || key == 'Z') 
	{	
		zDeltaSpin+=0.5; 
		glutIdleFunc(spinner);
	}
	if (key == 'f' || key == 'F') 
		filled = !filled;

	glutPostRedisplay();
}
void special(int key, int x, int y)
{
	if (key == GLUT_KEY_PAGE_UP)
		zoomy = zoomy - 0.05;
	if (key == GLUT_KEY_PAGE_DOWN)
		zoomy = zoomy + 0.05;

	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Welcome to Hell");
   init ();
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(mover);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);

   glutMainLoop();
   return 0;
}

#endif
