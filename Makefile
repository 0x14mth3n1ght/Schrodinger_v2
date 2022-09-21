CC=g++
CFLAGS=-I "./armadillo/include"
TARGET=target/testmain
HEADERS=$(wildcard headers/*.h)
SOURCES=$(wildcard src/*.cpp)
OBJ=$(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: compile_main

compile_main: $(OBJ) | target #Créer des dossiers obj et target s'ils n'existent pas
	$(CC) $(CFLAGS) -o $(TARGET) $^

obj/%.o: src/%.cpp $(HEADERS) | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p $@

target:
	mkdir -p $@