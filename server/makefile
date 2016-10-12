# The make file for Collabrogramming

# The compiler
CC = gcc

# Compiler Flags
# -g adds debugging information
# -Wall turns on most compiler warnings
CFLAGS = -g -Wall

# The name of the executable:
TARGET = Collabrogramming

all: $(TARGET)

# Create the executable with all the following dependancies
$(TARGET): fileio.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) fileio.o main.o

###################################################################################
# Create all the object files

# Create the object file for conf.o
fileio.o: fileio.c
	$(CC) $(CFLAGS) -c fileio.c

# Create the object file for main.o
main.o: main.c fileio.h
	$(CC) $(CFLAGS) -c main.c
