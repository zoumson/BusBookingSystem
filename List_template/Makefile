#  Makefile
#  Created by ZOUMA Adama on 11/14/19.
#  Copyright © 2019 ZOUMA Adama. All rights reserved

CC = g++
PCFLAG = -O1 -Wall -c
POFLAG = -O1 -Wall
HDR = Node.h List.h
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
TARGET = list

all: $(TARGET)

$(OBJ): $(SRC) $(HDR)
	$(CC) $(PCFLAG) $(@:.o=.cpp)
$(TARGET): $(OBJ)
	$(CC) $(POFLAG) $(LIB) $(OBJ) -o $@

clean:
	rm $(OBJ)
	rm $(TARGET)
