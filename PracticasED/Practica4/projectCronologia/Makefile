SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -pedantic -g -I$(INC)



all: main pruebacronologia unioncronologia

main:$(OBJ)/main.o $(OBJ)/EventoHistorico.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/main $(OBJ)/main.o $(OBJ)/EventoHistorico.o

pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/pruebacronologia $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o $(OBJ)/EventoHistorico.o

unioncronologia: $(OBJ)/unioncronologia.o $(OBJ)/Cronologia.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/unioncronologia $(OBJ)/unioncronologia.o $(OBJ)/Cronologia.o $(OBJ)/EventoHistorico.o
# ************ Compilación de módulos ************
$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp $(INC)/Cronologia.hpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/unioncronologia.o: $(SRC)/unioncronologia.cpp $(INC)/Cronologia.hpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/unioncronologia.o $(SRC)/unioncronologia.cpp

$(OBJ)/Cronologia.o: $(SRC)/Cronologia.cpp $(INC)/Cronologia.hpp $(INC)/EventoHistorico.hpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/EventoHistorico.hpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/EventoHistorico.o: $(SRC)/EventoHistorico.cpp $(INC)/EventoHistorico.hpp
	$(CXX) $(CXXFLAGS) -c -o $(OBJ)/EventoHistorico.o $(SRC)/EventoHistorico.cpp
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm ./$(OBJ)/* ./$(BIN)/* ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
