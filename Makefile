CC=gcc
CFLAGS= -I../inc -Wall -Wextra -Wpedantic -g -ggdb -std=c99
LDFLAGS = 

OBJDIR = obj
SRCDIR = src
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst %.c,$(OBJDIR)/%.o, $(notdir $(SRC)))

TARGET = ./bin/alloc 

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clear:
	rm -f $(OBJ)