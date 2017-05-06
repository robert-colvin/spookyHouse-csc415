# Structured makefile for camera placement
#
#

CC = g++
LDLIBS =  -lglut -lGL -lGLU -lm libSOIL.a -lGLEW
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h SOIL.h sysincludes.h
OBJS = init.o defineBox.o reshape.o display.o loadtex.o

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: spookyRoom tags 

spookyRoom :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o spookyRoom $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

loadtex.o : loadtex.cc globals.h
	$(CC) loadtex.cc -c

defineBox.o : defineBox.cc $(HEADERS)
	$(CC) $(CFLAGS) defineBox.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c

clean:
	rm spookyRoom
	rm *.o

pristine:
	touch *
	rm *.o
	rm spookyRoom

tags:
	ctags *.h *.cc
