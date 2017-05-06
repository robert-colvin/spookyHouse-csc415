#ifndef MAIN
#define MAIN

using namespace std;

#include "sysincludes.h"
#include <math.h>
#include "opengl.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"
#include <cstring>
#include <iostream>

#define WINDOW_MAX 800
#define WINDOW_MIN 0
#define VIEWPORT_MAX 700
#define VIEWPORT_MIN 100
#define MAX 100

//for phase space
float shift=0;
//for movement
vertex whereIAm = (vertex) {2, 2, 2, 1};
float zoomy=0.0, strafey=0.0, lookx=0.0, looky=0.0, lookUp=0.0;

float xspin,yspin,zspin,xDeltaSpin,yDeltaSpin,zDeltaSpin;
//just movey stuff
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
		if(whereIAm.x < 35.5)
			whereIAm.x+=0.5;
	}
	if(key == 'w' || key == 'W')
	{
		if(whereIAm.y < 26.5)
			whereIAm.y+=0.5;
	}
	if(key == 's' || key == 'S')
	{
		if(whereIAm.y > -21)
			whereIAm.y-=0.5;
	}
	if(key == 'a' || key == 'A')
	{
		if(whereIAm.x > -11)
			whereIAm.x-=0.5;
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
	if (key == GLUT_KEY_PAGE_UP)
	{
		if(whereIAm.z > -8)
			whereIAm.z-=0.5;
	}
	if (key == GLUT_KEY_PAGE_DOWN)
	{
		if(whereIAm.z < 14)
			whereIAm.z+=0.5;
	}

	glutPostRedisplay();
}
//draw dots in phase space representing pendulum movement
void phaseDisplay(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // reset the projection style
	gluOrtho2D(0.0,WINDOW_WIDTH,WINDOW_HEIGHT,0.0); // simple ortho
	glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

	glPointSize(2.5);
	glColor3f(1.0,0.0,0.0);
	double thetaDeg = toDegs(theta);
	glTranslatef(shift, thetaDeg, 0);
	glBegin(GL_POINTS);
		glVertex2d(0.0,WINDOW_HEIGHT/2);
	glEnd();
	shift+=0.25;
   glutSwapBuffers();
   glFlush();

}
//create phase space window and give it properties
void phaseSpace()
{
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);
   glutInitWindowPosition (100+WINDOW_WIDTH, 100);
   glutCreateWindow ("Phased");

	glClearColor(1.0,1.0,1.0,1.0);
   	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
	glMatrixMode(GL_MODELVIEW);
   
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(mover);
   glutDisplayFunc(phaseDisplay); 
   glutReshapeFunc(reshape);

}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Welcome to Hell");
   glewInit();
   init ();
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(mover);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
	
	//create phase space
	phaseSpace();

   glutMainLoop();
   return 0;
}

#endif
