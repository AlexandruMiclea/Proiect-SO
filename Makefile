CC=gcc
CFLAGS= -I../inc -Wall -Wextra -Wpedantic -lpthread -g -ggdb -std=gnu11
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