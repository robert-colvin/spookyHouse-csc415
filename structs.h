
#ifndef STRUCTS
#define STRUCTS

typedef struct vertex {
        float x;
        float y;
        float z;
        float w;
} vertex;

typedef struct colortype {
	float red;
	float green;
	float blue;
} colortype;

typedef struct box {
	vertex point[4];
	colortype color;	
} box;

typedef struct pentagon {
	vertex point[5];
	colortype color;
} pentagon;

#endif
