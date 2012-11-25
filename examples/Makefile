CC=gcc
CFLAGS=-c -Wall -I./../inc/
LDFLAGS=
SOURCES=example.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
LIBS=-L../out/ -labhitools

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f test
