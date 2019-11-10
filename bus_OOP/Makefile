#
#  Makefile for Architecture Explorer
#
#  by Alan Su, NCKU
#  alansuphd@mail.ncku.edu.tw
#

CC = g++
PCFLAG = -O1 -Wall -c
POFLAG = -O1 -Wall
HDR = Bus.h Function.h Menu.h
SRC = ${HDR:.h=.cpp} main.cpp
OBJ = ${HDR:.h=.o} main.o
TARGET = bus

all: $(TARGET)
Bus.o: Bus.h Bus.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
Function.o: Function.h Function.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
Menu.o: Menu.h Menu.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
main.o: main.cpp
	$(CC) $(PCFLAG) $(@:.o=.cpp)
$(TARGET): $(OBJ)
	$(CC) $(POFLAG) $(LIB) $(OBJ) -o $@

clean:
	rm $(OBJ)
	rm $(TARGET)
