CC = g++
CFLAGS = -Wall
PROG = 201101106

SRCS = 1.c imageloader.cpp md2model.cpp vec3f.cpp

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut -lGL -lGLU -lSOIL
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
