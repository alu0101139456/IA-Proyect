CXX		  := g++
CXX_FLAGS := -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= 
EXECUTABLE	:= main 


all: $(BIN)/$(EXECUTABLE) 

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) 

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	-rm $(BIN)/main
