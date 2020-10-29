CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= fibonacci_word


all: $(BIN)/$(EXECUTABLE) input.txt

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE) 

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/fibonacci_word
