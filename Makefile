CC=gcc
CFLAGS= -I. -Wall -Wextra -Wpedantic -g -ggdb -std=c99
LDFLAGS = 

OBJDIR = obj
SRCDIR = src
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst %.c,$(OBJDIR)/%.o, $(notdir $(SRC)))
$(info $(OBJ))

TARGET = ./bin/alloc 

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(OBJ)