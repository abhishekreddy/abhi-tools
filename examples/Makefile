CC=gcc
CFLAGS=-c -Wall -I./../inc/ -DDEBUG_MODE
LDFLAGS=
SOURCES=stringex.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
LIBS=-L../out/ -labhitools
OBJDIR=./../out
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(OBJDIR)/$@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f test
