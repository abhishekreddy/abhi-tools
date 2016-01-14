CC=gcc
CFLAGS=-c -Wall -I./../inc/ -fPIC -g -DDEBUG_MODE -ggdb -Werror
LDFLAGS=-shared
SOURCES=tools.c \
		stringsupport.c
OBJECTS=$(SOURCES:.c=.o)
TARGET=libabhitools.so
OBJDIR=./../out
OBJ=$(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))

.PHONY: all clean

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJ) 
	$(CC) $(LDFLAGS) -o $(OBJDIR)/$@ $^

clean:
	-rm -f $(TARGET) $(wildcard *.o)
	-rm -rf $(OBJDIR)

