#ifndef DRAWBOX
#define DRAWBOX

#include "opengl.h"
#include "globals.h"
#include <string.h>
#include "structs.h"
float xspin,yspin,zspin,xDeltaSpin,yDeltaSpin,zDeltaSpin;

void spinner(void)
{
	xspin = xspin + xDeltaSpin;
	yspin = yspin + yDeltaSpin;
	zspin = zspin + zDeltaSpin;

	if (xspin > 360.0) xspin = xspin-360.0;
	if (yspin > 360.0) yspin = yspin-360.0;
	if (zspin > 360.0) zspin = zspin-360.0;

	glutPostRedisplay();
}
void drawBox( struct pentagon *face, bool room )
{
    int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glTranslatef(0.0,2.0,0.0);

    for(j=0;j<7;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);
	glBegin(GL_POLYGON);
	        for (i=0;i<5;i++)
        	{
	            glVertex3f(face[j].point[i].x,
        	               face[j].point[i].y,
                	       face[j].point[i].z);
	        }
        glEnd();

	glColor4f(0.0,0.0,1.0, 1.0);
	glBegin(GL_LINE_LOOP);

        for (i=0;i<5;i++)
        {//glBegin(GL_LINE_LOOP);
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
	    glTexCoord3d(face[j].point[i].x,
                       face[j].point[i].y,
               	       face[j].point[i].z);
	//glEnd();
        }
        glEnd();
    }
    if(!room)
    {
	    glColor4f(1.0,1.0,1.0,1.0);
	    glBegin(GL_LINES);
    			glVertex3f(1.9938, 0.0, 0.0);
			glVertex3f(-0.5, 0.0, 0.0);
	    glEnd();
    }
    glPopMatrix();
}

#endif
