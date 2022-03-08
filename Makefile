OBJECTS=main.o
OUTPUT=main

CFLAGS=-I/usr/local/Mesa-3.4/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib

$(OUTPUT): $(OBJECTS)
	cc $(FLAGS) $(LDFLAGS)  -o $(OUTPUT) $(OBJECTS) $(LDLIBS)
	
$(OBJECTS): main.c

SRCS = $(shell find  -name '*.c')

all:
	cc $(FLAGS) $(LDFLAGS)  -o $(OUTPUT) $(SRCS) $(LDLIBS)

run:
	./main

clean:
	rm -f *.o
	rm -f main 