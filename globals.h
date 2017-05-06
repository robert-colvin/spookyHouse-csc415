#ifndef GLOBALS
#define GLOBALS

// use extern here -- then we include this header in each code piece that
// needs access to the variables.   Declare the actual variables in exactly
// one location. In the case of constants, make a specific header where you define 
// them and include it before main.c

extern float xspin,yspin,zspin,xDeltaSpin,yDeltaSpin,zDeltaSpin;
extern const int WINDOW_HEIGHT;
extern const int WINDOW_WIDTH;

extern float currentTime;
extern GLuint textureID;
extern GLUquadric *earth;

extern float shift;
extern int oldTime;
extern float actualfps, fps;
extern double Nstep;
extern bool go;
extern float transCoord;
extern double t;
extern double theta;
extern double omega;

extern GLfloat global_ambient[4];
extern GLfloat material_diffuse[4];
extern GLfloat material_ambient[4];
extern GLfloat material_emission[4];
extern GLfloat material_specular[4];

extern GLfloat light_0_position[4];

extern GLfloat light_0_ambient[4];
extern GLfloat light_0_diffuse[4];
extern GLfloat light_0_specular[4];
extern GLfloat light_0_spot_direction[3];
extern GLfloat light_0_spot_cutoff;
extern GLfloat light_0_spot_exponent;
extern GLfloat light_0_gl_constant_attenuation;
extern GLfloat light_0_gl_linear_attenuation;
extern GLfloat light_0_gl_quadratic_attenuation;

extern GLfloat light_1_position[4];
extern GLfloat light_1_ambient[4];
extern GLfloat light_1_diffuse[4];
extern GLfloat light_1_specular[4];
extern GLfloat light_1_spot_direction[3];
extern GLfloat light_1_spot_cutoff;
extern GLfloat light_1_spot_exponent;
extern GLfloat light_1_gl_constant_attenuation;
extern GLfloat light_1_gl_linear_attenuation;
extern GLfloat light_1_gl_quadratic_attenuation;

extern GLfloat light_2_position[4];
extern GLfloat light_2_ambient[4];
extern GLfloat light_2_diffuse[4];
extern GLfloat light_2_specular[4];
extern GLfloat light_2_spot_direction[3];
extern GLfloat light_2_spot_cutoff;
extern GLfloat light_2_spot_exponent;
extern GLfloat light_2_gl_constant_attenuation;
extern GLfloat light_2_gl_linear_attenuation;
extern GLfloat light_2_gl_quadratic_attenuation;

extern GLfloat light_3_position[4];
extern GLfloat light_3_ambient[4];
extern GLfloat light_3_diffuse[4];
extern GLfloat light_3_specular[4];
extern GLfloat light_3_spot_direction[3];
extern GLfloat light_3_spot_cutoff;
extern GLfloat light_3_spot_exponent;
extern GLfloat light_3_gl_constant_attenuation;
extern GLfloat light_3_gl_linear_attenuation;
extern GLfloat light_3_gl_quadratic_attenuation;
#endif

