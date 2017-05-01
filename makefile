# Structured makefile for camera placement
#
#

CC = g++
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = opengl.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineBox.o drawPend.o reshape.o display.o  

debug ?= n
ifeq ($(debug), y)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2 
endif


all: pendulum tags 

pendulum :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o pendulum $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

defineBox.o : defineBox.cc $(HEADERS)
	$(CC) $(CFLAGS) defineBox.cc -c

drawPend.o : drawPend.cc $(HEADERS)
	$(CC) $(CFLAGS) drawPend.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c

clean:
	rm pendulum
	rm *.o

pristine:
	touch *
	rm *.o
	rm pendulum

tags:
	ctags *.h *.cc
