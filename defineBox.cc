#ifndef DEFINE_BOX
#define DEFINE_BOX

#include "structs.h"


void defineBox(pentagon *face /*box *face*/ )
{
	face[0].point[0].x = -2.5;  // Bottom
    	face[0].point[0].y = -1.0;
	face[0].point[0].z = -1.0;
	face[0].point[0].w =  1.0;

	face[0].point[1].x = -2.5;
   	face[0].point[1].y =  1.0;
	face[0].point[1].z =  -1.0;
	face[0].point[1].w =  1.0;
	
	face[0].point[2].x =  -0.5;
    	face[0].point[2].y =  1.0;
	face[0].point[2].z =  -1.0;
	face[0].point[2].w =  1.0;

	face[0].point[3].x =  -0.5;
    	face[0].point[3].y = -1.0;
	face[0].point[3].z =  -1.0;
	face[0].point[3].w =  1.0;
	
	face[0].point[4].x =  -0.5;
    	face[0].point[4].y = -1.0;
	face[0].point[4].z =  -1.0;
	face[0].point[4].w =  1.0;
//----------------------------------------------------------------
	face[1].point[0].x = -2.5;  // Left Side
    	face[1].point[0].y = -1.0;
	face[1].point[0].z =  -1.0;
	face[1].point[0].w =  1.0;

	face[1].point[1].x = -2.5;
    	face[1].point[1].y = -1.0;
	face[1].point[1].z =  0.0;
	face[1].point[1].w =  1.0;

	face[1].point[2].x =  -0.5;
    	face[1].point[2].y = -1.0;
	face[1].point[2].z =  0.0;
	face[1].point[2].w =  1.0;

	face[1].point[3].x =  -0.5;
 	face[1].point[3].y = -1.0;
	face[1].point[3].z =  -1.0;
	face[1].point[3].w =  1.0;

	face[1].point[4].x =  -0.5;
 	face[1].point[4].y = -1.0;
	face[1].point[4].z =  -1.0;
	face[1].point[4].w =  1.0;
//-------------------------------------------------------------	
	face[2].point[0].x = -2.5;  // Right Side 
    	face[2].point[0].y =  1.0;
	face[2].point[0].z =  -1.0;
	face[2].point[0].w =  1.0;

	face[2].point[1].x = -2.5;
    	face[2].point[1].y =  1.0;
	face[2].point[1].z =  0.0;
	face[2].point[1].w =  1.0;

	face[2].point[2].x =  -0.5;
    	face[2].point[2].y =  1.0;
	face[2].point[2].z =  0.0;
	face[2].point[2].w =  1.0;

	face[2].point[3].x =  -0.5;
    	face[2].point[3].y =  1.0;
	face[2].point[3].z =  -1.0;
	face[2].point[3].w =  1.0;
	
	face[2].point[4].x =  -0.5;
    	face[2].point[4].y =  1.0;
	face[2].point[4].z =  -1.0;
	face[2].point[4].w =  1.0;
//------------------------------------------------------------	
		

	face[3].point[0].x = -2.5;  // Back Side 
    	face[3].point[0].y = -1.0;
	face[3].point[0].z =  -1.0;
	face[3].point[0].w =  1.0;

	face[3].point[1].x = -2.5;
    	face[3].point[1].y = -1.0;
	face[3].point[1].z =  0.0;
	face[3].point[1].w =  1.0;
	
	face[3].point[2].x = -2.5;
    	face[3].point[2].y =  0.0;
	face[3].point[2].z =  1.0;
	face[3].point[2].w =  1.0;
	
	face[3].point[3].x = -2.5;
    	face[3].point[3].y =  1.0;
	face[3].point[3].z =  0.0;
	face[3].point[3].w =  1.0;
	
	face[3].point[4].x = -2.5;
    	face[3].point[4].y =  1.0;
	face[3].point[4].z =  -1.0;
	face[3].point[4].w =  1.0;

//-------------------------------------------------------------
	face[4].point[0].x =  -0.5;  // Front Side 
    	face[4].point[0].y = -1.0;
	face[4].point[0].z =  -1.0;
	face[4].point[0].w =  1.0;

	face[4].point[1].x =  -0.5;
    	face[4].point[1].y = -1.0;
	face[4].point[1].z =  0.0;
	face[4].point[1].w =  1.0;
	
	face[4].point[2].x =  -0.5;
    	face[4].point[2].y =  0.0;
	face[4].point[2].z =  1.0;
	face[4].point[2].w =  1.0;
	
	face[4].point[3].x =  -0.5;
    	face[4].point[3].y =  1.0;
	face[4].point[3].z =  0.0;
	face[4].point[3].w =  1.0;

	face[4].point[4].x =  -0.5;
    	face[4].point[4].y =  1.0;
	face[4].point[4].z =  -1.0;
	face[4].point[4].w =  1.0;
	
//----------------------------------------------------------------------
	face[5].point[0].x = -2.5;  // TopL 
    	face[5].point[0].y = -1.0;
	face[5].point[0].z =  0.0;
	face[5].point[0].w =  1.0;

	face[5].point[1].x = -2.5;
    	face[5].point[1].y =  1.0;
	face[5].point[1].z =  0.0;
	face[5].point[1].w =  1.0;

	face[5].point[2].x =  -2.5;
    	face[5].point[2].y =  0.0;
	face[5].point[2].z =  1.0;
	face[5].point[2].w =  1.0;

	face[5].point[3].x =  -0.5;
    	face[5].point[3].y =  0.0;
	face[5].point[3].z =  1.0;
	face[5].point[3].w =  1.0;

	face[5].point[4].x =  -0.5;
    	face[5].point[4].y = -1.0;
	face[5].point[4].z =  0.0;
	face[5].point[4].w =  1.0;
//-----------------------------------------------------------------------
	face[6].point[0].x =  -0.5;  // Topr 
    	face[6].point[0].y =  1.0;
	face[6].point[0].z =  0.0;
	face[6].point[0].w =  1.0;

	face[6].point[1].x = -2.5;
    	face[6].point[1].y =  1.0;
	face[6].point[1].z =  0.0;
	face[6].point[1].w =  1.0;

	face[6].point[2].x =  -2.5;
    	face[6].point[2].y =  0.0;
	face[6].point[2].z =  1.0;
	face[6].point[2].w =  1.0;

	face[6].point[3].x =  -0.5;
    	face[6].point[3].y =  0.0;
	face[6].point[3].z =  1.0;
	face[6].point[3].w =  1.0;

	face[6].point[4].x =  -0.5;
    	face[6].point[4].y =  1.0;
	face[6].point[4].z =  0.0;
	face[6].point[4].w =  1.0;
// Define the colors
//
	face[0].color.red   = 0.0;
	face[0].color.green = 0.0;
	face[0].color.blue  = 1.0;
	
	face[1].color.red   = 0.0;
	face[1].color.green = 0.0;
	face[1].color.blue  = 1.0;
	
	face[2].color.red   = 0.0;
	face[2].color.green = 0.0;
	face[2].color.blue  = 1.0;

	face[3].color.red   = 0.0;
	face[3].color.green = 0.0;
	face[3].color.blue  = 1.0;

	face[4].color.red   = 0.0;
	face[4].color.green = 0.0;
	face[4].color.blue  = 1.0;

	face[5].color.red   = 0.0;
	face[5].color.green = 0.0;
	face[5].color.blue  = 1.0;
	
	face[6].color.red   = 0.0;
	face[6].color.green = 0.0;
	face[6].color.blue  = 1.0;
	
}

void defineRoom(pentagon *face /*box *face*/ )
{
	face[0].point[0].x = -2.5;  // Bottom
    	face[0].point[0].y = -1.0;
	face[0].point[0].z = -1.0;
	face[0].point[0].w =  1.0;

	face[0].point[1].x = -2.5;
   	face[0].point[1].y =  1.0;
	face[0].point[1].z =  -1.0;
	face[0].point[1].w =  1.0;
	
	face[0].point[2].x =  -0.5;
    	face[0].point[2].y =  1.0;
	face[0].point[2].z =  -1.0;
	face[0].point[2].w =  1.0;

	face[0].point[3].x =  -0.5;
    	face[0].point[3].y = -1.0;
	face[0].point[3].z =  -1.0;
	face[0].point[3].w =  1.0;
	
	face[0].point[4].x =  -0.5;
    	face[0].point[4].y = -1.0;
	face[0].point[4].z =  -1.0;
	face[0].point[4].w =  1.0;
//----------------------------------------------------------------
	face[1].point[0].x = -2.5;  // Left Side
    	face[1].point[0].y = -1.0;
	face[1].point[0].z =  -1.0;
	face[1].point[0].w =  1.0;

	face[1].point[1].x = -2.5;
    	face[1].point[1].y = -1.0;
	face[1].point[1].z =  0.0;
	face[1].point[1].w =  1.0;

	face[1].point[2].x =  -0.5;
    	face[1].point[2].y = -1.0;
	face[1].point[2].z =  0.0;
	face[1].point[2].w =  1.0;

	face[1].point[3].x =  -0.5;
 	face[1].point[3].y = -1.0;
	face[1].point[3].z =  -1.0;
	face[1].point[3].w =  1.0;

	face[1].point[4].x =  -0.5;
 	face[1].point[4].y = -1.0;
	face[1].point[4].z =  -1.0;
	face[1].point[4].w =  1.0;
//-------------------------------------------------------------	
	face[2].point[0].x = -2.5;  // Right Side 
    	face[2].point[0].y =  1.0;
	face[2].point[0].z =  -1.0;
	face[2].point[0].w =  1.0;

	face[2].point[1].x = -2.5;
    	face[2].point[1].y =  1.0;
	face[2].point[1].z =  0.0;
	face[2].point[1].w =  1.0;

	face[2].point[2].x =  -0.5;
    	face[2].point[2].y =  1.0;
	face[2].point[2].z =  0.0;
	face[2].point[2].w =  1.0;

	face[2].point[3].x =  -0.5;
    	face[2].point[3].y =  1.0;
	face[2].point[3].z =  -1.0;
	face[2].point[3].w =  1.0;
	
	face[2].point[4].x =  -0.5;
    	face[2].point[4].y =  1.0;
	face[2].point[4].z =  -1.0;
	face[2].point[4].w =  1.0;
//------------------------------------------------------------	
		

	face[3].point[0].x = -2.5;  // Back Side 
    	face[3].point[0].y = -1.0;
	face[3].point[0].z =  -1.0;
	face[3].point[0].w =  1.0;

	face[3].point[1].x = -2.5;
    	face[3].point[1].y = -1.0;
	face[3].point[1].z =  0.0;
	face[3].point[1].w =  1.0;
	
	face[3].point[2].x = -2.5;
    	face[3].point[2].y =  0.0;
	face[3].point[2].z =  1.0;
	face[3].point[2].w =  1.0;
	
	face[3].point[3].x = -2.5;
    	face[3].point[3].y =  1.0;
	face[3].point[3].z =  0.0;
	face[3].point[3].w =  1.0;
	
	face[3].point[4].x = -2.5;
    	face[3].point[4].y =  1.0;
	face[3].point[4].z =  -1.0;
	face[3].point[4].w =  1.0;

//-------------------------------------------------------------
	face[4].point[0].x =  -0.5;  // Front Side 
    	face[4].point[0].y = -1.0;
	face[4].point[0].z =  -1.0;
	face[4].point[0].w =  1.0;

	face[4].point[1].x =  -0.5;
    	face[4].point[1].y = -1.0;
	face[4].point[1].z =  0.0;
	face[4].point[1].w =  1.0;
	
	face[4].point[2].x =  -0.5;
    	face[4].point[2].y =  0.0;
	face[4].point[2].z =  1.0;
	face[4].point[2].w =  1.0;
	
	face[4].point[3].x =  -0.5;
    	face[4].point[3].y =  1.0;
	face[4].point[3].z =  0.0;
	face[4].point[3].w =  1.0;

	face[4].point[4].x =  -0.5;
    	face[4].point[4].y =  1.0;
	face[4].point[4].z =  -1.0;
	face[4].point[4].w =  1.0;
	
//----------------------------------------------------------------------
	face[5].point[0].x = -2.5;  // TopL 
    	face[5].point[0].y = -1.0;
	face[5].point[0].z =  0.0;
	face[5].point[0].w =  1.0;

	face[5].point[1].x = -2.5;
    	face[5].point[1].y =  1.0;
	face[5].point[1].z =  0.0;
	face[5].point[1].w =  1.0;

	face[5].point[2].x =  -2.5;
    	face[5].point[2].y =  0.0;
	face[5].point[2].z =  1.0;
	face[5].point[2].w =  1.0;

	face[5].point[3].x =  -0.5;
    	face[5].point[3].y =  0.0;
	face[5].point[3].z =  1.0;
	face[5].point[3].w =  1.0;

	face[5].point[4].x =  -0.5;
    	face[5].point[4].y = -1.0;
	face[5].point[4].z =  0.0;
	face[5].point[4].w =  1.0;
//-----------------------------------------------------------------------
	face[6].point[0].x =  -0.5;  // Topr 
    	face[6].point[0].y =  1.0;
	face[6].point[0].z =  0.0;
	face[6].point[0].w =  1.0;

	face[6].point[1].x = -2.5;
    	face[6].point[1].y =  1.0;
	face[6].point[1].z =  0.0;
	face[6].point[1].w =  1.0;

	face[6].point[2].x =  -2.5;
    	face[6].point[2].y =  0.0;
	face[6].point[2].z =  1.0;
	face[6].point[2].w =  1.0;

	face[6].point[3].x =  -0.5;
    	face[6].point[3].y =  0.0;
	face[6].point[3].z =  1.0;
	face[6].point[3].w =  1.0;

	face[6].point[4].x =  -0.5;
    	face[6].point[4].y =  1.0;
	face[6].point[4].z =  0.0;
	face[6].point[4].w =  1.0;
// Define the colors
//
	face[0].color.red   = 1.0;
	face[0].color.green = 1.0;
	face[0].color.blue  = 1.0;
	
	face[1].color.red   = 1.0;
	face[1].color.green = 1.0;
	face[1].color.blue  = 1.0;
	
	face[2].color.red   = 1.0;
	face[2].color.green = 1.0;
	face[2].color.blue  = 1.0;

	face[3].color.red   = 1.0;
	face[3].color.green = 1.0;
	face[3].color.blue  = 1.0;

	face[4].color.red   = 1.0;
	face[4].color.green = 1.0;
	face[4].color.blue  = 1.0;

	face[5].color.red   = 1.0;
	face[5].color.green = 1.0;
	face[5].color.blue  = 1.0;
	
	face[6].color.red   = 1.0;
	face[6].color.green = 1.0;
	face[6].color.blue  = 1.0;
	
}
#endif
