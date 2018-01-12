SRC = src
INC = includes
OBJ = obj
BIN = bin
LIB = lib
DAT = datos
RVS = rvs


CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++11 -g  -I$(INC)
AR = ar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile

# ************ Compilación de módulos ************
all : $(BIN)/fechahistorica_exe

$(OBJ)/TDA_fechahistorica.o : $(SRC)/TDA_fechahistorica.cpp $(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/TDA_fechahistorica.cpp -o $(OBJ)/TDA_fechahistorica.o

$(OBJ)/fechahistorica_exe.o : $(SRC)/fechahistorica_exe.cpp $(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/fechahistorica_exe.cpp -o $(OBJ)/fechahistorica_exe.o

$(BIN)/fechahistorica_exe : $(OBJ)/fechahistorica_exe.o $(OBJ)/TDA_fechahistorica.o
	$(CXX) -o $(BIN)/fechahistorica_exe $(OBJ)/fechahistorica_exe.o $(OBJ)/TDA_fechahistorica.o

# ************ Creación de la librería ************
$(LIB)/TDA_fechahistorica.a : $(OBJ)/TDA_fechahistorica.o
	$(AR) $(RVS) $(LIB)/TDA_fechahistorica.a $(OBJ)/TDA_fechahistorica.o

# ************ Limpieza ************
#clean :
	#-rm $(OBJ)/* $(LIB)/* #$(SRC)/*~ $(INC)/*~ ./*~

#mrproper : clean
	#-rm $(BIN)/* doc/html/*
