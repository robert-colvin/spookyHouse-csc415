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
vertex whereIAm = (vertex) {2, 2, 2, 1};
float zoomy=0.0, strafey=0.0, lookx=0.0, looky=0.0, lookUp=0.0;
int persp = 1;

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q') 
		exit(0);
	if (key == 'r')
	{
		Nstep = 100000;
		t = 0.0;
		theta = 0.0;
		omega = 1.5;
	}
	if(key == 'd' || key == 'D')
	{
		whereIAm.x+=0.5;
	}
	if(key == 'w' || key == 'W')
	{
		whereIAm.y+=0.5;
	}
	if(key == 's' || key == 'S')
	{
		whereIAm.y-=0.5;
	}
	if(key == 'a' || key == 'A')
	{
		whereIAm.x-=0.5;
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
	glutPostRedisplay();
}
void special(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xspin-=1;
	if (key == GLUT_KEY_DOWN)
		xspin+=1;
	if (key == GLUT_KEY_LEFT)
		yspin-=1;
	if (key == GLUT_KEY_RIGHT)
		yspin+=1;

	glutPostRedisplay();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Welcome to Hell");
   init ();
//   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(mover);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);

   glutMainLoop();
   return 0;
}

#endif
