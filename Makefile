CC=gcc
CFLAGS= -I../lib -Wall -Wextra -Wpedantic -g -ggdb -std=c99
LDFLAGS = 
OBJFILES = alloc.o main.o
TARGET = alloc 

all: $(TARGET)



build: $(CC) $(SRC) -o ./bin/alloc.o