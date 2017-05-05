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

bool filled = !false;
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
		cout << "x is " << whereIAm.x << endl;	
	}
	if(key == 'w' || key == 'W')
	{
		if(whereIAm.y < 27.5)
			whereIAm.y+=0.5;
	}
	if(key == 's' || key == 'S')
	{
		if(whereIAm.y > -22)
			whereIAm.y-=0.5;
	}
	if(key == 'a' || key == 'A')
	{
		whereIAm.x-=0.5;
		cout << "x is " << whereIAm.x << endl;	
		
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
	if (key == GLUT_KEY_PAGE_UP)
		whereIAm.z-=0.5;
	if (key == GLUT_KEY_PAGE_DOWN)
		whereIAm.z+=0.5;

	glutPostRedisplay();
}
void renderBitmapString(
		float x, 
		float y, 
		void *font, 
		string stringval) {  
  int i;
  glRasterPos2f(x, y);
  glColor3f(1.0,1.0,1.0);
  for (i=0; i < stringval.size(); i++) {
    glutBitmapCharacter(font, stringval.at(i) );
  }
}
void phaseDisplay(void)
{
/*	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // reset the projection style
	gluOrtho2D(0.0,100.0,100.0,0.0); // simple ortho

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
*/
/*	glPointSize(1.0);
	glBegin(GL_LINES);
		glVertex2d(0,0);
		glVertex2d(5,5);
	glEnd();
   */string s;
   char c[100];
 
   void *font = GLUT_BITMAP_TIMES_ROMAN_24;

   glClear (GL_COLOR_BUFFER_BIT  );
   

   glColor3f(1.0,1.0,0.0); 
   s = "Fire Control Settings";
   renderBitmapString(-.8,0.8,font,s);
}
void phaseSpace()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
//   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100+WINDOW_WIDTH, 100);
   glutCreateWindow ("Phased");
   
   glutDisplayFunc(phaseDisplay); 
   glutReshapeFunc(reshape);

   glutKeyboardFunc(keyboard);

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
   //loadTextures();
//   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutIdleFunc(mover);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);

	phaseSpace();

   glutMainLoop();
   return 0;
}

#endif
