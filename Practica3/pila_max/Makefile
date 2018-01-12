SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DAT = datos


CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++11 -g  -I$(INC)
AR = ar

all: documentacion: $(BIN)/Pila_Max :

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile

# ************ Compilación de módulos ************

$(OBJ)/Pila_Max.o : $(SRC)/Pila_Max.cpp $(INC)/Pila/Pila_max.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/Pila_Max.cpp -o $(OBJ)/Pila_Max.o

$(BIN)/Pila_Max : $(OBJ)/Pila_Max.o
	$(CXX) -o $(BIN)/Pila_Max $(OBJ)/Pila_Max.o