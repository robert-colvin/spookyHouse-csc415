
#ifndef DISPLAY
#define DISPLAY

using namespace std;

#include "opengl.h"
#include "globals.h"
#include "structs.h"
#include "prototypes.h"
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#define L	10.9938
#define G	9.80665

//for perspective view
double left0=-1.0;double right0=1.0;double bottom=-1.0;double top=1.0;double near=1.0;double far=50.0;double aspect = 0.0; double fovY = 0.0;
//for fps counter
int oldTime=0.0; float actualfps=0.0,fps=0.0;
//pend stats
double Nstep = 1000;
static int spin = 0;
double t=0.0;
double theta=0.0;
double omega=1.0;
//convert radians to degrees
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
   static double R = L;  // Length of pendulum
   static double g = G;  // Normalized gravitational constant
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
//print 2d period calculation to 3d screen
void showPeriod() {
    //probably a janky period equation I found for a pendulum
    float period = 2 * M_PI * sqrt(L/G);
    char label[20];
    //concatenate number with string
    sprintf(&label[0], "Period = %.2f", period);

    glPushMatrix();
    glClear(GL_DEPTH_BUFFER_BIT);

    //adjust draw space and draw
    void *font = GLUT_STROKE_ROMAN;
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // reset the projection style
    gluOrtho2D(0.0,100.0,100.0,0.0); // simple ortho

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(01, 05, 0);
    glScalef(0.15, 0.15, 0.15);
	
    glRotatef(180.0, 1.0, 0.0, 0.0);
    glScalef(0.1,0.1,0.1);
    int len = (int) strlen(label);
    for (int i = 0; i < len; i++) {
        glutStrokeCharacter(font, label[i]);
    }
    glPopMatrix();
}
//like above
void showFPS(float &fps, int &oldTime, float &actualfps) {
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    char str_fps[15];
    if ( (currentTime - oldTime) > 1000 ){
        actualfps = fps;
        fps = 0.0;
        oldTime = currentTime;
    } else
        fps++;
    sprintf(&str_fps[0], "FPS = %.0f",actualfps);


    glPushMatrix();
    glClear(GL_DEPTH_BUFFER_BIT);

    void *font = GLUT_STROKE_ROMAN;
    glColor3f(1.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // reset the projection style
    gluOrtho2D(0.0,100.0,100.0,0.0); // simple ortho

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(01, 03, 0);
    glScalef(0.15, 0.15, 0.15);

    glRotatef(180.0, 1.0, 0.0, 0.0);
    glScalef(0.1,0.1,0.1);
    int len = (int) strlen(str_fps);
    for (int i = 0; i < len; i++) {
        glutStrokeCharacter(font, str_fps[i]);
    }
    glPopMatrix();
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
//idle func
void mover(void)
{
	step(t,theta,omega);
	glutPostRedisplay();
}
void drawHud() {//to draw the 2d hud on 3d scene
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // reset the projection style
	gluOrtho2D(0.0,100.0,100.0,0.0); // simple ortho

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//draw 2D stuff
	showFPS(fps, oldTime, actualfps);
	showPeriod();
}
void display(void)
{
   //reset scary dark 3d world after shifting to 2d at end of every frame
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glClearColor(0.0,0.0,0.0,0.0);
   glFrustum (-1.0,1.0,-1.0,1.0,1.0,150.0);
	
   //define pendulum points  
   glMatrixMode (GL_MODELVIEW);
   
   float *M;
   int i, j;
   
   glClear (GL_COLOR_BUFFER_BIT);
   glColor4f (1.0, 1.0, 1.0, 1.0);

/* ONLY MODIFY CODE BELOW */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

   // Let's manually move the camera back
   
   glTranslatef(0.0, 0.0, -10.0);
	//for camera movement
	glRotatef(zspin,0.0,0.0,1.0);
	glRotatef(xspin,1.0,0.0,0.0);
	glRotatef(yspin,0.0,1.0,0.0);
   gluLookAt (0, 0, 0.5, 0.0, -1.0, 0.5, 0.0, 0.0, 1.0);
	
	glTranslatef(whereIAm.x, whereIAm.y, whereIAm.z);
/* DO NOT MODIFY ANYTHING ELSE */

   /* Draw a coordinate axis */

   //this line cost me hours of brainpower
   //texture_2d enable has to be petty and get its own enable
   glEnable(GL_TEXTURE_2D);
   glEnable( GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glScalef(25.0,25.0,25.0);
	glTranslatef(1,-1.75,0);
	
	//draw and texture room and what I think 'bob' means from the rubric
glPushMatrix();
   glTranslatef(0.0,2.0,0.4);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    	glBindTexture(GL_TEXTURE_2D, textureID);
	glPushMatrix();
	glTranslatef(-0.945,-0.2,0);
	gluSphere(earth, 0.4, 36, 72);
	glPopMatrix();
	

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//bottom of room
      glNormal3d(0,0,-1);
      glTexCoord3d( 0.0, 0.0, 1.0);   glVertex3d(  -2.5,  -1.0, -1.0 );
      glTexCoord3d( 0.0, 1.0, 1.0);   glVertex3d(  -2.5, 1.0, -1.0 );
      glTexCoord3d( 1.0, 1.0, 1.0);   glVertex3d( -0.5, 1.0, -1.0 );
      glTexCoord3d( 1.0, 0.0, 1.0);   glVertex3d( -0.5,  -1.0, -1.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//left
      glNormal3d(0,0,1);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  -2.5,  -1.0, -1.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  -2.5, -1.0, 0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( -0.5, -1.0, 0.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( -0.5,  -1.0, -1.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//right
      glNormal3d(-1,0,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  -2.5,  1.0,  -1.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  -2.5, 1.0,  0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d(  -0.5, 1.0, 0.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d(  -0.5,  1.0, -1.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//back
      glNormal3d(1,0,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d( -2.5, -1.0, -1.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d( -2.5, -1.0, 0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d(  -2.5, 1.0, 0.0);
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d(  -2.5, 1.0, -1.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//front
      glNormal3d(0,-1,0);
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d(-0.5,-1.0,-1.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(-0.5,-1.0,0.0 );
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d( -0.5,1.0,0.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( -0.5,1.0,-1.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_POLYGON);//top
      glNormal3d(0,1,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(-2.5,-1.0,0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(-2.5,1.0,0.0  );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d(-0.5,1.0,0.0  );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d(-0.5,-1.0,0.0  );
    glEnd();
glPopMatrix();

	glPopMatrix();

	//alter the multiverse based on pedulum angle and where it needs to be placed
	glPushMatrix();
	glTranslatef(1.9938,0.0,0.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glRotatef(toDegs(theta), 0.0, 1.0, 0.0);
	glTranslatef(-1.9938,0.0,0.0);
	//draw pendulum

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    	glBindTexture(GL_TEXTURE_2D, textureID);
	gluSphere(earth, 0.3, 36, 72);
	//draw pendulum string
	glColor4f(1.0,1.0,1.0,1.0);
        glBegin(GL_LINES);
	    	glVertex3f(1.9938, 0.0, 0.0);
		glVertex3f(-0.5, 0.0, 0.0);
	glEnd();
	//glPopMatrix();
	glPopMatrix();

	//do the 2d thing last
	glClear(GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	drawHud();
	glPopMatrix();
	glClear(GL_DEPTH_BUFFER_BIT);
   glutSwapBuffers();
   glutPostRedisplay();
}

#endif
