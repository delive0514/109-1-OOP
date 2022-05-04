.PHONY: all
CC = g++
SRC = ./src
BIN = ./bin
TEST = ./test
CFLAG = -Wfatal-errors
LIB = -lgtest -lpthread

all: what $(BIN)/ut_all

$(BIN)/ut_all : $(TEST)/ut_main.cpp $(SRC)/*.h
	$(CC) $(CFLAG) -o $@ $^ $(LIB)
what:
	mkdir -p bin obj

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
