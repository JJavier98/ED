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
all : $(BIN)/cronologia_exe

$(OBJ)/TDA_cronologia.o : $(SRC)/TDA_cronologia.cpp $(INC)/TDA_cronologia.h $(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/TDA_cronologia.cpp -o $(OBJ)/TDA_cronologia.o

$(OBJ)/cronologia_exe.o : $(SRC)/cronologia_exe.cpp $(INC)/TDA_cronologia.h $(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/cronologia_exe.cpp -o $(OBJ)/cronologia_exe.o

$(OBJ)/TDA_fechahistorica.o : $(SRC)/TDA_fechahistorica.cpp $(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/TDA_fechahistorica.cpp -o $(OBJ)/TDA_fechahistorica.o

$(BIN)/cronologia_exe : $(OBJ)/cronologia_exe.o $(LIB)/TDA_cronologia.a
	$(CXX) -o $(BIN)/cronologia_exe $(OBJ)/cronologia_exe.o $(LIB)/TDA_cronologia.a

# ************ Creación de la librería ************
$(LIB)/TDA_cronologia.a : $(OBJ)/TDA_cronologia.o $(OBJ)/TDA_fechahistorica.o
	$(AR) $(RVS) $(LIB)/TDA_cronologia.a $(OBJ)/TDA_cronologia.o $(OBJ)/TDA_fechahistorica.o

# ************ Limpieza ************
#clean -rm $(OBJ)/* $(LIB)/* #$(SRC)/*~ $(INC)/*~ ./*~

#mrproper  clean -rm $(BIN)/* doc/html/*
