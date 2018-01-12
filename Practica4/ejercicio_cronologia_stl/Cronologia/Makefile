SRC = src
INC = includes
OBJ = obj
BIN = bin
LIB = lib
DAT = datos
RVS = rvs


CXX = g++
#CXXFLAGS =  -fpermissive -Wreturn-type -Wall -Wextra -pedantic -std=c++11 -g  -I$(INC)
CXXFLAGS =  -std=c++11 -g  -I$(INC)
AR = ar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile

# ************ Compilación de módulos ************
all : $(BIN)/union_cronologia_exe $(BIN)/busca_palabra_cronologia_exe $(BIN)/intervalo_cronologia_exe $(BIN)/estadistica_cronologia_exe

$(OBJ)/TDA_cronologia.o : $(SRC)/TDA_cronologia.cpp $(INC)/TDA_cronologia.h ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/TDA_cronologia.cpp -o $(OBJ)/TDA_cronologia.o

$(OBJ)/TDA_fechahistorica.o : ../FechaHistorica/$(SRC)/TDA_fechahistorica.cpp ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) ../FechaHistorica/$(SRC)/TDA_fechahistorica.cpp -o $(OBJ)/TDA_fechahistorica.o

$(OBJ)/union_cronologia_exe.o : $(SRC)/ejecutables/union_cronologia_exe.cpp $(INC)/TDA_cronologia.h ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/ejecutables/union_cronologia_exe.cpp -o $(OBJ)/union_cronologia_exe.o

$(BIN)/union_cronologia_exe : $(OBJ)/union_cronologia_exe.o $(LIB)/TDA_cronologia.a
	$(CXX) -o $(BIN)/union_cronologia_exe $(OBJ)/union_cronologia_exe.o $(LIB)/TDA_cronologia.a

$(OBJ)/busca_palabra_cronologia_exe.o : $(SRC)/ejecutables/busca_palabra_cronologia_exe.cpp $(INC)/TDA_cronologia.h ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/ejecutables/busca_palabra_cronologia_exe.cpp -o $(OBJ)/busca_palabra_cronologia_exe.o

$(BIN)/busca_palabra_cronologia_exe : $(OBJ)/busca_palabra_cronologia_exe.o $(LIB)/TDA_cronologia.a
	$(CXX) -o $(BIN)/busca_palabra_cronologia_exe $(OBJ)/busca_palabra_cronologia_exe.o $(LIB)/TDA_cronologia.a

$(OBJ)/intervalo_cronologia_exe.o : $(SRC)/ejecutables/intervalo_cronologia_exe.cpp $(INC)/TDA_cronologia.h ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/ejecutables/intervalo_cronologia_exe.cpp -o $(OBJ)/intervalo_cronologia_exe.o

$(BIN)/intervalo_cronologia_exe : $(OBJ)/intervalo_cronologia_exe.o $(LIB)/TDA_cronologia.a
	$(CXX) -o $(BIN)/intervalo_cronologia_exe $(OBJ)/intervalo_cronologia_exe.o $(LIB)/TDA_cronologia.a

$(OBJ)/estadistica_cronologia_exe.o : $(SRC)/ejecutables/estadistica_cronologia_exe.cpp $(INC)/TDA_cronologia.h ../FechaHistorica/$(INC)/TDA_fechahistorica.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/ejecutables/estadistica_cronologia_exe.cpp -o $(OBJ)/estadistica_cronologia_exe.o

$(BIN)/estadistica_cronologia_exe : $(OBJ)/estadistica_cronologia_exe.o $(LIB)/TDA_cronologia.a
	$(CXX) -o $(BIN)/estadistica_cronologia_exe $(OBJ)/estadistica_cronologia_exe.o $(LIB)/TDA_cronologia.a

# ************ Creación de la librería ************
$(LIB)/TDA_cronologia.a : $(OBJ)/TDA_cronologia.o $(OBJ)/TDA_fechahistorica.o
	$(AR) $(RVS) $(LIB)/TDA_cronologia.a $(OBJ)/TDA_cronologia.o $(OBJ)/TDA_fechahistorica.o

# ************ Limpieza ************
#clean -rm $(OBJ)/* $(LIB)/* #$(SRC)/*~ $(INC)/*~ ./*~

#mrproper  clean -rm $(BIN)/* doc/html/*
