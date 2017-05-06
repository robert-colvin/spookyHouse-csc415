#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

extern bool filled, drawAxis, drawSign;
extern float xspin, yspin, zspin,xDeltaSpin,yDeltaSpin,zDeltaSpin,lookUp,lookx,looky,strafey,zoomy;
extern double near,far,left0,right0,fovY,aspect,bottom,top;
extern int persp;
extern vertex whereIAm;
void loadTextures();
void spinner(void);
void init(void);
double toDegs(double);
void p2Ortho( double fov, double aspecty, double zNear, double zFar );
void o2Persp(double lefty, double righty, double bottomy, double topy, double neary, double fary);
void drawTheSign(bool);
void defineRoom( struct pentagon* );
void defineBox( struct pentagon* );
void drawBox( struct box*, bool );
void drawBox( struct pentagon*, bool );
void display(void);
void showFPS(float &fps, int &oldTime, float &actualfps); 
void reshape (int , int );
void mover(void);
/*
void init(void) 
void drawAxes(int length)
void defineBox( box *face )
void drawBox( struct box *face )
void display(void)
void reshape (int w, int h)
*/
#endif

