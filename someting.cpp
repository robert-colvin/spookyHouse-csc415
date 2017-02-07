#ifndef THING
#define THING

using namespace std;

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "structs.h"

#define WINDOW_MAX 800
#define WINDOW_MIN 0
#define VIEWPORT_MAX 700
#define VIEWPORT_MIN 100
#define MAX 100
//---------------------------------------------------------------------------------------------------------------------------------------------------------
double Nstep = 100000;

bool go = true;
static int spin = 0;
double t=0.0;
double theta=0.0;
double omega=1.5;
double R,g,b,m,A,k;
// These two functions are the first and second derivative equations
// for the dynamical motion of the driven plane pendulum with damping
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
/*  static double R = 1.00;  // Length of pendulum
   static double g = 1.00;  // Normalized gravitational constant
   static double b = 0.00;  // Frictional damping constant
   static double m = 1.00;  // Mass in normalized gravitational units
   static double A = 0.00;  // Amplitude of initial driving force
   static double k = 0.00;  // Frequency parameter of initial driving force
*/
   double damp, kick, denom;

   damp = -b*omega; 
   kick =  A*cos(k*t);
   //denom = m*pow(R,2.0);
   denom = 1.0;
   return -g/R*sin(theta)+damp/denom+kick/denom;
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
//---------------------------------------------------------------------------------------------------------------------------------------------------
GLfloat transCoord = WINDOW_MAX/2.0;
float xshift, yshift;
float SCALE_UNIFORM = 1.0; 	//a single scale variable for all dimensions
float reflected = -1; 		//-1 for no reflect, 1 for reflect
bool showFilled = false;
/* Define these two variables to have a global scope */
float DELTA_SPIN = 0.0;
float SPINNY  = 0.0;

void display( void );

void defineArrow( float *apts )
{
   apts[ 0] = 375.0;  apts[ 1] = 200.0; apts[ 2] = 0.0; apts[ 3] = 1.0;
   apts[ 4] = 425.0;  apts[ 5] = 200.0; apts[ 6] = 0.0; apts[ 7] = 1.0;
   apts[8] = 425.0;  apts[9] = 300.0; apts[10] = 0.0; apts[11] = 1.0;
   apts[12] = 375.0;  apts[13] = 300.0; apts[14] = 0.0; apts[15] = 1.0;

}
void mover(void)
{
	if(go)
		step(t,theta,omega);

//	cout << theta << "	" << toDegs(theta) << endl;

	glutPostRedisplay();
}
void toVertex ( float *apts, struct vertex *vp, int pts )
{
	int i;

	for (i=0;i<pts;i++)
	{
	   (vp+i)->x = *(apts+(i*4)+0);
	   (vp+i)->y = *(apts+(i*4)+1);
	   (vp+i)->z = *(apts+(i*4)+2);
	   (vp+i)->w = *(apts+(i+4)+3);
	}
}

void myinit( void )
{
    /* attributes */

    glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */
    glPointSize(1.0);

    /* set up viewing */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (float) WINDOW_MAX, 
            0.0, (float) WINDOW_MAX);
    glMatrixMode(GL_MODELVIEW);
}
void drawArrow( vertex *vp, int points )
{
    int i;

    glColor3f(1.0,0.0,0.0);
    
    glBegin(GL_POLYGON);
    //glBegin(GL_LINE_LOOP);
    for (i=0;i<points;i++)
        glVertex2f( (vp+i)->x, (vp+i)->y );
    glEnd();


}

void scaleForTheGLadies(GLfloat uniformScale)
{
	glTranslatef(transCoord,transCoord,0.0);
	glScalef(uniformScale,uniformScale,1.0);
	glTranslatef(-transCoord,-transCoord,0.0);
}
void rotateItGLStyle(GLfloat angle)
{
	//glPushMatrix();
	glTranslatef(transCoord,transCoord,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(-transCoord,-transCoord,0.0);
	//glPopMatrix();
}
void translateItForExtraCredit(GLfloat xmove, GLfloat ymove)
{
	//glTranslatef(transCoord,transCoord,0.0);
	glTranslatef(xmove,ymove,0.0);
	//glTranslatef(-transCoord,-transCoord,0.0);
	//glutPostRedisplay();
}
void display( void )
{

    int inPoints;                       // The number of points in the arro
    float point[100];                   // Array to hold homogenous coordinates for arrow
    float *apts;                        // Pointer for point array

    struct vertex inVertexArray[MAX/4];	/* array of vertices to hold points */
    struct vertex *invp;                /* pointer for inVertexArray   */

    /* Make sure to initialize the pointers! */

    apts = &point[0];                  // the pointer to the array of points
    invp = &inVertexArray[0];          // the pointer to the array of vertices

    inPoints = 4;                      // the actual number of points in the arrow

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glLoadIdentity();              /* New - prior to any GL Operations, load identity matrix */           


    /* Draw Arrow in Viewport */
    glColor3f(1.0, 1.0, 1.0);

	GLsizei vwidth = WINDOW_MAX - (WINDOW_MAX - (VIEWPORT_MAX - VIEWPORT_MIN));

    // Make a local frame for the viewport 
    glPushMatrix();
    glLoadIdentity();
    glRecti(VIEWPORT_MIN,VIEWPORT_MIN,VIEWPORT_MAX,VIEWPORT_MAX); 
    glScissor(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX-VIEWPORT_MIN, VIEWPORT_MAX-VIEWPORT_MIN);
    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();
    glColor3f(0.6, 0.0, 1.0);
    glEnable(GL_SCISSOR_TEST);
    defineArrow( apts );           // Define the points for the arrow
    toVertex( apts, invp, inPoints ); 

	rotateItGLStyle(toDegs(theta));

    drawArrow( invp, inPoints );

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glDisable(GL_SCISSOR_TEST);
    glutSwapBuffers();

}
void specs(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
		Nstep*=1.1;
	if (key == GLUT_KEY_RIGHT)
		Nstep/=1.1;
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key =='Q')
		exit(0);
	if (key == 's' || key == 'S')
		go = !go;
	if (key == 'r' || key == 'R')
	{
		Nstep = 100000;
		t=0.0;
		theta=0.0;
		omega=1.5;
	}
}
int main(int argc, char** argv)
{
cout << "Enter value for length of pendulum (1.00): "; cin >> R;
cout << "Enter value for normalized gravity constant (1.00): "; cin >> g;
cout << "Enter value for frictional damping constant (0.00): "; cin >> b;
cout << "Enter value for mass in 'normalized gravitational units' (1.00): "; cin >> m;
cout << "Enter value for initial driving force amplitude (0.00): "; cin >> A;
cout << "Enter value for initial driving force frequency (0.00): "; cin >> k;
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("A Vertical Box For Some Reason; I Think It's Gonna Be A Pendulum"); 
    myinit(); 

    glutDisplayFunc(display); 
	glutIdleFunc(mover);	
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specs);

    glutMainLoop();
}
#endif
