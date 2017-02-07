#OBJS= singly.o myTesselate.o myVertexMath.o #sutherlandHodgman.o
LIBS=-lglut -lGLU -lGL
CC=g++
#CFLAG=-O2
HEADERS=structs.h

all: pendulum

pendulum : someting.o $(OBJS)
	$(CC) $(CFLAG) someting.o $(OBJS) -o pendulum $(LIBS)

someting.o: someting.cpp $(HEADERS)
	$(CC) someting.cpp $(CFLAG) -c

#singly.o: singly.cpp $(HEADERS)
#	$(CC) singly.cpp $(CLAG) -c

#myTesselate.o: myTesselate.cpp $(HEADERS)
#	$(CC) myTesselate.cpp $(CFLAG) -c

#myVertexMath.o: myVertexMath.cpp $(HEADERS)
#	$(CC) myVertexMath.cpp $(CFLAG) -c

#sutherlandHodgman.o: sutherlandHodgman.cpp $(HEADERS)
#	$(CC) sutherlandHodgman.cpp $(CFLAG) -c

clean:
	rm *.o

pristine:
	rm *.o
	touch *
