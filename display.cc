
#ifndef DISPLAY
#define DISPLAY

using namespace std;

#include "opengl.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"
#include <cmath>
#include <iostream>

double left0=-1.0;double right0=1.0;double bottom=-1.0;double top=1.0;double near=1.0;double far=50.0;double aspect = 0.0; double fovY = 0.0;

void p2Ortho( double fov, double aspecty, double zNear, double zFar )
{//
	near = zNear;
	far = zFar;
	
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fov / 360 * pi ) * zNear;
    fW = fH * aspecty;

	right0 = fW;
	left0 = -fW;
	top = fH;
	bottom = -fH;

    glOrtho( left0, right0, bottom, top, near, far );
}
void o2Persp(double lefty, double righty, double bottomy, double topy, double neary, double fary)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	//GLdouble fovY, aspect;
	
	aspect = right0/top;
	fovY = atan(top/near)/pi*360;
	
	gluPerspective(fovY,aspect,neary,fary);
}
double Nstep = 100000;
bool go = true;
static int spin = 0;
double t=0.0;
double theta=0.0;
double omega=1.5;
double toDegs(double radian)
{
	return radian * (180.0/M_PI);
}
double thetadot(double t, double theta, double omega)
{
   return omega;
}

double omegadot(double t, double theta, double omega)
{
   static double R = 10.9938;  // Length of pendulum
   static double g = 9.80665;  // Normalized gravitational constant
   static double b = 0.10;  // Frictional damping constant
   static double m = 1.00;  // Mass in normalized gravitational units
   static double A = 0.00;  // Amplitude of initial driving force
   static double k = 0.00;  // Frequency parameter of initial driving force

   double drag, kick, denom;

   denom = m*R*R;
   drag = b*omega / denom;
   kick = A*cos(k*t) / denom;
   return -g/R*sin(theta)-drag+kick;
	
}


void step(double &t, double &theta, double &omega )
{
  // Time step variables
  double dt, h; 
  // variables for fourth-order Runge-Kutta method
  double k1, k2, k3, k4, j1, j2, j3, j4;
  int i; 

  h=100.0/Nstep;   // Try changing the value of Nstep above to see what happens 

      // Fourth-Order Runge-Kutta propagation step for second order dynamical systems
        k1 = thetadot(t,theta, omega); 
        j1 = omegadot(t,theta, omega); 
        k2 = thetadot(t+h/2, theta+h/2*k1, omega+h/2*j1); 
        j2 = omegadot(t+h/2, theta+h/2*k1, omega+h/2*j1); 
        k3 = thetadot(t+h/2, theta+h/2*k2, omega+h/2*j2); 
        j3 = omegadot(t+h/2, theta+h/2*k2, omega+h/2*j2); 
        k4 = thetadot(t+h, theta+h*k3, omega+h*j3); 
        j4 = omegadot(t+h, theta+h*k3, omega+h*j3); 
        theta = theta + h/6*(k1+2*k2+2*k3+k4);
        omega = omega + h/6*(j1+2*j2+2*j3+j4);
        t = t + h;

}

void rotateItGLStyle(GLfloat angle)
{
	//glPushMatrix();
	glTranslatef(transCoord,transCoord,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(-transCoord,-transCoord,0.0);
	//glPopMatrix();
}
void mover(void)
{
	if(go)
		step(t,theta,omega);
	glutPostRedisplay();
}
void display(void)
{

   struct pentagon faces[7];
   struct pentagon room[7];
   
   float *M;
   int i, j;
   

   defineBox(&faces[0]);
   defineRoom(&room[0]);

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

/* ONLY MODIFY CODE BELOW */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

   // Let's manually move the camera back
   
   glTranslatef(0.0, 0.0, -10.0);

  
   gluLookAt (2+zoomy, 2+zoomy, 2+zoomy, -10.0, -10.0, -10.0, 0.0, 0.0, 1.0);

/* DO NOT MODIFY ANYTHING ELSE */

   /* Draw a coordinate axis */

   glEnable(GL_DEPTH_TEST | GL_LIGHTING | GL_LIGHT0 | GL_LIGHT1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glScalef(25.0,25.0,25.0);
	glTranslatef(1,-1.75,0);
	drawBox(&room[0],true);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.9938,0.0,0.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glRotatef(toDegs(theta), 0.0, 1.0, 0.0);
//	glRotatef(zspin,0.0,0.0,1.0);
//	glRotatef(xspin,1.0,0.0,0.0);
//	glRotatef(yspin,0.0,1.0,0.0);

	glTranslatef(-1.9938,0.0,0.0);
   	drawBox(&faces[0],false);
	glPushMatrix();
	glScalef(0.0025,0.0025,0.0025);
	//glRotatef(180.0,1.0,0.0,0.0);
	glRotatef(180.0,0.0,1.0,0.0);
	glTranslatef(-350.0,1220.0,-200.0);
	glRotatef(270.0,1.0,0.0,0.0);
//	drawBox(&faces[0],filled);   
	drawTheSign(drawSign);
	glPopMatrix();
//drawTheSign(drawSign);
	glPopMatrix();


   glutSwapBuffers();

}

#endif
